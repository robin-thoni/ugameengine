#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "vectorxd.h"

typedef VectorXD<3> Vector3D;

template<> class VectorXD<3>: public GenericVector<3, VectorXD<3> >
{
public:
    VectorXD<3>();
    VectorXD<3>(const double scalars[3]);
    VectorXD<3>(double x, double y, double z);
    VectorXD<3>(const Vector3D& other);
    virtual ~VectorXD<3>();

    double getX() const;
    Vector3D& setX(double x);

    double getY() const;
    Vector3D& setY(double y);

    double getZ() const;
    Vector3D& setZ(double z);

    using GenericVector<3, VectorXD<3> >::add;
    Vector3D& add(double x, double y, double z);

    using GenericVector<3, VectorXD<3> >::sub;
    Vector3D& sub(double x, double y, double z);

    using GenericVector<3, VectorXD<3> >::dotProduct;
    double dotProduct(double x, double y, double z) const;
};

#endif // VECTOR3D_H
