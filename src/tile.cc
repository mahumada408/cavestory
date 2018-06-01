#include "tile.h"

Tile::Tile() {}

Tile::Tile(SDL_Texture *tile_set_, MVector2 size_,
           MVector2 tileset_position_, MVector2 position_) : 
            tile_set_(tile_set_),
            size_(size_),
            tileset_position_(tileset_position_),
            position_(MVector2(position_.x * Sprite::sprite_scaler_, position_.y * Sprite::sprite_scaler_))
            //position_(Eigen::Vector2d << position_[x_index] * Sprite::sprite_scaler_, position_[y_index] * Sprite::sprite_scaler_)
{
}

void Tile::TileUpdate(double elaped_time) {}

void Tile::TileDraw(Graphics &graphics)
{
    SDL_Rect dest_rect = {this->position_.x,
                          this->position_.y,
                          this->size_.x * Sprite::sprite_scaler_,
                          this->size_.y * Sprite::sprite_scaler_ };
    SDL_Rect source_rect = {this->tileset_position_.x, this->tileset_position_.y, this->size_.x, this->size_.y};
    graphics.DrawToScreen(this->tile_set_, &source_rect, &dest_rect);
}

