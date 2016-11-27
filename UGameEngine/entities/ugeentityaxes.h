#ifndef UGEENTITYAXES_H
#define UGEENTITYAXES_H

#include "entities/ugeentity.h"

class UGEEntityAxes : public UGEEntity
{
    Q_OBJECT
public:
    explicit UGEEntityAxes(QObject *parent = 0);

    virtual void onDraw(AbstractRenderDevice* device);

signals:

public slots:

};

#endif // UGEENTITYAXES_H
