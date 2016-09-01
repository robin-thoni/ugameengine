#include "colorvector3d.h"

ColorVector3D::ColorVector3D(QColor color, double x, double y, double z)
    : Vector3D(x, y, z)
    , _color(color)
{
}

ColorVector3D::ColorVector3D(QColor color, const Vector3D &other)
    : Vector3D(other)
    , _color(color)
{
}

ColorVector3D::ColorVector3D(const ColorVector3D &other)
    : Vector3D(other)
    , _color(other._color)
{
}

QColor ColorVector3D::getColor() const
{
    return _color;
}

void ColorVector3D::setColor(const QColor &color)
{
    _color = color;
}

