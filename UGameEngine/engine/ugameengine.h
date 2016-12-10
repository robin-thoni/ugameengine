#ifndef UGAMEENGINE_H
#define UGAMEENGINE_H

#include "abstractrenderdevice.h"
#include "entities/ugeentity.h"
#include "entitiesupdatethread.h"

class EntitiesUpdateThread;
class UGEEntity;

class UGameEngine : public QObject
{
    Q_OBJECT
public:
    UGameEngine(AbstractRenderDevice* device);
    virtual ~UGameEngine();

    void draw();

    const QList<UGEEntity*>& getEntities() const;

    UGEEntity *getEntity(int i) const;

    Vector3D get2DFrom3D(const Vector3D& pos);

    Vector3D get3DFrom2D(const Vector2D &pos);

    UGEEntity* getVectorNearestIntesection(const Vector3D& vector, const Vector3D &pos, Vector3D *bestp);

public slots:
    void addEntity(UGEEntity* entity);

    void removeEntity(UGEEntity* entity);

    void lookAt(const Vector3D& eye, const Vector3D& center, const Vector3D& up = Vector3D(0.0, 1.0, 0.0));

    void setClearColor(const QColor &clearColor);

    void initialize(int fov, int width, int height);

    void resize(int width, int height);

    void loadTextureFromFile(const QVariant& id, const QString& filename);

protected:
    void update();

    QList<UGEEntity*> _entitites;

    AbstractRenderDevice* _device;

    QList<EntitiesUpdateThread*> _entitiesUpdateThreads;
};

#endif // UGAMEENGINE_H
