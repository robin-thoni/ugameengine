#include <math.h>

#define tmplx template<unsigned X>
#define tmpl template<unsigned X, class T>

tmplx VectorXD<X>::VectorXD()
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] = 0;
    }
}

tmplx VectorXD<X>::VectorXD(const double scalars[X])
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] = scalars[i];
    }
}

tmplx VectorXD<X>::VectorXD(const VectorXD<X>& other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] = other._scalars[i];
    }
}

tmpl T& GenericVector<X, T>::setScalar(unsigned i, double value)
{
    _scalars[i] = value;
    return *getThis();
}

tmpl double GenericVector<X, T>::getScalar(unsigned i) const
{
    return _scalars[i];
}

tmpl bool GenericVector<X, T>::isNull() const
{
    return equal(T());
}

tmpl bool GenericVector<X, T>::equal(const T &other) const
{
    for (unsigned i = 0; i < X; ++i) {
        if (_scalars[i] != other._scalars[i]) {
            return false;
        }
    }
    return true;
}

tmpl T &GenericVector<X, T>::add(double k)
{
    double scalars[X];
    for (unsigned i = 0; i < X; ++i) {
        scalars[i] = k;
    }
    return add(T(scalars));
}

tmpl T &GenericVector<X, T>::add(double scalars[X])
{
    return add(T(scalars));
}

tmpl T& GenericVector<X, T>::add(const  T &other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] += other._scalars[i];
    }
    return *getThis();
}

tmpl T &GenericVector<X, T>::sub(double k)
{
    double scalars[X];
    for (unsigned i = 0; i < X; ++i) {
        scalars[i] = k;
    }
    return sub(T(scalars));
}

tmpl T &GenericVector<X, T>::sub(double scalars[X])
{
    return sub(T(scalars));
}

tmpl T& GenericVector<X, T>::sub(const T &other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] -= other._scalars[i];
    }
    return *getThis();
}

tmpl T &GenericVector<X, T>::mult(double k)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] *= k;
    }
    return *getThis();
}

tmpl T &GenericVector<X, T>::mult(double scalars[X])
{
    return mult(T(scalars));
}

tmpl T &GenericVector<X, T>::mult(const T &other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] *= other._scalars[i];
    }
    return *getThis();
}

tmpl T &GenericVector<X, T>::div(double k)
{
    double scalars[X];
    for (unsigned i = 0; i < X; ++i) {
        scalars[i] = k;
    }
    return div(T(scalars));
}

tmpl T &GenericVector<X, T>::div(double scalars[X])
{
    return div(T(scalars));
}

tmpl T &GenericVector<X, T>::div(const T &other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] /= other._scalars[i];
    }
    return *getThis();
}

tmpl double GenericVector<X, T>::dotProduct(const T &other) const
{
    double total = 0;
    for (unsigned i = 0; i < X; ++i) {
        total += _scalars[i] * other._scalars[i];
    }
    return total;
}

tmpl T& GenericVector<X, T>::crossProduct(const T& other)
{
    T t = *getThis();
    for (unsigned i = 0; i < X; ++i) {
        unsigned j = (i + 1) % X;
        unsigned k = (i + 2) % X;
        _scalars[i] = (t._scalars[j] * other._scalars[k]) - (t._scalars[k] * other._scalars[j]);
    }
    return *getThis();
}

tmpl T GenericVector<X, T>::crossProduct(const T &v1, const T &v2)
{
    return T(v1).crossProduct(v2);
}

tmpl double GenericVector<X, T>::norm() const
{
    double total = 0;
    for (unsigned i = 0; i < X; ++i) {
        total += _scalars[i] * _scalars[i];
    }
    return sqrt(total);
}

tmpl T GenericVector<X, T>::operator+() const
{
    return *getThis();
}

tmpl T GenericVector<X, T>::operator+(const double &k) const
{
    return T(*getThis()).add(k);
}

tmpl T &GenericVector<X, T>::operator+=(const double &k)
{
    return add(k);
}

tmpl T GenericVector<X, T>::operator+(const T &other) const
{
    T v = *getThis();
    return v.add(other);
}

tmpl T &GenericVector<X, T>::operator+=(const T &other)
{
    return add(other);
}

tmpl T GenericVector<X, T>::operator-() const
{
    double scalars[X];
    for (unsigned i = 0; i < X; ++i) {
        scalars[i] = -_scalars[i];
    }
    return T(scalars);
}

tmpl T GenericVector<X, T>::operator-(const double &k) const
{
    return T(*getThis()).sub(k);
}

tmpl T &GenericVector<X, T>::operator-=(const double &k)
{
    return sub(k);
}

tmpl T GenericVector<X, T>::operator-(const T &other) const
{
    return T(*getThis()).sub(other);
}

tmpl T &GenericVector<X, T>::operator-=(const T &other)
{
    return sub(other);
}

tmpl T GenericVector<X, T>::operator*(const double &k) const
{
    return T(*getThis()).mult(k);
}

tmpl T &GenericVector<X, T>::operator*=(const double &k)
{
    return mult(k);
}

tmpl T GenericVector<X, T>::operator*(const T &other) const
{
    return T(*getThis()).mult(other);
}

tmpl T &GenericVector<X, T>::operator*=(const T &other)
{
    dotProduct(other);
    return *getThis();
}

tmpl T GenericVector<X, T>::operator/(const double &k) const
{
    return T(*getThis()).div(k);
}

tmpl T &GenericVector<X, T>::operator/=(const double &k)
{
    return div(k);
}

tmpl bool GenericVector<X, T>::operator==(const T &other) const
{
    return equal(other);
}

tmpl bool GenericVector<X, T>::operator!=(const T &other) const
{
    return !equal(other);
}

tmpl double GenericVector<X, T>::operator[](unsigned i) const
{
    return getScalar(i);
}

tmpl bool GenericVector<X, T>::operator!() const
{
    return isNull();
}

tmpl GenericVector<X, T>::operator bool() const
{
    return !isNull();
}

tmpl T* GenericVector<X, T>::getThis() const
{
    return (T*)this;
}

tmpl QDebug operator<<(QDebug dbg, const T &v)
{
    return dbg.nospace() << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
}
