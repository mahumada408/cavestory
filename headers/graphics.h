#pragma once

#include <SDL2/SDL.h>

class Graphics {
    public:
        // Constructor and destructor for the Graphics class. Constructor creates the window and rederer witha resolution of 640x480 in a window called "Cave Story."
        Graphics();
        ~Graphics();
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
};