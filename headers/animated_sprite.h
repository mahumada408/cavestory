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
        void PlayAnimation(std::string animation, bool once = false);

        // Updates the animated sprite on a timer. 
        void Update(double elapsed_time);

        // Draws sprite to screen.
        void AnimatedDraw(Graphics &graphics, int x, int y);

        struct Vector2 {
            double x;
            double y;
        };

    protected:
        // Amount of time between frames.
        double time_to_update;

        // How we know an animatino is only played once. 
        bool current_animation_once_;

        // Name of the current animaiton being played. 
        std::string current_animation_;

        // Adds animation to map of animations.  
        void AddAnimation(int frames, int x, int y, std::string name, int width,
         int height, Vector2 offset);

        // Resets the map. 
        void ResetAnimations();

        // Stops the current animation. 
        void StopAnimation();

        // Changes the visibility of the animated sprite. 
        void SetVisible(bool visible);

        // Logic that happens when an animation ends. 
        // Because it's == 0, it's a pure virtual method, and we can only 
        // implement them in a derived classes. 
        virtual void AnimationDone(std::string current_animation) = 0;

        // Sets up all the animations for a sprite. 
        // Because it's == 0, it's a pure virtual method, and we can only 
        // implement them in a derived classes. 
        virtual void SetupAnimation() = 0;

        Vector2 player_offsets_;

    private:
        // Holds the animation for a sprite. For example, the running animation 
        // for the guy is three pictures. Hold those three pics in the vector. 
        std::map<std::string, std::vector<SDL_Rect>> animation_;

        // Just in case we want to offset where we get our sprites from.
        std::map<std::string, Vector2> draw_offsets_;
        

        // Which frame in the animatino we are at. 
        int frame_index_;

        // Timer
        double time_elapsed_;

        // Whether or not the animation is visible. 
        bool visible_;
};
