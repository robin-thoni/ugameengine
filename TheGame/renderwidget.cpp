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
#include "gamecube.h"

RenderWidget::RenderWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    setMouseTracking(true);
    setFocusPolicy(Qt::StrongFocus);
    setAutoFillBackground(false);
    setAutoBufferSwap(false);
    #ifdef __APPLE__
    _assetsPath = "../../../assets/";
    #else
    _assetsPath = "./assets/";
    #endif

    _engine = new UGameEngine(new OpenGLRenderDevice(this));
    _camera = new FreeFlyCamera(_engine, this);

    //_engine->addEntity(new UGEEntityAxes(_engine));

//    for (int i = 0; i < 1; ++i) {
//        UGEEntityCube* cube = new GameCube(_engine);
//        cube->setTextureId("rubiks");
////        cube->rotate(Vector3D(0.0, 45.0, 45.0));
//        cube->move(Vector3D(0, i, i));
////        cube->setScale(Vector3D(1.0, 2.0, 1.0));
//        _engine->addEntity(cube);
//        _entities.append(cube);
//    }

    for(int i = 0,j = 0; i * j< 626;){
        UGEEntityCube* cube = new GameCube(_engine);
        cube->setTextureId("rubiks");
        cube->move(Vector3D(i, 0, j++));
        _engine->addEntity(cube);
        _entities.append(cube);
        if(j == 26){
            j = 0;
            i++;
        }
    }

    WaveFrontObj* wavefrontObj = new WaveFrontObj(this);
    wavefrontObj->openFile(_assetsPath + "objs/enterprise/USSEnterprise.obj");
    UGEEntityWaveFrontObj* obj = new UGEEntityWaveFrontObj(wavefrontObj, this);
    obj->hide();
    _engine->addEntity(obj);
    _entities.append(obj);
    animate();
}

void RenderWidget::initializeGL()
{
    makeCurrent();
    _engine->setClearColor(Qt::gray);
    _engine->initialize(70, width(), height());

    _engine->loadTextureFromFile("rubiks", _assetsPath + "textures/rubiks.png");
}

void RenderWidget::paintGL()
{
    _camera->updateLookAt();
    _engine->draw();
}

void RenderWidget::resizeGL(int width, int height)
{
    _engine->resize(width, height);
}

void RenderWidget::mousePressEvent(QMouseEvent *event)
{
    _camera->mousePressEvent(event);
    if (event->buttons() & Qt::LeftButton) {
//        Vector3D pos = _engine->get3DFrom2D(Vector2D(event->x(), height() - event->y()));
        Vector3D pos = _camera->getPosition();
        qDebug() << pos.getX() << pos.getY() << pos.getZ();
        Vector3D bestp;
        bool ok = false;
        for (int i = 0; i < _engine->getEntities().size(); i++) {
            UGEEntity* entity = _engine->getEntities()[i];
            bool provi;
            Vector3D collision = entity->getVectorNearestIntesection(_camera->getDirection(), pos, &provi);
            if (provi && (!ok || (pos - bestp).norm() > (pos - collision).norm())) {
                bestp = collision;
                UGEEntityAxes* axe = new UGEEntityAxes(_engine);
                axe->move(bestp);
                _engine->addEntity(axe);
                ok = true;
            }
        }
    }
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

void RenderWidget::paintEvent(QPaintEvent *event)
{
    QGLWidget::paintEvent(event);
    int r = 20;
    QPainter p;
    p.begin(this);
    QPoint c(width() / 2, height() / 2);
    p.drawLine(c.x() - r, c.y(), c.x() + r, c.y());
    p.drawLine(c.x(), c.y() - r, c.x(), c.y() + r);
    p.end();
    swapBuffers();
}

void RenderWidget::animate()
{
//    for (int i = 0; i < _entities.size(); ++i) {
//        _entities[i]->rotate(Vector3D(0.0, 2.0, 2.0));
//    }
    QTimer::singleShot(20, this, SLOT(animate()));
    update();
}
