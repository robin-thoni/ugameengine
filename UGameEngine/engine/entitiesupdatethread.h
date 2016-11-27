#ifndef ENTITIESUPDATETHREAD_H
#define ENTITIESUPDATETHREAD_H

#include <QThread>
#include "ugameengine.h"

class UGameEngine;

class EntitiesUpdateThread : public QThread
{
    Q_OBJECT
public:
    explicit EntitiesUpdateThread(UGameEngine *parent = 0);

    void update(int begin, int end);

protected:
    void run();

signals:

public slots:

private:
    UGameEngine* _engine;

    int _begin;

    int _end;

};

#endif // ENTITIESUPDATETHREAD_H
