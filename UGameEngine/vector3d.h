#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D
{
public:
    Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);
    Vector3D(const Vector3D& other);

    double getX() const;
    Vector3D& setX(double x);

    double getY() const;
    Vector3D& setY(double y);

    double getZ() const;
    Vector3D& setZ(double z);

    bool isNull() const;

    Vector3D& add(double x, double y, double z);
    Vector3D& add(const Vector3D& other);

    Vector3D& sub(double x, double y, double z);
    Vector3D& sub(const Vector3D& other);

    Vector3D& mult(double k);

    Vector3D& div(double k);

    double dotProduct(double x, double y, double z) const;
    double dotProduct(const Vector3D& other) const;

    double norm() const;

private:
    double _x;
    double _y;
    double _z;
};

Vector3D& operator+(const Vector3D& v1, const Vector3D& v2);

#endif // VECTOR3D_H
