#ifndef ABSTRACTRENDERDEVICE_H
#define ABSTRACTRENDERDEVICE_H

#include <QObject>
#include <QColor>
#include "vector3d.h"

class AbstractRenderDevice : public QObject
{
    Q_OBJECT
public:
    explicit AbstractRenderDevice(QObject *parent = 0);

    virtual ~AbstractRenderDevice();

    QColor getCurrentColor() const;

    Vector3D getLookEye() const;

    Vector3D getLookCenter() const;

    Vector3D getLookUp() const;

    QColor getClearColor() const;

public slots:
    virtual void setClearColor(const QColor &getClearColor);

    virtual void setCurrentColor(const QColor &color);

    virtual void lookAt(const Vector3D& eye, const Vector3D& center, const Vector3D& up = Vector3D(0.0, 1.0, 0.0));

    virtual void initialize(int fov, int width, int height) = 0;

    virtual void resize(int width, int height) = 0;

    virtual void preDraw() = 0;

    virtual void postDraw() = 0;

protected:
    QColor _clearColor;

    QColor _currentColor;

    Vector3D _lookEye;

    Vector3D _lookCenter;

    Vector3D _lookUp;
};

#endif // ABSTRACTRENDERDEVICE_H
