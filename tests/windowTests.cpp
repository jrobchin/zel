#include "lib/catch.hpp"

#include <string>
#include <SDL2/SDL.h>

#include "Log.hpp"
#include "Graphics.hpp"

TEST_CASE("create and destroy window") {
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

bool sameColor(SDL_Color color1, SDL_Color color2) {
    if (color1.r != color2.r)
        return false;
    if (color1.g != color2.g)
        return false;
    if (color1.b != color2.b)
        return false;
    return true;
}

TEST_CASE("graphics functions") {
    SECTION("create color") {
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
}