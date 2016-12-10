#include "abstractcamera.h"

AbstractCamera::AbstractCamera(UGameEngine* engine, QWidget* widget)
    : _engine(engine)
    , _widget(widget)
{
}

void AbstractCamera::mousePressEvent(QMouseEvent* event)
{
    (void) event;
}

void AbstractCamera::mouseReleaseEvent(QMouseEvent *event)
{
    (void) event;
}

void AbstractCamera::mouseMoveEvent(QMouseEvent* event)
{
    (void) event;
}

void AbstractCamera::mouseDoubleClickEvent(QMouseEvent* event)
{
    (void) event;
}

void AbstractCamera::wheelEvent(QWheelEvent* event)
{
    (void) event;
}

void AbstractCamera::keyPressEvent(QKeyEvent* event)
{
    (void) event;
}

void AbstractCamera::keyReleaseEvent(QKeyEvent* event)
{
    (void) event;
}
Vector3D AbstractCamera::getDirection() const
{
    return _direction;
}

void AbstractCamera::setDirection(const Vector3D &direction)
{
    _direction = direction;
}
Vector3D AbstractCamera::getPosition() const
{
    return _position;
}

void AbstractCamera::setPosition(const Vector3D &position)
{
    _position = position;
}



