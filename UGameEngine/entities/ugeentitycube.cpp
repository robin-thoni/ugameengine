#include "ugeentitycube.h"

UGEEntityCube::UGEEntityCube(QObject *parent)
    : UGEEntity(parent)
    , _size(1.0)
{
}

float UGEEntityCube::getSize() const
{
    return _size;
}

void UGEEntityCube::draw(AbstractRenderDevice *device)
{
    QColor color = Qt::red;
    float r = _size / 2;
    QList<ColorVector3D> points;
    points << ColorVector3D(color, -r, -r, r) << ColorVector3D(color, -r, r, r) << ColorVector3D(color, r, r, r) << ColorVector3D(color, r, -r, r);
    points << ColorVector3D(color, -r, -r, -r) << ColorVector3D(color, -r, r, -r) << ColorVector3D(color, r, r, -r) << ColorVector3D(color, r, -r, -r);
    drawPolygon(device, QList<ColorVector3D>() << points[3] << points[2] << points[1] << points[0]);
    drawPolygon(device, QList<ColorVector3D>() << points[2] << points[3] << points[7] << points[6]);
    drawPolygon(device, QList<ColorVector3D>() << points[6] << points[7] << points[4] << points[5]);
    drawPolygon(device, QList<ColorVector3D>() << points[5] << points[4] << points[0] << points[1]);
    drawPolygon(device, QList<ColorVector3D>() << points[1] << points[2] << points[6] << points[5]);
    drawPolygon(device, QList<ColorVector3D>() << points[4] << points[7] << points[3] << points[0]);
}

void UGEEntityCube::setSize(float size)
{
    _size = size;
}

