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
        entity->draw(_device);
    }

    _device->postDraw();
}
