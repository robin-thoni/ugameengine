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

    QVariant getTextureId() const;

signals:

public slots:
    void setSize(float size);
    void setTextureId(const QVariant &textureId);

private:
    float _size;
    QVariant _textureId;

};

#endif // UGEENTITYCUBE_H
