#ifndef MATRIXMXN_H
#define MATRIXMXN_H

#define uge_gm_tmpl_mnt template<unsigned M, unsigned N, class T>
#define uge_gm_tmpl_mn template<unsigned M, unsigned N>
#define uge_gm_tmpl_p template<unsigned P>
#define uge_gm_tmpl_mntp template<unsigned M, unsigned N, class T, unsigned P>

uge_gm_tmpl_mn class MatrixMxN;

uge_gm_tmpl_mnt class GenericMatrix
{
public:
    virtual ~GenericMatrix();

    static T getIdentityMatrix();

    T& setScalar(unsigned i, unsigned j, double value);
    double getScalar(unsigned i, unsigned j) const;

    bool isNull() const;

    bool equal(const T& other) const;

    T& fill(double k);
    T& fill(double scalars[M][N]);

    T& setToIdentity();

    T& add(double k);
    T& add(double scalars[M][N]);
    T& add(const T& other);

    T& sub(double k);
    T& sub(double scalars[M][N]);
    T& sub(const T& other);

    T& mult(double k);
    T& mult(double scalars[M][N]);
    T& mult(const T& other);
    uge_gm_tmpl_p MatrixMxN<M, P> multMatrix(double scalars[N][P]);
    uge_gm_tmpl_p MatrixMxN<M, P> multMatrix(const MatrixMxN<N, P>& other);

    T& div(double k);
    T& div(double scalars[M][N]);
    T& div(const T& other);

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
    T operator/(const T& other) const;
    T& operator/=(const T& other);

    bool operator==(const T& other) const;
    bool operator!=(const T& other) const;

    bool operator!() const;
    operator bool() const;

protected:
    double _scalars[M][N];

private:
    T* getThis() const;
};

uge_gm_tmpl_mn class MatrixMxN: public GenericMatrix<M, N, MatrixMxN<M, N> >
{
public:
    MatrixMxN();
    MatrixMxN(double k);
    MatrixMxN(double scalars[M][N]);
    virtual ~MatrixMxN();

protected:
    using GenericMatrix<M, N, MatrixMxN<M, N> >::_scalars;
};

#include "matrixmxn.hxx"

#endif // MATRIXMXN_H
