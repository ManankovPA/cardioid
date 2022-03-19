#pragma once

#include <cmath>

struct dual
{
    dual(double re, double im)
        :re(re)
        ,im(im)
    {}


    dual(double re)
        :re(re)
        ,im(0)
    {}


    dual()
        :re(0)
        ,im(0)
    {}

    double re;
    double im;

    static dual variable (double re)
    {
        return {re, 1};
    }
};

dual operator+(dual a, dual b)
{
    return dual (a.re + b.re, a.im + b.im);
}

dual operator-(dual a, dual b)
{
    return dual (a.re - b.re, a.im - b.im);
}

dual operator*(dual a, dual b)
{
    return dual (a.re * b.re, (a.im * b.re + a.re * b.im));
}

dual operator/(dual a, dual b)
{
    return dual (a.re / b.re, (b.re * a.im - b.im * a.re) / (b.re * b.re));
}

dual sin(dual a)
{
    return dual (sin(a.re), a.im * cos(a.re));
}

dual cos(dual a)
{
    return dual (cos(a.re), a.im * -sin(a.re));
}
