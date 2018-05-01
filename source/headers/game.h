#pragma once

#include <SDL2/SDL.h>
#include "graphics.h"

// Game Class
// This class holds all information dealing with the game for Cavestory

class Game {
    public:
        // We call the main GameLoop from the contructor
        Game();
        ~Game();
    private:
        void GameLoop();
        void Draw(Graphics &graphics);
        void Update(double elapsed_time);
};
