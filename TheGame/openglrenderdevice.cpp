#include "openglrenderdevice.h"
#include <QRgb>
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#endif

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

void OpenGLRenderDevice::loadTexture(const QVariant &id, const QImage &texture)
{
    OpenGLTextureData data;
    data.id = 0;
    data.image = texture;
    char rawData[texture.width() * texture.height() * 4];

    for (int y = 0; y < texture.height(); ++y) {
        for(int x = 0; x < texture.width(); ++x) {
            int p = (y * texture.height() * 4) + x * 4;
            QColor px = QColor(texture.pixel(x, y));
            rawData[p] = px.red();
            rawData[p + 1] = px.green();
            rawData[p + 2] = px.blue();
            rawData[p + 3] = 255;
        }
    }


    glGenTextures(1, &data.id);
    glBindTexture(GL_TEXTURE_2D, data.id);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.width(), texture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, rawData);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    _textures.insert(id, data);
}

void OpenGLRenderDevice::initialize(int fov, int width, int height)
{
    _fov = fov;
    _width = width;
    _height = height;

    glClearColor(_clearColor.redF(), _clearColor.greenF(),
                 _clearColor.blueF(), _clearColor.alphaF());

//    glShadeModel(GL_SMOOTH);
//    glBlendFunc (GL_SRC_ALPHA_SATURATE, GL_ONE);
//    glColorMaterial(GL_FRONT,GL_SPECULAR);
//    glCullFace(GL_BACK);

//    glEnable(GL_LIGHTING);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_CULL_FACE);
    glEnable(GL_TEXTURE_2D);

//    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


//    GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
//    GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, light_diffuse);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHTING);

    glEnable(GL_DEPTH_TEST);
//    glDisable(GL_BLEND);
//    glDisable(GL_POLYGON_SMOOTH);
//    glEnable(GL_TEXTURE_2D);
//    glColorMaterial(GL_FRONT,GL_SPECULAR);
//    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_CULL_FACE);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(_fov, _width / _height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void OpenGLRenderDevice::resize(int width, int height)
{
    _width = width;
    _height = height;
//    glViewport(0, 0, _width, _height);
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
//    GLfloat d[] = { point.getColor().redF(), point.getColor().greenF(), point.getColor().blueF(), point.getColor().alphaF() };
//    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, d);
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
//    Vector3D p1 = points[0];
//    Vector3D p2 = points[1];
//    Vector3D n = p1.crossProduct(p2);
//    Vector3D n2 = p2.crossProduct(p1);
//    qDebug() << n.getX() << n.getY() << n.getZ() << n2.getX() << n2.getY() << n2.getZ();
//    glNormal3d(n.getX(), n.getY(), n.getZ());
    for (int i = 0; i < points.size(); ++i) {
        drawVertex(points[i]);
    }
    glEnd();
}

void OpenGLRenderDevice::drawPolygonTexture(const QList<TextureVector3D> &points, const QVariant &textureId)
{
    const OpenGLTextureData& data = _textures[textureId];
    glBindTexture(GL_TEXTURE_2D, data.id);
    glBegin(GL_POLYGON);
    for (int i = 0; i < points.size(); ++i) {
        const TextureVector3D& p = points[i];
        const Vector2D& coord = p.getTextureCoord();
        glTexCoord2d(coord.getX(), coord.getY());
        drawVertex(p);
    }
    glEnd();
}
