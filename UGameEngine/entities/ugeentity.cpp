#include "ugeentity.h"

UGEEntity::UGEEntity(QObject *parent)
    : QObject(parent)
    , _visible(true)
{
}

UGEEntity::~UGEEntity()
{
}

Vector3D UGEEntity::getPosition() const
{
    return _position;
}

void UGEEntity::setPosition(const Vector3D &position)
{
    _position = position;
}

void UGEEntity::move(const Vector3D &move)
{
    _position += move;
}

Vector3D UGEEntity::getSpeed() const
{
    return _speed;
}

void UGEEntity::setSpeed(const Vector3D &speed)
{
    _speed = speed;
}

void UGEEntity::accelerate(const Vector3D &speed)
{
    _speed += speed;
}

Vector3D UGEEntity::getRotation() const
{
    return _rotation;
}

void UGEEntity::setRotation(const Vector3D &rotation)
{
    _rotation = rotation;
}

void UGEEntity::rotate(const Vector3D &rotation)
{
    _rotation += rotation;
}

Vector3D UGEEntity::getScale() const
{
    return _scale;
}

void UGEEntity::setScale(const Vector3D &scale)
{
    _scale = scale;
}

void UGEEntity::scale(const Vector3D &scale)
{
    _scale += scale;
}
bool UGEEntity::isVisible() const
{
    return _visible;
}

void UGEEntity::setVisible(bool visible)
{
    _visible = visible;
}

void UGEEntity::show()
{
    _visible = true;
}

void UGEEntity::hide()
{
    _visible = false;
}

Vector3D UGEEntity::getRealPoint(const Vector3D &pos)
{
    return pos + _position;
}

ColorVector3D UGEEntity::getRealPoint(const ColorVector3D &pos)
{
    return ColorVector3D(pos.getColor(), getRealPoint((Vector3D)pos));
}

TextureVector3D UGEEntity::getRealPoint(const TextureVector3D &pos)
{
    return TextureVector3D(pos.getTextureCoord(), getRealPoint((ColorVector3D)pos));
}

void UGEEntity::drawPoint(AbstractRenderDevice *device, const ColorVector3D &point)
{
    device->drawPoint(getRealPoint(point));
}

void UGEEntity::drawLine(AbstractRenderDevice *device, const ColorVector3D &begin, const ColorVector3D &end, double width)
{
    device->drawLine(getRealPoint(begin), getRealPoint(end), width);
}

void UGEEntity::drawPolygon(AbstractRenderDevice *device, QList<ColorVector3D> points)
{
    for (int i = 0; i < points.size(); ++i) {
        points[i] = getRealPoint(points[i]);
    }
    device->drawPolygon(points);
}

void UGEEntity::drawPolygonTexture(AbstractRenderDevice *device, QList<TextureVector3D> points, const QVariant &textureId)
{
    for (int i = 0; i < points.size(); ++i) {
        points[i] = getRealPoint(points[i]);
    }
    device->drawPolygonTexture(points, textureId);
}
