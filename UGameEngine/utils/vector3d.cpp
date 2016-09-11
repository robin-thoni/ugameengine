#include "vector3d.h"
#include <math.h>

Vector3D::VectorXD()
{
    _scalars[0] = 0.0;
    _scalars[1] = 0.0;
    _scalars[2] = 0.0;
}

Vector3D::VectorXD(const double scalars[3])
{
    _scalars[0] = scalars[0];
    _scalars[1] = scalars[1];
    _scalars[2] = scalars[2];
}

Vector3D::VectorXD(double x, double y, double z)
{
    _scalars[0] = x;
    _scalars[1] = y;
    _scalars[2] = z;
}

Vector3D::VectorXD(const Vector3D &other)
{
    _scalars[0] = other._scalars[0];
    _scalars[1] = other._scalars[1];
    _scalars[2] = other._scalars[2];
}

Vector3D::~VectorXD()
{
}

double Vector3D::getX() const
{
    return _scalars[0];
}

Vector3D& Vector3D::setX(double x)
{
    _scalars[0] = x;
    return *this;
}
double Vector3D::getY() const
{
    return _scalars[1];
}

Vector3D& Vector3D::setY(double y)
{
    _scalars[1] = y;
    return *this;
}
double Vector3D::getZ() const
{
    return _scalars[2];
}

Vector3D& Vector3D::setZ(double z)
{
    _scalars[2] = z;
    return *this;
}

Vector3D &Vector3D::add(double x, double y, double z)
{
    _scalars[0] += x;
    _scalars[1] += y;
    _scalars[2] += z;
    return *this;
}

Vector3D &Vector3D::sub(double x, double y, double z)
{
    _scalars[0] -= x;
    _scalars[1] -= y;
    _scalars[2] -= z;
    return *this;
}

double Vector3D::dotProduct(double x, double y, double z) const
{
    return dotProduct(Vector3D(x, y, z));
}
