#include "vector3d.h"
#include <math.h>

Vector3D::MatrixMxN()
{
    this->fill(0.0);
}

Vector3D::MatrixMxN(double k)
{
    this->fill(k);
}

Vector3D::MatrixMxN(const double scalars[3])
{
    _scalars[0][0] = scalars[0];
    _scalars[1][0] = scalars[1];
    _scalars[2][0] = scalars[2];
}

Vector3D::MatrixMxN(double x, double y, double z)
{
    _scalars[0][0] = x;
    _scalars[1][0] = y;
    _scalars[2][0] = z;
}

Vector3D::MatrixMxN(const Vector3D &other)
{
    _scalars[0][0] = other._scalars[0][0];
    _scalars[1][0] = other._scalars[1][0];
    _scalars[2][0] = other._scalars[2][0];
}

Vector3D::~MatrixMxN()
{
}

double Vector3D::getX() const
{
    return _scalars[0][0];
}

Vector3D& Vector3D::setX(double x)
{
    _scalars[0][0] = x;
    return *this;
}
double Vector3D::getY() const
{
    return _scalars[1][0];
}

Vector3D& Vector3D::setY(double y)
{
    _scalars[1][0] = y;
    return *this;
}
double Vector3D::getZ() const
{
    return _scalars[2][0];
}

Vector3D& Vector3D::setZ(double z)
{
    _scalars[2][0] = z;
    return *this;
}

Vector3D &Vector3D::add(double x, double y, double z)
{
    _scalars[0][0] += x;
    _scalars[1][0] += y;
    _scalars[2][0] += z;
    return *this;
}

Vector3D &Vector3D::sub(double x, double y, double z)
{
    _scalars[0][0] -= x;
    _scalars[1][0] -= y;
    _scalars[2][0] -= z;
    return *this;
}

double Vector3D::dotProduct(double x, double y, double z) const
{
    return dotProduct(Vector3D(x, y, z));
}
