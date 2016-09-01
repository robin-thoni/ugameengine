#include "openglrenderdevice.h"
#include "GL/gl.h"
#include "GL/glu.h"

OpenGLRenderDevice::OpenGLRenderDevice(QObject *parent) :
    AbstractRenderDevice(parent)
{
}

void OpenGLRenderDevice::initialize(int fov, int width, int height)
{
    glClearColor((GLfloat)_clearColor.red() / 255.0, (GLfloat)_clearColor.green() / 255.0,
                      (GLfloat)_clearColor.blue() / 255.0, (GLfloat) _clearColor.alpha() / 255.0);

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_MULTISAMPLE);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(fov, width/height, 0.1, 100.0);
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
