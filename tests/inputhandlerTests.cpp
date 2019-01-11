#include "lib/catch.hpp"

#include "Log.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"

/*
 * Each test loops for `INPUT_TEST_FRAMES` frames with a frame delay of
 * `INPUT_TEST_DELAY` for `INPUT_TEST_NLOOPS` loops. 
 * 
 * Maybe add loop until quit option.
 */

#define INPUT_TEST_DELAY 17 // ms to wait for one input frame
#define INPUT_TEST_FRAMES 1800  // number of input frames for each test
#define INPUT_TEST_NLOOPS INPUT_TEST_FRAMES / INPUT_TEST_DELAY // number of loops for test for loops

TEST_CASE("input tests") {
    // There must be target window for inputs
    Window* window = Window::Instance();
    
    // Get input handler instance (this will create the instance)
    InputHandler* inputHandler = InputHandler::Instance();

    SECTION("keyboard") {
        Log::log("= Keyboard Input Tests =");
        Log::log("= Input `w` =");
        for (int i = 0; i < INPUT_TEST_NLOOPS; i++) {
            inputHandler->update();
            ButtonState state = inputHandler->getKeyState(SDL_SCANCODE_W);
            if (state != ButtonState::DEFAULT)
                Log::log("w key state: " + inputHandler->printableButtonState(state));
            SDL_Delay(INPUT_TEST_DELAY);
        }
    }

    SECTION("mouse") {
        Log::log("= Mouse Input Tests =");
        

        // InputHandler currently has 4 mouse functions
        SECTION("InputHandler::getMouseButtonState") {
            Log::log("= Click the left mouse button =");
            for(int i = 0; i < INPUT_TEST_NLOOPS; i++)
            {
                inputHandler->update();
                ButtonState state = inputHandler->getMouseButtonState(MouseButton::LEFT);
                if (state != ButtonState::DEFAULT)
                    Log::log("left mouse button state: " + inputHandler->printableButtonState(state));
                SDL_Delay(INPUT_TEST_DELAY);
            }
        }

        SECTION("InputHandler::getMousePosition") {
            Log::log("= Move mouse =");

            for(int i = 0; i < INPUT_TEST_NLOOPS; i++)
            {
                inputHandler->update();
                
                int x, y;
                inputHandler->getMousePosition(&x, &y);

                Log::log("Mouse(x: " + std::to_string(x) + ", y: " + std::to_string(y) + ")");

                SDL_Delay(INPUT_TEST_DELAY);
            }
        }

        SECTION("InputHandler::getMouse #1") {

            Mouse mouse;
        
            Log::log("= Move mouse and click buttons =");
            
            for(int i = 0; i < INPUT_TEST_NLOOPS; i++)
            {
                inputHandler->update();
                
                inputHandler->getMouse(&mouse);
                
                if (mouse.left == ButtonState::DOWN) {
                    Log::log("Left down"); 
                    Log::log("Mouse(x: " + std::to_string(mouse.x) + ", y: " + std::to_string(mouse.y) + ")");
                }

                if (mouse.middle == ButtonState::DOWN) {
                    Log::log("Middle down"); 
                    Log::log("Mouse(x: " + std::to_string(mouse.x) + ", y: " + std::to_string(mouse.y) + ")");
                }

                if (mouse.right == ButtonState::DOWN) {
                    Log::log("Right down"); 
                    Log::log("Mouse(x: " + std::to_string(mouse.x) + ", y: " + std::to_string(mouse.y) + ")");
                }

                SDL_Delay(INPUT_TEST_DELAY);
            }
        }

        SECTION("InputHandler::getMouse #2") {

            Mouse mouse;

            Log::log("= Move mouse and click buttons =");

            for(int i = 0; i < INPUT_TEST_NLOOPS; i++)
            {
                inputHandler->update();

                mouse = inputHandler->getMouse();

                if (mouse.left == ButtonState::DOWN) {
                    Log::log("Left down"); 
                    Log::log("Mouse(x: " + std::to_string(mouse.x) + ", y: " + std::to_string(mouse.y) + ")");
                }

                if (mouse.middle == ButtonState::DOWN) {
                    Log::log("Middle down"); 
                    Log::log("Mouse(x: " + std::to_string(mouse.x) + ", y: " + std::to_string(mouse.y) + ")");
                }

                if (mouse.right == ButtonState::DOWN) {
                    Log::log("Right down"); 
                    Log::log("Mouse(x: " + std::to_string(mouse.x) + ", y: " + std::to_string(mouse.y) + ")");
                }

                SDL_Delay(INPUT_TEST_DELAY);
            }
        }

        inputHandler->update();
    }

}