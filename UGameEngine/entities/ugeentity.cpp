#include "ugeentity.h"
#include "utils/tools.h"

UGEEntity::UGEEntity(QObject *parent)
    : QObject(parent)
    , _scale(1.0, 1.0, 1.0)
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
    emit positionChanged();
    emit positionChanged(_position);
}

void UGEEntity::move(const Vector3D &move)
{
    _position += move;
    emit positionChanged();
    emit positionChanged(_position);
}

//Vector3D UGEEntity::getSpeed() const
//{
//    return _speed;
//}

//void UGEEntity::setSpeed(const Vector3D &speed)
//{
//    _speed = speed;
//}

//void UGEEntity::accelerate(const Vector3D &speed)
//{
//    _speed += speed;
//}

Vector3D UGEEntity::getRotation() const
{
    return _rotation;
}

void UGEEntity::setRotation(const Vector3D &rotation)
{
    _rotation = Tools::normalizeAngle(rotation);
    emit rotationChanged();
    emit rotationChanged(rotation);
}

void UGEEntity::rotate(const Vector3D &rotation)
{
    _rotation = Tools::normalizeAngle(rotation + _rotation);
    emit rotationChanged();
    emit rotationChanged(rotation);
}

Vector3D UGEEntity::getScale() const
{
    return _scale;
}

void UGEEntity::setScale(const Vector3D &scale)
{
    _scale = scale;
    emit scaleChanged();
    emit scaleChanged(_scale);
}

void UGEEntity::scale(const Vector3D &scale)
{
    _scale += scale;
    emit scaleChanged();
    emit scaleChanged(_scale);
}
bool UGEEntity::isVisible() const
{
    return _visible;
}

void UGEEntity::setVisible(bool visible)
{
    _visible = visible;
    emit visibilityChanged();
    emit visibilityChanged(_visible);
}

void UGEEntity::show()
{
    _visible = true;
    emit visibilityChanged();
    emit visibilityChanged(_visible);
}

void UGEEntity::hide()
{
    _visible = false;
    emit visibilityChanged();
    emit visibilityChanged(_visible);
}

QColor UGEEntity::getColor() const
{
    return _color;
}

void UGEEntity::setColor(const QColor &color)
{
    _color = color;
    emit colorChanged();
    emit colorChanged(_color);
}

Vector3D UGEEntity::getRealPoint(const Vector3D &pos)
{
    Matrix3x3 trans = getTransformationMatrix();
    return (trans.multMatrix(pos) + _position);
}

ColorVector3D UGEEntity::getRealPoint(const ColorVector3D &pos)
{
    return ColorVector3D(pos.getColor(), getRealPoint((Vector3D)pos));
}

TextureVector3D UGEEntity::getRealPoint(const TextureVector3D &pos)
{
    return TextureVector3D(pos.getTextureCoord(), getRealPoint((ColorVector3D)pos));
}

Matrix3x3 UGEEntity::getTransformationMatrix() const
{
    return getRotationMatrix().multMatrix(getScaleMatrix());
}

Matrix3x3 UGEEntity::getScaleMatrix() const
{
    Matrix3x3 scale;
    scale.setScalar(0, 0, _scale.getX());
    scale.setScalar(1, 1, _scale.getY());
    scale.setScalar(2, 2, _scale.getZ());
    return scale;
}

Matrix3x3 UGEEntity::getRotationMatrix() const
{
    Vector3D r = Tools::degreeToRad(_rotation);

    Matrix3x3 mx;
    mx.setToIdentity();
    mx.setScalar(1, 1, cos(r.getX()));
    mx.setScalar(1, 2, -sin(r.getX()));
    mx.setScalar(2, 1, sin(r.getX()));
    mx.setScalar(2, 2, cos(r.getX()));

    Matrix3x3 my;
    my.setToIdentity();
    my.setScalar(0, 0, cos(r.getY()));
    my.setScalar(0, 2, sin(r.getY()));
    my.setScalar(2, 0, -sin(r.getY()));
    my.setScalar(2, 2, cos(r.getY()));

    Matrix3x3 mz;
    mz.setToIdentity();
    mz.setScalar(0, 0, cos(r.getZ()));
    mz.setScalar(0, 1, -sin(r.getZ()));
    mz.setScalar(1, 0, sin(r.getZ()));
    mz.setScalar(1, 1, cos(r.getZ()));

    return mx.multMatrix(my).multMatrix(mz);
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
