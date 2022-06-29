/****************************************************************************
** Meta object code from reading C++ file 'Alquerque.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Alquerque/Alquerque.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Alquerque.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Alquerque_t {
    const uint offsetsAndSize[48];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Alquerque_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Alquerque_t qt_meta_stringdata_Alquerque = {
    {
QT_MOC_LITERAL(0, 9), // "Alquerque"
QT_MOC_LITERAL(10, 7), // "endTurn"
QT_MOC_LITERAL(18, 0), // ""
QT_MOC_LITERAL(19, 11), // "SendMessage"
QT_MOC_LITERAL(31, 11), // "const char*"
QT_MOC_LITERAL(43, 7), // "message"
QT_MOC_LITERAL(51, 8), // "EatPiece"
QT_MOC_LITERAL(60, 5), // "Hole*"
QT_MOC_LITERAL(66, 4), // "hole"
QT_MOC_LITERAL(71, 4), // "Play"
QT_MOC_LITERAL(76, 2), // "id"
QT_MOC_LITERAL(79, 11), // "ExecuteTurn"
QT_MOC_LITERAL(91, 7), // "Restart"
QT_MOC_LITERAL(99, 18), // "UnlockEnemyButtons"
QT_MOC_LITERAL(118, 13), // "UnlockButtons"
QT_MOC_LITERAL(132, 11), // "LockButtons"
QT_MOC_LITERAL(144, 16), // "NeighboringHoles"
QT_MOC_LITERAL(161, 7), // "Hole*[]"
QT_MOC_LITERAL(169, 10), // "negithbors"
QT_MOC_LITERAL(180, 12), // "SwitchPlayer"
QT_MOC_LITERAL(193, 5), // "About"
QT_MOC_LITERAL(199, 16), // "UpdateGameStatus"
QT_MOC_LITERAL(216, 10), // "isNeighbor"
QT_MOC_LITERAL(227, 11) // "supNeighbor"

    },
    "Alquerque\0endTurn\0\0SendMessage\0"
    "const char*\0message\0EatPiece\0Hole*\0"
    "hole\0Play\0id\0ExecuteTurn\0Restart\0"
    "UnlockEnemyButtons\0UnlockButtons\0"
    "LockButtons\0NeighboringHoles\0Hole*[]\0"
    "negithbors\0SwitchPlayer\0About\0"
    "UpdateGameStatus\0isNeighbor\0supNeighbor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Alquerque[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   99,    2, 0x08,    2 /* Private */,
       6,    1,  102,    2, 0x08,    4 /* Private */,
       9,    1,  105,    2, 0x08,    6 /* Private */,
      11,    1,  108,    2, 0x08,    8 /* Private */,
      12,    0,  111,    2, 0x08,   10 /* Private */,
      13,    1,  112,    2, 0x08,   11 /* Private */,
      14,    1,  115,    2, 0x08,   13 /* Private */,
      15,    1,  118,    2, 0x08,   15 /* Private */,
      16,    2,  121,    2, 0x08,   17 /* Private */,
      19,    0,  126,    2, 0x08,   20 /* Private */,
      20,    0,  127,    2, 0x08,   21 /* Private */,
      21,    0,  128,    2, 0x08,   22 /* Private */,
      22,    2,  129,    2, 0x08,   23 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 17,    8,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 7, 0x80000000 | 7,    8,   23,

       0        // eod
};

void Alquerque::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Alquerque *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->endTurn(); break;
        case 1: _t->SendMessage((*reinterpret_cast< std::add_pointer_t<const char*>>(_a[1]))); break;
        case 2: _t->EatPiece((*reinterpret_cast< std::add_pointer_t<Hole*>>(_a[1]))); break;
        case 3: _t->Play((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->ExecuteTurn((*reinterpret_cast< std::add_pointer_t<Hole*>>(_a[1]))); break;
        case 5: _t->Restart(); break;
        case 6: _t->UnlockEnemyButtons((*reinterpret_cast< std::add_pointer_t<Hole*>>(_a[1]))); break;
        case 7: _t->UnlockButtons((*reinterpret_cast< std::add_pointer_t<Hole*>>(_a[1]))); break;
        case 8: _t->LockButtons((*reinterpret_cast< std::add_pointer_t<Hole*>>(_a[1]))); break;
        case 9: _t->NeighboringHoles((*reinterpret_cast< std::add_pointer_t<Hole*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Hole*[]>>(_a[2]))); break;
        case 10: _t->SwitchPlayer(); break;
        case 11: _t->About(); break;
        case 12: _t->UpdateGameStatus(); break;
        case 13: { bool _r = _t->isNeighbor((*reinterpret_cast< std::add_pointer_t<Hole*>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Hole*>>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Alquerque::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Alquerque::endTurn)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Alquerque::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Alquerque.offsetsAndSize,
    qt_meta_data_Alquerque,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Alquerque_t
, QtPrivate::TypeAndForceComplete<Alquerque, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>, QtPrivate::TypeAndForceComplete<Hole *, std::false_type>


>,
    nullptr
} };


const QMetaObject *Alquerque::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Alquerque::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Alquerque.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Alquerque::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Alquerque::endTurn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
