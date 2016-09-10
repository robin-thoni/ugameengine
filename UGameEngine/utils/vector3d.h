#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "vectorxd.h"

class Vector3D: public VectorXD<3>
{
public:
    explicit Vector3D(double x = 0.0, double y = 0.0, double z = 0.0);
    Vector3D(const Vector3D& other);
    Vector3D(const VectorXD<3>& other);
    virtual ~Vector3D();

    double getX() const;
    Vector3D& setX(double x);

    double getY() const;
    Vector3D& setY(double y);

    double getZ() const;
    Vector3D& setZ(double z);

    using VectorXD<3>::add;
    Vector3D& add(double x, double y, double z);

    using VectorXD<3>::sub;
    Vector3D& sub(double x, double y, double z);

    using VectorXD<3>::dotProduct;
    double dotProduct(double x, double y, double z) const;
};

#endif // VECTOR3D_H
