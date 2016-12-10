#include "ugeentitywavefrontobj.h"

UGEEntityWaveFrontObj::UGEEntityWaveFrontObj(WaveFrontObj *obj, UGameEngine *engine, QObject *parent)
    : UGEEntity(engine, parent)
    , _obj(obj)
{

}

UGEEntityWaveFrontObj::UGEEntityWaveFrontObj(WaveFrontObj *obj, UGameEngine *engine)
    : UGEEntity(engine)
    , _obj(obj)
{

}

void UGEEntityWaveFrontObj::onDraw(AbstractRenderDevice *device)
{
    QList<QList<WaveFrontObjFaceVertex> > faces = _obj->getFaces();
    QList<Vector3D> vertexes = _obj->getVertexes();
    for (int i = 0; i < faces.size(); ++i) {
        QList<WaveFrontObjFaceVertex> face = faces[i];
        QList<ColorVector3D> poly;
        for (int j = 0; j < face.size(); ++j) {
            poly.append(ColorVector3D(Qt::black, vertexes[face[j].vertexPosition - 1]));
        }
        drawPolygon(device, poly);
    }
}

Vector3D UGEEntityWaveFrontObj::getVectorNearestIntesection(const Vector3D &vector, const Vector3D &pos, bool *ok)
{
    *ok = false;
    return Vector3D();
}
