#include "lib/catch.hpp"

#include <iostream>
#include "Log.hpp"

TEST_CASE("debug off") {
    
    std::cout << "== LOG TEST: DEBUG OFF" << std::endl;

    Log::debugMode(false);

    SECTION("color off") {
        std::cout << "==== COLOR OFF" << std::endl;
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
    }

    SECTION("color on") {
        std::cout << "==== COLOR ON" << std::endl;
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
    }

}

TEST_CASE("debug on") {

    std::cout << "== LOG TEST: DEBUG ON" << std::endl;
    
    Log::debugMode(true);

    SECTION("color off") {
        std::cout << "==== COLOR OFF" << std::endl;
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
    }

    SECTION("color on") {
        std::cout << "==== COLOR ON" << std::endl;
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
    }

}