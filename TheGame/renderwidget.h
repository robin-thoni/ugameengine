#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>
#include "engine/ugameengine.h"
#include "openglrenderdevice.h"
#include "cameras/abstractcamera.h"

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
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);
    void wheelEvent(QWheelEvent* event);
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);

signals:

public slots:
    void animate();

private:
    UGameEngine* _engine;

    Vector3D pos;

    QList<UGEEntity*> _entities;

    AbstractCamera* _camera;
};

#endif // RENDERWIDGET_H
