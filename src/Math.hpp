#ifndef MATH_HPP
#define MATH_HPP

/*
 * 2D math utils. 
 */
template <class T>
struct Point {
    T x, y;

    Point() : x(x), y(y) {};
    Point(T x, T y) : x(x), y(y) {};
};

#endif