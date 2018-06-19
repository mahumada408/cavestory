#pragma once 

#include "animated_sprite.h"
#include "graphics.h"
#include "mrectangle.h"
#include "mvector2.h"
#include "sides.h"
#include "sprite.h"

class Player : public AnimatedSprite {
    public:
        // Comments for this can be found in animated_sprite.h
        Player();
        Player(Graphics &graphics, MVector2 spawn_point);
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

        // Handles collisions of all tiles the player is colliding with.
        void HandleTileCollisions(std::vector<MRectangle>& colliding_rectangle);

        // Gets the current position of the player in x and y.
        const double GetX() const;
        const double GetY() const;

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

        // Bool to tell us if the player is touching the ground. True when the 
        // player is touching the ground. 
        bool grounded_;
};