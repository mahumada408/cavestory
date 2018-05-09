#include "sprite.h"

Sprite::Sprite() {}

Sprite::Sprite(Graphics &graphics, const std::string &filepath, int sourceX, 
            int sourceY, int width, int height, double posX, double posY) :
    x_(posX),
    y_(posY) 
{
    this->source_rectangle_.x = sourceX;
    this->source_rectangle_.y = sourceY;
    this->source_rectangle_.w = width;
    this->source_rectangle_.h = height;

    sprite_scaler_ = 2;

    this->sprite_sheet = SDL_CreateTextureFromSurface(graphics.GetRenderer(), 
                                                graphics.LoadImage(filepath));

    if (this->sprite_sheet == NULL) {
        std::cout << "Error: Unable to load image." << std::endl;
    }
}

Sprite::~Sprite() {}

void Sprite::Draw(Graphics &graphics, int x, int y) {
    SDL_Rect destination_rectangle = {x, y, this->source_rectangle_.w * sprite_scaler_, 
    this->source_rectangle_.h * sprite_scaler_};

    graphics.DrawToScreen(this->sprite_sheet, &this->source_rectangle_, 
                                                        &destination_rectangle);
}

void Sprite::Update() {}