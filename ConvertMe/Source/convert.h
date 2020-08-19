#ifndef CONVERT_H
#define CONVERT_H

#include <QObject>
#include <qdebug.h>

class convert : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nominal READ nominal WRITE setNominal NOTIFY nominalChanged)
    Q_PROPERTY(QString nominal1 READ nominal1 WRITE setNominal1 NOTIFY nominal1Changed)
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString value1 READ value1 WRITE setValue1 NOTIFY value1Changed)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString name1 READ name1 WRITE setName1 NOTIFY name1Changed)
    Q_PROPERTY(QString kurs READ kurs WRITE setKurs NOTIFY kursChanged)
    Q_PROPERTY(QString kurs1 READ kurs1 WRITE setKurs1 NOTIFY kurs1Changed)
    Q_PROPERTY(bool mode READ mode WRITE setMode NOTIFY modeChanged)
    Q_PROPERTY(bool Convert_N_Rf READ Convert_N_Rf WRITE setConvert_N_Rf NOTIFY Convert_N_RfChanged)
public:
    explicit convert(QObject *parent = nullptr);

    bool mode();
    void setMode(const bool b);

    bool Convert_N_Rf();
    void setConvert_N_Rf(const bool b);

    QString name();
    void setName(const QString &name);
    QString name1();
    void setName1(const QString &name);

    QString kurs();
    void setKurs(const QString &kurs);
    QString kurs1();
    void setKurs1(const QString &kurs);


    QString value();
    void setValue(const QString &value);
    QString value1();
    void setValue1(const QString &value);

    QString nominal();
    void setNominal(const QString &nominal);
    QString nominal1();
    void setNominal1(const QString &nominal);

   Q_INVOKABLE void calcValue1();
   Q_INVOKABLE void calcValue();

signals:
    void valueChanged();
    void nominalChanged();

    void value1Changed();
    void nominal1Changed();

    void nameChanged();
    void name1Changed();

    void kursChanged();
    void kurs1Changed();

    void modeChanged();
    void Convert_N_RfChanged();

public slots:

private:
    QString m_kurs    = "";
    QString m_kurs1   = "";
    QString m_name    = "";
    QString m_name1   = "";
    QString m_value   = "1";
    QString m_nominal = "";
    QString m_value1  = "";
    QString m_nominal1= "";
    //расчитываем нижнюю строчку?
    bool m_mode       = true;
    //перевод не в рубль РФ?
    bool m_convert_N_Rf = false;
};

#endif // CONVERT_H
