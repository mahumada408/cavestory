#include "game.h"

Game::Game() {
    // Initializes a lot of SDL things.
    SDL_Init(SDL_INIT_EVERYTHING);

    // Calling the loop from the constructor.
    this->GameLoop();
}

Game::~Game() {

}

// This is a very important function, maybe the most important in the program. This will happen every frame!
void Game::GameLoop() {
    Graphics graphics;
    SDL_Event  sdl_event;

    while (true) {
        // SDL will poll for events and stick them in that sdl_event object.
        if(SDL_PollEvent(&sdl_event)){
            // SDL_QUIT can happen if we x out of the game window. This allows us to close the program without getting stuck in the loop. 
            if(sdl_event.type == SDL_QUIT){
                return;
            }

        }
    }
}

void Game::Draw(Graphics &graphics) {

}

void Game::Update(double elapsed_time) {

}
