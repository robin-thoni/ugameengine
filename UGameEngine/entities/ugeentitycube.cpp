#include "ugeentitycube.h"

UGEEntityCube::UGEEntityCube(QObject *parent)
    : UGEEntity(parent)
    , _size(1.0)
{
    updateFaces();
    connect(this, SIGNAL(colorChanged()), this, SLOT(updateFaces()));
    connect(this, SIGNAL(sizeChanged()), this, SLOT(updateFaces()));
    connect(this, SIGNAL(textureChanged()), this, SLOT(updateFaces()));
}

double UGEEntityCube::getSize() const
{
    return _size;
}

void UGEEntityCube::draw(AbstractRenderDevice *device)
{
    if (!_facesColor.empty()) {
        for (int i = 0; i < _facesColor.size(); ++i) {
            drawPolygon(device, _facesColor[i]);
        }
    }
    else {
        for (int i = 0; i < _facesTexture.size(); ++i) {
            drawPolygonTexture(device, _facesTexture[i], _textureId);
        }
    }
}

void UGEEntityCube::setSize(double size)
{
    _size = size;
    emit sizeChanged();
    emit sizeChanged(_size);
}

void UGEEntityCube::increaseSize(double size)
{
    _size += size;
    emit sizeChanged();
    emit sizeChanged(_size);
}

QVariant UGEEntityCube::getTextureId() const
{
    return _textureId;
}

void UGEEntityCube::setTextureId(const QVariant &textureId)
{
    _textureId = textureId;
    setColor(Qt::white);
    emit textureChanged();
    emit textureChanged(_textureId);
}

void UGEEntityCube::updateFaces()
{
    _facesColor.clear();
    _facesTexture.clear();
    double r = _size / 2;
    if (_textureId.isNull()) {
        QList<ColorVector3D> points;
        points << ColorVector3D(getColor(), -r, -r, r)  << ColorVector3D(getColor(), -r, r, r)
               << ColorVector3D(getColor(), r, r, r)    << ColorVector3D(getColor(), r, -r, r)
               << ColorVector3D(getColor(), -r, -r, -r) << ColorVector3D(getColor(), -r, r, -r)
               << ColorVector3D(getColor(), r, r, -r)   << ColorVector3D(getColor(), r, -r, -r);
        _facesColor.append(QList<ColorVector3D>() << points[3] << points[2] << points[1] << points[0]);
        _facesColor.append(QList<ColorVector3D>() << points[2] << points[3] << points[7] << points[6]);
        _facesColor.append(QList<ColorVector3D>() << points[6] << points[7] << points[4] << points[5]);
        _facesColor.append(QList<ColorVector3D>() << points[5] << points[4] << points[0] << points[1]);
        _facesColor.append(QList<ColorVector3D>() << points[1] << points[2] << points[6] << points[5]);
        _facesColor.append(QList<ColorVector3D>() << points[4] << points[7] << points[3] << points[0]);
    }
    else {
        _facesTexture.append(QList<TextureVector3D>() << TextureVector3D(Vector2D(0.25, 0.50), getColor(), r, -r, r)
                             << TextureVector3D(Vector2D(0.25, 0.25), getColor(), r, r, r)
                             << TextureVector3D(Vector2D(0.00, 0.25), getColor(), -r, r, r)
                             << TextureVector3D(Vector2D(0.00, 0.50), getColor(), -r, -r, r));
        _facesTexture.append(QList<TextureVector3D>() << TextureVector3D(Vector2D(0.25, 0.50), getColor(), r, r, r)
                             << TextureVector3D(Vector2D(0.25, 0.25), getColor(), r, -r, r)
                             << TextureVector3D(Vector2D(0.50, 0.25), getColor(), r, -r, -r)
                             << TextureVector3D(Vector2D(0.50, 0.50), getColor(), r, r, -r));
        _facesTexture.append(QList<TextureVector3D>() << TextureVector3D(Vector2D(0.50, 0.25), getColor(), r, r, -r)
                             << TextureVector3D(Vector2D(0.50, 0.50), getColor(), r, -r, -r)
                             << TextureVector3D(Vector2D(0.75, 0.50), getColor(), -r, -r, -r)
                             << TextureVector3D(Vector2D(0.75, 0.25), getColor(), -r, r, -r));
        _facesTexture.append(QList<TextureVector3D>() << TextureVector3D(Vector2D(0.75, 0.25), getColor(), -r, r, -r)
                             << TextureVector3D(Vector2D(0.75, 0.50), getColor(), -r, -r, -r)
                             << TextureVector3D(Vector2D(1.00, 0.50), getColor(), -r, -r, r)
                             << TextureVector3D(Vector2D(1.00, 0.25), getColor(), -r, r, r));
        _facesTexture.append(QList<TextureVector3D>() << TextureVector3D(Vector2D(0.25, 0.00), getColor(), -r, r, r)
                             << TextureVector3D(Vector2D(0.25, 0.25), getColor(), r, r, r)
                             << TextureVector3D(Vector2D(0.50, 0.25), getColor(), r, r, -r)
                             << TextureVector3D(Vector2D(0.50, 0.00), getColor(), -r, r, -r));
        _facesTexture.append(QList<TextureVector3D>() << TextureVector3D(Vector2D(0.50, 0.75), getColor(), -r, -r, -r)
                             << TextureVector3D(Vector2D(0.50, 0.50), getColor(), r, -r, -r)
                             << TextureVector3D(Vector2D(0.25, 0.5), getColor(), r, -r, r)
                             << TextureVector3D(Vector2D(0.25, 0.75), getColor(), -r, -r, r));
    }
}
