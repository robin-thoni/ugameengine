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
