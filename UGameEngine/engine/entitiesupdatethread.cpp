#include "entitiesupdatethread.h"
#include "entities/ugeentity.h"

EntitiesUpdateThread::EntitiesUpdateThread(UGameEngine *parent)
    : QThread(parent)
    , _engine(parent)
{
}

void EntitiesUpdateThread::update(int begin, int end)
{
    _begin = begin;
    _end = end;
    start();
}

void EntitiesUpdateThread::run()
{
    for (int i = _begin; i < _end; ++i) {
        UGEEntity* entity = _engine->getEntity(i);
        if (entity->isVisible()) {
            entity->update();
        }
    }
}
