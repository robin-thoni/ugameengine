#include "wavefrontobj.h"
#include <QFile>
#include <QDebug>
#include "lexer-wavefront-obj.h"
#include "parser-wavefront-obj.h"

WaveFrontObj::WaveFrontObj(QObject *parent) :
    QObject(parent)
{
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
    WaveFrontObjData data;
    int res = wavefront_objparse(&data);
    wavefront_obj_delete_buffer(bufferState);
    if (res) {
        _error = "Parse error: " + data._error;
        qDebug() << _error;
    }
    else {
        qDebug() << "faces:" << data._faces.size() << "vertexes" << data._vertexes.size();
    }

    return res == 0;
}
