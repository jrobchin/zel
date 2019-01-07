#include "lib/catch.hpp"

#include "Log.hpp"
#include "Window.hpp"
#include "InputHandler.hpp"

TEST_CASE("test input w, a, s, d") {
    Log::log("=== Input Tests ===");

    Window window = Window();
    
    InputHandler* inputHandler = InputHandler::getInstance();

    Log::log("= Input `w` =");
    for (int i = 0; i < 30; i++) {
        inputHandler->update();
        if (inputHandler->isKeyPressed(SDL_SCANCODE_W)) {
            Log::log("w pressed.");
        }
        SDL_Delay(100);
    }

    Log::log("= Input `a` =");
    for (int i = 0; i < 30; i++) {
        inputHandler->update();
        if (inputHandler->isKeyPressed(SDL_SCANCODE_A)) {
            Log::log("a pressed.");
        }
        SDL_Delay(100);
    }

    Log::log("= Input `s` =");
    for (int i = 0; i < 30; i++) {
        inputHandler->update();
        if (inputHandler->isKeyPressed(SDL_SCANCODE_S)) {
            Log::log("s pressed.");
        }
        SDL_Delay(100);
    }

    Log::log("= Input `d` long delay =");
    for (int i = 0; i < 10; i++) {
        inputHandler->update();
        if (inputHandler->isKeyPressed(SDL_SCANCODE_D)) {
            Log::log("d pressed.");
        }
        SDL_Delay(500);
    }
}