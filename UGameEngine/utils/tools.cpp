#include "tools.h"
#include <math.h>

double Tools::normalizeAngle(double angle)
{
    while (angle >= 360.0) {
        angle -= 360.0;
    }
    while (angle < 0.0) {
        angle += 360.0;
    }
    return angle;
}

double Tools::radToDegree(double angle)
{
    return angle * 180.0 / M_PI;
}

double Tools::degreeToRad(double angle)
{
    return angle * M_PI / 180.0;
}
