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
//        _entities.append(cube);
//    }


//    int xmax = 25;
//    int zmax = 25;
    int xmax = 1;
    int zmax = 1;
    for (int x = 0; x < xmax; ++x) {
        for (int z = 0; z < zmax; ++z) {
            UGEEntityCube* cube = new UGEEntityCube(_engine);
            cube->setTextureId("rubiks");
            cube->move(Vector3D(x - (xmax / 2), 0, z - (zmax / 2)));
        }
    }

    WaveFrontObj* wavefrontObj = new WaveFrontObj(this);
    wavefrontObj->openFile(_assetsPath + "objs/enterprise/USSEnterprise.obj");
    UGEEntityWaveFrontObj* obj = new UGEEntityWaveFrontObj(wavefrontObj, _engine);
    obj->hide();
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
    bool left = event->buttons() & Qt::LeftButton;
    bool right = event->buttons() & Qt::RightButton;
    if (left || right) {
        Vector3D bestp;
        UGEEntity* entity = _engine->getVectorNearestIntesection(_camera->getDirection(), _camera->getPosition(), &bestp);
        if (entity) {
//            UGEEntity* axe = new UGEEntityAxes(_engine);
//            axe->move(bestp);
            if (right) {
                entity->deleteLater();
            }
            else if (left) {
                Vector3D pos = entity->getPosition();
                Vector3D diff = pos - bestp;
                if (fmod(fabs(diff.getX()), 0.5) == 0) {
                    pos.add(Vector3D(1 * (diff.getX() < 0 ? 1 : -1), 0, 0));
                }
                else if (fmod(fabs(diff.getY()), 0.5) == 0) {
                    pos.add(Vector3D(0, 1 * (diff.getY() < 0 ? 1 : -1), 0));
                }
                else if (fmod(fabs(diff.getZ()), 0.5) == 0) {
                    pos.add(Vector3D(0, 0, 1 * (diff.getZ() < 0 ? 1 : -1)));
                }
                UGEEntityCube* cube = new UGEEntityCube(_engine);
                cube->move(pos);
                cube->setTextureId("rubiks");
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
