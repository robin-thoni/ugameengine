#ifndef UGEENTITYAXES_H
#define UGEENTITYAXES_H

#include "entities/ugeentity.h"

class UGEEntityAxes : public UGEEntity
{
    Q_OBJECT
public:
    explicit UGEEntityAxes(UGameEngine* engine, QObject *parent);
    explicit UGEEntityAxes(UGameEngine* engine);

    virtual void onDraw(AbstractRenderDevice* device);

    virtual Vector3D getVectorNearestIntesection(const Vector3D &vector, const Vector3D &pos, bool* ok);

    double size() const;
    void setSize(double size);

signals:

public slots:

protected:
    double _size;

private:
    void init();

};

#endif // UGEENTITYAXES_H
