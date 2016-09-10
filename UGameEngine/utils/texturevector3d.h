#ifndef TEXTUREVECTOR3D_H
#define TEXTUREVECTOR3D_H

#include "colorvector3d.h"

class TextureVector3D : public ColorVector3D
{
public:
    TextureVector3D(QColor color = Qt::white, double x = 0.0, double y = 0.0, double z = 0.0);
    TextureVector3D(QColor color = Qt::white, const Vector3D& other = Vector3D());
    TextureVector3D(const ColorVector3D& other);
    virtual ~TextureVector3D();
};

#endif // TEXTUREVECTOR3D_H
