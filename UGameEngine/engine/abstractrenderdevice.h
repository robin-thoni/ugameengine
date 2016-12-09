#ifndef ABSTRACTRENDERDEVICE_H
#define ABSTRACTRENDERDEVICE_H

#include <QObject>
#include <QColor>
#include <QImage>
#include "utils/colorvector3d.h"
#include "utils/texturevector3d.h"

class AbstractRenderDevice : public QObject
{
    Q_OBJECT
public:
    explicit AbstractRenderDevice(QObject *parent = 0);

    virtual ~AbstractRenderDevice();

    QColor getCurrentColor() const;

    Vector3D getLookEye() const;

    Vector3D getLookCenter() const;

    Vector3D getLookUp() const;

    QColor getClearColor() const;

    virtual Vector3D get2DFrom3D(const Vector3D& pos) = 0;

    virtual Vector3D get3DFrom2D(const Vector2D& pos) = 0;

public slots:
    virtual void setClearColor(const QColor &clearColor);

    virtual void setCurrentColor(const QColor &color);

    virtual void lookAt(const Vector3D& eye, const Vector3D& center, const Vector3D& up = Vector3D(0.0, 1.0, 0.0));

    void loadTextureFromFile(const QVariant& id, const QString& filename);

    virtual void loadTexture(const QVariant& id, const QImage& texture) = 0;

    virtual void initialize(int fov, int width, int height) = 0;

    virtual void resize(int width, int height) = 0;

    virtual void preDraw() = 0;

    virtual void postDraw() = 0;

    virtual void drawPoint(const ColorVector3D& point) = 0;

    virtual void drawLine(const ColorVector3D& begin, const ColorVector3D& end, double width = 1.0) = 0;

    virtual void drawPolygon(const QList<ColorVector3D>& points) = 0;

    virtual void drawPolygonTexture(const QList<TextureVector3D>& points, const QVariant& textureId) = 0;

protected:
    QColor _clearColor;

    QColor _currentColor;

    Vector3D _lookEye;

    Vector3D _lookCenter;

    Vector3D _lookUp;
};

#endif // ABSTRACTRENDERDEVICE_H
