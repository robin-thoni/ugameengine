#ifndef VECTORXD_H
#define VECTORXD_H

#include <QDebug>

#define tmplx template<unsigned X>
#define tmpl template<unsigned X, class T>

tmpl class GenericVector
{
public:

    T& setScalar(unsigned i, double value);
    double getScalar(unsigned i) const;

    bool isNull() const;

    bool equal(const T& other) const;

    T& add(double k);
    T& add(double scalars[X]);
    T& add(const T& other);

    T& sub(double k);
    T& sub(double scalars[X]);
    T& sub(const T& other);

    T& mult(double k);
    T& mult(double scalars[X]);
    T& mult(const T& other);

    T& div(double k);
    T& div(double scalars[X]);
    T& div(const T& other);

    double dotProduct(const T& other) const;

    T& crossProduct(const T& other);
    static T crossProduct(const T &v1, const T &v2);

    double norm() const;

    T operator+() const;
    T operator+(const double& k) const;
    T& operator+=(const double& k);
    T operator+(const T& other) const;
    T& operator+=(const T& other);

    T operator-() const;
    T operator-(const double& k) const;
    T& operator-=(const double& k);
    T operator-(const T& other) const;
    T& operator-=(const T& other);

    T operator*(const double& k) const;
    T& operator*=(const double& k);
    T operator*(const T& other) const;
    T& operator*=(const T& other);

    T operator/(const double& k) const;
    T& operator/=(const double& k);

    bool operator==(const T& other) const;
    bool operator!=(const T& other) const;

    double operator[](unsigned i) const;

    bool operator!() const;
    operator bool() const;

protected:
    double _scalars[X];

private:
    T* getThis() const;
};

tmplx class VectorXD: public GenericVector<X, VectorXD<X> >
{
public:
    VectorXD();
    VectorXD(const double scalars[X]);
    VectorXD(const VectorXD<X>& other);

protected:
    using GenericVector<X, VectorXD<X> >::_scalars;
};

tmplx QDebug operator<<(QDebug dbg, const VectorXD<X>& v);

#include "vectorxd.hxx"

#endif // VECTORXD_H
