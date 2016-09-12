#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "vectorxd.h"

typedef MatrixMxN<2, 1> Vector2D;

template<> class MatrixMxN<2, 1> : public GenericVector<2, Vector2D>
{
public:
    MatrixMxN<2, 1>();
    MatrixMxN<2, 1>(const double scalars[2]);
    MatrixMxN<2, 1>(double x, double y);
    MatrixMxN<2, 1>(const Vector2D& other);
    virtual ~MatrixMxN<2, 1>();

    double getX() const;
    Vector2D& setX(double x);

    double getY() const;
    Vector2D& setY(double y);

    using GenericVector<2, Vector2D>::add;
    Vector2D& add(double x, double y);

    using GenericVector<2, Vector2D>::sub;
    Vector2D& sub(double x, double y);

    using GenericVector<2, Vector2D>::dotProduct;
    double dotProduct(double x, double y) const;
};

#endif // VECTOR2D_H
