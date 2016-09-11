#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "vectorxd.h"

typedef VectorXD<2> Vector2D;

template<> class VectorXD<2> : public GenericVector<2, VectorXD<2> >
{
public:
    VectorXD<2>();
    VectorXD<2>(const double scalars[2]);
    VectorXD<2>(double x, double y);
    VectorXD<2>(const VectorXD<2>& other);
    virtual ~VectorXD<2>();

    double getX() const;
    Vector2D& setX(double x);

    double getY() const;
    Vector2D& setY(double y);

    using GenericVector<2, VectorXD<2> >::add;
    Vector2D& add(double x, double y);

    using GenericVector<2, VectorXD<2> >::sub;
    Vector2D& sub(double x, double y);

    using GenericVector<2, VectorXD<2> >::dotProduct;
    double dotProduct(double x, double y) const;
};

#endif // VECTOR2D_H
