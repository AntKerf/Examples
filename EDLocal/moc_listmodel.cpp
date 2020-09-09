/****************************************************************************
** Meta object code from reading C++ file 'listmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../EDLocal/listmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'listmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ListModel_t {
    QByteArrayData data[26];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListModel_t qt_meta_stringdata_ListModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ListModel"
QT_MOC_LITERAL(1, 10, 25), // "countSelectSystemsChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 5), // "getId"
QT_MOC_LITERAL(4, 43, 3), // "row"
QT_MOC_LITERAL(5, 47, 18), // "getCountRowVisible"
QT_MOC_LITERAL(6, 66, 10), // "getNumPage"
QT_MOC_LITERAL(7, 77, 21), // "getCountSelectSystems"
QT_MOC_LITERAL(8, 99, 7), // "getName"
QT_MOC_LITERAL(9, 107, 18), // "setCountRowVisible"
QT_MOC_LITERAL(10, 126, 8), // "countRow"
QT_MOC_LITERAL(11, 135, 10), // "setNumPage"
QT_MOC_LITERAL(12, 146, 10), // "PageSelect"
QT_MOC_LITERAL(13, 157, 15), // "setSearchString"
QT_MOC_LITERAL(14, 173, 3), // "str"
QT_MOC_LITERAL(15, 177, 21), // "setFilterPrimaryStart"
QT_MOC_LITERAL(16, 199, 7), // "setSort"
QT_MOC_LITERAL(17, 207, 6), // "column"
QT_MOC_LITERAL(18, 214, 13), // "Qt::SortOrder"
QT_MOC_LITERAL(19, 228, 5), // "order"
QT_MOC_LITERAL(20, 234, 4), // "sort"
QT_MOC_LITERAL(21, 239, 11), // "updateModel"
QT_MOC_LITERAL(22, 251, 6), // "select"
QT_MOC_LITERAL(23, 258, 13), // "_queryFilters"
QT_MOC_LITERAL(24, 272, 20), // "_countSelectSysytems"
QT_MOC_LITERAL(25, 293, 18) // "countSelectSystems"

    },
    "ListModel\0countSelectSystemsChanged\0"
    "\0getId\0row\0getCountRowVisible\0getNumPage\0"
    "getCountSelectSystems\0getName\0"
    "setCountRowVisible\0countRow\0setNumPage\0"
    "PageSelect\0setSearchString\0str\0"
    "setFilterPrimaryStart\0setSort\0column\0"
    "Qt::SortOrder\0order\0sort\0updateModel\0"
    "select\0_queryFilters\0_countSelectSysytems\0"
    "countSelectSystems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       1,  130, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   95,    2, 0x0a /* Public */,
       5,    0,   98,    2, 0x0a /* Public */,
       6,    0,   99,    2, 0x0a /* Public */,
       7,    0,  100,    2, 0x0a /* Public */,
       8,    1,  101,    2, 0x0a /* Public */,
       9,    1,  104,    2, 0x0a /* Public */,
      11,    1,  107,    2, 0x0a /* Public */,
      13,    1,  110,    2, 0x0a /* Public */,
      15,    1,  113,    2, 0x0a /* Public */,
      16,    2,  116,    2, 0x0a /* Public */,
      20,    2,  121,    2, 0x0a /* Public */,
      21,    0,  126,    2, 0x08 /* Private */,
      22,    0,  127,    2, 0x08 /* Private */,
      23,    0,  128,    2, 0x08 /* Private */,
      24,    0,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int, QMetaType::Int,    4,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 18,   17,   19,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 18,   17,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      25, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,

       0        // eod
};

void ListModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ListModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->countSelectSystemsChanged(); break;
        case 1: { int _r = _t->getId((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: { int _r = _t->getCountRowVisible();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getNumPage();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->getCountSelectSystems();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getName((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->setCountRowVisible((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setNumPage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->setSearchString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setFilterPrimaryStart((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setSort((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 11: _t->sort((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Qt::SortOrder(*)>(_a[2]))); break;
        case 12: _t->updateModel(); break;
        case 13: _t->select(); break;
        case 14: _t->_queryFilters(); break;
        case 15: _t->_countSelectSysytems(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ListModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ListModel::countSelectSystemsChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ListModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getCountSelectSystems(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ListModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QSqlQueryModel::staticMetaObject>(),
    qt_meta_stringdata_ListModel.data,
    qt_meta_data_ListModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ListModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ListModel.stringdata0))
        return static_cast<void*>(this);
    return QSqlQueryModel::qt_metacast(_clname);
}

int ListModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSqlQueryModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ListModel::countSelectSystemsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
