#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <string>
#include <SDL2/SDL.h>

// Number of scan codes in SDL2
#define SCANCODE_SIZE 286

enum class MouseButton { LEFT, MIDDLE, RIGHT };

enum class ButtonState { DEFAULT, DOWN, UP, HELD };

struct Mouse {
    int x;
    int y;
    
    // Used for storing the actual button state
    ButtonState left;
    ButtonState middle;
    ButtonState right;
};

/* 
 * InputHandler
 * 
 * The `InputHandler` class is a singleton class used for getting
 * input from the user.
 */
class InputHandler {
public:
    ~InputHandler();

    /// Get or create new instance of the input handler
    static InputHandler* getInstance();

    /// Update inputs with current inputs
    void update();

    /// True if user fires a SDL_QUIT event
    bool quit;

    /// Check if key is pressed (maybe change to defined enum to be consistent with isMouseButtonPressed())
    ButtonState getKeyState(SDL_Scancode scancode);

    /// Check if mouse button is pressed
    ButtonState getMouseButtonState(MouseButton mouseButton);

    /// Get mouse position
    void getMousePosition(int* x, int* y);

    /// Get mouse state
    void getMouse(Mouse* mouse); // Copy values to given mouse
    Mouse getMouse(); // Return mouse object

    /// Convert ButtonState to printable
    std::string printableButtonState(ButtonState);
private:
    InputHandler();

    /// Stores singleton instance
    static InputHandler* _instance;

    /// Stores keyboard state, only stores if the key is currently pressed down
    const uint8_t* _keyboardState;
    /// Stores current keyboard key state
    ButtonState _keyboard[SCANCODE_SIZE];

    /// Stores mouse state
    Mouse _mouse;
    
    /// Determine next button state, called on the fly when button states are requested
    ButtonState nextButtonState(ButtonState prevState, bool pressed);

    /// Close input handler and clean up
    void _close();
};

#endif