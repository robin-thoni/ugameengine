#ifndef RENDERWIDGET_H
#define RENDERWIDGET_H

#include <QGLWidget>
#include "ugameengine.h"
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

signals:

public slots:
    void animate();

    void drawAxes();

private:
    OpenGLRenderDevice* _device;

    int angle;

    UGameEngine* _engine;

};

#endif // RENDERWIDGET_H
