#pragma once


template<typename T>
struct point
{
    point(T x, T y)
        :x(x)
        ,y(y)
    {}

    point()
        :x(0)
        ,y(0)
    {}

    T x;
    T y;

    static point<T> from_polar(T phi, T radius)
    {
        return point<T>(cos(phi), sin(phi)) * radius;
    }
};

template<typename T>
point<T> operator+(point<T> a, point<T> b)
{
    return point<T> (a.x + b.x, a.y + b.y);
}

template<typename T>
point<T> operator-(point<T> a, point<T> b)
{
    return point<T> (a.x - b.x, a.y - b.y);
}

template<typename T>
point<T> operator*(point<T> a, T c)
{
    return point<T> (a.x * c, a.y * c);
}

template<typename T>
point<T> operator*( T c, point<T> a)
{
    return point<T> (a.x * c, a.y * c);
}

template<typename T>
point<T> operator/(point<T> a, T c)
{
    return point<T> (a.x / c, a.y / c);
}

