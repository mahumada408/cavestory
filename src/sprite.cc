#include "sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string &filepath, int sourceX, 
            int sourceY, int width, int height, double posX, double posY) :
    sprite_x_(posX),
    sprite_y_(posY) 
{
    this->source_rectangle_.x = sourceX;
    this->source_rectangle_.y = sourceY;
    this->source_rectangle_.w = width;
    this->source_rectangle_.h = height;

    this->sprite_sheet = SDL_CreateTextureFromSurface(graphics.GetRenderer(), 
                                                graphics.LoadImage(filepath));

    if (this->sprite_sheet == NULL) {
        std::cout << "Error: Unable to load image." << std::endl;
    }

    // Initialize the collision box.
    this->collision_box = MRectangle(this->sprite_x_, this->sprite_y_, width * sprite_scaler_,
                                     height * sprite_scaler_);
}

Sprite::~Sprite() {}

void Sprite::Draw(Graphics &graphics, int x, int y) {
    SDL_Rect destination_rectangle = {x, y, this->source_rectangle_.w * sprite_scaler_, 
    this->source_rectangle_.h * sprite_scaler_};

    graphics.DrawToScreen(this->sprite_sheet, &this->source_rectangle_, 
                                                        &destination_rectangle);
}

const MRectangle Sprite::GetCollisionBox() const {
    return this->collision_box;
}
const Sides::Side Sprite::GetCollisionSide(MRectangle& colliding_rectangle) const {
    // Determine the penetration of the collision box on each side.
    // Note that the one smallest value is the one that has collided. 
    int pen_top, pen_bottom, pen_right, pen_left;
    pen_top = std::abs(this->collision_box.GetTop() - colliding_rectangle.GetBottom());
    pen_bottom = std::abs(this->collision_box.GetBottom() - colliding_rectangle.GetTop());
    pen_right = std::abs(this->collision_box.GetRight() - colliding_rectangle.GetLeft());
    pen_left = std::abs(this->collision_box.GetLeft() - colliding_rectangle.GetRight());

    int smallest_pen = std::min({pen_top, pen_bottom, pen_right, pen_left});

    return 
        // If smallest_pen is equal to pen_top, return TOP_SIDE.
        smallest_pen == pen_top ? Sides::Side::TOP_SIDE :
        smallest_pen == pen_bottom ? Sides::Side::BOTTOM_SIDE :
        smallest_pen == pen_right ? Sides::Side::RIGHT_SIDE :
        smallest_pen == pen_left ? Sides::Side::LEFT_SIDE :
        Sides::Side::NONE_SIDE;
}

void Sprite::Update() {
    // Update the location of the collision box to follow the sprite.
    this->collision_box = MRectangle(this->sprite_x_, this->sprite_y_, this->source_rectangle_.w * sprite_scaler_, this->source_rectangle_.h * sprite_scaler_);
}