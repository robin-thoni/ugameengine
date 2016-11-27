#define uge_gm_tmpl_mnt template<unsigned M, unsigned N, class T>
#define uge_gm_tmpl_mn template<unsigned M, unsigned N>

uge_gm_tmpl_mn MatrixMxN<M, N>::MatrixMxN()
{
    this->fill(0.0);
}

uge_gm_tmpl_mn MatrixMxN<M, N>::MatrixMxN(double k)
{
    this->fill(k);
}

uge_gm_tmpl_mn MatrixMxN<M, N>::MatrixMxN(double scalars[M][N])
{
    this->fill(scalars);
}

uge_gm_tmpl_mn MatrixMxN<M, N>::~MatrixMxN()
{
}

uge_gm_tmpl_mnt GenericMatrix<M, N, T>::~GenericMatrix()
{
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::getIdentityMatrix()
{
    T m;
    m.setToIdentity();
    return m;
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::setScalar(unsigned i, unsigned j, double value)
{
    _scalars[i][j] = value;
    return *getThis();
}

uge_gm_tmpl_mnt double GenericMatrix<M, N, T>::getScalar(unsigned i, unsigned j) const
{
    return _scalars[i][j];
}

uge_gm_tmpl_mnt bool GenericMatrix<M, N, T>::isNull() const
{
    return equal(T());
}

uge_gm_tmpl_mnt bool GenericMatrix<M, N, T>::equal(const T &other) const
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (_scalars[i][j] != other.getScalar(i, j)) {
                return false;
            }
        }
    }
    return true;
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::fill(double k)
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] = k;
        }
    }
    return *getThis();
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::fill(double scalars[M][N])
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] = scalars[i][j];
        }
    }
    return *getThis();
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::setToIdentity()
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] = (i == j);
        }
    }
    return *getThis();
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::add(double k)
{
    return add(T(k));
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::add(double scalars[M][N])
{
    return add(T(scalars));
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::add(const T &other)
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] += other.getScalar(i, j);
        }
    }
    return *getThis();
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::sub(double k)
{
    return sub(T(k));
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::sub(double scalars[M][N])
{
    return sub(T(scalars));
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::sub(const T &other)
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] -= other.getScalar(i, j);
        }
    }
    return *getThis();
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::mult(double k)
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] *= k;
        }
    }
    return *getThis();
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::mult(double scalars[M][N])
{
    return mult(T(scalars));
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::mult(const T &other)
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] *= other.getScalar(i, j);
        }
    }
    return *getThis();
}

uge_gm_tmpl_mnt uge_gm_tmpl_p
MatrixMxN<M, P> GenericMatrix<M, N, T>::multMatrix(double scalars[N][P])
{
    return multMatrix(MatrixMxN<N, P>(scalars));
}

uge_gm_tmpl_mnt uge_gm_tmpl_p
MatrixMxN<M, P> GenericMatrix<M, N, T>::multMatrix(const MatrixMxN<N, P>& other)
{
    MatrixMxN<M, P> m;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            double t = 0;
            for (int k = 0; k < N; ++k) {
                t += _scalars[i][k] * other.getScalar(k, j);
            }
            m.setScalar(i, j, t);
        }
    }
    return m;
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::div(double k)
{
    return div(T(k));
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::div(double scalars[M][N])
{
    return div(T(scalars));
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::div(const T &other)
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] /= other.getScalar(i, j);
        }
    }
    return *getThis();
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator+() const
{
    return *getThis();
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator+(const double &k) const
{
    return T(*getThis()).add(k);
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::operator+=(const double &k)
{
    return add(k);
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator+(const T &other) const
{
    return T(*getThis()).add(other);
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::operator+=(const T &other)
{
    return add(other);
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator-() const
{
    return T() - (*getThis());
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator-(const double &k) const
{
    return T(*getThis()).sub(k);
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::operator-=(const double &k)
{
    return sub(k);
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator-(const T &other) const
{
    return T(*getThis()).sub(other);
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::operator-=(const T &other)
{
    return sub(other);
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator*(const double &k) const
{
    return T(*getThis()).mult(k);
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::operator*=(const double &k)
{
    return mult(k);
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator*(const T &other) const
{
    return T(*getThis()).mult(other);
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::operator*=(const T &other)
{
    return mult(other);
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator/(const double &k) const
{
    return T(*getThis()).div(k);
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::operator/=(const double &k)
{
    return div(k);
}

uge_gm_tmpl_mnt T GenericMatrix<M, N, T>::operator/(const T &other) const
{
    return T(*getThis()).div(other);
}

uge_gm_tmpl_mnt T &GenericMatrix<M, N, T>::operator/=(const T &other)
{
    return div(other);
}

uge_gm_tmpl_mnt bool GenericMatrix<M, N, T>::operator==(const T &other) const
{
    return equal(other);
}

uge_gm_tmpl_mnt bool GenericMatrix<M, N, T>::operator!=(const T &other) const
{
    return !equal(other);
}

uge_gm_tmpl_mnt bool GenericMatrix<M, N, T>::operator!() const
{
    return isNull();
}

uge_gm_tmpl_mnt GenericMatrix<M, N, T>::operator bool() const
{
    return !isNull();
}

uge_gm_tmpl_mnt T *GenericMatrix<M, N, T>::getThis() const
{
    return (T*)this;
}
