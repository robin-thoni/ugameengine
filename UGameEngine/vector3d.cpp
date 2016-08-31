#include "vector3d.h"
#include <math.h>

Vector3D::Vector3D(double x, double y, double z)
    : _x(x)
    , _y(y)
    , _z(z)
{
}

Vector3D::Vector3D(const Vector3D &other)
    : _x(other._x)
    , _y(other._y)
    , _z(other._z)
{
}

double Vector3D::getX() const
{
    return _x;
}

Vector3D& Vector3D::setX(double x)
{
    _x = x;
    return *this;
}
double Vector3D::getY() const
{
    return _y;
}

Vector3D& Vector3D::setY(double y)
{
    _y = y;
    return *this;
}
double Vector3D::getZ() const
{
    return _z;
}

Vector3D& Vector3D::setZ(double z)
{
    _z = z;
    return *this;
}

bool Vector3D::isNull() const
{
    return _x == 0 && _y == 0 && _z == 0;
}

Vector3D &Vector3D::add(double x, double y, double z)
{
    return add(Vector3D(x, y, z));
}

Vector3D& Vector3D::add(const Vector3D &other)
{
    _x += other._x;
    _y += other._y;
    _z += other._z;
    return *this;
}

Vector3D &Vector3D::sub(double x, double y, double z)
{
    return sub(Vector3D(x, y, z));
}

Vector3D& Vector3D::sub(const Vector3D &other)
{
    _x -= other._x;
    _y -= other._y;
    _z -= other._z;
    return *this;
}

Vector3D &Vector3D::mult(double k)
{
    _x *= k;
    _y *= k;
    _z *= k;
    return *this;
}

Vector3D &Vector3D::div(double k)
{
    _x /= k;
    _y /= k;
    _z /= k;
    return *this;
}

double Vector3D::dotProduct(double x, double y, double z) const
{
    return dotProduct(Vector3D(x, y, z));
}

double Vector3D::dotProduct(const Vector3D &other) const
{
    return (_x * other._x) + (_y * other._y) + (_z * other._z);
}

double Vector3D::norm() const
{
    return sqrt((_x * _x) + (_y * _y) + (_z * _z));
}


Vector3D &operator+(const Vector3D &v1, const Vector3D &v2)
{
    return Vector3D(v1).add(v2);
}
