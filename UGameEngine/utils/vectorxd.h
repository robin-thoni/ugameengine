#ifndef VECTORXD_H
#define VECTORXD_H

#include <QDebug>

#define tmpl template<unsigned X>

tmpl class VectorXD
{
public:
    VectorXD();
    VectorXD(const double scalars[X]);
    VectorXD(const VectorXD<X>& other);

    VectorXD<X>& setScalar(unsigned i, double value);
    double getScalar(unsigned i);

    bool isNull() const;

    bool equal(const VectorXD<X>& other) const;

    VectorXD<X>& add(double k);
    VectorXD<X>& add(double scalars[X]);
    VectorXD<X>& add(const VectorXD<X>& other);

    VectorXD<X>& sub(double k);
    VectorXD<X>& sub(double scalars[X]);
    VectorXD<X>& sub(const VectorXD<X>& other);

    VectorXD<X>& mult(double k);
    VectorXD<X>& mult(double scalars[X]);
    VectorXD<X>& mult(const VectorXD<X>& k);

    VectorXD<X>& div(double k);
    VectorXD<X>& div(double scalars[X]);
    VectorXD<X>& div(const VectorXD<X>& k);


    double dotProduct(const VectorXD<X>& other) const;

    VectorXD<X>& crossProduct(const VectorXD<X>& other);
    static VectorXD<X> crossProduct(const VectorXD<X> &v1, const VectorXD<X> &v2);

    double norm() const;

    VectorXD<X> operator+() const;
    VectorXD<X> operator+(const double& k) const;
    VectorXD<X>& operator+=(const double& k);
    VectorXD<X> operator+(const VectorXD<X>& other) const;
    VectorXD<X>& operator+=(const VectorXD<X>& other);

    VectorXD<X> operator-() const;
    VectorXD<X> operator-(const double& k) const;
    VectorXD<X>& operator-=(const double& k);
    VectorXD<X> operator-(const VectorXD<X>& other) const;
    VectorXD<X>& operator-=(const VectorXD<X>& other);

    VectorXD<X> operator*(const double& k) const;
    VectorXD<X>& operator*=(const double& k);
    VectorXD<X> operator*(const VectorXD<X>& other) const;
    VectorXD<X>& operator*=(const VectorXD<X>& other);

    VectorXD<X> operator/(const double& k) const;
    VectorXD<X>& operator/=(const double& k);

    bool operator==(const VectorXD<X>& other) const;
    bool operator!=(const VectorXD<X>& other) const;

    bool operator!() const;
    operator bool() const;

protected:
    double _scalars[X];
};

tmpl QDebug operator<<(QDebug dbg, const VectorXD<X>& v);

#include "vectorxd.hxx"

#endif // VECTORXD_H
