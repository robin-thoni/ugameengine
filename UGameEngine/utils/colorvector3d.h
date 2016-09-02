#ifndef COLORVECTOR3D_H
#define COLORVECTOR3D_H

#include <QColor>
#include "vector3d.h"

class ColorVector3D : public Vector3D
{
public:
    ColorVector3D(QColor color = Qt::black, double x = 0.0, double y = 0.0, double z = 0.0);
    ColorVector3D(QColor color = Qt::black, const Vector3D& other = Vector3D());
    ColorVector3D(const ColorVector3D& other);
    virtual ~ColorVector3D();

    QColor getColor() const;
    void setColor(const QColor &color);

private:
    QColor _color;
};

#endif // COLORVECTOR3D_H
