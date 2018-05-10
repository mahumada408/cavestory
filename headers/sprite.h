#pragma once

#include "graphics.h"
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

// Forward declare graphics
class Graphics;

// Sprite class
// Holds all information for individual sprites. 
// A sprite is basically a picture. 

class Sprite
{
  public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filepath, int sourceX, 
            int sourceY, int width, int height, double posX, double posY);

    virtual ~Sprite();
    virtual void Update();

    // Draws sprite to screen.
    void Draw(Graphics &graphics, int x, int y);

  private:
    SDL_Rect source_rectangle_;
    SDL_Texture* sprite_sheet;

    double x_, y_;
    int sprite_scaler_;
};
