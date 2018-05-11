#include "animated_sprite.h"

AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filepath,
int source_x, int source_y, int width, int height, double pos_x, double pos_y, 
double time_to_update) {
    frame_index_ = 0;
    time_to_update = 0;
    visible_ = true;
    current_animation_once_ = false;
    current_animation_ = "";
}

void AnimatesSprite::AddAnimation(int frames, int x, int y, std::string name,
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
    this->offsets_.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedSprite::ResetAnimations() {
    this->animation_.clear();
    this->offsets_.clear();
}

void AnimatedSprite::PlayAnimation(std::string animation, bool once) {
    this->current_animation_once_ = once;
    if (this->current_animation_ != animation_) {
        this->current_animation_ = animation_;
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

void AnimatedSprite::Update(int elapsed_time) {
    Sprite::Update();

    this->time_elapsed_ += elapsed_time;
    if (this->time_elapsed_ > this->time_to_update) {
        
    }
}