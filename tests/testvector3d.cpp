#include <QtTest/QtTest>
#include "vector3d.h"

class TestVector3D : public QObject
{
    Q_OBJECT

private slots:
    void gettersSetters1();
    void gettersSetters2();
    void gettersSetters3();
    void mult();
    void div();
};

void TestVector3D::gettersSetters1()
{
    Vector3D v;
    QCOMPARE(v.getX(), 0.0);
    QCOMPARE(v.getY(), 0.0);
    QCOMPARE(v.getZ(), 0.0);
}

void TestVector3D::gettersSetters2()
{
    double x = 1.42, y = 2.0, z = 3.0;
    Vector3D v(x, y, z);
    QCOMPARE(v.getX(), x);
    QCOMPARE(v.getY(), y);
    QCOMPARE(v.getZ(), z);
}

void TestVector3D::gettersSetters3()
{
    double x = 1.42, y = 2.0, z = 3.0;
    Vector3D v;
    v.setX(x).setY(y).setZ(z);
    QCOMPARE(v.getX(), x);
    QCOMPARE(v.getY(), y);
    QCOMPARE(v.getZ(), z);
}

void TestVector3D::mult()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 2.0;
    Vector3D v(x, y, z);
    v.mult(m);
    QCOMPARE(v.getX(), x * m);
    QCOMPARE(v.getY(), y * m);
    QCOMPARE(v.getZ(), z * m);
}

void TestVector3D::div()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 2.0;
    Vector3D v(x, y, z);
    v.div(m);
    QCOMPARE(v.getX(), x / m);
    QCOMPARE(v.getY(), y / m);
    QCOMPARE(v.getZ(), z / m);
}

QTEST_MAIN(TestVector3D)
#include "testvector3d.moc"
