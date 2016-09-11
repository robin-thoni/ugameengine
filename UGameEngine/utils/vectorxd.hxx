#include <math.h>

#define tmpl template<unsigned X>

tmpl VectorXD<X>::VectorXD()
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] = 0;
    }
}

tmpl VectorXD<X>::VectorXD(const double scalars[X])
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] = scalars[i];
    }
}

tmpl VectorXD<X>::VectorXD(const VectorXD<X>& other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] = other._scalars[i];
    }
}

tmpl VectorXD<X>& VectorXD<X>::setScalar(unsigned i, double value)
{
    _scalars[i] = value;
    return *this;
}

tmpl double VectorXD<X>::getScalar(unsigned i)
{
    return _scalars[i];
}

tmpl bool VectorXD<X>::isNull() const
{
    return equal(VectorXD<X>());
}

tmpl bool VectorXD<X>::equal(const VectorXD<X> &other) const
{
    for (unsigned i = 0; i < X; ++i) {
        if (_scalars[i] != other._scalars[i]) {
            return false;
        }
    }
    return true;
}

tmpl VectorXD<X> &VectorXD<X>::add(double k)
{
    double scalars[X];
    for (unsigned i = 0; i < X; ++i) {
        scalars[i] = k;
    }
    return add(VectorXD<X>(scalars));
}

tmpl VectorXD<X> &VectorXD<X>::add(double scalars[X])
{
    return add(VectorXD<X>(scalars));
}

tmpl VectorXD<X>& VectorXD<X>::add(const  VectorXD<X> &other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] += other._scalars[i];
    }
    return *this;
}

tmpl VectorXD<X> &VectorXD<X>::sub(double k)
{
    double scalars[X];
    for (unsigned i = 0; i < X; ++i) {
        scalars[i] = k;
    }
    return sub(VectorXD<X>(scalars));
}

tmpl VectorXD<X> &VectorXD<X>::sub(double scalars[X])
{
    return sub(VectorXD<X>(scalars));
}

tmpl VectorXD<X>& VectorXD<X>::sub(const VectorXD<X> &other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] -= other._scalars[i];
    }
    return *this;
}

tmpl VectorXD<X> &VectorXD<X>::mult(double k)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] *= k;
    }
    return *this;
}

tmpl VectorXD<X> &VectorXD<X>::mult(double scalars[X])
{
    return mult(VectorXD<X>(scalars));
}

tmpl VectorXD<X> &VectorXD<X>::mult(const VectorXD<X> &other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] *= other._scalars[i];
    }
    return *this;
}

tmpl VectorXD<X> &VectorXD<X>::div(double k)
{
    double scalars[X];
    for (unsigned i = 0; i < X; ++i) {
        scalars[i] = k;
    }
    return div(VectorXD<X>(scalars));
}

tmpl VectorXD<X> &VectorXD<X>::div(double scalars[X])
{
    return div(VectorXD<X>(scalars));
}

tmpl VectorXD<X> &VectorXD<X>::div(const VectorXD<X> &other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] /= other._scalars[i];
    }
    return *this;
}

tmpl double VectorXD<X>::dotProduct(const VectorXD<X> &other) const
{
    double total = 0;
    for (unsigned i = 0; i < X; ++i) {
        total += _scalars[i] * other._scalars[i];
    }
    return total;
}

tmpl VectorXD<X>& VectorXD<X>::crossProduct(const VectorXD<X>& other)
{
    VectorXD<X> t = *this;
    for (unsigned i = 0; i < X; ++i) {
        unsigned j = (i + 1) % X;
        unsigned k = (i + 2) % X;
        _scalars[i] = (t._scalars[j] * other._scalars[k]) - (t._scalars[k] * other._scalars[j]);
    }
    return *this;
}

tmpl VectorXD<X> VectorXD<X>::crossProduct(const VectorXD<X> &v1, const VectorXD<X> &v2)
{
    return VectorXD<X>(v1).crossProduct(v2);
}

tmpl double VectorXD<X>::norm() const
{
    double total = 0;
    for (unsigned i = 0; i < X; ++i) {
        total += _scalars[i] * _scalars[i];
    }
    return sqrt(total);
}

tmpl VectorXD<X> VectorXD<X>::operator+() const
{
    return *this;
}

tmpl VectorXD<X> VectorXD<X>::operator+(const double &k) const
{
    return VectorXD(*this).add(k);
}

tmpl VectorXD<X> &VectorXD<X>::operator+=(const double &k)
{
    return add(k);
}

tmpl VectorXD<X> VectorXD<X>::operator+(const VectorXD<X> &other) const
{
    return VectorXD<X>(*this).add(other);
}

tmpl VectorXD<X> &VectorXD<X>::operator+=(const VectorXD<X> &other)
{
    return add(other);
}

tmpl VectorXD<X> VectorXD<X>::operator-() const
{
    double scalars[X];
    for (unsigned i = 0; i < X; ++i) {
        scalars[i] = -_scalars[i];
    }
    return VectorXD<X>(scalars);
}

tmpl VectorXD<X> VectorXD<X>::operator-(const double &k) const
{
    return VectorXD(*this).sub(k);
}

tmpl VectorXD<X> &VectorXD<X>::operator-=(const double &k)
{
    return sub(k);
}

tmpl VectorXD<X> VectorXD<X>::operator-(const VectorXD<X> &other) const
{
    return VectorXD(*this).sub(other);
}

tmpl VectorXD<X> &VectorXD<X>::operator-=(const VectorXD<X> &other)
{
    return sub(other);
}

tmpl VectorXD<X> VectorXD<X>::operator*(const double &k) const
{
    return VectorXD<X>(*this).mult(k);
}

tmpl VectorXD<X> &VectorXD<X>::operator*=(const double &k)
{
    return mult(k);
}

tmpl VectorXD<X> VectorXD<X>::operator*(const VectorXD<X> &other) const
{
    return VectorXD<X>(*this).mult(other);
}

tmpl VectorXD<X> &VectorXD<X>::operator*=(const VectorXD<X> &other)
{
    dotProduct(other);
    return *this;
}

tmpl VectorXD<X> VectorXD<X>::operator/(const double &k) const
{
    return VectorXD<X>(*this).div(k);
}

tmpl VectorXD<X> &VectorXD<X>::operator/=(const double &k)
{
    return div(k);
}

tmpl bool VectorXD<X>::operator==(const VectorXD<X> &other) const
{
    return equal(other);
}

tmpl bool VectorXD<X>::operator!=(const VectorXD<X> &other) const
{
    return !equal(other);
}

tmpl bool VectorXD<X>::operator!() const
{
    return isNull();
}

tmpl VectorXD<X>::operator bool() const
{
    return !isNull();
}

tmpl QDebug operator<<(QDebug dbg, const VectorXD<X> &v)
{
    return dbg.nospace() << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
}
