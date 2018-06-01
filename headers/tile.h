#pragma once

#include <SDL2/SDL.h>
#include <eigen3/Eigen/Core>

#include "graphics.h"
#include "sprite.h"
#include "mvector2.h"

class Tile {
    public:
        Tile();
        Tile(SDL_Texture* tile_size_, MVector2 size_, 
                   MVector2 tileset_position_,MVector2 position_);
        // Update out tiles for collisions. 
        void TileUpdate(double elapsed_time);

        // Draws graphics to the renderer. 
        void TileDraw(Graphics &graphics);

    private:
        SDL_Texture* tile_set_;

        // Size of the tile
        MVector2 size_;

        // Position on the tile set where the tile is. 
        MVector2 tileset_position_;

        // Position on the map that the tile is in.
        MVector2 position_;

        int x_index = 0;
        int y_index = 1;
};