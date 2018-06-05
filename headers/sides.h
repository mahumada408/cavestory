#pragma once

class Sides {
    public:
        enum Side {
            TOP_SIDE, 
            BOTTOM_SIDE, 
            LEFT_SIDE, 
            RIGHT_SIDE, 
            NONE_SIDE
        };

        const Side GetOppositeSide(Side side) {
            return 
                // If side is equal to TOP, return BOTTOM.
                side == TOP_SIDE ? BOTTOM_SIDE:
                // else if 
                side == BOTTOM_SIDE ? TOP_SIDE:
                side == LEFT_SIDE ? RIGHT_SIDE:
                side == RIGHT_SIDE ? LEFT_SIDE:
                // else
                NONE_SIDE;
        }
};