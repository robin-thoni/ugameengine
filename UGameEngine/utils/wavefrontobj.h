#ifndef WAVEFRONTOBJ_H
#define WAVEFRONTOBJ_H

#include <QObject>
#include <QIODevice>
#include "utils/vector3d.h"

class WaveFrontObj : public QObject
{
    Q_OBJECT
public:
    explicit WaveFrontObj(QObject *parent = 0);

signals:

public slots:
    bool openFile(const QString& filename);
    bool load(QIODevice& device);

private:
    QString _error;

};

struct WaveFrontObjData
{
    QList<Vector3D> _vertexes;
    QList<QList<int> > _faces;
    QString _error;
};

#endif // WAVEFRONTOBJ_H
