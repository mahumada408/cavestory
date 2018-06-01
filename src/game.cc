#include "game.h"

namespace
{
const int frame_rate = 50;
const double max_frame_time = 5 * 1000 / frame_rate;
}

Game::Game()
{
    // Initializes a lot of SDL things.
    SDL_Init(SDL_INIT_EVERYTHING);

    // Calling the loop from the constructor.
    this->GameLoop();
}

Game::~Game() 
{
}

// This is a very important function, maybe the most important in the program. 
// This will happen every frame!
void Game::GameLoop()
{
    Graphics graphics;
    Input key_input;
    SDL_Event sdl_event;

    this->player_ = 
    Player(graphics, 100, 100);

    this->level_ = Level("Map_1", MVector2(100,100), graphics);

    int last_update_time = SDL_GetTicks();
    // Start game loop
    while (true)
    {
        // Reset the key frame.
        key_input.BeginNewFrame();

        // Check for keyboard events.
        this->EventChecker(sdl_event, key_input);

        if (key_input.WasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
        {
            return;
        }
        else if (key_input.IsKeyCurrentlyHeld(SDL_SCANCODE_LEFT) == true) {
            this->player_.MoveLeft();
        }
        else if (key_input.IsKeyCurrentlyHeld(SDL_SCANCODE_RIGHT) == true) {
            this->player_.MoveRight();
        }

        if (!key_input.IsKeyCurrentlyHeld(SDL_SCANCODE_LEFT) && !key_input.IsKeyCurrentlyHeld(SDL_SCANCODE_RIGHT)) {
            this->player_.StopMoving();
        }

        if (sdl_event.type == SDL_QUIT)
        {
            return;
        }

        const double current_time_ms = SDL_GetTicks();
        double elapsed_time_ms = current_time_ms - last_update_time;
        this->Update(std::min(elapsed_time_ms, max_frame_time));
        last_update_time = current_time_ms;
        
        this->Draw(graphics);
    }
}

void Game::EventChecker(SDL_Event &sdl_event, Input &key_input)
{
    // SDL will poll for keyboard events and stick them in that sdl_event 
    // object.
    if (SDL_PollEvent(&sdl_event))
    {
        if (sdl_event.type == SDL_KEYDOWN)
        {
            // Zero if it's not a repeat key.
            if (sdl_event.key.repeat == 0)
            {
                key_input.KeyPressedEvent(sdl_event);
            }
        }
        else if (sdl_event.type == SDL_KEYUP)
        {
            key_input.KeyReleasedEvent(sdl_event);
        }
        // SDL_QUIT can happen if we x out of the game window. This allows
        // us to close the program without getting stuck in the loop.
        else if (sdl_event.type == SDL_QUIT)
        {
            return;
        }
    }
}

void Game::Draw(Graphics &graphics) {
    graphics.Clear();

    // Draw whatever cool stuff we have to the screen. Make sure to draw level 
    // before player so he gets drawn on top of the level.
    this->level_.LevelDraw(graphics);
    this->player_.PlayerDraw(graphics);

    // To actually draw it on the screen from the renderer.
    graphics.Flip();
}

void Game::Update(double elapsed_time) {
    this->player_.PlayerUpdate(elapsed_time);
    this->level_.LevelUpdate(elapsed_time);
}
