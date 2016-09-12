#include <QtTest/QtTest>
#include "utils/matrix3x3.h"
#include "testmatrix3x3.h"

void TestMatrix3x3::gettersSetters1()
{
    Matrix3x3 m;
    QCOMPARE(m.getScalar(0, 0), 0.0);
    QCOMPARE(m.getScalar(0, 1), 0.0);
    QCOMPARE(m.getScalar(1, 0), 0.0);
}

void TestMatrix3x3::gettersSetters2()
{
    double scalars[3][3] = {{0.0, 1.0, 2.0},
                            {3.0, 4.0, 5.0},
                            {6.0, 7.0, 8.0}};
    Matrix3x3 m(scalars);
    QCOMPARE(m.getScalar(0, 0), 0.0);
    QCOMPARE(m.getScalar(0, 1), 1.0);
    QCOMPARE(m.getScalar(1, 0), 3.0);
    QCOMPARE(m.getScalar(1, 2), 5.0);
}

void TestMatrix3x3::gettersSetters3()
{
    Matrix3x3 m;
    m.setScalar(0, 0, 42.0).setScalar(0, 1, 24.0).setScalar(1, 0, 10.0);
    QCOMPARE(m.getScalar(0, 0), 42.0);
    QCOMPARE(m.getScalar(0, 1), 24.0);
    QCOMPARE(m.getScalar(1, 0), 10.0);
}

void TestMatrix3x3::isNull1()
{
    double scalars[3][3] = {{0.0, 1.0, 2.0},
                            {3.0, 4.0, 5.0},
                            {6.0, 7.0, 8.0}};
    Matrix3x3 m(scalars);
    QCOMPARE(m.isNull(), false);
}

void TestMatrix3x3::isNull1Op()
{
//    double scalars[3][3] = {{0.0, 1.0, 2.0},
//                            {3.0, 4.0, 5.0},
//                            {6.0, 7.0, 8.0}};
//    Matrix3x3 m(scalars);
//    QCOMPARE((bool)m, false);
}

void TestMatrix3x3::isNull2()
{
    Matrix3x3 m;
    QCOMPARE(m.isNull(), true);
}

void TestMatrix3x3::isNull2Op()
{
//    Matrix3x3 m;
//    QCOMPARE((bool)m, true);
}
