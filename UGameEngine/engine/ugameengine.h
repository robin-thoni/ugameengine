#ifndef UGAMEENGINE_H
#define UGAMEENGINE_H

#include "abstractrenderdevice.h"
#include "entities/ugeentity.h"
#include "entitiesupdatethread.h"

class EntitiesUpdateThread;

class UGameEngine : public QObject
{
    Q_OBJECT
public:
    UGameEngine(AbstractRenderDevice* device);
    virtual ~UGameEngine();

    void update();

    void draw();

    const QList<UGEEntity*>& getEntities() const;

    UGEEntity *getEntity(int i) const;

public slots:
    void addEntity(UGEEntity* entity);

    void lookAt(const Vector3D& eye, const Vector3D& center, const Vector3D& up = Vector3D(0.0, 1.0, 0.0));

    void setClearColor(const QColor &clearColor);

    void initialize(int fov, int width, int height);

    void resize(int width, int height);

    void loadTextureFromFile(const QVariant& id, const QString& filename);

protected:
    QList<UGEEntity*> _entitites;

    AbstractRenderDevice* _device;

    QList<EntitiesUpdateThread*> _entitiesUpdateThreads;
};

#endif // UGAMEENGINE_H
