#pragma once

#include <boost/math/special_functions/sign.hpp>
#include <cmath>

#include "mrectangle.h"
#include "mvector2.h"

class Slope {
    public:
        Slope() {}

        // Constructor that calculates the slope between any two points. 
        Slope(MVector2 point1, MVector2 point2);

        // Return the slope.
        const double GetSlope() { return this->slope_; }

        // Check if the player collision rectangle collides with the slope. 
        const bool CollidesWidth(MRectangle& colliding_rectangle) const; 

        const MVector2 GetP1() const { return this->point1_; }
        const MVector2 GetP2() const { return this->point2_; }

    private:
        // point1 and 2 are the x and y coordinates of the points that make 
        // the line of the slope.
        MVector2 point1_, point2_;
        double slope_;

};