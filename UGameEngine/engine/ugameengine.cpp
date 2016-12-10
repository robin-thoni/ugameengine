#include "ugameengine.h"
#include <QTime>

UGameEngine::UGameEngine(AbstractRenderDevice* device)
    : _device(device)
{
    for (int i = 0; i < 8; ++i) {
        _entitiesUpdateThreads.append(new EntitiesUpdateThread(this));
    }
}

UGameEngine::~UGameEngine()
{
}

void UGameEngine::update()
{
    int entitiesCount = _entitites.size();
    if (entitiesCount > 1000) {
        int threads = _entitiesUpdateThreads.size();
        for (int t = 0; t < threads; ++t) {
            EntitiesUpdateThread* thread = _entitiesUpdateThreads[t];
            int begin = (entitiesCount / threads) * t;
            int end = (entitiesCount / threads) * (t + 1);
            if (t == threads - 1) {
                end = entitiesCount;
            }
            thread->update(begin, end);
        }
        for (int t = 0; t < threads; ++t) {
            EntitiesUpdateThread* thread = _entitiesUpdateThreads[t];
            thread->wait();
        }
    }
    else {
        for(int i = 0; i < _entitites.size(); ++i) {
            UGEEntity* entity = _entitites[i];
            if (entity->isVisible()) {
                entity->update();
            }
        }
    }
}

void UGameEngine::draw()
{
    _device->preDraw();

    QTime time;
    time.start();
    update();
    int update = time.elapsed();
    time.restart();

    for(int i = 0; i < _entitites.size(); ++i) {
        UGEEntity* entity = _entitites[i];
        if (entity->isVisible()) {
            entity->draw(_device);
        }
    }
    int draw = time.elapsed();
//    qDebug() << update << draw << (update + draw);

    _device->postDraw();
}

const QList<UGEEntity *> &UGameEngine::getEntities() const
{
    return _entitites;
}

UGEEntity *UGameEngine::getEntity(int i) const
{
    return _entitites[i];
}

Vector3D UGameEngine::get2DFrom3D(const Vector3D &pos)
{
    return _device->get2DFrom3D(pos);
}

Vector3D UGameEngine::get3DFrom2D(const Vector2D &pos)
{
    return _device->get3DFrom2D(pos);
}

UGEEntity *UGameEngine::getVectorNearestIntesection(const Vector3D &vector, const Vector3D &pos, Vector3D* bestp)
{
    UGEEntity* beste = 0;
    bool ok = false;
    for (int i = 0; i < _entitites.size(); i++) {
        UGEEntity* entity = _entitites[i];
        bool provi;
        Vector3D collision = entity->getVectorNearestIntesection(vector, pos, &provi);
        if (provi && (!ok || (pos - *bestp).norm() > (pos - collision).norm())) {
            *bestp = collision;
            beste = entity;
            ok = true;
        }
    }
    return beste;
}

void UGameEngine::addEntity(UGEEntity *entity)
{
    _entitites.append(entity);
}

void UGameEngine::removeEntity(UGEEntity *entity)
{
    _entitites.removeOne(entity);
}

void UGameEngine::lookAt(const Vector3D &eye, const Vector3D &center, const Vector3D &up)
{
    _device->lookAt(eye, center, up);
}

void UGameEngine::setClearColor(const QColor &clearColor)
{
    _device->setClearColor(clearColor);
}

void UGameEngine::initialize(int fov, int width, int height)
{
    _device->initialize(fov, width, height);
}

void UGameEngine::resize(int width, int height)
{
    _device->resize(width, height);
}

void UGameEngine::loadTextureFromFile(const QVariant &id, const QString &filename)
{
    _device->loadTextureFromFile(id, filename);
}
