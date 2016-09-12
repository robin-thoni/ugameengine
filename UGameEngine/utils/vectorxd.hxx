#include <math.h>

#define tmplx template<unsigned X>
#define tmpl template<unsigned X, class T>

tmplx VectorXD<X>::MatrixMxN()
{
    this->fill(0);
}

tmplx VectorXD<X>::MatrixMxN(double k)
{
    this->fill(k);
}

tmplx VectorXD<X>::MatrixMxN(const double scalars[X])
{
    this->fill(scalars);
}

tmplx VectorXD<X>::MatrixMxN(const VectorXD<X>& other)
{
    for (unsigned i = 0; i < X; ++i) {
        _scalars[i] = other._scalars[i];
    }
}

tmpl T& GenericVector<X, T>::setScalar(unsigned i, double value)
{
    return setScalar(i, 0,value);
}

tmpl double GenericVector<X, T>::getScalar(unsigned i) const
{
    return getScalar(i, 0);
}

tmpl double GenericVector<X, T>::operator[](unsigned i) const
{
    return getScalar(i);
}

tmpl double GenericVector<X, T>::dotProduct(const T &other) const
{
    double total = 0;
    for (unsigned i = 0; i < X; ++i) {
        total += _scalars[i][0] * other._scalars[i][0];
    }
    return total;
}

tmpl T& GenericVector<X, T>::crossProduct(const T& other)
{
    T t = *getThis();
    for (unsigned i = 0; i < X; ++i) {
        unsigned j = (i + 1) % X;
        unsigned k = (i + 2) % X;
        _scalars[i][0] = (t._scalars[j][0] * other._scalars[k][0]) - (t._scalars[k][0] * other._scalars[j][0]);
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
        total += _scalars[i][0] * _scalars[i][0];
    }
    return sqrt(total);
}

tmpl T* GenericVector<X, T>::getThis() const
{
    return (T*)this;
}

//tmpl QDebug operator<<(QDebug dbg, const T &v)
//{
//    return dbg.nospace() << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
//}
