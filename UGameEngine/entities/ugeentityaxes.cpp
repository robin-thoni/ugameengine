#include "ugeentityaxes.h"

UGEEntityAxes::UGEEntityAxes(QObject *parent) :
    UGEEntity(parent)
{
}

void UGEEntityAxes::draw(AbstractRenderDevice *device)
{
    drawLine(device, ColorVector3D(Qt::red, 0.0, 0.0, 0.0), ColorVector3D(Qt::red, 1.0, 0.0, 0.0), 2.5);
    drawLine(device, ColorVector3D(Qt::green, 0.0, 0.0, 0.0), ColorVector3D(Qt::green, 0.0, 1.0, 0.0), 2.5);
    drawLine(device, ColorVector3D(Qt::blue, 0.0, 0.0, 0.0), ColorVector3D(Qt::blue, 0.0, 0.0, 1.0), 2.5);
}
