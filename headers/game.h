#pragma once

#include <SDL2/SDL.h>

#include "animated_sprite.h"
#include "graphics.h"
#include "input.h"
#include "sprite.h"

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

        AnimatedSprite player_;
};
