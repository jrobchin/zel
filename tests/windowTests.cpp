#include "lib/catch.hpp"

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