#ifndef ROTATIONCAMERA_H
#define ROTATIONCAMERA_H

#include "abstractcamera.h"

class RotationCamera : public AbstractCamera
{
public:
    RotationCamera(UGameEngine* engine, QWidget *widget, double radius, double phi, double theta);

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);

    virtual void wheelEvent(QWheelEvent* event);

    virtual void keyPressEvent(QKeyEvent* event);

    virtual void updateLookAt();

    void rotate(float phi, float theta);

private:
    double _radius;

    double _phi;

    double _theta;

    QPoint _lastPoint;
};

#endif // ROTATIONCAMERA_H
