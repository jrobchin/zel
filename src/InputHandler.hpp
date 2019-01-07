#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <SDL2/SDL.h>

// Number of scan codes in SDL2
#define SCANCODE_SIZE 286

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

    /// Check if key is pressed
    bool isKeyPressed(SDL_Scancode scancode);

private:
    InputHandler();

    /// Stores singleton instance
    static InputHandler* _instance;

    /// Stores key states
    const uint8_t* _keyboard;
    
    /// Close input handler and clean up
    void _close();
};

#endif