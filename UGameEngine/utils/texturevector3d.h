#ifndef TEXTUREVECTOR3D_H
#define TEXTUREVECTOR3D_H

#include "colorvector3d.h"
#include "vector2d.h"

class TextureVector3D : public ColorVector3D
{
public:
    TextureVector3D();
    TextureVector3D(const Vector2D& textureCoord);
    TextureVector3D(const Vector2D& textureCoord, const QColor& color);
    TextureVector3D(const Vector2D& textureCoord, const QColor& color, double x, double y, double z);
    TextureVector3D(const Vector2D& textureCoord, const QColor& color, const Vector3D& other);
    TextureVector3D(const Vector2D& textureCoord, const ColorVector3D& other);
    TextureVector3D(const TextureVector3D& other);
    virtual ~TextureVector3D();

    Vector2D getTextureCoord() const;
    void setTextureCoord(const Vector2D &textureCoord);

private:
    Vector2D _textureCoord;
};

#endif // TEXTUREVECTOR3D_H
