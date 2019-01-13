#include "lib/catch.hpp"

#include <string>
#include <SDL2/SDL.h>

#include "Log.hpp"
#include "Window.hpp"

TEST_CASE("create and destroy window") {
    Log::verboseMode(true); // print verbose 
    
    Window* window = Window::Instance();

    REQUIRE(window->window != NULL);
    REQUIRE(window->renderer != NULL);
    
    int w, h;
    window->getSize(&w, &h);
    REQUIRE(w == SCREEN_WIDTH);
    REQUIRE(h == SCREEN_HEIGHT);

    SDL_Delay(1000); // wait to show window for a second
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

TEST_CASE("window functions") {
    SECTION("create color") {
        Window* window = Window::Instance();

        // Green test color: rgb(78, 219, 90)
        SDL_Color testColor = { (uint8_t) 78, (uint8_t) 219, (uint8_t) 90};

        SDL_Color rgbColor; // color to be created by inputting RGB values
        SDL_Color hexColor; // color to be created by inputting a hex value

        rgbColor = window->createColor(78, 219, 90, 127);
        hexColor = window->createColor("#4edb5a");

        // Check that we made the colors correctly
        REQUIRE(sameColor(testColor, rgbColor) == true);
        REQUIRE(sameColor(testColor, hexColor) == true);
    }
}