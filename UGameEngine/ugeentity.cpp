#include "ugeentity.h"

UGEEntity::UGEEntity(QObject *parent) :
    QObject(parent)
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
