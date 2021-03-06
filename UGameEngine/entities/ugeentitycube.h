#ifndef UGEENTITYCUBE_H
#define UGEENTITYCUBE_H

#include "ugeentity.h"

class UGEEntityCube : public UGEEntity
{
    Q_OBJECT
public:
    explicit UGEEntityCube(UGameEngine* engine, QObject *parent);
    explicit UGEEntityCube(UGameEngine* engine);

    double getSize() const;

    QVariant getTextureId() const;

    virtual void onDraw(AbstractRenderDevice* device);
    void onUpdate();

    virtual Vector3D getVectorNearestIntesection(const Vector3D &vector, const Vector3D &origin, bool* ok);

signals:
    void sizeChanged();
    void sizeChanged(double);

    void textureChanged();
    void textureChanged(const QVariant& textureId);

public slots:
    void setSize(double size);
    void increaseSize(double size);

    void setTextureId(const QVariant &textureId);

protected:
    double _size;

    QVariant _textureId;

    QList<QList<TextureVector3D> > _facesTexture;

    QList<QList<ColorVector3D> > _facesColor;

private:
    void init();

};

#endif // UGEENTITYCUBE_H
