#pragma once

#include <map>
#include <string>
#include <SDL2/SDL.h>
#include <vector>

#include "graphics.h"
#include "sprite.h"

// Animated Sprites class
// Holds logic for animating the sprite in the renderer. 

class AnimatedSprite : public Sprite {
    public:
        AnimatedSprite();
        AnimatedSprite(Graphics &graphics, const std::string &filepath,int source_x, int source_y, int width, int height, double pos_x, double pos_y, double time_to_update);

        // This method is how we actually start playing the animation. once is 
        // the default parameter that gets set by deafult, but you don't need to
        // explicitly pass anything in. PLays the animation provided it isn't 
        // playing already.
        void PlayAnimation(std::string, bool once = false);

        // Updates the animated sprite on a timer. 
        void Update(int elapsed_time);

        // Draws sprite to screen.
        void Draw(Graphics &graphics, int x, int y);

        // Sets up all the animations for a sprite. 
        virtual void SetupAnimation();

        struct Vector2 {
            double x;
            double y;
        };

    private:
        // Holds the animatino for a sprite. For example, the running animation 
        // for the guy is three pictures. Hold those three pics in the vector. 
        std::map<std::string, std::vector<SDL_Rect>> animation_;

        // Just in case we want to pffset where we get our sprites from.
        std::map<std::string, Vector2> offsets_;

        // Which frame in the animatino we are at. 
        int frame_index_;

        // Timer
        double time_elapsed_;

        // Whether or not the animation is visible. 
        bool visible_;
};
