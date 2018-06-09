#pragma once

#include <algorithm>
#include <cmath>
#include <eigen3/Eigen/Core>
#include <iostream>
#include <SDL2/SDL.h>
#include <sstream>
#include <string>
#include <vector>

#include "graphics.h"
#include "mrectangle.h"
#include "mvector2.h"
#include "sprite.h"
#include "tile.h"
#include "tinyxml2.h"

// Tileset stucture
struct TileSet {
    SDL_Texture* texture;
    int first_gid;
    TileSet() {
        this->first_gid = -1;
    }
    TileSet(SDL_Texture* texture_init, int first_gid_init) {
        this->texture = texture_init;
        this->first_gid = first_gid_init;
    }
};

class Level {
    public:
        Level();
        Level(std::string map_name, MVector2 spawn_point,
              Graphics &graphics);
        ~Level();

        void LevelUpdate(double elapsed_time);
        void LevelDraw(Graphics &graphics);

        std::vector<MRectangle> CheckTileCollisions(const MRectangle& other_rect);

    private:
        std::string map_name_;
        MVector2 spawn_point_;
        MVector2 size_;
        MVector2 tile_size_;
        SDL_Texture* background_texture_;
        std::vector<Tile> tile_list_;
        std::vector<TileSet> tile_sets;
        std::vector<MRectangle> collision_rectangles_;

        // Loads a map.
        void LoadMap(std::string map_name, Graphics &graphics);
};