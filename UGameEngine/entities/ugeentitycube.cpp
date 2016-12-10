#include "ugeentitycube.h"

UGEEntityCube::UGEEntityCube(UGameEngine *engine, QObject *parent)
    : UGEEntity(engine, parent)
{
    init();
}

UGEEntityCube::UGEEntityCube(UGameEngine *engine)
    : UGEEntity(engine)
{
    init();
}

double UGEEntityCube::getSize() const
{
    return _size;
}

void UGEEntityCube::onDraw(AbstractRenderDevice *device)
{
    if (!_facesColor.empty()) {
        for (int i = 0; i < _facesColor.size(); ++i) {
//            drawPolygon(device, _facesColor[i]);
            device->drawPolygon(_facesColor[i]);
        }
    }
    else {
        for (int i = 0; i < _facesTexture.size(); ++i) {
//            drawPolygonTexture(device, _facesTexture[i], _textureId);
            device->drawPolygonTexture(_facesTexture[i], _textureId);
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

void UGEEntityCube::init()
{
    connect(this, SIGNAL(sizeChanged()), this, SLOT(needUpdate()));
    connect(this, SIGNAL(textureChanged()), this, SLOT(needUpdate()));

    _size = 1;
}

void UGEEntityCube::onUpdate()
{
    double r = _size / 2;
    if (_textureId.isNull()) {
        _facesColor.clear();
        QList<ColorVector3D> points;
        points << ColorVector3D(getColor(), -r, -r, r)  << ColorVector3D(getColor(), -r, r, r)
               << ColorVector3D(getColor(), r, r, r)    << ColorVector3D(getColor(), r, -r, r)
               << ColorVector3D(getColor(), -r, -r, -r) << ColorVector3D(getColor(), -r, r, -r)
               << ColorVector3D(getColor(), r, r, -r)   << ColorVector3D(getColor(), r, -r, -r);
        for (int i = 0; i < points.size(); ++i) {
            points[i] = getRealPoint(points[i]);
        }
        _facesColor.append(QList<ColorVector3D>() << points[3] << points[2] << points[1] << points[0]);
        _facesColor.append(QList<ColorVector3D>() << points[2] << points[3] << points[7] << points[6]);
        _facesColor.append(QList<ColorVector3D>() << points[6] << points[7] << points[4] << points[5]);
        _facesColor.append(QList<ColorVector3D>() << points[5] << points[4] << points[0] << points[1]);
        _facesColor.append(QList<ColorVector3D>() << points[1] << points[2] << points[6] << points[5]);
        _facesColor.append(QList<ColorVector3D>() << points[4] << points[7] << points[3] << points[0]);
    }
    else {
        _facesTexture.clear();
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
        for (int i = 0; i < _facesTexture.size(); ++i) {
            QList<TextureVector3D>& face = _facesTexture[i];
            for (int j = 0; j < face.size(); ++j) {
                face[j] = getRealPoint(face[j]);
            }
        }
    }
}

Vector3D UGEEntityCube::getVectorNearestIntesection(const Vector3D &vector, const Vector3D &origin, bool *ok)
{
    *ok = false;
    Vector3D bestP;
    for (int i = 0; i < _facesTexture.size(); ++i){
        bool provi = false;
        QList<TextureVector3D> face = _facesTexture[i];
        Vector3D pinter = getVectorNearestFaceIntersection(face[0], face[1], face[2], vector, origin, &provi);
        if (provi) {
            bool isNearest = (origin - pinter).norm() < (origin - bestP).norm();
            bool isInFace = (_position - face[0]).norm() >= (_position - pinter).norm();
            if (isInFace && (!(*ok) || isNearest)) {
                bestP = pinter;
                *ok = true;
            }
        }
    }
    return bestP;
}
