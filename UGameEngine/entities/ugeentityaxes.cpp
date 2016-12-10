#include "ugeentityaxes.h"

UGEEntityAxes::UGEEntityAxes(UGameEngine *engine, QObject *parent) :
    UGEEntity(engine, parent)
{
    init();
}

UGEEntityAxes::UGEEntityAxes(UGameEngine *engine) :
    UGEEntity(engine)
{
    init();
}

void UGEEntityAxes::onDraw(AbstractRenderDevice *device)
{
    drawLine(device, ColorVector3D(Qt::red, 0.0, 0.0, 0.0), ColorVector3D(Qt::red, _size, 0.0, 0.0), 2.5);
    drawLine(device, ColorVector3D(Qt::green, 0.0, 0.0, 0.0), ColorVector3D(Qt::green, 0.0, _size, 0.0), 2.5);
    drawLine(device, ColorVector3D(Qt::blue, 0.0, 0.0, 0.0), ColorVector3D(Qt::blue, 0.0, 0.0, _size), 2.5);
}

Vector3D UGEEntityAxes::getVectorNearestIntesection(const Vector3D &vector, const Vector3D &pos, bool *ok)
{
    *ok = false;
    return Vector3D();
}
double UGEEntityAxes::size() const
{
    return _size;
}

void UGEEntityAxes::setSize(double size)
{
    _size = size;
}

void UGEEntityAxes::init()
{
    _size = 1.0;
}

