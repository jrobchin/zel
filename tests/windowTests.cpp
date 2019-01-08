#include "lib/catch.hpp"

#include "Log.hpp"
#include "Window.hpp"

TEST_CASE("create and destroy window") {
    Log::verboseMode(true); // print verbose 
    
    Window window = Window();

    REQUIRE(window.window != NULL);
    REQUIRE(window.renderer != NULL);

    SDL_Delay(1000); // wait to show window for a second
}