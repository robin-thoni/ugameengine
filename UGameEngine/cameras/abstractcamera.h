#ifndef ABSTRACTCAMERA_H
#define ABSTRACTCAMERA_H

#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QtWidgets/QWidget>

#include "engine/ugameengine.h"

class AbstractCamera
{
public:
    AbstractCamera(UGameEngine* engine, QWidget* widget);

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);

    virtual void wheelEvent(QWheelEvent* event);

    virtual void keyPressEvent(QKeyEvent* event);
    virtual void keyReleaseEvent(QKeyEvent* event);

    virtual void updateLookAt() = 0;

    Vector3D getDirection() const;
    void setDirection(const Vector3D &getDirection);

    Vector3D getPosition() const;
    void setPosition(const Vector3D &getPosition);

protected:
    UGameEngine* _engine;

    QWidget* _widget;

    Vector3D _direction;

    Vector3D _position;
};

#endif // ABSTRACTCAMERA_H
