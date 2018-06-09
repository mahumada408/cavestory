#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>

#include "graphics.h"
#include "mrectangle.h"
#include "sides.h"

// Sprite class
// Holds all information for individual sprites. 
// A sprite is basically a picture. 

class Sprite {
  public:
    Sprite();
    Sprite(Graphics &graphics, const std::string &filepath, int sourceX, 
            int sourceY, int width, int height, double posX, double posY);

    virtual ~Sprite();
    virtual void Update();

    // Draws sprite to screen.
    void Draw(Graphics &graphics, int x, int y);

    // Scales the size of the sprite;
    static const int sprite_scaler_ = 2;

    const MRectangle GetCollisionBox() const;

    // determines which side the collision happened on. 
    const Sides::Side GetCollisionSide(MRectangle& colliding_rectangle) const;

  protected:
    SDL_Rect source_rectangle_;
    SDL_Texture* sprite_sheet;

    double sprite_x_, sprite_y_;

    // Object for the collision box around the prite.
    MRectangle collision_box;
    
  private:
    
};
