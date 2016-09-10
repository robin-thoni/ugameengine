#include "renderwidget.h"
#include <QTimer>
#include <math.h>
#include <QDebug>
#include "entities/ugeentitycube.h"
#include "entities/ugeentityaxes.h"
#include "utils/wavefrontobj.h"
#include "entities/ugeentitywavefrontobj.h"

RenderWidget::RenderWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
  , _radius(5.0)
  , _phi(45)
  , _theta(45)
{
    _device = new OpenGLRenderDevice(this);
    _engine = new UGameEngine(_device);
    UGEEntityCube* cube = new UGEEntityCube(_engine);
//    cube->move(Vector3D(0, 1, 0));
    cube->hide();
    _engine->addEntity(cube);
    _engine->addEntity(new UGEEntityAxes(_engine));
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);

    WaveFrontObj* wavefrontObj = new WaveFrontObj(this);
    wavefrontObj->openFile("/home/robin/Downloads/enterprise/obj/USSEnterprise.obj");

    UGEEntityWaveFrontObj* obj = new UGEEntityWaveFrontObj(wavefrontObj, this);
    _engine->addEntity(obj);
//    obj->hide();

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
    _device->drawLine(ColorVector3D(Qt::black, 0, 0, 0), ColorVector3D(Qt::black, pos));
    _device->drawPoint(ColorVector3D(Qt::magenta, 0.5, 0.5, 0.5));
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
    if (event->buttons() & Qt::LeftButton) {
        QPoint diff = event->pos() - _lastPoint;

        rotate(-diff.x(), -diff.y());

        _lastPoint = event->pos();
    }

    Vector3D dd = _device->get2DFrom3D(Vector3D(0.5, 0.5, 0.5));
    dd.setY(height() - dd.getY());
//    qDebug() << event->pos() << dd;
    pos = _device->get3DFrom2D(event->x(), height() - event->y());

    update();
}

void RenderWidget::wheelEvent(QWheelEvent *event)
{
    _radius = qMax(2.0, _radius - event->delta() / 30.0);
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
