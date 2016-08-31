#include <QtTest/QtTest>
#include "vector3d.h"

class TestVector3D : public QObject
{
    Q_OBJECT

private slots:
    void gettersSetters1();
    void gettersSetters2();
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
    Vector3D v(1.42, 2.0, 3.0);
    QCOMPARE(v.getX(), 1.42);
    QCOMPARE(v.getY(), 2.0);
    QCOMPARE(v.getZ(), 3.0);
}

QTEST_MAIN(TestVector3D)
#include "testvector3d.moc"
