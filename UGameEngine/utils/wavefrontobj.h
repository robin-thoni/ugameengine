#ifndef WAVEFRONTOBJ_H
#define WAVEFRONTOBJ_H

#include <QObject>
#include <QIODevice>
#include "utils/vector3d.h"

struct WaveFrontObjFaceVertex
{
    int vertexPosition;
    int textureCoordPosition;
};

class WaveFrontObj : public QObject
{
    Q_OBJECT
public:
    explicit WaveFrontObj(QObject *parent = 0);

    QList<QList<WaveFrontObjFaceVertex> > getFaces() const;
    QList<Vector3D> getVertexes() const;

signals:

public slots:
    bool openFile(const QString& filename);
    bool load(QIODevice& device);
    void addFace(QList<WaveFrontObjFaceVertex> face);
    void addVertex(const Vector3D& vertex);
    void setError(const QString& error);

private:
    QString _error;
    QList<Vector3D> _vertexes;
    QList<QList<WaveFrontObjFaceVertex> > _faces;

};

#endif // WAVEFRONTOBJ_H
