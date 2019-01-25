#ifndef MATH_HPP
#define MATH_HPP

#include <SDL2/SDL.h>
#include "Log.hpp"

/*
 * 2D math utils. 
 */

/* Point */
template <class T>
struct Point {
    T x, y;

    Point() : x(0), y(0) {};
    Point(T x, T y) : x(x), y(y) {};

    friend bool operator== (const Point<T>& p1, const Point<T>& p2) {
        return (p1.x == p2.x && p1.y == p2.y);
    }
};

/* 
 * Rectangle.
 * 
 * Rectangles are currently immutable.
 * 
 * TODO: Add recalculate method and make rectangles mutable.
 */
template <class T>
class Rectangle {
public:
    Rectangle();
    Rectangle(T top, T left, T bottom, T right);
    Rectangle(Point<T> topLeft, Point<T> bottomRight);
    Rectangle(Point<T> topLeft, T width, T height);
    Rectangle(T width, T height);
    ~Rectangle();
    
    /// SDL_Rect that matches the dimensions of the rectangle
    SDL_Rect sdl_rect;
    /// Get top
    T top();
    /// Get left
    T left();
    /// Get bottom
    T bottom();
    /// Get right
    T right();
    /// Get top-left corner
    Point<T> topLeft();
    /// Get top-right corner
    Point<T> topRight();
    /// Get bottom-left corner
    Point<T> bottomLeft();
    /// Get bottom-right corner
    Point<T> bottomRight();
    /// Get midpoint
    Point<T> midPoint();
    /// Get rect width
    T width();
    /// Get rect height
    T height();
    /// Get SDL rect pointer
    SDL_Rect getSDL_Rect();

private:
    void _init();
    T _top, _left, _bottom, _right;
};

template <class T>
Rectangle<T>::Rectangle() :
    _top(0),
    _left(0),
    _bottom(0),
    _right(0)
{
    _init();
}

template <class T>
Rectangle<T>::Rectangle(T top, T left, T bottom, T right) {
    _top = top;
    _left = left;
    _bottom = bottom;
    _right = right;
    _init();
}

template <class T>
Rectangle<T>::Rectangle(Point<T> topLeft, Point<T> bottomRight) {
    _top = topLeft.y;
    _left = topLeft.x;
    _bottom = bottomRight.y;
    _right = bottomRight.x;
    _init();
}

template <class T>
Rectangle<T>::Rectangle(Point<T> topLeft, T width, T height) {
    _top = topLeft.y;
    _left = topLeft.x;
    _bottom = topLeft.y + height;
    _right = topLeft.x + width;
    _init();
}

template <class T>
Rectangle<T>::Rectangle(T width, T height) {
    _top = 0;
    _left = 0;
    _bottom = height;
    _right = width;
    _init();
}

template <class T>
void Rectangle<T>::_init() {
    sdl_rect.x = _left;
    sdl_rect.y = _top;
    sdl_rect.w = _right - _left;
    sdl_rect.h = _bottom - _top;
}

template <class T>
Rectangle<T>::~Rectangle() {
}

template <class T>
T Rectangle<T>::top() {
    return _top;
}

template <class T>
T Rectangle<T>::left() {
    return _left;
}

template <class T>
T Rectangle<T>::bottom() {
    return _bottom;
}

template <class T>
T Rectangle<T>::right() {
    return _right;
}

template <class T>
Point<T> Rectangle<T>::topLeft() {
    return Point<T>(_left, _top);
}

template <class T>
Point<T> Rectangle<T>::topRight() {
    return Point<T>(_right, _top);
}

template <class T>
Point<T> Rectangle<T>::bottomLeft() {
    return Point<T>(_left, _bottom);
}

template <class T>
Point<T> Rectangle<T>::bottomRight() {
    return Point<T>(_right, _bottom);
}

template <class T>
Point<T> Rectangle<T>::midPoint() {
    T midx = (_left + _right) / 2;
    T midy = (_top + _bottom) / 2;
    return Point<T>(midx, midy);
}

template <class T>
T Rectangle<T>::width() {
    return _right - _left;
}

template <class T>
T Rectangle<T>::height() {
    return _bottom - _top;
}

#endif