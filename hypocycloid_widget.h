#pragma once

#include <QWidget>
#include <QPainter>
#include <QElapsedTimer>
#include "point.h"

class hypocycloid_widget: public QWidget
{
    Q_OBJECT

    double phi = 0;
    QElapsedTimer last_repaint;
    std::vector<QPointF> CurveB;
    double radius_max = 200.;
    int numerator = 3;
    int denumerator = 7;

public:
    hypocycloid_widget(QWidget *parent = nullptr);

    void setnumerator(int numerator)
    {
        this->numerator = numerator;
    }

    void setdenumerator(int denumerator)
    {
        this->denumerator = denumerator;
    }

private:

    template <typename T>
    point<T>Q(T phi, point<T> center);

    template <typename T>
    point<T> trace(T phi,  point<T> center);


    void paintEvent(QPaintEvent* ) override;    
    double radius_min();
    int division(int numerator,int denumerator);
};
/*
f(x) = ax + b;
f(x) = (a, 0) * (x, 1) + (b, 0);
f(x) = x;
f(x) = (x, 1);
f(x) = a;
f(x) = (a, 0);
*/



















