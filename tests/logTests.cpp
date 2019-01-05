#include "lib/catch.hpp"

#include <iostream>
#include "Log.hpp"

TEST_CASE("debug: off, verbose: off") {
    
    std::cout << "== LOG TEST: DEBUG OFF" << std::endl;
    std::cout << "== LOG TEST: VERBOSE OFF" << std::endl;

    Log::debugMode(false);
    Log::verboseMode(false);

    SECTION("color off") {
        std::cout << "==== COLOR OFF" << std::endl;
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

    SECTION("color on") {
        std::cout << "==== COLOR ON" << std::endl;
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

}

TEST_CASE("debug: on, verbose: off") {
    
    std::cout << "== LOG TEST: DEBUG ON" << std::endl;
    std::cout << "== LOG TEST: VERBOSE OFF" << std::endl;

    Log::debugMode(true);
    Log::verboseMode(false);

    SECTION("color off") {
        std::cout << "==== COLOR OFF" << std::endl;
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

    SECTION("color on") {
        std::cout << "==== COLOR ON" << std::endl;
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

}

TEST_CASE("debug: off, verbose: on") {
    
    std::cout << "== LOG TEST: DEBUG OFF" << std::endl;
    std::cout << "== LOG TEST: VERBOSE ON" << std::endl;

    Log::debugMode(false);
    Log::verboseMode(true);

    SECTION("color off") {
        std::cout << "==== COLOR OFF" << std::endl;
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

    SECTION("color on") {
        std::cout << "==== COLOR ON" << std::endl;
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

}

TEST_CASE("debug: on, verbose: on") {
    
    std::cout << "== LOG TEST: DEBUG ON" << std::endl;
    std::cout << "== LOG TEST: VERBOSE ON" << std::endl;

    Log::debugMode(true);
    Log::verboseMode(true);

    SECTION("color off") {
        std::cout << "==== COLOR OFF" << std::endl;
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

    SECTION("color on") {
        std::cout << "==== COLOR ON" << std::endl;
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

}