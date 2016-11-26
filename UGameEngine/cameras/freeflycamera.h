#ifndef FREEFLYCAMERA_H
#define FREEFLYCAMERA_H

#include "cameras/abstractcamera.h"
#include "utils/vector3d.h"

class FreeFlyCamera : public AbstractCamera
{
public:
    FreeFlyCamera(UGameEngine* engine, QWidget *widget);

    virtual void mouseMoveEvent(QMouseEvent* event);

    virtual void keyPressEvent(QKeyEvent* event);
    virtual void keyReleaseEvent(QKeyEvent* event);

    virtual void updateLookAt();

    void rotate(float phi, float theta);

private:
    Vector3D _direction;

    Vector3D _position;

    Vector2D _speedVector;

    double _speed;

    double _phi;

    double _theta;

    QPoint _lastPoint;
};

#endif // FREEFLYCAMERA_H
