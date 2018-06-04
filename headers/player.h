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

        // Gets the current position of the player in x and y.
        const double GetX() const;
        const double GetY() const;

        enum Direction {
            LEFT, 
            RIGHT, 
            UP, 
            DOWN
        };

        enum Side {
            TOP_SIDE, 
            BOTTOM_SIDE, 
            LEFT_SIDE, 
            RIGHT_SIDE, 
            NONE_SIDE
        };

        const Side GetOppositeSide(Side side);

    private:
        // Change in x and y;
        double dx_, dy_;

        Direction facing_;

        // Bool to tell us if the player is touching the ground. True when the 
        // player is touching the ground. 
        bool grounded_;
};