#include "rotationcamera.h"
#include "utils/tools.h"

RotationCamera::RotationCamera(UGameEngine* engine, QWidget* widget, double radius, double phi, double theta)
    : AbstractCamera(engine, widget)
    , _radius(radius)
    , _phi(phi)
    , _theta(theta)
{
}

void RotationCamera::mousePressEvent(QMouseEvent *event)
{
    _lastPoint = event->pos();
}

void RotationCamera::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - _lastPoint;

        rotate(-diff.x(), -diff.y());

        _lastPoint = event->pos();
    }
}

void RotationCamera::wheelEvent(QWheelEvent *event)
{
    _radius = qMax(2.0, _radius - event->delta() / 30.0);
}

void RotationCamera::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up) {
        rotate(0.0, 1.0);
    }
    else if (event->key() == Qt::Key_Down) {
        rotate(0.0, -1.0);
    }
    else if (event->key() == Qt::Key_Left) {
        rotate(1.0, 0.0);
    }
    else if (event->key() == Qt::Key_Right) {
        rotate(-1.0, 0.0);
    }
}

void RotationCamera::updateLookAt()
{
    float theta = fabs(_theta / 180.0 * M_PI);
    float phi = _phi / 180.0 * M_PI;
    _position = Vector3D(
                _radius * sin(theta) * sin(phi),
                _radius * cos(theta),
                _radius * sin(theta) * cos(phi)
                );
    _direction = -_position;
    _engine->lookAt(_position, Vector3D(0.0f, 0.0f, 0.0f));
}

void RotationCamera::rotate(float phi, float theta)
{
    _phi = Tools::normalizeAngle(_phi + phi);
    if (_theta + theta >= 180.0) {
        theta = 179.0;
    }
    else if (_theta + theta < 1.0) {
        theta = 1.0;
    }
    else {
        _theta = Tools::normalizeAngle(_theta + theta);
    }
}
