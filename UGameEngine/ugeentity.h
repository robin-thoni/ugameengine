#ifndef UGEENTITY_H
#define UGEENTITY_H

#include <QObject>
#include <QPoint>
#include "vector3d.h"

class UGEEntity : public QObject
{
    Q_OBJECT
public:
    explicit UGEEntity(QObject *parent = 0);

signals:

public slots:

private:
    Vector3D _position;

};

#endif // UGEENTITY_H
