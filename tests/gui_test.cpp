#include "lib/catch.hpp"

#include <SDL2/SDL.h>

#include "Log.hpp"
#include "Graphics.hpp"
#include "GUI/Container.hpp"

TEST_CASE("gui") {

    SECTION("container") {
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

    SECTION("events") {
        // Get graphics instance
        Graphics* graphics = Graphics::Instance();

        // Create main container to listen for events
    }
}