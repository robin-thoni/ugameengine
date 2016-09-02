#ifndef UGAMEENGINE_H
#define UGAMEENGINE_H

#include "abstractrenderdevice.h"
#include "entities/ugeentity.h"

class UGameEngine : public QObject
{
    Q_OBJECT
public:
    UGameEngine(AbstractRenderDevice* device);
    virtual ~UGameEngine();

    void draw();

protected:
    QList<UGEEntity*> _entitites;

    AbstractRenderDevice* _device;
};

#endif // UGAMEENGINE_H
