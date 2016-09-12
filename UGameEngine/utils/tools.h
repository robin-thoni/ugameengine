#ifndef TOOLS_H
#define TOOLS_H

#include "utils/matrixmxn.h"

class Tools
{
public:
    static double normalizeAngle(double angle);
    uge_gm_tmpl_mn static MatrixMxN<M, N> normalizeAngle(const MatrixMxN<M, N>& rotation);

    static double radToDegree(double angle);
    uge_gm_tmpl_mn static MatrixMxN<M, N> radToDegree(const MatrixMxN<M, N>& rotation);

    static double degreeToRad(double angle);
    uge_gm_tmpl_mn static MatrixMxN<M, N> degreeToRad(const MatrixMxN<M, N>& rotation);
};

#include "utils/tools.hxx"

#endif // TOOLS_H
