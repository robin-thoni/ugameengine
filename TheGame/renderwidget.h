#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
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

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);

signals:

public slots:
    void drawAxes();

private:
    OpenGLRenderDevice* _device;

    int angle;

    UGameEngine* _engine;

    QPoint _lastPoint;

    float _radius;

    float _phi;

    float _theta;

};

#endif // RENDERWIDGET_H
