/****************************************************************************
** Meta object code from reading C++ file 'Picaria.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.1.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Picaria/Picaria.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Picaria.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.1.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Picaria_t {
    const uint offsetsAndSize[56];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Picaria_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Picaria_t qt_meta_stringdata_Picaria = {
    {
QT_MOC_LITERAL(0, 7), // "Picaria"
QT_MOC_LITERAL(8, 11), // "modeChanged"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 13), // "Picaria::Mode"
QT_MOC_LITERAL(35, 4), // "mode"
QT_MOC_LITERAL(40, 8), // "gameOver"
QT_MOC_LITERAL(49, 15), // "Picaria::Player"
QT_MOC_LITERAL(65, 6), // "player"
QT_MOC_LITERAL(72, 4), // "play"
QT_MOC_LITERAL(77, 2), // "id"
QT_MOC_LITERAL(80, 5), // "reset"
QT_MOC_LITERAL(86, 9), // "showAbout"
QT_MOC_LITERAL(96, 10), // "updateMode"
QT_MOC_LITERAL(107, 8), // "QAction*"
QT_MOC_LITERAL(116, 6), // "action"
QT_MOC_LITERAL(123, 15), // "updateStatusBar"
QT_MOC_LITERAL(139, 15), // "setNeighborhood"
QT_MOC_LITERAL(155, 15), // "toggleEasterEgg"
QT_MOC_LITERAL(171, 12), // "showGameOver"
QT_MOC_LITERAL(184, 4), // "Mode"
QT_MOC_LITERAL(189, 9), // "NineHoles"
QT_MOC_LITERAL(199, 13), // "ThirteenHoles"
QT_MOC_LITERAL(213, 6), // "Player"
QT_MOC_LITERAL(220, 9), // "RedPlayer"
QT_MOC_LITERAL(230, 10), // "BluePlayer"
QT_MOC_LITERAL(241, 5), // "Phase"
QT_MOC_LITERAL(247, 9), // "DropPhase"
QT_MOC_LITERAL(257, 9) // "MovePhase"

    },
    "Picaria\0modeChanged\0\0Picaria::Mode\0"
    "mode\0gameOver\0Picaria::Player\0player\0"
    "play\0id\0reset\0showAbout\0updateMode\0"
    "QAction*\0action\0updateStatusBar\0"
    "setNeighborhood\0toggleEasterEgg\0"
    "showGameOver\0Mode\0NineHoles\0ThirteenHoles\0"
    "Player\0RedPlayer\0BluePlayer\0Phase\0"
    "DropPhase\0MovePhase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Picaria[] = {

 // content:
       9,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       1,   94, // properties
       3,   99, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       5,    1,   77,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   80,    2, 0x08,    5 /* Private */,
      10,    0,   83,    2, 0x08,    7 /* Private */,
      11,    0,   84,    2, 0x08,    8 /* Private */,
      12,    1,   85,    2, 0x08,    9 /* Private */,
      15,    0,   88,    2, 0x08,   11 /* Private */,
      16,    0,   89,    2, 0x08,   12 /* Private */,
      17,    0,   90,    2, 0x08,   13 /* Private */,
      18,    1,   91,    2, 0x08,   14 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

 // properties: name, type, flags
       4, 0x80000000 | 3, 0x0001510b, uint(0), 0,

 // enums: name, alias, flags, count, data
      19,   19, 0x0,    2,  114,
      22,   22, 0x0,    2,  118,
      25,   25, 0x0,    2,  122,

 // enum data: key, value
      20, uint(Picaria::NineHoles),
      21, uint(Picaria::ThirteenHoles),
      23, uint(Picaria::RedPlayer),
      24, uint(Picaria::BluePlayer),
      26, uint(Picaria::DropPhase),
      27, uint(Picaria::MovePhase),

       0        // eod
};

void Picaria::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Picaria *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->modeChanged((*reinterpret_cast< Picaria::Mode(*)>(_a[1]))); break;
        case 1: _t->gameOver((*reinterpret_cast< Picaria::Player(*)>(_a[1]))); break;
        case 2: _t->play((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->reset(); break;
        case 4: _t->showAbout(); break;
        case 5: _t->updateMode((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 6: _t->updateStatusBar(); break;
        case 7: _t->setNeighborhood(); break;
        case 8: _t->toggleEasterEgg(); break;
        case 9: _t->showGameOver((*reinterpret_cast< Picaria::Player(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Picaria::*)(Picaria::Mode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Picaria::modeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Picaria::*)(Picaria::Player );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Picaria::gameOver)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Picaria *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< Picaria::Mode*>(_v) = _t->mode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Picaria *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setMode(*reinterpret_cast< Picaria::Mode*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject Picaria::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Picaria.offsetsAndSize,
    qt_meta_data_Picaria,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Picaria_t
, QtPrivate::TypeAndForceComplete<Picaria::Mode, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Picaria::Mode, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Picaria::Player, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QAction *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Picaria::Player, std::false_type>


>,
    nullptr
} };


const QMetaObject *Picaria::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Picaria::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Picaria.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Picaria::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Picaria::modeChanged(Picaria::Mode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Picaria::gameOver(Picaria::Player _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
