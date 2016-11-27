#include "renderwidget.h"
#include <QTimer>
#include <math.h>
#include <QDebug>
#include "entities/ugeentitycube.h"
#include "entities/ugeentityaxes.h"
#include "utils/wavefrontobj.h"
#include "entities/ugeentitywavefrontobj.h"
#include "cameras/rotationcamera.h"
#include "cameras/freeflycamera.h"

RenderWidget::RenderWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);

    _engine = new UGameEngine(new OpenGLRenderDevice(this));
    _camera = new FreeFlyCamera(_engine, this);

    _engine->addEntity(new UGEEntityAxes(_engine));

    for (int i = 0; i < 1000; ++i) {
        UGEEntityCube* cube = new UGEEntityCube(_engine);
        cube->setTextureId("test");
        cube->rotate(Vector3D(0.0, 45.0, 45.0));
        cube->move(Vector3D(0, i, i));
//        cube->setScale(Vector3D(1.0, 2.0, 1.0));
        _engine->addEntity(cube);
        _entities.append(cube);
    }

    WaveFrontObj* wavefrontObj = new WaveFrontObj(this);
    wavefrontObj->openFile("/home/robin/Downloads/enterprise/obj/USSEnterprise.obj");
    UGEEntityWaveFrontObj* obj = new UGEEntityWaveFrontObj(wavefrontObj, this);
    _engine->addEntity(obj);
    _entities.append(obj);
    animate();
}

void RenderWidget::initializeGL()
{
    makeCurrent();
    _engine->setClearColor(Qt::gray);
    _engine->initialize(70, width(), height());

    _engine->loadTextureFromFile("test", "/home/robin/Downloads/test.png");
}

void RenderWidget::paintGL()
{
    _camera->updateLookAt();
    _engine->draw();
//    _device->drawLine(ColorVector3D(Qt::black, 0, 0, 0), ColorVector3D(Qt::black, pos));
//    _device->drawPoint(ColorVector3D(Qt::magenta, 0.5, 0.5, 0.5));
}

void RenderWidget::resizeGL(int width, int height)
{
    _engine->resize(width, height);
}

void RenderWidget::mousePressEvent(QMouseEvent *event)
{
    _camera->mousePressEvent(event);
}

void RenderWidget::mouseReleaseEvent(QMouseEvent *event)
{
    _camera->mouseReleaseEvent(event);
}

void RenderWidget::mouseMoveEvent(QMouseEvent *event)
{
    _camera->mouseMoveEvent(event);

//    Vector3D dd = _device->get2DFrom3D(Vector3D(0.5, 0.5, 0.5));
//    dd.setY(height() - dd.getY());
//    qDebug() << event->pos() << dd;
//    pos = _device->get3DFrom2D(event->x(), height() - event->y());

}

void RenderWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    _camera->mouseDoubleClickEvent(event);
}

void RenderWidget::wheelEvent(QWheelEvent *event)
{
    _camera->wheelEvent(event);
}

void RenderWidget::keyPressEvent(QKeyEvent *event)
{
    _camera->keyPressEvent(event);
}

void RenderWidget::keyReleaseEvent(QKeyEvent *event)
{
    _camera->keyReleaseEvent(event);
}

void RenderWidget::animate()
{
    for (int i = 0; i < _entities.size(); ++i) {
        _entities[i]->rotate(Vector3D(0.0, 2.0, 2.0));
    }
    QTimer::singleShot(20, this, SLOT(animate()));
    update();
}
