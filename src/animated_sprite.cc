#include "animated_sprite.h"

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filepath,
int source_x, int source_y, int width, int height, double pos_x, double pos_y, 
double time_to_update) : 
    Sprite(graphics, filepath, source_x, source_y, width, height, pos_x, pos_y), 
    frame_index_(0), 
    time_to_update(time_to_update), 
    visible_(true), 
    current_animation_once_(false),
    current_animation_("") {

    // Initialize offsets.
    zero_offsets_.x = 0;
    zero_offsets_.y = 0;

}

void AnimatedSprite::AddAnimation(int frames, int x, int y, std::string name,
                                  int width, int height, Vector2 offset)
{
    std::vector<SDL_Rect> rectangles;

    // Loop through the number of frames from our sprite sheet.
    for (int i; i < frames; i++)
    {
        SDL_Rect new_rect = {(i+x) * width, y, width, height};
        rectangles.push_back(new_rect);
    }

    // Add the vector to the map.
    this->animation_.insert(std::pair<std::string,
                                      std::vector<SDL_Rect>>(name, rectangles));

    // Store our offsets.
    this->draw_offsets_.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::ResetAnimations() {
    this->animation_.clear();
    this->draw_offsets_.clear();
}

void AnimatedSprite::PlayAnimation(std::string animation, bool once) {
    this->current_animation_once_ = once;
    if (this->current_animation_ != animation) {
        this->current_animation_ = animation;
        this->frame_index_ = 0;
    }
}

void AnimatedSprite::SetVisible(bool visible) {
    this->visible_ = visible;
}

void AnimatedSprite::StopAnimation() {
    this->frame_index_ = 0;
    this->AnimationDone(this->current_animation_);
}

void AnimatedSprite::Update(double elapsed_time) {
    Sprite::Update();

    this->time_elapsed_ += elapsed_time;
    if (this->time_elapsed_ > this->time_to_update) {

        // Decide which frame to go to. Unfortunately, it's not as simple as 
        // just going to the next frame, because we need to wrap around when we
        // reach the third frame.
        if (this->frame_index_ < this->animation_[this->current_animation_].size() - 1) {
            // If frame index is not at the last one.
            this->frame_index_++;
        }
        else {
            if (this->current_animation_once_ == true) {
                // If our animation has been played throuhgh once.
                this->SetVisible(false);
            }
            // Wrap around.
            this->frame_index_ = 0;
            this->AnimationDone(this->current_animation_);
        }

        // Reset timer back to zero.
        this->time_elapsed_ = 0;
    }
}

void AnimatedSprite::AnimatedDraw(Graphics &graphics, int x, int y){
    if (this->visible_) {
        SDL_Rect destination_rectangle;
        destination_rectangle.x = x + this->draw_offsets_[this->current_animation_].x;
        destination_rectangle.y = y + this->draw_offsets_[this->current_animation_].y;
        destination_rectangle.w = this->source_rectangle_.w * sprite_scaler_;
        destination_rectangle.h = this->source_rectangle_.h * sprite_scaler_;

        // Current animation indexes the map, frame index indexes the vector.
        SDL_Rect source_rect = this->animation_[this->current_animation_][this->frame_index_];
        graphics.DrawToScreen(this->sprite_sheet, &source_rect, &destination_rectangle);
        
    }
}

void AnimatedSprite::AnimationDone(std::string current_animation_){}

// The implementation should be done in the class that inherits from AnimatedSprite.
void AnimatedSprite::SetupAnimation(){
    int num_frames = 3;
    int x_init = 0;
    int y_init = 0;
    int height = 16; // In pixels
    int width = 16; // In pixels
    this->AddAnimation(num_frames, x_init, y_init, "RunLeft", height, width, zero_offsets_);
    this->AddAnimation(num_frames, 0, 16, "RunRight", height, width, zero_offsets_);

}