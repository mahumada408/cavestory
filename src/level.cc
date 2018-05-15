#include "level.h"

Level::Level() {}

Level::Level(std::string map_name, 
                Eigen::Vector2d spawn_point,
                Graphics &graphics) : 
                map_name_(map_name),
                spawn_point_(spawn_point),
                size_(Eigen::Vector2d::Zero()) {

    this->LoadMap(map_name, graphics);
}

Level::~Level() {}

void Level::LoadMap(std::string map_name, Graphics &graphics)
{
    // TEMP CODE TO LOAD BACKGROUND
    this->background_texture_ = SDL_CreateTextureFromSurface(graphics.GetRenderer(), graphics.LoadImage("/home/manuel/development/cavestory/content/backgrounds/bkBlue.png"));

    if (this->background_texture_ == NULL) {
        std::cout << "Error: Unable to load image." << std::endl;
    }

    // Use size when drawing background.
    this->size_ << 1280, 960;
}

void Level::LevelUpdate(double elapsed_time) {}

void Level::LevelDraw(Graphics &graphics)
{
    // Draw the background

    // The source background image is 64x64 pixels.
    SDL_Rect source_rect = {0, 0, 64, 64};

    SDL_Rect destination_rect;

    // Loop to draw over the entire 1280x960 display.
    for (int i = 0; i < this->size_[0] / 64; i++)
    {
        for (int j = 0; j < this->size_[1] / 64; j++)
        {
            destination_rect.x = i * 64;
            destination_rect.y = j * 64;
            destination_rect.w = 64;
            destination_rect.h = 64;
            graphics.DrawToScreen(this->background_texture_, &source_rect, &destination_rect);
        }
    }
}
