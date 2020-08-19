/****************************************************************************
** Meta object code from reading C++ file 'convert.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qmltest/convert.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'convert.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_convert_t {
    QByteArrayData data[24];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_convert_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_convert_t qt_meta_stringdata_convert = {
    {
QT_MOC_LITERAL(0, 0, 7), // "convert"
QT_MOC_LITERAL(1, 8, 12), // "valueChanged"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 14), // "nominalChanged"
QT_MOC_LITERAL(4, 37, 13), // "value1Changed"
QT_MOC_LITERAL(5, 51, 15), // "nominal1Changed"
QT_MOC_LITERAL(6, 67, 11), // "nameChanged"
QT_MOC_LITERAL(7, 79, 12), // "name1Changed"
QT_MOC_LITERAL(8, 92, 11), // "kursChanged"
QT_MOC_LITERAL(9, 104, 12), // "kurs1Changed"
QT_MOC_LITERAL(10, 117, 11), // "modeChanged"
QT_MOC_LITERAL(11, 129, 19), // "Convert_N_RfChanged"
QT_MOC_LITERAL(12, 149, 10), // "calcValue1"
QT_MOC_LITERAL(13, 160, 9), // "calcValue"
QT_MOC_LITERAL(14, 170, 7), // "nominal"
QT_MOC_LITERAL(15, 178, 8), // "nominal1"
QT_MOC_LITERAL(16, 187, 5), // "value"
QT_MOC_LITERAL(17, 193, 6), // "value1"
QT_MOC_LITERAL(18, 200, 4), // "name"
QT_MOC_LITERAL(19, 205, 5), // "name1"
QT_MOC_LITERAL(20, 211, 4), // "kurs"
QT_MOC_LITERAL(21, 216, 5), // "kurs1"
QT_MOC_LITERAL(22, 222, 4), // "mode"
QT_MOC_LITERAL(23, 227, 12) // "Convert_N_Rf"

    },
    "convert\0valueChanged\0\0nominalChanged\0"
    "value1Changed\0nominal1Changed\0nameChanged\0"
    "name1Changed\0kursChanged\0kurs1Changed\0"
    "modeChanged\0Convert_N_RfChanged\0"
    "calcValue1\0calcValue\0nominal\0nominal1\0"
    "value\0value1\0name\0name1\0kurs\0kurs1\0"
    "mode\0Convert_N_Rf"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_convert[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
      10,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,
       8,    0,   80,    2, 0x06 /* Public */,
       9,    0,   81,    2, 0x06 /* Public */,
      10,    0,   82,    2, 0x06 /* Public */,
      11,    0,   83,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
      12,    0,   84,    2, 0x02 /* Public */,
      13,    0,   85,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      14, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      16, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      18, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00495103,
      20, QMetaType::QString, 0x00495103,
      21, QMetaType::QString, 0x00495103,
      22, QMetaType::Bool, 0x00495103,
      23, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       1,
       3,
       0,
       2,
       4,
       5,
       6,
       7,
       8,
       9,

       0        // eod
};

void convert::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        convert *_t = static_cast<convert *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged(); break;
        case 1: _t->nominalChanged(); break;
        case 2: _t->value1Changed(); break;
        case 3: _t->nominal1Changed(); break;
        case 4: _t->nameChanged(); break;
        case 5: _t->name1Changed(); break;
        case 6: _t->kursChanged(); break;
        case 7: _t->kurs1Changed(); break;
        case 8: _t->modeChanged(); break;
        case 9: _t->Convert_N_RfChanged(); break;
        case 10: _t->calcValue1(); break;
        case 11: _t->calcValue(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::nominalChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::value1Changed)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::nominal1Changed)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::nameChanged)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::name1Changed)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::kursChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::kurs1Changed)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::modeChanged)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (convert::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convert::Convert_N_RfChanged)) {
                *result = 9;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        convert *_t = static_cast<convert *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->nominal(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->nominal1(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->value(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->value1(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->name1(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->kurs(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->kurs1(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->mode(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->Convert_N_Rf(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        convert *_t = static_cast<convert *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setNominal(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setNominal1(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setValue(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setValue1(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setName1(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setKurs(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setKurs1(*reinterpret_cast< QString*>(_v)); break;
        case 8: _t->setMode(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setConvert_N_Rf(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

const QMetaObject convert::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_convert.data,
      qt_meta_data_convert,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *convert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *convert::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_convert.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int convert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void convert::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void convert::nominalChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void convert::value1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void convert::nominal1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void convert::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void convert::name1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void convert::kursChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void convert::kurs1Changed()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void convert::modeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void convert::Convert_N_RfChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
