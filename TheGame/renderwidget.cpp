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
  , _reverse(false)
{
    _device = new OpenGLRenderDevice(this);
    _engine = new UGameEngine(_device);
    setMouseTracking(false);
    setFocusPolicy(Qt::StrongFocus);
}

void RenderWidget::initializeGL()
{
    makeCurrent();
    _device->setClearColor(Qt::gray);
    _device->initialize(70, width(), height());

}

void RenderWidget::paintGL()
{
    float theta = fabs(_theta / 180.0 * M_PI);
    float phi = _phi / 180.0 * M_PI;
    Vector3D center = Vector3D(
                _radius * sin(theta) * sin(phi),
                _radius * cos(theta),
                _radius * sin(theta) * cos(phi)
                );
    _device->lookAt(center, Vector3D(0.0f, 0.0f, 0.0f));
    _engine->draw();

    drawAxes();
}

void RenderWidget::resizeGL(int width, int height)
{
    _device->resize(width, height);
}

float RenderWidget::normalizeAngle(float angle)
{
    while (angle >= 360.0) {
        angle -= 360.0;
    }
    while (angle < 0.0) {
        angle += 360.0;
    }
    return angle;
}

void RenderWidget::mousePressEvent(QMouseEvent *event)
{
    _lastPoint = event->pos();
}

void RenderWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPoint diff = event->pos() - _lastPoint;

    rotate(-diff.x(), -diff.y());

    _lastPoint = event->pos();
}

void RenderWidget::wheelEvent(QWheelEvent *event)
{
    _radius = qMax(2.0, _radius - event->delta() / 20.0);
    update();
}

void RenderWidget::keyPressEvent(QKeyEvent *event)
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

void RenderWidget::rotate(float phi, float theta)
{
    _phi = normalizeAngle(_phi + phi);
    if (_theta + theta >= 180.0) {
        theta = 179.0;
    }
    else if (_theta + theta < 1.0) {
        theta = 1.0;
    }
    else {
        _theta = normalizeAngle(_theta + theta);
    }
    update();
}

void RenderWidget::drawAxes()
{
    _device->drawLine(ColorVector3D(Qt::red, 0.0, 0.0, 0.0), ColorVector3D(Qt::red, 1.0, 0.0, 0.0), 2.5);
    _device->drawLine(ColorVector3D(Qt::green, 0.0, 0.0, 0.0), ColorVector3D(Qt::green, 0.0, 1.0, 0.0), 2.5);
    _device->drawLine(ColorVector3D(Qt::blue, 0.0, 0.0, 0.0), ColorVector3D(Qt::blue, 0.0, 0.0, 1.0), 2.5);

    _device->drawPolygon(QList<ColorVector3D>() << ColorVector3D(Qt::red, 0, 0, 0) << ColorVector3D(Qt::green, 1, 0, 0) << ColorVector3D(Qt::transparent, 1, 1, 0) << ColorVector3D(Qt::blue, 0, 1, 0));

}
