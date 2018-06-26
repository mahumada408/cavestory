#pragma once

#include <cmath>

#include "mvector2.h"

class Slope {
    public:
        Slope(MVector2 point1, MVector2 point2);

    private:
        // point1 and 2 are the x and y coordinates of the points that make 
        // the line of the slope.
        MVector2 point1_, point2_;
        double slope_;

};