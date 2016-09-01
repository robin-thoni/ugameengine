#ifndef OPENGLRENDERDEVICE_H
#define OPENGLRENDERDEVICE_H

#include "abstractrenderdevice.h"

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

};

#endif // OPENGLRENDERDEVICE_H
