#ifndef VECTOR2D_H
#define VECTOR2D_H

#include "vectorxd.h"

class Vector2D : public VectorXD<2>
{
public:
    explicit Vector2D(double x = 0.0, double y = 0.0);
    Vector2D(const Vector2D& other);
    Vector2D(const VectorXD<2>& other);
    virtual ~Vector2D();

    double getX() const;
    Vector2D& setX(double x);

    double getY() const;
    Vector2D& setY(double y);

    using VectorXD<2>::add;
    Vector2D& add(double x, double y);

    using VectorXD<2>::sub;
    Vector2D& sub(double x, double y);

    using VectorXD<2>::dotProduct;
    double dotProduct(double x, double y) const;
};

#endif // VECTOR2D_H
