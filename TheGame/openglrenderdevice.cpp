#include "openglrenderdevice.h"
#include "GL/gl.h"
#include "GL/glu.h"

OpenGLRenderDevice::OpenGLRenderDevice(QObject *parent)
    : AbstractRenderDevice(parent)
    , _width(0)
    , _height(0)
    , _fov(0)
{
}

Vector3D OpenGLRenderDevice::get2DFrom3D(const Vector3D &pos)
{
    double gx, gy, gz;
    double modelMatrix[16];
    double projMatrix[16];
    GLint viewport[4];
    glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);
    glGetIntegerv(GL_VIEWPORT, viewport);

     gluProject(pos.getX(), pos.getY(), pos.getZ(), modelMatrix, projMatrix, viewport, &gx, &gy, &gz);
     return Vector3D(gx, gy, gz);
}

Vector3D OpenGLRenderDevice::get3DFrom2D(int x, int y)
{
    double gx, gy, gz;
    double modelMatrix[16];
    double projMatrix[16];
    GLint viewport[4];
    glGetDoublev(GL_MODELVIEW_MATRIX, modelMatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);
    glGetIntegerv(GL_VIEWPORT, viewport);

    gluUnProject(x, y, 1, modelMatrix, projMatrix, viewport, &gx, &gy, &gz);
    return Vector3D(gx, gy, gz);
}

void OpenGLRenderDevice::initialize(int fov, int width, int height)
{
    _fov = fov;
    _width = width;
    _height = height;
    glClearColor(_clearColor.redF(), _clearColor.greenF(),
                 _clearColor.blue(), _clearColor.alpha());

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(_fov, _width / _height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void OpenGLRenderDevice::resize(int width, int height)
{
    _width = width;
    _height = height;
    int side = qMin(_width, _height);
    glViewport((_width - side) / 2, (_height - side) / 2, side, side);
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
