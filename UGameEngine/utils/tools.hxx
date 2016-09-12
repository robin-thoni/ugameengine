#ifndef TOOLS_HXX
#define TOOLS_HXX

#include <math.h>
#define uge_gm_tmpl_mn template<unsigned M, unsigned N>

uge_gm_tmpl_mn MatrixMxN<M, N> Tools::normalizeAngle(const MatrixMxN<M, N> &rotation)
{
    MatrixMxN<M, N> other;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            other.setScalar(i, j, normalizeAngle(rotation.getScalar(i)));
        }
    }
    return other;
}

uge_gm_tmpl_mn MatrixMxN<M, N> Tools::radToDegree(const MatrixMxN<M, N> &rotation)
{
    return rotation * MatrixMxN<M, N>(180.0 / M_PI);
}

uge_gm_tmpl_mn MatrixMxN<M, N> Tools::degreeToRad(const MatrixMxN<M, N> &rotation)
{
    return rotation * MatrixMxN<M, N>(M_PI / 180.0);
}

#endif // TOOLS_HXX
