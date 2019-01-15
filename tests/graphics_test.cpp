#include "lib/catch.hpp"

#include <string>
#include <SDL2/SDL.h>

#include "Log.hpp"
#include "Graphics.hpp"

TEST_CASE("window") {
    /* 
    * Illustrates the creation and destruction of the game window.
    */

    Log::verboseMode(true); // print verbose 
    
    Graphics* graphics = Graphics::Instance();

    REQUIRE(graphics->window != NULL);
    REQUIRE(graphics->renderer != NULL);
    
    int w, h;
    graphics->getWindowSize(&w, &h);
    REQUIRE(w == SCREEN_WIDTH);
    REQUIRE(h == SCREEN_HEIGHT);

    SDL_Delay(1000); // wait to show graphics for a second
}


/// Used to check if two SDL_Color's are identical
bool sameColor(SDL_Color color1, SDL_Color color2) {
    if (color1.r != color2.r)
        return false;
    if (color1.g != color2.g)
        return false;
    if (color1.b != color2.b)
        return false;
    return true;
}

TEST_CASE("graphics_functions") {
    /* 
     * Illustrates functionality of the Graphics class.
     */

    SECTION("create_color") {
        /* Create colours multiple ways and make sure the result is expected. */

        Graphics* graphics = Graphics::Instance();

        // Green test color: rgb(78, 219, 90)
        SDL_Color testColor = { (uint8_t) 78, (uint8_t) 219, (uint8_t) 90};

        SDL_Color rgbColor; // color to be created by inputting RGB values
        SDL_Color hexColor; // color to be created by inputting a hex value

        rgbColor = graphics->createColor(78, 219, 90, 127);
        hexColor = graphics->createColor("#4edb5a");

        // Check that we made the colors correctly
        REQUIRE(sameColor(testColor, rgbColor) == true);
        REQUIRE(sameColor(testColor, hexColor) == true);
    }

    SECTION("draw_color") {
        /* Create a color and draw it to the window. */
        
        Graphics* graphics = Graphics::Instance();

        SDL_Color color = graphics->createColor("#4edb5a");

        graphics->setDrawColor(color);

        graphics->clearRender();
        graphics->presentRender();

        SDL_Delay(500);
    }

    SECTION("create_draw_texture") {
        /* Create a texture from a png file and draw it to the window. */

        Graphics* graphics = Graphics::Instance();

        SDL_Texture* texture = graphics->createTexture("../assets/images/test.png");

        graphics->clearRender();
        graphics->drawTexture(texture);
        graphics->presentRender();

        SDL_Delay(500);
    }
}