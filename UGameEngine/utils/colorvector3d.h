#ifndef COLORVECTOR3D_H
#define COLORVECTOR3D_H

#include <QColor>
#include "vector3d.h"

class ColorVector3D : public Vector3D
{
public:
    ColorVector3D();
    ColorVector3D(const QColor& color);
    ColorVector3D(const QColor& color, double x, double y, double z);
    ColorVector3D(const QColor& color, const Vector3D& other);
    ColorVector3D(const ColorVector3D& other);
    virtual ~ColorVector3D();

    QColor getColor() const;
    void setColor(const QColor &color);

private:
    QColor _color;
};

#endif // COLORVECTOR3D_H
