#include "graphics.h"

// Grahics Class
// Implementation for the Graphics class
// This class holds all information dealing with the graphics for Cavestory


// Graphics class constructor
Graphics::Graphics(){
    // SDL function to create the window and renderer together.
    // Funtion needs the window size (640x480), int value for the flags being set (in this case we will use 0), 
    // and the window and renderer pointers. By using the &, we are passing in the address to the pointers we created.
    SDL_CreateWindowAndRenderer(640, 480, 0, &_window, &_renderer);
    SDL_SetWindowTitle(_window, "Cave Story");
}

// Graphics class destructor
Graphics::~Graphics(){
    SDL_DestroyWindow(_window);
}
