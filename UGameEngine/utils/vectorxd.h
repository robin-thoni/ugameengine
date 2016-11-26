#ifndef VECTORXD_H
#define VECTORXD_H

#include <QDebug>
#include "matrixmxn.h"

#define uge_gv_tmpl_x template<unsigned X>
#define uge_gv_tmpl_xt template<unsigned X, class T>

uge_gv_tmpl_xt class GenericVector: public GenericMatrix<X, 1, T >
{
public:

    using GenericMatrix<X, 1, T >::setScalar;
    T& setScalar(unsigned i, double value);
    using GenericMatrix<X, 1, T >::getScalar;
    double getScalar(unsigned i) const;

    double dotProduct(const T& other) const;

    T& crossProduct(const T& other);
    static T crossProduct(const T &v1, const T &v2);

    double norm() const;

    double operator[](unsigned i) const;

protected:
    using GenericMatrix<X, 1, T >::_scalars;

private:
    T* getThis() const;
};

uge_gv_tmpl_x using VectorXD = MatrixMxN<X, 1>;

uge_gv_tmpl_x class MatrixMxN<X, 1>: public GenericVector<X, VectorXD<X>>
{
public:
    MatrixMxN();
    MatrixMxN(double k);
    MatrixMxN(const double scalars[X]);
    MatrixMxN(const VectorXD<X>& other);

protected:
    using GenericMatrix<X, 1, VectorXD<X>>::_scalars;
};

#include "vectorxd.hxx"

#endif // VECTORXD_H






