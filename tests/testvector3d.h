#ifndef TESTVECTOR3D_H
#define TESTVECTOR3D_H

#include <QObject>

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

#endif // TESTVECTOR3D_H
