#include "game.h"

namespace {
    const int frame_rate = 50;
    const int max_frame_time = 5*1000/frame_rate;
}


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
    Input input;
    SDL_Event sdl_event;

    int last_update_time = SDL_GetTicks();

    // Start game loop
    while (true) {
        // Reset the key frame.
        input.BeginNewFrame();

        // SDL will poll for events and stick them in that sdl_event object.
        if(SDL_PollEvent(&sdl_event)){
            if(sdl_event.type == SDL_KEYDOWN) {
                if(sdl_event.key.repeat == 0){
                    input.KeyPressedEvent(sdl_event);
                }
            }
            else if(sdl_event.type == SDL_KEYUP) {
                input.KeyReleasedEvent(sdl_event);
            }
            // SDL_QUIT can happen if we x out of the game window. This allows us to close the program without getting stuck in the loop. 
            else if(sdl_event.type == SDL_QUIT){
                return;
            }

        }
        if(input.WasKeyPressed(SDL_SCANCODE_ESCAPE) == true) {
            return;
        }
        
        const int current_time_ms = SDL_GetTicks();
        int elapsed_time_ms = current_time_ms - last_update_time;
        this->Update(std::min(elapsed_time_ms, max_frame_time));
        last_update_time = current_time_ms;
    }
}

void Game::Draw(Graphics &graphics) {

}

void Game::Update(double elapsed_time) {

}
