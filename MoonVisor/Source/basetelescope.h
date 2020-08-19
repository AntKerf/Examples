#ifndef BASETELESCOPE_H
#define BASETELESCOPE_H
#include "qobject.h"

class baseTelescope:public QObject
{
    Q_OBJECT
    Q_PROPERTY(double apperture READ getApperture WRITE setApperture NOTIFY appertureChanged)
    Q_PROPERTY(double focusT READ getFocusT WRITE setFocusT NOTIFY focusTChanged)
    Q_PROPERTY(double focusO READ getFocusO WRITE setFocusO NOTIFY focusOChanged)
    Q_PROPERTY(double optZoom READ getOptZoom NOTIFY optZoomChanged)
    Q_PROPERTY(double exEye READ getExEye NOTIFY exEyeChanged)
public:
    explicit baseTelescope(QObject *parent = nullptr );

    Q_INVOKABLE void computeOptZoom();
    Q_INVOKABLE void computeExEye();
    double virtual getExEye();
    double virtual getOptZoom();
    double getFocusO();
    double getFocusT();
    double getApperture();

public slots:
    void setApperture(double);
    void setFocusT(double);
    void setFocusO(double);
signals:
    void appertureChanged(double apperture);
    void focusTChanged(double focusT);
    void focusOChanged(double focusO);
    void optZoomChanged(double optZoom);
    void exEyeChanged(double exEye);
private:
    //выходной зрачок (мм)
    double exEye = 0;
    //апертура телескопа (мм)
    double apperture = 0;
    //фокус телескопа (мм)
    double focusT = 0;
    //фокус окуляра (мм)
    double focusO = 0;
    //увеличение (крат)
    double optZoom = 0;
};

#endif // BASETELESCOPE_H
