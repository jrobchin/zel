#include "lib/catch.hpp"

#include <string>

#include "Log.hpp"
#include "Math.hpp"

TEST_CASE("math:rectangle") {

    Point<int> topLeft(10, 400);
    Point<int> topRight(30, 400);
    Point<int> bottomLeft(10, 600);
    Point<int> bottomRight(30, 600);
    Point<int> midPoint(
        (topLeft.x + topRight.x)/2,
        (topLeft.y + bottomLeft.y)/2
    );

    Rectangle<int> rect1 = Rectangle<int>(topLeft, bottomRight);

    REQUIRE(rect1.top == topLeft.y);
    REQUIRE(rect1.left == topLeft.x);
    REQUIRE(rect1.bottom == bottomRight.y);
    REQUIRE(rect1.right == bottomRight.x);
    REQUIRE(rect1.topLeft() == topLeft);
    REQUIRE(rect1.topRight() == topRight);
    REQUIRE(rect1.bottomLeft() == bottomLeft);
    REQUIRE(rect1.bottomRight() == bottomRight);
    REQUIRE(rect1.midPoint() == midPoint);

    Rectangle<int> rect2 = Rectangle<int>(topLeft, topRight.x - topLeft.x, bottomLeft.y - topLeft.y);

    REQUIRE(rect2.top == topLeft.y);
    REQUIRE(rect2.left == topLeft.x);
    REQUIRE(rect2.bottom == bottomRight.y);
    REQUIRE(rect2.right == bottomRight.x);
    REQUIRE(rect2.topLeft() == topLeft);
    REQUIRE(rect2.topRight() == topRight);
    REQUIRE(rect2.bottomLeft() == bottomLeft);
    REQUIRE(rect2.bottomRight() == bottomRight);
    REQUIRE(rect2.midPoint() == midPoint);

}