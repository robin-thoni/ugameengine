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

Vector3D::~Vector3D()
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

bool Vector3D::equal(const Vector3D &other) const
{
    return _x == other._x && _y == other._y && _z == other._z;
}

Vector3D &Vector3D::add(double k)
{
    return add(Vector3D(k, k, k));
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

Vector3D &Vector3D::sub(double k)
{
    return sub(Vector3D(k, k, k));
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

Vector3D Vector3D::operator+() const
{
    return *this;
}

Vector3D Vector3D::operator+(const double &k) const
{
    return Vector3D(*this).add(k);
}

Vector3D &Vector3D::operator+=(const double &k)
{
    return add(k);
}

Vector3D Vector3D::operator+(const Vector3D &other) const
{
    return Vector3D(*this).add(other);
}

Vector3D &Vector3D::operator+=(const Vector3D &other)
{
    return add(other);
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-_x, -_y, -_z);
}

Vector3D Vector3D::operator-(const double &k) const
{
    return Vector3D(*this).sub(k);
}

Vector3D &Vector3D::operator-=(const double &k)
{
    return sub(k);
}

Vector3D Vector3D::operator-(const Vector3D &other) const
{
    return Vector3D(*this).sub(other);
}

Vector3D &Vector3D::operator-=(const Vector3D &other)
{
    return sub(other);
}

Vector3D Vector3D::operator*(const double &k) const
{
    return Vector3D(*this).mult(k);
}

Vector3D &Vector3D::operator*=(const double &k)
{
    return mult(k);
}

double Vector3D::operator*(const Vector3D &other) const
{
    return Vector3D(*this).dotProduct(other);
}

Vector3D &Vector3D::operator*=(const Vector3D &other)
{
    dotProduct(other);
    return *this;
}

Vector3D Vector3D::operator/(const double &k) const
{
    return Vector3D(*this).div(k);
}

Vector3D &Vector3D::operator/=(const double &k)
{
    return div(k);
}

bool Vector3D::operator==(const Vector3D &other) const
{
    return equal(other);
}

bool Vector3D::operator!=(const Vector3D &other) const
{
    return !equal(other);
}

bool Vector3D::operator!() const
{
    return isNull();
}

Vector3D::operator bool() const
{
    return !isNull();
}


QDebug operator<<(QDebug dbg, const Vector3D &v)
{
    return dbg.nospace() << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
}
