#ifndef UGEENTITY_H
#define UGEENTITY_H

#include <QObject>
#include <QPoint>
#include <QSharedPointer>
#include "utils/vector3d.h"
#include "utils/matrix3x3.h"
#include "engine/abstractrenderdevice.h"
#include "engine/ugameengine.h"

class UGameEngine;

class UGEEntity : public QObject
{
    Q_OBJECT
public:
    explicit UGEEntity(UGameEngine* engine, QObject *parent);
    explicit UGEEntity(UGameEngine* engine);
    virtual ~UGEEntity();

    Vector3D getPosition() const;
    void setPosition(const Vector3D& position);
    void move(const Vector3D& move);

//    Vector3D getSpeed() const;
//    void setSpeed(const Vector3D& speed);
//    void accelerate(const Vector3D& speed);

    Vector3D getRotation() const;
    void setRotation(const Vector3D& rotation);
    void rotate(const Vector3D& rotation);

    Vector3D getScale() const;
    void setScale(const Vector3D& scale);
    void scale(const Vector3D& scale);

    bool isVisible() const;
    void setVisible(bool visible);
    void show();
    void hide();

    const QColor &getColor() const;
    void setColor(const QColor &color);

    Vector3D getRealPoint(const Vector3D& pos);
    ColorVector3D getRealPoint(const ColorVector3D& pos);
    TextureVector3D getRealPoint(const TextureVector3D& pos);

    Matrix3x3 getTransformationMatrix() const;
    Matrix3x3 getScaleMatrix() const;
    Matrix3x3 getRotationMatrix() const;

    void drawPoint(AbstractRenderDevice* device, const ColorVector3D& point);

    void drawLine(AbstractRenderDevice* device, const ColorVector3D& begin, const ColorVector3D& end, double width = 1.0);

    void drawPolygon(AbstractRenderDevice* device, QList<ColorVector3D> points);

    void drawPolygonTexture(AbstractRenderDevice *device, QList<TextureVector3D> points, const QVariant& textureId);

    void draw(AbstractRenderDevice* device);

    virtual void onDraw(AbstractRenderDevice* device) = 0;

    virtual Vector3D getVectorNearestIntesection(const Vector3D &vector, const Vector3D &pos, bool* ok) = 0;

    Vector3D getVectorNearestFaceIntersection(const Vector3D & p0, const Vector3D &p1, const Vector3D &p2, const Vector3D &vector, const Vector3D &pos, bool* ok);

    bool isZero(double v);

    void update();

    virtual void onUpdate();

public slots:

    void needUpdate();

signals:
    void positionChanged();
    void positionChanged(const Vector3D& position);

    void rotationChanged();
    void rotationChanged(const Vector3D& rotation);

    void scaleChanged();
    void scaleChanged(const Vector3D& scale);

    void visibilityChanged();
    void visibilityChanged(bool visible);

    void colorChanged();
    void colorChanged(QColor color);

protected:
    UGameEngine* _engine;

    Vector3D _position;

//    Vector3D _speed;

    Vector3D _rotation;

    Vector3D _scale;

    bool _visible;

    QColor _color;

    bool _needUpdate;

    Matrix3x3 _tranformation;

    double _zero;

private:
    void init();

};

#endif // UGEENTITY_H
