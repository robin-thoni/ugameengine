#ifndef UGEENTITY_H
#define UGEENTITY_H

#include <QObject>
#include <QPoint>
#include <QSharedPointer>
#include "vector3d.h"
#include "abstractrenderdevice.h"

class UGEEntity : public QObject
{
    Q_OBJECT
public:
    explicit UGEEntity(QObject *parent = 0);

    Vector3D getPosition() const;
    void setPosition(const Vector3D& position);
    void move(const Vector3D& move);

    Vector3D getSpeed() const;
    void setSpeed(const Vector3D& speed);
    void accelerate(const Vector3D& speed);

    Vector3D getRotation() const;
    void setRotation(const Vector3D& rotation);
    void rotate(const Vector3D& rotation);

    Vector3D getScale() const;
    void setScale(const Vector3D& scale);
    void scale(const Vector3D& scale);

    virtual void draw(AbstractRenderDevice* device) = 0;

private:
    Vector3D _position;

    Vector3D _speed;

    Vector3D _rotation;

    Vector3D _scale;

};

#endif // UGEENTITY_H
