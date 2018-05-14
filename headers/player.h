#pragma once 

#include "animated_sprite.h"
#include "graphics.h"

class Player : public AnimatedSprite {
    public:
        // Comments for this can be found in animated_sprite.h
        Player();
        Player(Graphics &graphics, double x, double y);
        void PlayerDraw(Graphics &graphics);
        void PlayerUpdate(double elapsed_time);

        // Moves the player left by dx (i.e -dx).
        void MoveLeft();

        // Moves the player right by dx. 
        void MoveRight();

        // Stops moving the player and plays idle. 
        void StopMoving();

        virtual void AnimationDone(std::string current_animation);
        virtual void SetupAnimation();

        enum Direction {
            LEFT, 
            RIGHT, 
            UP, 
            DOWN
        };

    private:
        // Change in x and y;
        double dx_, dy_;

        Direction facing_;
};