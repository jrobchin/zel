#include "lib/catch.hpp"

#include <iostream>
#include "Log.hpp"

TEST_CASE("debug: off, verbose: off") {
    
    Log::debugMode(false);
    Log::verboseMode(false);

    SECTION("color off") {
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

    SECTION("color on") {
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

}

TEST_CASE("debug: on, verbose: off") {
    

    Log::debugMode(true);
    Log::verboseMode(false);

    SECTION("color off") {
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

    SECTION("color on") {
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

}

TEST_CASE("debug: off, verbose: on") {
    

    Log::debugMode(false);
    Log::verboseMode(true);

    SECTION("color off") {
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

    SECTION("color on") {
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

}

TEST_CASE("debug: on, verbose: on") {
    

    Log::debugMode(true);
    Log::verboseMode(true);

    SECTION("color off") {
        Log::colors(false);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

    SECTION("color on") {
        Log::colors(true);
        Log::log("log");
        Log::warning("warning");
        Log::error("error");
        Log::debug("debug");
        Log::verbose("verbose");
    }

}