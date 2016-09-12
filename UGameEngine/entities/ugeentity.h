#ifndef UGEENTITY_H
#define UGEENTITY_H

#include <QObject>
#include <QPoint>
#include <QSharedPointer>
#include "utils/vector3d.h"
#include "utils/matrix3x3.h"
#include "engine/abstractrenderdevice.h"

class UGEEntity : public QObject
{
    Q_OBJECT
public:
    explicit UGEEntity(QObject *parent = 0);
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

    QColor getColor() const;
    void setColor(const QColor &color);

    Vector3D getRealPoint(const Vector3D& pos);
    ColorVector3D getRealPoint(const ColorVector3D& pos);
    TextureVector3D getRealPoint(const TextureVector3D& pos);

    Matrix3x3 getRotationMatrix(const Vector3D& rotation);

    virtual void drawPoint(AbstractRenderDevice* device, const ColorVector3D& point);

    virtual void drawLine(AbstractRenderDevice* device, const ColorVector3D& begin, const ColorVector3D& end, double width = 1.0);

    virtual void drawPolygon(AbstractRenderDevice* device, QList<ColorVector3D> points);

    virtual void drawPolygonTexture(AbstractRenderDevice *device, QList<TextureVector3D> points, const QVariant& textureId);

    virtual void draw(AbstractRenderDevice* device) = 0;

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

private:
    Vector3D _position;

//    Vector3D _speed;

    Vector3D _rotation;

    Vector3D _scale;

    bool _visible;

    QColor _color;

};

#endif // UGEENTITY_H
