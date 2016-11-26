#include "freeflycamera.h"
#include <QCursor>
#include "utils/tools.h"

FreeFlyCamera::FreeFlyCamera(UGameEngine *engine, QWidget* widget)
    : AbstractCamera(engine, widget)
    , _speed(0.2)
    , _phi(45)
    , _theta(45)
{
    _widget->setCursor(Qt::BlankCursor);
    _lastPoint = QPoint(_widget->width()/2,_widget->height()/2);
    rotate(0, 0);
}

void FreeFlyCamera::mouseMoveEvent(QMouseEvent *event)
{
    QPoint diff = (event->pos() - _lastPoint) / 2;

    rotate(-diff.x(), diff.y());

    QPoint glob = _widget->mapToGlobal(QPoint(_widget->width()/2,_widget->height()/2));
    QCursor::setPos(glob);
    _lastPoint = QPoint(_widget->width()/2,_widget->height()/2);
}

void FreeFlyCamera::keyPressEvent(QKeyEvent *event)
{
    if (event->isAutoRepeat()) {
        return;
    }
    if (event->key() == Qt::Key_Z) {
        _speedVector.setX(1);
    }
    else if (event->key() == Qt::Key_S) {
        _speedVector.setX(-1);
    }
    else if (event->key() == Qt::Key_Q) {
        _speedVector.setY(1);
    }
    else if (event->key() == Qt::Key_D) {
        _speedVector.setY(-1);
    }
}

void FreeFlyCamera::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Z || event->key() == Qt::Key_S) {
        _speedVector.setX(0);
    }
    else if (event->key() == Qt::Key_Q || event->key() == Qt::Key_D) {
        _speedVector.setY(0);
    }
}

void FreeFlyCamera::updateLookAt()
{
    Vector3D perp(_direction.getZ(), 0, -_direction.getX());
    perp /= perp.norm();
    _position += Vector3D(_direction * _speedVector.getX()).mult(_speed);
    _position += Vector3D(perp * _speedVector.getY()).mult(_speed);
    _engine->lookAt(_position, _direction + _position);
}

void FreeFlyCamera::rotate(float phi, float theta)
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
    float thetaRad = fabs(_theta / 180.0 * M_PI);
    float phiRad = _phi / 180.0 * M_PI;
    _direction = Vector3D(
                sin(thetaRad) * sin(phiRad),
                cos(thetaRad),
                sin(thetaRad) * cos(phiRad)
                );
}
