#ifndef TESTMATRIX3X3_H
#define TESTMATRIX3X3_H

#include <QObject>

class TestMatrix3x3 : public QObject
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

    void mult1();
};

#endif // TESTMATRIX3X3_H
