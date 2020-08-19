#include "convert.h"

QString convert::value()
{
    return m_value;
}

void convert::setValue(const QString &value)
{
    if(value!=m_value)
    {
        m_value=value;
        if(m_mode)calcValue1();
        emit valueChanged();
    }
    else return;
}

QString convert::nominal()
{
    return m_nominal;
}

void convert::setNominal(const QString &nominal)
{
    if(nominal!= m_nominal)
    {
        m_nominal=nominal;
        if(m_mode)calcValue1();
        if(!m_mode)calcValue();
        emit nominalChanged();
    }
    else return;
}

QString convert::value1()
{
    return m_value1;
}

void convert::setValue1(const QString &value)
{
    if(value!=m_value1)
    {

        m_value1=value;
        if(!m_mode)calcValue();
        emit value1Changed();
    }
    else return;
}

QString convert::nominal1()
{
    return m_nominal1;
}

void convert::setNominal1(const QString &nominal)
{
    if(nominal!= m_nominal1)
    {
        m_nominal1=nominal;
        emit nominal1Changed();
    }
    else return;
}

void convert::calcValue1()
{
    bool ok = true;
    QLocale::setDefault(QLocale::German);
    QLocale g(QLocale::German);
    if(m_convert_N_Rf)
    {//перевод не в рубль РФ
        double tmp=g.toDouble(m_value,&ok);
        double tmp2=g.toDouble(m_kurs,&ok)/g.toDouble(m_nominal,&ok);
        tmp *=tmp2;
        tmp /=g.toDouble(m_kurs1,&ok);
        tmp *=g.toDouble(m_nominal1,&ok);
        setValue1(g.toString(tmp,'f',2));
    }
    else
    {
        double tmp=g.toDouble(m_value,&ok);
        double tmp2=g.toDouble(m_kurs,&ok)/g.toDouble(m_nominal,&ok);
        tmp *=tmp2;
        setValue1(g.toString(tmp,'f',2));
    }

}

void convert::calcValue()
{
    bool ok = true;
    QLocale::setDefault(QLocale::German);
    QLocale g(QLocale::German);
    if(m_convert_N_Rf)
    {//перевод не из рубля РФ
        double tmp=g.toDouble(m_value1,&ok)/g.toDouble(m_kurs,&ok);
        tmp *=g.toDouble(m_nominal,&ok);
        double tmp3=g.toDouble(m_kurs1,&ok)/g.toDouble(m_nominal1,&ok);
        tmp *=tmp3;
        setValue(g.toString(tmp,'f',2));
    }
    else
    {
        double tmp=g.toDouble(m_value1,&ok)/g.toDouble(m_kurs,&ok);
        double tmp2=g.toDouble(m_nominal,&ok);
        tmp *=tmp2;
        setValue(g.toString(tmp,'f',2));
    }

}

convert::convert(QObject *parent) : QObject(parent)
{
}

bool convert::mode()
{
    return m_mode;
}

void convert::setMode(const bool b)
{
  if(b!=m_mode)
  {
      m_mode=b;
      emit modeChanged();
  }
  else return;
}

bool convert::Convert_N_Rf()
{
    return m_convert_N_Rf;
}

void convert::setConvert_N_Rf(const bool b)
{
    if(b!=m_convert_N_Rf)
    {
        m_convert_N_Rf=b;
        emit Convert_N_RfChanged();
    }
    else return;
}

QString convert::name()
{
    return m_name;
}

void convert::setName(const QString &name)
{
    if(name!=m_name)
    {
        m_name=name;
        emit nameChanged();
    }
    else return;
}

QString convert::name1()
{
    return m_name1;
}

void convert::setName1(const QString &name)
{
    if(name!=m_name1)
    {
        m_name1=name;
        emit name1Changed();
    }
    else return;
}

QString convert::kurs()
{
    return m_kurs;
}

void convert::setKurs(const QString &kurs)
{
    if(kurs!=m_kurs)
    {
        m_kurs=kurs;
        if(m_mode)calcValue1();
        else calcValue();
        emit kursChanged();
    }
    else return;
}

QString convert::kurs1()
{
    return m_kurs1;
}

void convert::setKurs1(const QString &kurs)
{
    if(kurs!=m_kurs1)
    {
        m_kurs1=kurs;
        emit kurs1Changed();
    }
    else return;
}
