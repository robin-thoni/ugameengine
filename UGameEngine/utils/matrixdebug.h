#ifndef MATRIXDEBUG_H
#define MATRIXDEBUG_H

#include <QDebug>
#include "matrixmxn.h"

uge_gm_tmpl_mn QDebug operator<<(QDebug dbg, const MatrixMxN<M, N>& v);

#include "matrixdebug.hxx"

#endif // MATRIXDEBUG_H
