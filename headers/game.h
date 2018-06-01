#pragma once

#include <eigen3/Eigen/Core>
#include <SDL2/SDL.h>

#include "graphics.h"
#include "input.h"
#include "level.h"
#include "mvector2.h"
#include "player.h"
#include "sprite.h"

// Game Class
// This class holds all information dealing with the game for Cavestory

class Game {
    public:
        // We call the main GameLoop from the contructor
        Game();
        ~Game();
    private:
        // Runs the main loop of the game.
        void GameLoop();

        // Draws the graphics to the renderer.
        void Draw(Graphics &graphics);

        // Checks for any events (e.g. keyboard, game pad, etc.)
        void EventChecker(SDL_Event &sdl_event, Input &key_input);

        // Updates the player animation at the given time.
        void Update(double elapsed_time);

        // Our player!
        Player player_;

        // Our levels!
        Level level_;
};
