#ifndef WAVEFRONTOBJ_H
#define WAVEFRONTOBJ_H

#include <QObject>
#include <QIODevice>

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
};

#endif // WAVEFRONTOBJ_H
