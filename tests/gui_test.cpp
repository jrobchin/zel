#include "lib/catch.hpp"

#include <SDL2/SDL.h>

#include "Log.hpp"
#include "Graphics.hpp"
#include "InputHandler.hpp"
#include "GUI/Container.hpp"

TEST_CASE("container") {
    // Get graphics instance
    Graphics* graphics = Graphics::Instance();

    // Create a main container
    Container mainContainer = Container();
    
    // Create a texture for the background of the container
    SDL_Texture* mainBackgroundTexture = graphics->createTexture("../assets/images/test.png");
    mainContainer.setBackgroundTexture(mainBackgroundTexture);

    // Main render loop
    for (int i = 0; i < 30; i++) {
        graphics->clearRender();

        mainContainer.render();

        graphics->presentRender();

        SDL_Delay(50);
    }
}

TEST_CASE("events") {
    // Get graphics instance and inputhandler instance
    Graphics* graphics = Graphics::Instance();
    InputHandler* input = InputHandler::Instance();

    // Create main container to listen for events
    int borderMargin = 100;
    Container mainContainer = Container(Rectangle<int>(100, 100, 200, 200));
    SDL_Texture* mainBackgroundTexture = graphics->createTexture("../assets/images/test.png");
    mainContainer.setBackgroundTexture(mainBackgroundTexture);

    SDL_Rect* rect = mainContainer.getRect();

    // Set draw color just so we know we have a functional screen
    graphics->setDrawColor(graphics->createColor("#4edb5a"));

    // Main render loop
    Log::log("Press `q` to quit");
    while (true) {
        input->update();

        if (input->getKeyState(SDL_SCANCODE_Q) == ButtonState::DOWN) {
            break;
        }

        graphics->clearRender();

        mainContainer.render();

        graphics->presentRender();

        SDL_Delay(16);
    }
}