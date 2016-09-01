#include "renderwidget.h"
#include <QTimer>
#include <math.h>
#include <QDebug>

RenderWidget::RenderWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
  , angle(0)
  , _radius(5.0)
  , _phi(45)
  , _theta(45)
{
    _device = new OpenGLRenderDevice(this);
    _engine = new UGameEngine(_device);
    setMouseTracking(false);
}

void RenderWidget::initializeGL()
{
    makeCurrent();
    _device->setClearColor(Qt::gray);
    _device->initialize(70, width(), height());

}

void RenderWidget::paintGL()
{
    float theta = _theta / 180.0 * M_PI;
    float phi = _phi / 180.0 * M_PI;
    _device->lookAt(Vector3D(
                        _radius * sin(theta) * sin(phi),
                        _radius * cos(theta),
                        _radius * sin(theta) * cos(phi)
                        ),
                   Vector3D(0.0f, 0.0f, 0.0f));
    _engine->draw();

    drawAxes();
}

void RenderWidget::resizeGL(int width, int height)
{
    _device->resize(width, height);
}

void RenderWidget::mousePressEvent(QMouseEvent *event)
{
    _lastPoint = event->pos();
}

void RenderWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint diff = event->pos() - _lastPoint;

    _phi -= diff.x();
    _theta -= diff.y();

    qDebug() << _phi << _theta;

    _lastPoint = event->pos();
    update();
}

void RenderWidget::wheelEvent(QWheelEvent *event)
{
    _radius = qMax(2.0, _radius - event->delta() / 20.0);
    update();
}

void RenderWidget::drawAxes()
{
    _device->drawLine(ColorVector3D(Qt::red, 0.0, 0.0, 0.0), ColorVector3D(Qt::red, 1.0, 0.0, 0.0), 2.5);
    _device->drawLine(ColorVector3D(Qt::green, 0.0, 0.0, 0.0), ColorVector3D(Qt::green, 0.0, 1.0, 0.0), 2.5);
    _device->drawLine(ColorVector3D(Qt::blue, 0.0, 0.0, 0.0), ColorVector3D(Qt::blue, 0.0, 0.0, 1.0), 2.5);

    _device->drawPolygon(QList<ColorVector3D>() << ColorVector3D(Qt::red, 0, 0, 0) << ColorVector3D(Qt::green, 1, 0, 0) << ColorVector3D(Qt::transparent, 1, 1, 0) << ColorVector3D(Qt::blue, 0, 1, 0));

}
