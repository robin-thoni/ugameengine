#include "vector2d.h"

VectorXD<2>::VectorXD()
{
    _scalars[0] = 0.0;
    _scalars[1] = 0.0;
}

VectorXD<2>::VectorXD(const double scalars[2])
{
    _scalars[0] = scalars[0];
    _scalars[1] = scalars[1];
}

Vector2D::VectorXD(double x, double y)
{
    _scalars[0] = x;
    _scalars[1] = y;
}

Vector2D::VectorXD(const VectorXD<2> &other)
{
    _scalars[0] = other._scalars[0];
    _scalars[1] = other._scalars[1];
}

Vector2D::~VectorXD()
{
}

double Vector2D::getX() const
{
    return _scalars[0];
}

Vector2D& Vector2D::setX(double x)
{
    _scalars[0] = x;
    return *this;
}
double Vector2D::getY() const
{
    return _scalars[1];
}

Vector2D& Vector2D::setY(double y)
{
    _scalars[1] = y;
    return *this;
}

Vector2D &Vector2D::add(double x, double y)
{
    return add(Vector2D(x, y));
}

Vector2D &Vector2D::sub(double x, double y)
{
    return sub(Vector2D(x, y));
}

double Vector2D::dotProduct(double x, double y) const
{
    return dotProduct(Vector2D(x, y));
}
