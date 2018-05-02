#include "input.h"

// This function gets called at the beginning of each frame to reset the keys that are no longer relevant.
void Input::BeginNewFrame(){
    // These two map methods clear the elements of the map
    this->pressed_keys.clear();
    this->released_keys.clear();
}

// Every time a key is pressed, an event happens, and we save that event in a map. 
// Also, because we are pressing a key, we are technically holding the key, so
// do the same for held_keys.
void Input::KeyPressedEvent(const SDL_Event& event) {
    this->pressed_keys[event.key.keysym.scancode] = true;
    this->held_keys[event.key.keysym.scancode] = true;
}

// Every time a key is released, an event happens, and we save that event in a map. 
// Also, because we are releasing a key, we need to clear the map event. 
void Input::KeyReleasedEvent(const SDL_Event& event) {
    this->released_keys[event.key.keysym.scancode] = true;
    this->released_keys[event.key.keysym.scancode] = false;
}

// Key pressed event checker.
bool Input::WasKeyPressed(SDL_Scancode key) {
    return this->pressed_keys[key];
}

// Key released event checker
bool Input::WasKeyReleased(SDL_Scancode key) {
    return this->released_keys[key];
}

// Key held event checker.
bool Input::IsKeyCurrentlyHeld(SDL_Scancode key) {
    return this->held_keys[key];
}