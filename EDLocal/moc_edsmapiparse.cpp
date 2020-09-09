/****************************************************************************
** Meta object code from reading C++ file 'edsmapiparse.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../EDLocal/edsmapiparse.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edsmapiparse.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EdsmApiParse_t {
    QByteArrayData data[21];
    char stringdata0[224];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EdsmApiParse_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EdsmApiParse_t qt_meta_stringdata_EdsmApiParse = {
    {
QT_MOC_LITERAL(0, 0, 12), // "EdsmApiParse"
QT_MOC_LITERAL(1, 13, 11), // "getResponse"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 14), // "QNetworkReply*"
QT_MOC_LITERAL(4, 41, 5), // "reply"
QT_MOC_LITERAL(5, 47, 11), // "splitSystem"
QT_MOC_LITERAL(6, 59, 13), // "QJsonValueRef"
QT_MOC_LITERAL(7, 73, 11), // "splitCoords"
QT_MOC_LITERAL(8, 85, 9), // "splitInfo"
QT_MOC_LITERAL(9, 95, 13), // "splitPrimStar"
QT_MOC_LITERAL(10, 109, 15), // "handleJsonAcync"
QT_MOC_LITERAL(11, 125, 20), // "std::queue<QString>&"
QT_MOC_LITERAL(12, 146, 6), // "size_t"
QT_MOC_LITERAL(13, 153, 11), // "ThreadCount"
QT_MOC_LITERAL(14, 165, 5), // "bool&"
QT_MOC_LITERAL(15, 171, 10), // "handleJson"
QT_MOC_LITERAL(16, 182, 7), // "GetCube"
QT_MOC_LITERAL(17, 190, 10), // "SystemName"
QT_MOC_LITERAL(18, 201, 4), // "size"
QT_MOC_LITERAL(19, 206, 12), // "FromFileJson"
QT_MOC_LITERAL(20, 219, 4) // "Path"

    },
    "EdsmApiParse\0getResponse\0\0QNetworkReply*\0"
    "reply\0splitSystem\0QJsonValueRef\0"
    "splitCoords\0splitInfo\0splitPrimStar\0"
    "handleJsonAcync\0std::queue<QString>&\0"
    "size_t\0ThreadCount\0bool&\0handleJson\0"
    "GetCube\0SystemName\0size\0FromFileJson\0"
    "Path"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EdsmApiParse[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       7,    1,   70,    2, 0x08 /* Private */,
       8,    1,   73,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      10,    3,   79,    2, 0x08 /* Private */,
      15,    2,   86,    2, 0x08 /* Private */,
      16,    1,   91,    2, 0x0a /* Public */,
      16,    2,   94,    2, 0x0a /* Public */,
      19,    1,   99,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Bool, 0x80000000 | 6,    2,
    QMetaType::Bool, 0x80000000 | 6,    2,
    QMetaType::Bool, 0x80000000 | 6,    2,
    QMetaType::Bool, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 12, 0x80000000 | 14,    2,   13,    2,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 14,    2,    2,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,
    QMetaType::Void, QMetaType::QString,   20,

       0        // eod
};

void EdsmApiParse::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EdsmApiParse *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->getResponse((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 1: { bool _r = _t->splitSystem((*reinterpret_cast< QJsonValueRef(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->splitCoords((*reinterpret_cast< QJsonValueRef(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->splitInfo((*reinterpret_cast< QJsonValueRef(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->splitPrimStar((*reinterpret_cast< QJsonValueRef(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->handleJsonAcync((*reinterpret_cast< std::queue<QString>(*)>(_a[1])),(*reinterpret_cast< size_t(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 6: _t->handleJson((*reinterpret_cast< std::queue<QString>(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 7: _t->GetCube((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->GetCube((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 9: _t->FromFileJson((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EdsmApiParse::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EdsmApiParse.data,
    qt_meta_data_EdsmApiParse,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EdsmApiParse::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EdsmApiParse::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EdsmApiParse.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EdsmApiParse::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
