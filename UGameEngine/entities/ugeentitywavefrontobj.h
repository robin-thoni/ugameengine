#ifndef UGEENTITYWAVEFRONTOBJ_H
#define UGEENTITYWAVEFRONTOBJ_H

#include "ugeentity.h"
#include "utils/wavefrontobj.h"

class UGEEntityWaveFrontObj : public UGEEntity
{
    Q_OBJECT
public:
    explicit UGEEntityWaveFrontObj(WaveFrontObj* obj, QObject *parent = 0);

    virtual void onDraw(AbstractRenderDevice* device);

signals:

public slots:

private:
    WaveFrontObj* _obj;

};

#endif // UGEENTITYWAVEFRONTOBJ_H
