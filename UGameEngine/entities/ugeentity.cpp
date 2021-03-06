#include "ugeentity.h"
#include "utils/tools.h"

UGEEntity::UGEEntity(UGameEngine *engine, QObject *parent)
    : QObject(parent)
    , _engine(engine)
{
    init();
}

UGEEntity::UGEEntity(UGameEngine *engine)
    : QObject(engine)
    , _engine(engine)
{
    init();
}

UGEEntity::~UGEEntity()
{
    _engine->removeEntity(this);
}

Vector3D UGEEntity::getPosition() const
{
    return _position;
}

void UGEEntity::setPosition(const Vector3D &position)
{
    _position = position;
    emit positionChanged();
    emit positionChanged(_position);
}

void UGEEntity::move(const Vector3D &move)
{
    _position += move;
    emit positionChanged();
    emit positionChanged(_position);
}

//Vector3D UGEEntity::getSpeed() const
//{
//    return _speed;
//}

//void UGEEntity::setSpeed(const Vector3D &speed)
//{
//    _speed = speed;
//}

//void UGEEntity::accelerate(const Vector3D &speed)
//{
//    _speed += speed;
//}

Vector3D UGEEntity::getRotation() const
{
    return _rotation;
}

void UGEEntity::setRotation(const Vector3D &rotation)
{
    _rotation = Tools::normalizeAngle(rotation);
    emit rotationChanged();
    emit rotationChanged(rotation);
}

void UGEEntity::rotate(const Vector3D &rotation)
{
    _rotation = Tools::normalizeAngle(rotation + _rotation);
    emit rotationChanged();
    emit rotationChanged(rotation);
}

Vector3D UGEEntity::getScale() const
{
    return _scale;
}

void UGEEntity::setScale(const Vector3D &scale)
{
    _scale = scale;
    emit scaleChanged();
    emit scaleChanged(_scale);
}

void UGEEntity::scale(const Vector3D &scale)
{
    _scale += scale;
    emit scaleChanged();
    emit scaleChanged(_scale);
}
bool UGEEntity::isVisible() const
{
    return _visible;
}

void UGEEntity::setVisible(bool visible)
{
    _visible = visible;
    emit visibilityChanged();
    emit visibilityChanged(_visible);
}

void UGEEntity::show()
{
    _visible = true;
    emit visibilityChanged();
    emit visibilityChanged(_visible);
}

void UGEEntity::hide()
{
    _visible = false;
    emit visibilityChanged();
    emit visibilityChanged(_visible);
}

const QColor& UGEEntity::getColor() const
{
    return _color;
}

void UGEEntity::setColor(const QColor &color)
{
    _color = color;
    emit colorChanged();
    emit colorChanged(_color);
}

Vector3D UGEEntity::getRealPoint(const Vector3D &pos)
{
    return (_tranformation.multMatrix(pos) + _position);
}

ColorVector3D UGEEntity::getRealPoint(const ColorVector3D &pos)
{
    return ColorVector3D(pos.getColor(), getRealPoint((Vector3D)pos));
}

TextureVector3D UGEEntity::getRealPoint(const TextureVector3D &pos)
{
    return TextureVector3D(pos.getTextureCoord(), getRealPoint((ColorVector3D)pos));
}

Matrix3x3 UGEEntity::getTransformationMatrix() const
{
    return getRotationMatrix().multMatrix(getScaleMatrix());
}

Matrix3x3 UGEEntity::getScaleMatrix() const
{
    Matrix3x3 scale;
    scale.setScalar(0, 0, _scale.getX());
    scale.setScalar(1, 1, _scale.getY());
    scale.setScalar(2, 2, _scale.getZ());
    return scale;
}

Matrix3x3 UGEEntity::getRotationMatrix() const
{
    Vector3D r = Tools::degreeToRad(_rotation);

    Matrix3x3 mx;
    mx.setToIdentity();
    mx.setScalar(1, 1, cos(r.getX()));
    mx.setScalar(1, 2, -sin(r.getX()));
    mx.setScalar(2, 1, sin(r.getX()));
    mx.setScalar(2, 2, cos(r.getX()));

    Matrix3x3 my;
    my.setToIdentity();
    my.setScalar(0, 0, cos(r.getY()));
    my.setScalar(0, 2, sin(r.getY()));
    my.setScalar(2, 0, -sin(r.getY()));
    my.setScalar(2, 2, cos(r.getY()));

    Matrix3x3 mz;
    mz.setToIdentity();
    mz.setScalar(0, 0, cos(r.getZ()));
    mz.setScalar(0, 1, -sin(r.getZ()));
    mz.setScalar(1, 0, sin(r.getZ()));
    mz.setScalar(1, 1, cos(r.getZ()));

    return mx.multMatrix(my).multMatrix(mz);
}

void UGEEntity::drawPoint(AbstractRenderDevice *device, const ColorVector3D &point)
{
    device->drawPoint(getRealPoint(point));
}

void UGEEntity::drawLine(AbstractRenderDevice *device, const ColorVector3D &begin, const ColorVector3D &end, double width)
{
    device->drawLine(getRealPoint(begin), getRealPoint(end), width);
}

void UGEEntity::drawPolygon(AbstractRenderDevice *device, QList<ColorVector3D> points)
{
    for (int i = 0; i < points.size(); ++i) {
        points[i] = getRealPoint(points[i]);
    }
    device->drawPolygon(points);
}

void UGEEntity::drawPolygonTexture(AbstractRenderDevice *device, QList<TextureVector3D> points, const QVariant &textureId)
{
    for (int i = 0; i < points.size(); ++i) {
        points[i] = getRealPoint(points[i]);
    }
    device->drawPolygonTexture(points, textureId);
}

void UGEEntity::draw(AbstractRenderDevice *device)
{
    onDraw(device);
}

void UGEEntity::update()
{
    if (_needUpdate) {
        _tranformation = getTransformationMatrix();
        onUpdate();
        _needUpdate = false;
    }
}

void UGEEntity::onUpdate()
{

}

void UGEEntity::needUpdate()
{
    _needUpdate = true;
}

void UGEEntity::init()
{
    connect(this, SIGNAL(positionChanged()), this, SLOT(needUpdate()));
    connect(this, SIGNAL(rotationChanged()), this, SLOT(needUpdate()));
    connect(this, SIGNAL(scaleChanged()), this, SLOT(needUpdate()));
    connect(this, SIGNAL(colorChanged()), this, SLOT(needUpdate()));

    _scale = Vector3D(1.0, 1.0, 1.0);
    _visible = true;
    _needUpdate =true;
    _zero = 0.001;

    _engine->addEntity(this);
}


Vector3D UGEEntity::getVectorNearestFaceIntersection(const Vector3D & p0, const Vector3D &p1, const Vector3D &p2, const Vector3D &vector, const Vector3D &pos, bool* ok){
    Vector3D v1 = p1 - p0;
    Vector3D v2 = p2 - p0;
    Vector3D n = v1.crossProduct(v2);
    double dotProduct = vector.dotProduct(n);
    if(isZero(dotProduct)){
        *ok = false;
        return Vector3D();
    }
    double l2 = n.dotProduct(p0 - pos) / dotProduct;
    if(-_zero > l2){
        *ok = false;
        return Vector3D();
    }
    *ok = true;
    Vector3D unit = (vector / vector.norm()) * l2;
    return pos + unit;
}

bool UGEEntity::isZero(double v){
    return v < _zero && v > -_zero;
}
