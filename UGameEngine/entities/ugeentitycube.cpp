#include "ugeentitycube.h"

UGEEntityCube::UGEEntityCube(QObject *parent)
    : UGEEntity(parent)
    , _size(1.0)
{
}

float UGEEntityCube::getSize() const
{
    return _size;
}

void UGEEntityCube::draw(AbstractRenderDevice *device)
{
    float r = _size / 2;
    if (_textureId.isNull()) {
        QColor color = Qt::red;
        QList<ColorVector3D> points;
        points << ColorVector3D(color, -r, -r, r)  << ColorVector3D(color, -r, r, r)
               << ColorVector3D(color, r, r, r)    << ColorVector3D(color, r, -r, r)
               << ColorVector3D(color, -r, -r, -r) << ColorVector3D(color, -r, r, -r)
               << ColorVector3D(color, r, r, -r)   << ColorVector3D(color, r, -r, -r);
        drawPolygon(device, QList<ColorVector3D>() << points[3] << points[2] << points[1] << points[0]);
        drawPolygon(device, QList<ColorVector3D>() << points[2] << points[3] << points[7] << points[6]);
        drawPolygon(device, QList<ColorVector3D>() << points[6] << points[7] << points[4] << points[5]);
        drawPolygon(device, QList<ColorVector3D>() << points[5] << points[4] << points[0] << points[1]);
        drawPolygon(device, QList<ColorVector3D>() << points[1] << points[2] << points[6] << points[5]);
        drawPolygon(device, QList<ColorVector3D>() << points[4] << points[7] << points[3] << points[0]);
    }
    else {
        QColor color = Qt::white;
        drawPolygonTexture(device, QList<TextureVector3D>() << TextureVector3D(Vector2D(0.25, 0.50), color, r, -r, r)
                           << TextureVector3D(Vector2D(0.25, 0.25), color, r, r, r)
                           << TextureVector3D(Vector2D(0.00, 0.25), color, -r, r, r)
                           << TextureVector3D(Vector2D(0.00, 0.50), color, -r, -r, r), _textureId);
        drawPolygonTexture(device, QList<TextureVector3D>() << TextureVector3D(Vector2D(0.25, 0.50), color, r, r, r)
                           << TextureVector3D(Vector2D(0.25, 0.25), color, r, -r, r)
                           << TextureVector3D(Vector2D(0.50, 0.25), color, r, -r, -r)
                           << TextureVector3D(Vector2D(0.50, 0.50), color, r, r, -r), _textureId);
        drawPolygonTexture(device, QList<TextureVector3D>() << TextureVector3D(Vector2D(0.50, 0.25), color, r, r, -r)
                           << TextureVector3D(Vector2D(0.50, 0.50), color, r, -r, -r)
                           << TextureVector3D(Vector2D(0.75, 0.50), color, -r, -r, -r)
                           << TextureVector3D(Vector2D(0.75, 0.25), color, -r, r, -r), _textureId);
        drawPolygonTexture(device, QList<TextureVector3D>() << TextureVector3D(Vector2D(0.75, 0.25), color, -r, r, -r)
                           << TextureVector3D(Vector2D(0.75, 0.50), color, -r, -r, -r)
                           << TextureVector3D(Vector2D(1.00, 0.50), color, -r, -r, r)
                           << TextureVector3D(Vector2D(1.00, 0.25), color, -r, r, r), _textureId);
        drawPolygonTexture(device, QList<TextureVector3D>() << TextureVector3D(Vector2D(0.25, 0.00), color, -r, r, r)
                           << TextureVector3D(Vector2D(0.25, 0.25), color, r, r, r)
                           << TextureVector3D(Vector2D(0.50, 0.25), color, r, r, -r)
                           << TextureVector3D(Vector2D(0.50, 0.00), color, -r, r, -r), _textureId);
        drawPolygonTexture(device, QList<TextureVector3D>() << TextureVector3D(Vector2D(0.50, 0.75), color, -r, -r, -r)
                           << TextureVector3D(Vector2D(0.50, 0.50), color, r, -r, -r)
                           << TextureVector3D(Vector2D(0.25, 0.5), color, r, -r, r)
                           << TextureVector3D(Vector2D(0.25, 0.75), color, -r, -r, r), _textureId);
    }
}

QVariant UGEEntityCube::getTextureId() const
{
    return _textureId;
}

void UGEEntityCube::setSize(float size)
{
    _size = size;
}

void UGEEntityCube::setTextureId(const QVariant &textureId)
{
    _textureId = textureId;
}


