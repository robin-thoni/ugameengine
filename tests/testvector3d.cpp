#include <QtTest/QtTest>
#include "utils/vector3d.h"

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
    void mult1Op();
    void mult2Op();
    void mult3Op();

    void div();
    void divOp();

    void dotProduct1();
    void dotProduct2();

    void crossProduct1();
    void crossProduct2();
    void crossProduct3();

    void norm1();
    void norm2();

    void getScalarOp();
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

void TestVector3D::mult1Op()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 2.0;
    Vector3D v1(x, y, z);
    Vector3D v = v1 * m;
    QCOMPARE(v.getX(), x * m);
    QCOMPARE(v.getY(), y * m);
    QCOMPARE(v.getZ(), z * m);
}

void TestVector3D::mult2Op()
{
    Vector3D v1(1.5, 2.0, 3.0);
    Vector3D v2(42.0, 5.0, 7.0);
    Vector3D v = v1 * v2;
    QCOMPARE(v.getX(), v1.getX() * v2.getX());
    QCOMPARE(v.getY(), v1.getY() * v2.getY());
    QCOMPARE(v.getZ(), v1.getZ() * v2.getZ());
}

void TestVector3D::mult3Op()
{
    Vector3D v1(20.0, 42.0, 10.0);
    Vector3D v2(42.0, 5.0, 7.0);
    Vector3D v = v1 * v2;
    QCOMPARE(v.getX(), v1.getX() * v2.getX());
    QCOMPARE(v.getY(), v1.getY() * v2.getY());
    QCOMPARE(v.getZ(), v1.getZ() * v2.getZ());
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

void TestVector3D::divOp()
{
    double x = 1.42, y = 2.0, z = 3.0, m = 2.0;
    Vector3D v1(x, y, z);
    Vector3D v = v1 / m;
    QCOMPARE(v.getX(), x / m);
    QCOMPARE(v.getY(), y / m);
    QCOMPARE(v.getZ(), z / m);
}

void TestVector3D::dotProduct1()
{
    Vector3D v1(1.5, 2.0, 3.0);
    Vector3D v2(42.0, 5.0, 7.0);
    QCOMPARE(v1.dotProduct(v2), 94.0);
}

void TestVector3D::dotProduct2()
{
    Vector3D v1(20, 42, 10);
    Vector3D v2(42.0, 5.0, 7.0);
    QCOMPARE(v1.dotProduct(v2), 1120.0);
}

void TestVector3D::crossProduct1()
{
    Vector3D v(10.0, 42.0, 5.0);
    Vector3D v2(9.0, 5.0, 4.0);
    v.crossProduct(v2);
    QCOMPARE(v.getX(), 143.0);
    QCOMPARE(v.getY(), 5.0);
    QCOMPARE(v.getZ(), -328.0);
}

void TestVector3D::crossProduct2()
{
    Vector3D v(10.0, 24.0, 8.0);
    Vector3D v2(15.0, 5.0, 0.0);
    v.crossProduct(v2);
    QCOMPARE(v.getX(), -40.0);
    QCOMPARE(v.getY(), 120.0);
    QCOMPARE(v.getZ(), -310.0);
}

void TestVector3D::crossProduct3()
{
    Vector3D v1(10.0, 24.0, 8.0);
    Vector3D v2(15.0, 5.0, 0.0);
    Vector3D v = Vector3D::crossProduct(v1, v2);
    QCOMPARE(v.getX(), -40.0);
    QCOMPARE(v.getY(), 120.0);
    QCOMPARE(v.getZ(), -310.0);
}

void TestVector3D::norm1()
{
    Vector3D v(3.0, 4.0, 0.0);;
    QCOMPARE(v.norm(), 5.0);
}

void TestVector3D::norm2()
{
    Vector3D v(0.0, 30.0, 40.0);;
    QCOMPARE(v.norm(), 50.0);
}

void TestVector3D::getScalarOp()
{
    double x = 1.42, y = 2.0, z = 3.0;
    Vector3D v(x, y, z);
    QCOMPARE(v[0], x);
    QCOMPARE(v[1], y);
    QCOMPARE(v[2], z);
}

QTEST_MAIN(TestVector3D)
#include "testvector3d.moc"
