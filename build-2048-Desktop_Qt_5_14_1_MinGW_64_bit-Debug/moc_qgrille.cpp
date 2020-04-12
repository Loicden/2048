/****************************************************************************
** Meta object code from reading C++ file 'qgrille.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../2048/qgrille.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgrille.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGrille_t {
    QByteArrayData data[25];
    char stringdata0[162];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGrille_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGrille_t qt_meta_stringdata_QGrille = {
    {
QT_MOC_LITERAL(0, 0, 7), // "QGrille"
QT_MOC_LITERAL(1, 8, 4), // "coup"
QT_MOC_LITERAL(2, 13, 0), // ""
QT_MOC_LITERAL(3, 14, 7), // "newGame"
QT_MOC_LITERAL(4, 22, 7), // "getlist"
QT_MOC_LITERAL(5, 30, 5), // "color"
QT_MOC_LITERAL(6, 36, 6), // "string"
QT_MOC_LITERAL(7, 43, 9), // "colortext"
QT_MOC_LITERAL(8, 53, 5), // "case0"
QT_MOC_LITERAL(9, 59, 5), // "case1"
QT_MOC_LITERAL(10, 65, 5), // "case2"
QT_MOC_LITERAL(11, 71, 5), // "case3"
QT_MOC_LITERAL(12, 77, 5), // "case4"
QT_MOC_LITERAL(13, 83, 5), // "case5"
QT_MOC_LITERAL(14, 89, 5), // "case6"
QT_MOC_LITERAL(15, 95, 5), // "case7"
QT_MOC_LITERAL(16, 101, 5), // "case8"
QT_MOC_LITERAL(17, 107, 5), // "case9"
QT_MOC_LITERAL(18, 113, 6), // "case10"
QT_MOC_LITERAL(19, 120, 6), // "case11"
QT_MOC_LITERAL(20, 127, 6), // "case12"
QT_MOC_LITERAL(21, 134, 6), // "case13"
QT_MOC_LITERAL(22, 141, 6), // "case14"
QT_MOC_LITERAL(23, 148, 6), // "case15"
QT_MOC_LITERAL(24, 155, 6) // "QScore"

    },
    "QGrille\0coup\0\0newGame\0getlist\0color\0"
    "string\0colortext\0case0\0case1\0case2\0"
    "case3\0case4\0case5\0case6\0case7\0case8\0"
    "case9\0case10\0case11\0case12\0case13\0"
    "case14\0case15\0QScore"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGrille[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
      17,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x02 /* Public */,
       3,    0,   42,    2, 0x02 /* Public */,
       4,    0,   43,    2, 0x02 /* Public */,
       5,    1,   44,    2, 0x02 /* Public */,
       7,    1,   47,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::Int,    1,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    6,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00095001,
       9, QMetaType::QString, 0x00095001,
      10, QMetaType::QString, 0x00095001,
      11, QMetaType::QString, 0x00095001,
      12, QMetaType::QString, 0x00095001,
      13, QMetaType::QString, 0x00095001,
      14, QMetaType::QString, 0x00095001,
      15, QMetaType::QString, 0x00095001,
      16, QMetaType::QString, 0x00095001,
      17, QMetaType::QString, 0x00095001,
      18, QMetaType::QString, 0x00095001,
      19, QMetaType::QString, 0x00095001,
      20, QMetaType::QString, 0x00095001,
      21, QMetaType::QString, 0x00095001,
      22, QMetaType::QString, 0x00095001,
      23, QMetaType::QString, 0x00095001,
      24, QMetaType::QString, 0x00095001,

       0        // eod
};

void QGrille::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QGrille *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->coup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->newGame(); break;
        case 2: _t->getlist(); break;
        case 3: { QString _r = _t->color((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->colortext((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QGrille *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->case0(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->case1(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->case2(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->case3(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->case4(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->case5(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->case6(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->case7(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->case8(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->case9(); break;
        case 10: *reinterpret_cast< QString*>(_v) = _t->case10(); break;
        case 11: *reinterpret_cast< QString*>(_v) = _t->case11(); break;
        case 12: *reinterpret_cast< QString*>(_v) = _t->case12(); break;
        case 13: *reinterpret_cast< QString*>(_v) = _t->case13(); break;
        case 14: *reinterpret_cast< QString*>(_v) = _t->case14(); break;
        case 15: *reinterpret_cast< QString*>(_v) = _t->case15(); break;
        case 16: *reinterpret_cast< QString*>(_v) = _t->Getscore(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QGrille::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QGrille.data,
    qt_meta_data_QGrille,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QGrille::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGrille::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGrille.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QGrille::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 17;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 17;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
