#include "renderwidget.h"
#include <GL/glu.h>
#include <QTimer>
#include <math.h>

RenderWidget::RenderWidget(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
  , angle(0)
  , _fov(70)
{
}

void RenderWidget::initializeGL()
{
    makeCurrent();
    qglClearColor(Qt::gray);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(_fov, width()/height(), 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
    animate();
}

void RenderWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    float rad = (float)angle / 180.0 * M_PI;
    float radius = 5.0f;

    gluLookAt(radius * cos(rad), 5.0f, radius * sin(rad),
               0.0f, 0.0f, 0.0f,
               0.0f, 1.0f, 0.0f);

    drawAxes();
}

void RenderWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
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
