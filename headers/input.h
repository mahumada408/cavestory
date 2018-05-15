#pragma once

// Include maps from the std library
#include <map>
#include <SDL2/SDL.h>

// Input Class
// This class handles all the input from the keyboard. If the user wanted to play the game with another type of input, it would algo get handeled by this class. 
// Basically, keeps the state of the keyboard for the game to use. 
class Input {
    public:
        void BeginNewFrame();
        void KeyPressedEvent(const SDL_Event& event);
        void KeyReleasedEvent(const SDL_Event& event);

        // Key pressed event checker.
        bool WasKeyPressed(SDL_Scancode key);

        // Key released event checker
        bool WasKeyReleased(SDL_Scancode key);

        // Need the currently held checker given that no events actually happen 
        // when the key is held.
        bool IsKeyCurrentlyHeld(SDL_Scancode key);

    private:
        std::map<SDL_Scancode, bool> held_keys;
        std::map<SDL_Scancode, bool> pressed_keys;
        std::map<SDL_Scancode, bool> released_keys;
};