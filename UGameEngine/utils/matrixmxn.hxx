#define uge_gm_tmpl_mnt template<unsigned M, unsigned N, class T>
#define uge_gm_tmpl_mn template<unsigned M, unsigned N>

uge_gm_tmpl_mn MatrixMxN<M, N>::MatrixMxN()
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] = 0;
        }
    }
}

uge_gm_tmpl_mn MatrixMxN<M, N>::MatrixMxN(double k)
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] = k;
        }
    }
}

uge_gm_tmpl_mn MatrixMxN<M, N>::MatrixMxN(double scalars[M][N])
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            _scalars[i][j] = scalars[i][j];
        }
    }
}

uge_gm_tmpl_mn MatrixMxN<M, N>::~MatrixMxN()
{
}

uge_gm_tmpl_mnt GenericMatrix<M, N, T>::~GenericMatrix()
{
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

uge_gm_tmpl_mnt T *GenericMatrix<M, N, T>::getThis() const
{
    return (T*)this;
}

uge_gm_tmpl_mnt bool GenericMatrix<M, N, T>::isNull() const
{
    return equal(T());
}

uge_gm_tmpl_mnt bool GenericMatrix<M, N, T>::equal(const T &other) const
{
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (_scalars[i][j] != other._scalars[i][j]) {
                return false;
            }
        }
    }
    return true;
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
            _scalars[i][j] += other._scalars[i][j];
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
            _scalars[i][j] -= other._scalars[i][j];
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

uge_gm_tmpl_mnt uge_gm_tmpl_p MatrixMxN<M, P> GenericMatrix<M, N, T>::mult(double scalars[N][P])
{
    return mult(MatrixMxN<N, P>(scalars));
}

uge_gm_tmpl_mnt uge_gm_tmpl_p MatrixMxN<M, P> GenericMatrix<M, N, T>::mult(const MatrixMxN<N, P>& other)
{
    MatrixMxN<N, P> m;
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
            _scalars[i][j] /= other._scalars[i][j];
        }
    }
    return *getThis();
}
