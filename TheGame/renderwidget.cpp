#include "renderwidget.h"
#include <QTimer>
#include <math.h>
#include <QDebug>
#include <QDir>
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
    _camera->setPosition(Vector3D(0, 1.5, 0));

    //_engine->addEntity(new UGEEntityAxes(_engine));

//    for (int i = 0; i < 1; ++i) {
//        UGEEntityCube* cube = new GameCube(_engine);
//        cube->setTextureId("rubiks");
////        cube->rotate(Vector3D(0.0, 45.0, 45.0));
//        cube->move(Vector3D(0, i, i));
////        cube->setScale(Vector3D(1.0, 2.0, 1.0));
//        _entities.append(cube);
//    }


    int xmax = 25;
    int zmax = 25;
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
    obj->move(Vector3D(0, 15, 0));

    UGEEntityCube* cube = new UGEEntityCube(_engine);
    cube->move(Vector3D(5, 17, 5));
    cube->setTextureId("dice");
    _entities.append(cube);
    cube = new UGEEntityCube(_engine);
    cube->move(Vector3D(-5, 17, 5));
    cube->setTextureId("dice");
    _entities.append(cube);
    cube = new UGEEntityCube(_engine);
    cube->move(Vector3D(-5, 17, -5));
    cube->setTextureId("dice");
    _entities.append(cube);
    cube = new UGEEntityCube(_engine);
    cube->move(Vector3D(5, 17, -5));
    cube->setTextureId("dice");
    _entities.append(cube);

    animate();
}

void RenderWidget::initializeGL()
{
    srand(time(0));
    makeCurrent();
    _engine->setClearColor(Qt::gray);
    _engine->initialize(70, width(), height());

    _textures.clear();
    QDir texturesDir(_assetsPath + "textures");
    QFileInfoList files = texturesDir.entryInfoList(QStringList() << "*.png" << "*.jpg" << "*.jpeg");
    for (int i = 0; i < files.size(); ++i)
    {
        QFileInfo file = files[i];

        _engine->loadTextureFromFile(file.baseName(), file.absoluteFilePath());
        _textures.append(file.baseName());
    }
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
            for (int i = 0; i < _entities.size(); ++i) {
                if (_entities[i] == entity) {
                    return;
                }
            }
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

                QList<UGEEntity*> entities = _engine->getEntities();
                for (int i = 0; i < entities.size(); ++i) {
                    UGEEntity* e = entities[i];
                    if (e->getPosition() == pos) {
                        return;
                    }
                }

                int x = (rand() >= RAND_MAX / 2 ? 90 : 0) * (rand() >= RAND_MAX / 2 ? -1 : 1);
                int y = (rand() >= RAND_MAX / 2 ? 90 : 0) * (rand() >= RAND_MAX / 2 ? -1 : 1);
                int z = (rand() >= RAND_MAX / 2 ? 90 : 0) * (rand() >= RAND_MAX / 2 ? -1 : 1);
                QString texture = _textures[rand() / (double)RAND_MAX * _textures.size()];


                UGEEntityCube* cube = new UGEEntityCube(_engine);
                cube->move(pos);
                cube->rotate(Vector3D(x, y, z));
                cube->setTextureId(texture);
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
    for (int i = 0; i < _entities.size(); ++i) {
        _entities[i]->rotate(Vector3D(0.0, 2.0, 2.0));
    }
    QTimer::singleShot(20, this, SLOT(animate()));
    update();
}
