#ifndef VECTOR3D_H
#define VECTOR3D_H

#include "vectorxd.h"

typedef MatrixMxN<3, 1> Vector3D;

template<> class MatrixMxN<3, 1>: public GenericVector<3, Vector3D>
{
public:
    MatrixMxN<3, 1>();
    MatrixMxN<3, 1>(double k);
    MatrixMxN<3, 1>(const double scalars[3]);
    MatrixMxN<3, 1>(double x, double y, double z);
    MatrixMxN<3, 1>(const Vector3D& other);
    virtual ~MatrixMxN<3, 1>();

    double getX() const;
    Vector3D& setX(double x);

    double getY() const;
    Vector3D& setY(double y);

    double getZ() const;
    Vector3D& setZ(double z);

    using GenericVector<3, Vector3D>::add;
    Vector3D& add(double x, double y, double z);

    using GenericVector<3, Vector3D>::sub;
    Vector3D& sub(double x, double y, double z);

    using GenericVector<3, Vector3D>::dotProduct;
    double dotProduct(double x, double y, double z) const;
};

#endif // VECTOR3D_H
