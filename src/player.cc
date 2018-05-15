#include "player.h"
#include "graphics.h"

namespace player_constants {
    const double WALK_SPEED = 0.5;
}

Player::Player() {}

Player::Player(Graphics &graphics, double x, double y) : AnimatedSprite(graphics, "/home/manuel/development/cavestory/content/sprites/MyChar.png", 0, 0, 16, 16, x, y, 100)
{
    graphics.LoadImage("/home/manuel/development/cavestory/content/sprites/MyChar.png");
    this->SetupAnimation();
    this->PlayAnimation("RunLeft");
}

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

void Player::AnimationDone(std::string current_animation_) {}

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

void Player::PlayerUpdate(double elapsed_time) {
    // Move by dx based on the frame rate (elapsed time).
    this->sprite_x_ += this->dx_ * elapsed_time;

    AnimatedSprite::Update(elapsed_time);
}

void Player::PlayerDraw(Graphics &graphics) {
    AnimatedSprite::AnimatedDraw(graphics, this->sprite_x_, this->sprite_y_);
}