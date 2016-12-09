#ifndef UGEENTITYAXES_H
#define UGEENTITYAXES_H

#include "entities/ugeentity.h"

class UGEEntityAxes : public UGEEntity
{
    Q_OBJECT
public:
    explicit UGEEntityAxes(QObject *parent = 0);

    virtual void onDraw(AbstractRenderDevice* device);

    virtual Vector3D getVectorNearestIntesection(const Vector3D &vector, const Vector3D &pos, bool* ok);

signals:

public slots:

};

#endif // UGEENTITYAXES_H
