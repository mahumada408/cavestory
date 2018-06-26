#include "slope.h"

Slope::Slope(MVector2 point1, MVector2 point2) : 
            point1_(point1), 
            point2_(point2) {

    // Calculate slope
    using std::abs;

    if (this->point2_.x - this->point1_.x != 0) {
        this->slope_ = (abs(this->point2_.y) - abs(this->point1_.y)/(abs(this->point2_.x) - abs(this->point1_.x));
    }
}