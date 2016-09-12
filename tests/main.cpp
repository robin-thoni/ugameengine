#include <QApplication>
#include <QtTest/QtTest>

#include "testvector3d.h"
#include "testmatrix3x3.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_Use96Dpi, true);
    QTEST_DISABLE_KEYPAD_NAVIGATION;
    TestVector3D tv3d;
    int rtv3d = QTest::qExec(&tv3d, argc, argv);
    TestMatrix3x3 tm33;
    int rtm33 = QTest::qExec(&tm33, argc, argv);
    return !rtv3d && !rtm33;
}
