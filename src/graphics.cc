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
    SDL_DestroyWindow(this->window_);
    SDL_DestroyRenderer(this->renderer_);
}

SDL_Surface* Graphics::LoadImage(const std::string &filepath) {
    // Sprite sheet has not been loaded.  
    if (this->sprite_sheets_.count(filepath) == 0) {
        // Load the sprite sheet map
        this->sprite_sheets_[filepath] = IMG_Load(filepath.c_str());
    }
    return sprite_sheets_[filepath];
}

void Graphics::DrawToScreen(SDL_Texture* texture, SDL_Rect* source_rectangle, 
                            SDL_Rect* destination_rectangle) {
    // Copies whatever you pass in to the renderer. 
    SDL_RenderCopy(this->renderer_, texture, source_rectangle, destination_rectangle);
}

void Graphics::DrawRect(SDL_Rect* rectangle) {
    // Change color to blue!
    SDL_SetRenderDrawColor(this->renderer_, 0, 0, 255, 255);

    // Draw rectangle to screen.
    SDL_RenderFillRect(this->renderer_, rectangle);

    //SDL_RenderPresent(this->renderer_);
}

void Graphics::Flip() {
    // Actually draws it to the screen.
    SDL_RenderPresent(this->renderer_);
}

void Graphics::Clear() {
    SDL_RenderClear(this->renderer_);
}

SDL_Renderer* Graphics::GetRenderer() const {
    return this->renderer_;
}