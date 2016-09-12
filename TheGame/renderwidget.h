#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include "engine/ugameengine.h"
#include "openglrenderdevice.h"

class RenderWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit RenderWidget(QWidget *parent = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    float normalizeAngle(float angle);

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void keyPressEvent(QKeyEvent* event);

    void rotate(float phi, float theta);

signals:

public slots:
    void animate();

private:
    AbstractRenderDevice* _device;

    UGameEngine* _engine;

    QPoint _lastPoint;

    double _radius;

    double _phi;

    double _theta;

    Vector3D pos;

    double _angle;

    UGEEntity* _entity;
};

#endif // RENDERWIDGET_H
