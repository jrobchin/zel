#ifndef MATH_HPP
#define MATH_HPP

/*
 * 2D math utils. 
 */

/* Point */
template <class T>
struct Point {
    T x, y;

    Point() : x(x), y(y) {};
    Point(T x, T y) : x(x), y(y) {};

    friend bool operator== (const Point<T>& p1, const Point<T>& p2) {
        return (p1.x == p2.x && p1.y == p2.y);
    }
};

/* Rectangle */
template <class T>
class Rectangle {
public:
    T top, left, bottom, right;

    Rectangle();
    Rectangle(T top, T left, T bottom, T right);
    Rectangle(Point<T> topLeft, Point<T> bottomRight);
    Rectangle(Point<T> topLeft, T width, T height);
    Rectangle(T width, T height);
    Point<T> topLeft();
    Point<T> topRight();
    Point<T> bottomLeft();
    Point<T> bottomRight();
    Point<T> midPoint();
};

template <class T>
Rectangle<T>::Rectangle() :
    top(0),
    left(0),
    bottom(0),
    right(0)
{
}

template <class T>
Rectangle<T>::Rectangle(T top, T left, T bottom, T right) {
    top = top;
    left = left;
    bottom = bottom;
    right = right;
}

template <class T>
Rectangle<T>::Rectangle(Point<T> topLeft, Point<T> bottomRight) {
    top = topLeft.y;
    left = topLeft.x;
    bottom = bottomRight.y;
    right = bottomRight.x;
}

template <class T>
Rectangle<T>::Rectangle(Point<T> topLeft, T width, T height) {
    top = topLeft.y;
    left = topLeft.x;
    bottom = topLeft.y + height;
    right = topLeft.x + width;
}

template <class T>
Rectangle<T>::Rectangle(T width, T height) {
    top = 0;
    left = 0;
    bottom = height;
    right = width;
}

template <class T>
Point<T> Rectangle<T>::topLeft() {
    return Point<T>(left, top);
}

template <class T>
Point<T> Rectangle<T>::topRight() {
    return Point<T>(right, top);
}

template <class T>
Point<T> Rectangle<T>::bottomLeft() {
    return Point<T>(left, bottom);
}

template <class T>
Point<T> Rectangle<T>::bottomRight() {
    return Point<T>(right, bottom);
}

template <class T>
Point<T> Rectangle<T>::midPoint() {
    T midx = (left + right) / 2;
    T midy = (top + bottom) / 2;
    return Point<T>(midx, midy);
}

#endif