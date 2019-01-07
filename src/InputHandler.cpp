#include <string>
#include <SDL2/SDL.h>

#include "Log.hpp"
#include "InputHandler.hpp"

InputHandler* InputHandler::_instance = nullptr;

InputHandler::InputHandler():
    _keyboard(nullptr),
    quit(false) 
{
    update();
}

InputHandler::~InputHandler() {
}

InputHandler* InputHandler::getInstance() {
    if (!_instance)
        _instance = new InputHandler();
    return _instance;
}

void InputHandler::update() {
    SDL_PumpEvents();
    _keyboard = SDL_GetKeyboardState(NULL);
}

bool InputHandler::isKeyPressed(SDL_Scancode scancode) {
    return _keyboard[scancode];
}