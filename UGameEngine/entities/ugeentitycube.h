#ifndef UGEENTITYCUBE_H
#define UGEENTITYCUBE_H

#include "ugeentity.h"

class UGEEntityCube : public UGEEntity
{
    Q_OBJECT
public:
    explicit UGEEntityCube(QObject *parent = 0);

    float getSize() const;

    virtual void draw(AbstractRenderDevice* device);

signals:

public slots:
    void setSize(float size);

private:
    float _size;

};

#endif // UGEENTITYCUBE_H
