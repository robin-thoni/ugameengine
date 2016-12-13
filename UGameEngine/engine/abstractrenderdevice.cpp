#include "abstractrenderdevice.h"
#include <QImage>
#include <QDir>

AbstractRenderDevice::AbstractRenderDevice(QObject *parent) :
    QObject(parent)
{
}

AbstractRenderDevice::~AbstractRenderDevice()
{

}

QColor AbstractRenderDevice::getCurrentColor() const
{
    return _currentColor;
}

Vector3D AbstractRenderDevice::getLookEye() const
{
    return _lookEye;
}

Vector3D AbstractRenderDevice::getLookCenter() const
{
    return _lookCenter;
}

Vector3D AbstractRenderDevice::getLookUp() const
{
    return _lookUp;
}

void AbstractRenderDevice::setCurrentColor(const QColor &color)
{
    _currentColor = color;
}

void AbstractRenderDevice::lookAt(const Vector3D &eye, const Vector3D &center, const Vector3D &up)
{
    _lookEye = eye;
    _lookCenter = center;
    _lookUp = up;
}

void AbstractRenderDevice::loadTextureFromFile(const QVariant &id, const QString &filename)
{
    QImage img;
    if (img.load(filename)) {
        loadTexture(id, img);
    }
}

QColor AbstractRenderDevice::getClearColor() const
{
    return _clearColor;
}

void AbstractRenderDevice::setClearColor(const QColor &clearColor)
{
    _clearColor = clearColor;
}


