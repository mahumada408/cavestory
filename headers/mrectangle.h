#pragma once

#include "sides.h"

// Class to implement a rectangle and does some simple collision checking 
// between two rectangles. 

class MRectangle {
    public:
        MRectangle(){};

        MRectangle(int x, int y, int width, int height, int id = 0) : x_(x),
                                                          y_(y),
                                                          width_(width),
                                                          height_(height), 
                                                          id_(id){};

        // Returns the x value located at the center of the rectangle.
        const int GetCenterX() const { return this->x_ + this->width_/2; }

        // Returns the x value located at the center of the rectangle.
        const int GetCenterY() const { return this->y_ + this->height_/2; }

        const int GetWidth() const { return this->width_; }
        const int GetHeight() const { return this->height_; }

        // Get the sides of our rectangle.
        const int GetLeft() const { return this->x_; }
        const int GetRight() const { return this->x_ + this->width_; }
        const int GetTop() const { return this->y_; }
        const int GetBottom() const { return this->y_ + this->height_; }

        // Returns the side that we pass in.
        const int GetSide(const Sides::Side side) const {
            return 
                // If side is equal to the left side, return left side.
                side == Sides::Side::LEFT_SIDE ? this->GetLeft():
                // Elseif
                side == Sides::Side::RIGHT_SIDE ? this->GetRight():
                side == Sides::Side::TOP_SIDE ? this->GetTop():
                side == Sides::Side::BOTTOM_SIDE ? this-> GetBottom():
                // Else
                Sides::Side::NONE_SIDE;
        }

        // Takes in another rectangle and checks if the two are colliding.
        const bool CollidesWith(const MRectangle& other_rect) const {
            return
                // If our right side is greater than or equal to the other's 
                // left AND ...
                this->GetRight() >= other_rect.GetLeft() &&
                this->GetLeft() <= other_rect.GetRight() &&
                this->GetTop() <= other_rect.GetBottom() &&
                this->GetBottom() >= other_rect.GetTop();
        }

        // Checks if this rectangle is a valid rectangle.
        const bool IsValidRectangle() const
        {
            return (this->x_ >= 0 && this->y_ >= 0 && this->width_ >= 0 && this->height_ >= 0);
        }

      private:
        int x_;
        int y_;
        int width_;
        int height_;
        int id_;
};