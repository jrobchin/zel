#include <string>
#include <SDL2/SDL.h>

#include "Log.hpp"
#include "InputHandler.hpp"

InputHandler* InputHandler::_instance = nullptr;

InputHandler::InputHandler():
    _keyboardState(nullptr),
    quit(false)
{
    
    for(int i = 0; i < SCANCODE_SIZE; i++)
    {
        _keyboard[i] = ButtonState::DEFAULT; // Initialize to all default key state
    }

    update();
}

InputHandler::~InputHandler() {
}

InputHandler* InputHandler::Instance() {
    if (!_instance)
        _instance = new InputHandler();
    return _instance;
}

ButtonState InputHandler::nextButtonState(ButtonState prevState, bool pressed) {
    if (pressed) {
        if (prevState == ButtonState::DEFAULT || prevState == ButtonState::UP) {
            // Button was up and just pressed, set to DOWN
            return ButtonState::DOWN;
        } else if (prevState == ButtonState::DOWN || prevState == ButtonState::HELD) {
            // Button was down or held already and just pressed, set to HELD
            return ButtonState::HELD;
        }
    } else {
        if (prevState == ButtonState::DEFAULT || prevState == ButtonState::UP) {
            // Button was up and not pressed, set to DEFAULT
            return ButtonState::DEFAULT;
        } else if (prevState == ButtonState::DOWN || prevState == ButtonState::HELD) {
            // Button was down or held, set to UP
            return ButtonState::UP;
        }
    }
    return ButtonState::DEFAULT;
}

void InputHandler::update() {
    // Update SDL events for getting current states
    SDL_PumpEvents();
    
    _keyboardState = SDL_GetKeyboardState(NULL);

    // This might be too slow, refactor to use SDL_PollEvent()
    // BOTTLE_NECK
    for (int i; i < SCANCODE_SIZE; i++) {
        ButtonState state = _keyboard[i];
        _keyboard[i] = nextButtonState(state, _keyboardState[i]);
    }

    uint32_t mouseState = SDL_GetMouseState(&_mouse.x, &_mouse.y);
    bool leftPressed = mouseState & SDL_BUTTON(SDL_BUTTON_LEFT);
    _mouse.left = nextButtonState(_mouse.left, leftPressed);

    bool middlePressed = mouseState & SDL_BUTTON(SDL_BUTTON_MIDDLE);
    _mouse.middle = nextButtonState(_mouse.middle, middlePressed);

    bool rightPressed = mouseState & SDL_BUTTON(SDL_BUTTON_RIGHT);
    _mouse.right = nextButtonState(_mouse.right, rightPressed);
}

ButtonState InputHandler::getKeyState(SDL_Scancode scancode) {
    return _keyboard[scancode];
}

ButtonState InputHandler::getMouseButtonState(MouseButton mouseButton) {
    // Should probably be an array but there are only 3 mouse buttons
    switch (mouseButton) {
        case MouseButton::LEFT:
            return _mouse.left;
            break;
        case MouseButton::MIDDLE:
            return _mouse.middle;
            break;
        case MouseButton::RIGHT:
            return _mouse.right;
            break;
        default:
            Log::error("Mouse button not recognized.");
            return; // TODO: make this nicer or throw an exception
            break;
    }
}

void InputHandler::getMousePosition(int* x, int* y) {
    *x = _mouse.x;
    *y = _mouse.y;
}

void InputHandler::getMouse(Mouse* mouse) {
    mouse->x = _mouse.x;
    mouse->y = _mouse.y;
    mouse->left = _mouse.left;
    mouse->middle = _mouse.middle;
    mouse->right = _mouse.right;
}

Mouse InputHandler::getMouse() {
    return _mouse;
}

std::string InputHandler::printableButtonState(ButtonState state) {
    switch (state) {
        case ButtonState::DEFAULT:
            return "ButtonState::DEFAULT";
            break; 
        case ButtonState::DOWN:
            return "ButtonState::DOWN";
            break; 
        case ButtonState::UP:
            return "ButtonState::UP";
            break; 
        case ButtonState::HELD:
            return "ButtonState::HELD";
            break; 
        default:
            throw "No printable version of button state.";
            break; 
    }
}