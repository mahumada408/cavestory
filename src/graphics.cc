#include "graphics.h"

// Graphics class constructor
Graphics::Graphics()
{
    // SDL function to create the window and renderer together.
    // Funtion needs the window size (640x480), int value for the flags being 
    // set (in this case we will use 0), and the window and renderer pointers. 
    // By using the &, we are passing in the address to the pointers we created.
    SDL_CreateWindowAndRenderer(640, 480, 0, &window_, &renderer_);
    SDL_SetWindowTitle(window_, "Cave Story");
}

// Graphics class destructor
Graphics::~Graphics()
{
    SDL_DestroyWindow(window_);
}
