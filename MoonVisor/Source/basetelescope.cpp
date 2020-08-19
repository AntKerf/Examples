#include "basetelescope.h"

baseTelescope::baseTelescope (QObject *parent) : QObject(parent)
{
}

//baseTelescope::baseTelescope(QObject *parent = nullptr ,double dapperture, double dFT, double dFO) : QObject(parent)
//{
//    apperture= dapperture;
//    focusT=dFT;
//    focusO=dFO;
//}

void baseTelescope::computeOptZoom()
{
    double tmp = focusT/focusO;
    if (optZoom == tmp)
        return;

    optZoom = tmp;
    emit optZoomChanged(optZoom);
}

void baseTelescope::computeExEye()
{
    double tmp = apperture/optZoom;
    if (exEye == tmp)
        return;

    exEye = tmp;
    emit exEyeChanged(exEye);
}

void baseTelescope::setApperture(double dApper)
{
    if (apperture == dApper)
        return;

    apperture = dApper;
    emit appertureChanged(apperture);
}

void baseTelescope::setFocusT(double dFT)
{
    if (focusT == dFT)
        return;

    focusT = dFT;
    emit focusTChanged(focusT);
}

void baseTelescope::setFocusO(double dFO)
{
    if (focusO == dFO)
        return;

    focusO = dFO;
    emit focusOChanged(focusO);
}

double baseTelescope::getOptZoom()
{
    computeOptZoom();
    return optZoom;
}

double baseTelescope::getExEye()
{
    computeExEye();
    return exEye;
}

double baseTelescope::getFocusT()
{
    return focusT;
}

double baseTelescope::getFocusO()
{
    return focusO;
}

double baseTelescope::getApperture()
{
    return apperture;
}
