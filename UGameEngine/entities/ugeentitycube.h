#ifndef UGEENTITYCUBE_H
#define UGEENTITYCUBE_H

#include "ugeentity.h"

class UGEEntityCube : public UGEEntity
{
    Q_OBJECT
public:
    explicit UGEEntityCube(QObject *parent = 0);

    double getSize() const;

    QVariant getTextureId() const;

    virtual void onDraw(AbstractRenderDevice* device);
    void onUpdate();

signals:
    void sizeChanged();
    void sizeChanged(double);

    void textureChanged();
    void textureChanged(const QVariant& textureId);

public slots:
    void setSize(double size);
    void increaseSize(double size);

    void setTextureId(const QVariant &textureId);

private:
    double _size;

    QVariant _textureId;

    QList<QList<TextureVector3D> > _facesTexture;

    QList<QList<ColorVector3D> > _facesColor;

};

#endif // UGEENTITYCUBE_H
