#include "texturevector3d.h"

TextureVector3D::TextureVector3D()
    : ColorVector3D(Qt::white, 0.0, 0.0, 0.0)
    , _textureCoord(0.0, 0.0)
{
}

TextureVector3D::TextureVector3D(const Vector2D &textureCoord)
    : ColorVector3D(Qt::white, 0.0, 0.0, 0.0)
    , _textureCoord(textureCoord)
{
}

TextureVector3D::TextureVector3D(const Vector2D &textureCoord, const QColor &color)
    : ColorVector3D(color, 0.0, 0.0, 0.0)
    , _textureCoord(textureCoord)
{
}

TextureVector3D::TextureVector3D(const Vector2D &textureCoord, const QColor &color, double x, double y, double z)
    : ColorVector3D(color, x, y, z)
    , _textureCoord(textureCoord)
{
}

TextureVector3D::TextureVector3D(const Vector2D &textureCoord, const QColor& color, const Vector3D &other)
    : ColorVector3D(color, other)
    , _textureCoord(textureCoord)
{
}

TextureVector3D::TextureVector3D(const Vector2D &textureCoord, const ColorVector3D &other)
    : ColorVector3D(other)
    , _textureCoord(textureCoord)
{
}

TextureVector3D::TextureVector3D(const TextureVector3D &other)
    : ColorVector3D(other)
    , _textureCoord(other._textureCoord)
{
}

TextureVector3D::~TextureVector3D()
{
}

const Vector2D &TextureVector3D::getTextureCoord() const
{
    return _textureCoord;
}

void TextureVector3D::setTextureCoord(const Vector2D &textureCoord)
{
    _textureCoord = textureCoord;
}
