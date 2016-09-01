#include "renderwidget.h"
#include <QTimer>
#include <math.h>

RenderWidget::RenderWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
  , angle(0)
{
    _device = new OpenGLRenderDevice(this);
    _engine = new UGameEngine(_device);
}

void RenderWidget::initializeGL()
{
    makeCurrent();
    _device->setClearColor(Qt::gray);
    _device->initialize(70, width(), height());

    animate();
}

void RenderWidget::paintGL()
{
    float rad = (float)angle / 180.0 * M_PI;
    float radius = 5.0f;
    _device->lookAt(Vector3D(radius * cos(rad), 5.0f, radius * sin(rad)),
                   Vector3D(0.0f, 0.0f, 0.0f));
    _engine->draw();
//    device->preDraw();





    drawAxes();

//    device->postDraw();
}

void RenderWidget::resizeGL(int width, int height)
{
    _device->resize(width, height);
}

void RenderWidget::animate()
{
    angle = (angle + 3) % 360;
    update();
    QTimer::singleShot(50, this, SLOT(animate()));
}

void RenderWidget::drawAxes()
{
    glLineWidth(2.5);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(1.0, 0.0, 0.0);
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 1.0);
    glEnd();
}
