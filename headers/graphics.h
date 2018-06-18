#pragma once

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Grahics Class
// This class holds all information dealing with the graphics for Cavestory

class Graphics
{
public:
  // Constructor and destructor for the Graphics class. Constructor creates the
  // window and rederer with a resolution of 640x480 in a window called
  // "Cave Story."
  Graphics();
  ~Graphics();

  // Loads an image into the sprite_sheets map if it doesn't already exist. As a
  // result, each image will only be loaded once. Returns the image from the map
  // gardless of whether or not it has been loaded. 
  SDL_Surface* LoadImage(const std::string &filepath);

  // Draws a texture to a certain part of the screen. 
  // [in] source - what we are drawing to the screen.
  // [in] source_rectangle - what part of the source are we drawing to the 
  // screen. For example, from the sprite sheet, we would load up a section.
  // [in] destination_rectangle - the location of that certain part of the 
  // screen. 
  void DrawToScreen(SDL_Texture* texture, SDL_Rect* source_rectangle, 
                    SDL_Rect* destination_rectangle);

  // Draws a simple rectangle to the screen.
  void DrawRect(SDL_Rect* rectangle);
  
  // Renders everything to the screen.
  void Flip();

  // Clears the screen.
  void Clear();

  // Returns the renderer so we can use it elsewhere. 
  SDL_Renderer* GetRenderer() const;

private:
  SDL_Window *window_;
  SDL_Renderer *renderer_;

  std::map<std::string, SDL_Surface*> sprite_sheets_;
};