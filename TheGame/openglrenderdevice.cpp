#include "openglrenderdevice.h"
#include "GL/gl.h"
#include "GL/glu.h"

OpenGLRenderDevice::OpenGLRenderDevice(QObject *parent) :
    AbstractRenderDevice(parent)
{
}

void OpenGLRenderDevice::initialize(int fov, int width, int height)
{
    glClearColor(_clearColor.redF(), _clearColor.greenF(),
                 _clearColor.blue(), _clearColor.alpha());

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(fov, width / height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void OpenGLRenderDevice::resize(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);
}

void OpenGLRenderDevice::preDraw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(_lookEye.getX(), _lookEye.getY(), _lookEye.getZ(),
               _lookCenter.getX(), _lookCenter.getY(), _lookCenter.getZ(),
               _lookUp.getX(), _lookUp.getY(), _lookUp.getZ());
}

void OpenGLRenderDevice::postDraw()
{

}

void OpenGLRenderDevice::drawVertex(const ColorVector3D &point)
{
    glColor4f(point.getColor().redF(), point.getColor().greenF(),
                  point.getColor().blue(), point.getColor().alpha());
    glVertex3d(point.getX(), point.getY(), point.getZ());
}

void OpenGLRenderDevice::drawPoint(const ColorVector3D &point)
{
    glBegin(GL_POINTS);
    drawVertex(point);
    glEnd();
}

void OpenGLRenderDevice::drawLine(const ColorVector3D &begin, const ColorVector3D &end, double width)
{
    glLineWidth(width);
    glBegin(GL_LINES);
    drawVertex(begin);
    drawVertex(end);
    glEnd();
}

void OpenGLRenderDevice::drawPolygon(const QList<ColorVector3D> &points)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < points.size(); ++i) {
        drawVertex(points[i]);
    }
    glEnd();
}
