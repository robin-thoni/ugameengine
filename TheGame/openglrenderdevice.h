#ifndef OPENGLRENDERDEVICE_H
#define OPENGLRENDERDEVICE_H

#include "engine/abstractrenderdevice.h"

class OpenGLRenderDevice : public AbstractRenderDevice
{
    Q_OBJECT
public:
    explicit OpenGLRenderDevice(QObject *parent = 0);

signals:

public slots:

    virtual void initialize(int fov, int width, int height);

    virtual void resize(int width, int height);

    virtual void preDraw();

    virtual void postDraw();

    virtual void drawVertex(const ColorVector3D& point);

    virtual void drawPoint(const ColorVector3D& point);

    virtual void drawLine(const ColorVector3D& begin, const ColorVector3D& end, double width = 1.0);

    virtual void drawPolygon(const QList<ColorVector3D>& points);

};

#endif // OPENGLRENDERDEVICE_H
