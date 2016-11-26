#include "ugameengine.h"


UGameEngine::UGameEngine(AbstractRenderDevice* device)
    : _device(device)
{
}

UGameEngine::~UGameEngine()
{
}

void UGameEngine::draw()
{
    _device->preDraw();

    for(int i = 0; i < _entitites.size(); ++i) {
        UGEEntity* entity = _entitites[i];
        if (entity->isVisible()) {
            entity->draw(_device);
        }
    }

    _device->postDraw();
}

void UGameEngine::addEntity(UGEEntity *entity)
{
    _entitites.append(entity);
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
