#include "matrixdebug.h"

uge_gm_tmpl_mn QDebug operator<<(QDebug dbg, const MatrixMxN<M, N> &v)
{
    QDebug d = dbg.nospace();
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            d << v.getScalar(i, j) << (j == N - 1 ? "" : " ");
        }
        d << "\n";
    }
    return dbg.nospace() << "(" << v.getX() << ", " << v.getY() << ", " << v.getZ() << ")";
}
