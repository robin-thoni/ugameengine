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

