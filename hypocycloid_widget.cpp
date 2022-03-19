#include <math.h>
#include <QElapsedTimer>
#include "hypocycloid_widget.h"
#include "dual.h"
#include <vector>

QPointF to_qpoint(point<dual> point_tmp)
{
    return QPointF(point_tmp.x.re, point_tmp.y.re);
}


QPointF to_qpoint(point<double> point_tmp)
{
    return QPointF(point_tmp.x, point_tmp.y);
}


hypocycloid_widget::hypocycloid_widget(QWidget *parent)
    :QWidget(parent)
{
        last_repaint.start();
}

int hypocycloid_widget::division(int numerator, int denumerator)
{
    while(denumerator)
    {
        numerator %= denumerator;
        std::swap(numerator, denumerator);
    }
    return numerator;
}

double hypocycloid_widget::radius_min ()
{
    int tmp = division(numerator, denumerator);
    return (radius_max * (numerator / tmp)) / (denumerator / tmp);
}

template <typename T>
point<T> hypocycloid_widget::Q (T phi, point<T> center)
{   
    return point<T>::from_polar(phi, radius_max - radius_min()) + center;
}

template <typename T>
point<T> hypocycloid_widget::trace(T phi,  point<T> center)
{
    return point<T>::from_polar(phi * (1. - radius_max/radius_min()), radius_min()) + Q(phi, center);
}


void hypocycloid_widget::paintEvent(QPaintEvent *)
{
    QPainter painter (this);

    point<dual> center (400., 300.);

    QPainterPath curve;

    std::vector<QPointF> v;

    for(double i = 0; i < 44; i+= 0.2)
    {
        QPointF tmp (400. + 200. * sin(i), 300. + 200. * cos(i));
        v.push_back(tmp);
    }

    painter.setPen(Qt::blue);
    for(size_t i = 0; i < v.size(); ++i)
    {
        painter.drawEllipse(v[i], 4, 4);
    }

    painter.setPen(Qt::green);
    curve.moveTo(v[0]);

    for(size_t j = 0; j < v.size(); ++j)
    {
        for(size_t i = 0; i < v.size(); ++i)
        {
            curve.moveTo(v[i]);
            size_t tmp = (2 * i) % v.size();
            curve.lineTo(v[tmp]);
        }
    }


    painter.drawPath(curve);



    /*
    for(double phi = 0.; phi < max_phi; phi += 0.05)
    {
        QPointF b (300 * phi, 300 * phi);
        curve.lineTo(b);
    }
*/
   // painter.drawPath(curve);

    qint64 time = last_repaint.restart();
    phi -= 0.0009 * time;
    painter.drawEllipse(to_qpoint(center), radius_max, radius_max);

    update();
}
