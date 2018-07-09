#include "slope.h"

Slope::Slope(MVector2 point1, MVector2 point2) : 
            point1_(point1), 
            point2_(point2) {

    // Calculate slope
    using std::abs;

    if (this->point2_.x - this->point1_.x != 0) {
        this->slope_ = (abs(this->point2_.y) - abs(this->point1_.y))/(abs(this->point2_.x) - abs(this->point1_.x));
    }
}

const bool Slope::CollidesWidth(MRectangle& colliding_rectangle) const {
    
    // Using the magnitude of a 2D vector cross product to detect if any of our corner points collide with the slope. 
    // position = sign((Bx - Ax) * (Y - Ay) - (By - Ay) * (X - Ax))
    // v1.x*v2.y - v1.y*v2.x
    // It is 0 on the line (collision), and +1 on one side, -1 on the other side.  
    return true;
}