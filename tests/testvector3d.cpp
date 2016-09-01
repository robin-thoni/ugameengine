#include <QtTest/QtTest>
#include "vector3d.h"

class TestVector3D : public QObject
{
    Q_OBJECT

private slots:
    void gettersSetters1();
    void gettersSetters2();
    void gettersSetters3();

    void isNull1();
    void isNull1Op();
    void isNull2();
    void isNull2Op();

    void equal1();
    void equal2();
    void equal3();
    void equal4();
    void equal5();
    void equal6();

    void add1();
    void add1Op();
    void add2();
    void add2Op();
    void add3Op();

    void sub1();
    void sub1Op();
    void sub2();
    void sub2Op();
    void sub3Op();

    void mult();
    void multOp();


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

void TestVector3D::isNull1()
{
    double x = 1.42, y = 2.0, z = 3.0;
    Vector3D v(x, y, z);
    QCOMPARE(v.isNull(), false);
}

void TestVector3D::isNull1Op()
{
    double x = 1.42, y = 2.0, z = 3.0;
    Vector3D v(x, y, z);
    QCOMPARE((bool)v, true);
}

void TestVector3D::isNull2()
{
    Vector3D v;
    QCOMPARE(v.isNull(), true);
}

void TestVector3D::isNull2Op()
{
    Vector3D v;
    QCOMPARE(!v, true);
}

void TestVector3D::equal1()
{
    Vector3D v1(1.42, 2.0, 3.0);
    Vector3D v2(1.42, 2.0, 3.0);
    QCOMPARE(v1.equal(v2), true);
}

void TestVector3D::equal2()
{
    Vector3D v1(1.42, 2.0, 3.0);
    Vector3D v2(1.40, 2.0, 3.0);
    QCOMPARE(v1.equal(v2), false);
}

void TestVector3D::equal3()
{
    Vector3D v1(1.42, 2.0, 3.0);
    Vector3D v2(1.42, 2.1, 3.0);
    QCOMPARE(v1.equal(v2), false);
}

void TestVector3D::equal4()
{
    Vector3D v1(1.42, 2.0, 3.0);
    Vector3D v2(1.42, 2.0, 3.1);
    QCOMPARE(v1.equal(v2), false);
}

void TestVector3D::equal5()
{
    Vector3D v1(1.42, 2.0, 3.0);
    Vector3D v2(1.42, 2.0, 3.1);
    QCOMPARE(v1 == v2, false);
}

void TestVector3D::equal6()
{
    Vector3D v1(1.42, 2.0, 3.0);
    Vector3D v2(1.42, 2.0, 3.0);
    QCOMPARE(v1 == v2, true);
}

void TestVector3D::add1()
{
    double x = 1.42, y = 2.0, z = 3.0, x2 = 0.24, y2 = 24.0, z2 = 42.0;
    Vector3D v(x, y, z);
    v.add(x2, y2, z2);
    QCOMPARE(v.getX(), x + x2);
    QCOMPARE(v.getY(), y + y2);
    QCOMPARE(v.getZ(), z + z2);
}

void TestVector3D::add1Op()
{
    double x = 1.42, y = 2.0, z = 3.0, x2 = 0.24, y2 = 24.0, z2 = 42.0;
    Vector3D v1(x, y, z);
    Vector3D v2(x2, y2, z2);
    Vector3D v = v1 + v2;

    QCOMPARE(v.getX(), x + x2);
    QCOMPARE(v.getY(), y + y2);
    QCOMPARE(v.getZ(), z + z2);

    QCOMPARE(v1.getX(), x);
    QCOMPARE(v1.getY(), y);
    QCOMPARE(v1.getZ(), z);

    QCOMPARE(v2.getX(), x2);
    QCOMPARE(v2.getY(), y2);
    QCOMPARE(v2.getZ(), z2);
}

void TestVector3D::add2()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 0.24;
    Vector3D v(x, y, z);
    v.add(m);
    QCOMPARE(v.getX(), x + m);
    QCOMPARE(v.getY(), y + m);
    QCOMPARE(v.getZ(), z + m);
}

void TestVector3D::add2Op()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 0.24;
    Vector3D v1(x, y, z);
    Vector3D v = v1 + m;

    QCOMPARE(v.getX(), x + m);
    QCOMPARE(v.getY(), y + m);
    QCOMPARE(v.getZ(), z + m);

    QCOMPARE(v1.getX(), x);
    QCOMPARE(v1.getY(), y);
    QCOMPARE(v1.getZ(), z);
}

void TestVector3D::add3Op()
{
    double x = 1.42, y = 2.0, z = 3.0;
    Vector3D v1(x, y, z);
    Vector3D v = +v1;

    QCOMPARE(v.getX(), x);
    QCOMPARE(v.getY(), y);
    QCOMPARE(v.getZ(), z);

    QCOMPARE(v1.getX(), x);
    QCOMPARE(v1.getY(), y);
    QCOMPARE(v1.getZ(), z);
}

void TestVector3D::sub1()
{
    double x = 1.42, y = 2.0, z = 3.0, x2 = 0.24, y2 = 24.0, z2 = 42.0;
    Vector3D v(x, y, z);
    v.sub(x2, y2, z2);
    QCOMPARE(v.getX(), x - x2);
    QCOMPARE(v.getY(), y - y2);
    QCOMPARE(v.getZ(), z - z2);
}

void TestVector3D::sub1Op()
{
    double x = 1.42, y = 2.0, z = 3.0, x2 = 0.24, y2 = 24.0, z2 = 42.0;
    Vector3D v1(x, y, z);
    Vector3D v2(x2, y2, z2);
    Vector3D v = v1 - v2;

    QCOMPARE(v.getX(), x - x2);
    QCOMPARE(v.getY(), y - y2);
    QCOMPARE(v.getZ(), z - z2);

    QCOMPARE(v1.getX(), x);
    QCOMPARE(v1.getY(), y);
    QCOMPARE(v1.getZ(), z);

    QCOMPARE(v2.getX(), x2);
    QCOMPARE(v2.getY(), y2);
    QCOMPARE(v2.getZ(), z2);
}

void TestVector3D::sub2()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 0.24;
    Vector3D v(x, y, z);
    v.sub(m);
    QCOMPARE(v.getX(), x - m);
    QCOMPARE(v.getY(), y - m);
    QCOMPARE(v.getZ(), z - m);
}

void TestVector3D::sub2Op()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 0.24;
    Vector3D v1(x, y, z);
    Vector3D v = v1 - m;

    QCOMPARE(v.getX(), x - m);
    QCOMPARE(v.getY(), y - m);
    QCOMPARE(v.getZ(), z - m);

    QCOMPARE(v1.getX(), x);
    QCOMPARE(v1.getY(), y);
    QCOMPARE(v1.getZ(), z);
}

void TestVector3D::sub3Op()
{
    double x = 1.42, y = 2.0, z = 3.0;
    Vector3D v1(x, y, z);
    Vector3D v = -v1;

    QCOMPARE(v.getX(), -x);
    QCOMPARE(v.getY(), -y);
    QCOMPARE(v.getZ(), -z);

    QCOMPARE(v1.getX(), x);
    QCOMPARE(v1.getY(), y);
    QCOMPARE(v1.getZ(), z);
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

void TestVector3D::multOp()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 2.0;
    Vector3D v1(x, y, z);
    Vector3D v = v1 * m;
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
