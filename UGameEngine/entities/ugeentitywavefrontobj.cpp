#include "ugeentitywavefrontobj.h"

UGEEntityWaveFrontObj::UGEEntityWaveFrontObj(WaveFrontObj *obj, QObject *parent)
    : UGEEntity(parent)
    , _obj(obj)
{
}

void UGEEntityWaveFrontObj::draw(AbstractRenderDevice *device)
{
    QList<QList<int> > faces = _obj->getFaces();
    QList<Vector3D> vertexes = _obj->getVertexes();
    for (int i = 0; i < faces.size(); ++i) {
        QList<int> face = faces[i];
        QList<ColorVector3D> poly;
        for (int j = 0; j < face.size(); ++j) {
            poly.append(ColorVector3D(Qt::black, vertexes[face[j] - 1]));
        }
        drawPolygon(device, poly);
    }
}
