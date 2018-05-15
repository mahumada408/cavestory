#pragma once

#include <eigen3/Eigen/Core>
#include <iostream>
#include <SDL2/SDL.h>
#include <string>

#include "graphics.h"

class Level {
    public:
        Level();
        Level(std::string map_name, Eigen::Vector2d spawn_point,
              Graphics &graphics);
        ~Level();

        void LevelUpdate(double elapsed_time);
        void LevelDraw(Graphics &graphics);

    private:
        std::string map_name_;
        Eigen::Vector2d spawn_point_;
        Eigen::Vector2d size_;
        SDL_Texture* background_texture_;

        // Loads a map.
        void LoadMap(std::string map_name, Graphics &graphics);
};