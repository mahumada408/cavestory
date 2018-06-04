#include "player.h"
#include "graphics.h"

namespace player_constants {
    const double WALK_SPEED = 0.2;
    const double GRAVITY = 0.002;
    const double GRAVITY_CAP = 0.8;
}

Player::Player() {}

Player::Player(Graphics &graphics, double x, double y) : 
    AnimatedSprite(graphics, "/home/manuel/development/cavestory/content/sprites/MyChar.png", 0, 0, 16, 16, x, y, 100), 
    dx_(0), 
    dy_(0), 
    facing_(RIGHT),
    grounded_(false)
{
    graphics.LoadImage("/home/manuel/development/cavestory/content/sprites/MyChar.png");
    this->SetupAnimation();
    this->PlayAnimation("RunLeft");
}

void Player::PlayerDraw(Graphics &graphics) {
    AnimatedSprite::AnimatedDraw(graphics, this->sprite_x_, this->sprite_y_);
}

void Player::PlayerUpdate(double elapsed_time) {
    // Apply gravity to our player. 
    if (this->dy_ <= player_constants::GRAVITY_CAP) {
        this->dy_ += player_constants::GRAVITY * elapsed_time;
    }

    // Move by dx based on the frame rate (elapsed time).
    this->sprite_x_ += this->dx_ * elapsed_time;

    // Move by dy based on "gravity."
    this->sprite_y_ += this->dy_ * elapsed_time;

    AnimatedSprite::Update(elapsed_time);
}

void Player::MoveLeft() {
    this->dx_ = -player_constants::WALK_SPEED;
    this->PlayAnimation("RunLeft");
    this->facing_ = LEFT;
}

void Player::MoveRight() {
    this->dx_ = player_constants::WALK_SPEED;
    this->PlayAnimation("RunRight");
    this->facing_ = RIGHT;
}

void Player::StopMoving() {
    this->dx_ = 0.0;
    this->PlayAnimation(this->facing_ == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::AnimationDone(std::string current_animation_) {}

void Player::SetupAnimation() {
    int animation_frames = 3;
    int x_init = 0;
    int y_init = 0;
    int height = 16; // In pixels
    int width = 16;  // In pixels
    this->AddAnimation(animation_frames, x_init, y_init, "RunLeft", height, width, this->player_offsets_);
    this->AddAnimation(animation_frames, 0, 16, "RunRight", height, width, this->player_offsets_);
    this->AddAnimation(1, 0, 0, "IdleLeft", height, width, this->player_offsets_);
    this->AddAnimation(1, 0, 16, "IdleRight", height, width, this->player_offsets_);
}

const double Player::GetX() const {
    return this->sprite_x_;
}

const double Player::GetY() const {
    return this->sprite_y_;
}

const Player::Side Player::GetOppositeSide(Side side) {
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