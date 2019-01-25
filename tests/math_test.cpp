#include "lib/catch.hpp"

#include <string>
#include <SDL2/SDL.h>

#include "Log.hpp"
#include "Math.hpp"

TEST_CASE("math:rectangle") {

    /* 
        Test Rectangle:
        (10, 100) -- 100 -- (110, 100)
            |                  |
           200    (60, 200)   200
            |                  |
        (10, 300) -- 100 -- (110, 300)
     */
    Point<int> topLeft(10, 100);
    REQUIRE(topLeft.x == 10);
    REQUIRE(topLeft.y == 100);

    Point<int> topRight(110, 100);
    REQUIRE(topRight.x == 110);
    REQUIRE(topRight.y == 100);

    Point<int> bottomLeft(10, 300);
    REQUIRE(bottomLeft.x == 10);
    REQUIRE(bottomLeft.y == 300);
    
    Point<int> bottomRight(110, 300);
    REQUIRE(bottomRight.x == 110);
    REQUIRE(bottomRight.y == 300);

    Point<int> midPoint(
        (topLeft.x + topRight.x)/2,
        (topLeft.y + bottomLeft.y)/2
    );
    REQUIRE(midPoint.x == 60);
    REQUIRE(midPoint.y == 200);

    Rectangle<int> rect1 = Rectangle<int>(topLeft, bottomRight);
    REQUIRE(rect1.top() == 100);
    REQUIRE(rect1.left() == 10);
    REQUIRE(rect1.bottom() == 300);
    REQUIRE(rect1.right() == 110);
    REQUIRE(rect1.topLeft() == topLeft);
    REQUIRE(rect1.topRight() == topRight);
    REQUIRE(rect1.bottomLeft() == bottomLeft);
    REQUIRE(rect1.bottomRight() == bottomRight);
    REQUIRE(rect1.midPoint() == midPoint);
    REQUIRE(rect1.width() == 100);
    REQUIRE(rect1.height() == 200);
    REQUIRE(rect1.sdl_rect.x == 10);
    REQUIRE(rect1.sdl_rect.y == 100);
    REQUIRE(rect1.sdl_rect.w == 100);
    REQUIRE(rect1.sdl_rect.h == 200);

    Rectangle<int> rect2 = Rectangle<int>(topLeft, topRight.x - topLeft.x, bottomLeft.y - topLeft.y);
    REQUIRE(rect2.top() == 100);
    REQUIRE(rect2.left() == 10);
    REQUIRE(rect2.bottom() == 300);
    REQUIRE(rect2.right() == 110);
    REQUIRE(rect2.topLeft() == topLeft);
    REQUIRE(rect2.topRight() == topRight);
    REQUIRE(rect2.bottomLeft() == bottomLeft);
    REQUIRE(rect2.bottomRight() == bottomRight);
    REQUIRE(rect2.midPoint() == midPoint);
    REQUIRE(rect1.width() == 100);
    REQUIRE(rect1.height() == 200);
    REQUIRE(rect2.sdl_rect.x == 10);
    REQUIRE(rect2.sdl_rect.y == 100);
    REQUIRE(rect2.sdl_rect.w == 100);
    REQUIRE(rect2.sdl_rect.h == 200);
}

TEST_CASE("math:collisions") {
    // Rectangle to test collisions against
    Rectangle<int> rect1 = Rectangle<int>(Point<int>(0, 0), 100, 100);
    // This is inside rect1
    Point<int> pt1 = Point<int>(50, 50);
    // This is not inside rect1
    Point<int> pt2 = Point<int>(150, 150);
    // This collides with rect1
    Rectangle<int> rect2 = Rectangle<int>(Point<int>(50, 50), 100, 100);
    // This does not collide with rect1
    Rectangle<int> rect3 = Rectangle<int>(Point<int>(150, 150), 100, 100);

    REQUIRE(rect1.isInside(pt1) == true);
    REQUIRE(rect1.isInside(pt2) == false);
    REQUIRE(rect1.isCollision(rect2) == true);
    REQUIRE(rect1.isCollision(rect3) == false);
}