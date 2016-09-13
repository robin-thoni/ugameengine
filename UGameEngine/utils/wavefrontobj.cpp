#include "wavefrontobj.h"
#include <QFile>
#include <QDebug>
#include "lexer-wavefront-obj.h"
#include "parser-wavefront-obj.h"
#include "lexer-wavefront-mtl.h"
#include "parser-wavefront-mtl.h"

WaveFrontObj::WaveFrontObj(QObject *parent) :
    QObject(parent)
{
}

QList<QList<WaveFrontObjFaceVertex> > WaveFrontObj::getFaces() const
{
    return _faces;
}

QList<Vector3D> WaveFrontObj::getVertexes() const
{
    return _vertexes;
}

bool WaveFrontObj::openFile(const QString &filename)
{
    QFile f(filename);
    if (f.open(QIODevice::ReadOnly)) {
        bool res = load(f);
        f.close();
        return res;
    }
    _error = "Failed to open file: " + f.errorString();
    return false;
}

bool WaveFrontObj::load(QIODevice &device)
{
    _error.clear();
    QString file = device.readAll();

    YY_BUFFER_STATE bufferState = wavefront_obj_scan_string(file.toUtf8().constData());

    int res = wavefront_objparse(this);
    wavefront_obj_delete_buffer(bufferState);
    if (res) {
        qDebug() << _error;
        return false;
    }
    else {
        return true;
    }
}

void WaveFrontObj::addFace(QList<WaveFrontObjFaceVertex> face)
{
    _faces.append(face);
}

void WaveFrontObj::addVertex(const Vector3D &vertex)
{
    _vertexes.append(vertex);
}

void WaveFrontObj::setError(const QString &error)
{
    _error = error;
}
