/****************************************************************************
** Meta object code from reading C++ file 'customplantplace.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AutoPlacingforPVZ/customplantplace.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customplantplace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPlantMoniterENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSPlantMoniterENDCLASS = QtMocHelpers::stringData(
    "PlantMoniter",
    "updateValues",
    "",
    "changetype",
    "p0",
    "p1",
    "threadend"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPlantMoniterENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[3];
    char stringdata5[3];
    char stringdata6[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPlantMoniterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPlantMoniterENDCLASS_t qt_meta_stringdata_CLASSPlantMoniterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "PlantMoniter"
        QT_MOC_LITERAL(13, 12),  // "updateValues"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 10),  // "changetype"
        QT_MOC_LITERAL(38, 2),  // "p0"
        QT_MOC_LITERAL(41, 2),  // "p1"
        QT_MOC_LITERAL(44, 9)   // "threadend"
    },
    "PlantMoniter",
    "updateValues",
    "",
    "changetype",
    "p0",
    "p1",
    "threadend"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlantMoniterENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   26,    2, 0x06,    1 /* Public */,
       6,    0,   33,    2, 0x06,    5 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlantMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSPlantMoniterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPlantMoniterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPlantMoniterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlantMoniter, std::true_type>,
        // method 'updateValues'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'threadend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PlantMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlantMoniter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateValues((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->threadend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlantMoniter::*)(int , int , int );
            if (_t _q_method = &PlantMoniter::updateValues; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlantMoniter::*)();
            if (_t _q_method = &PlantMoniter::threadend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *PlantMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlantMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPlantMoniterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PlantMoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void PlantMoniter::updateValues(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlantMoniter::threadend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASScustomplantplaceENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASScustomplantplaceENDCLASS = QtMocHelpers::stringData(
    "customplantplace",
    "on_exitbutton_clicked",
    "",
    "on_updateplant_clicked",
    "showgrid_slot",
    "on_isrealtime_stateChanged",
    "arg1",
    "on_deleteplant_clicked",
    "on_clear_clicked",
    "on_plantplace_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASScustomplantplaceENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[17];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[14];
    char stringdata5[27];
    char stringdata6[5];
    char stringdata7[23];
    char stringdata8[17];
    char stringdata9[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASScustomplantplaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASScustomplantplaceENDCLASS_t qt_meta_stringdata_CLASScustomplantplaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "customplantplace"
        QT_MOC_LITERAL(17, 21),  // "on_exitbutton_clicked"
        QT_MOC_LITERAL(39, 0),  // ""
        QT_MOC_LITERAL(40, 22),  // "on_updateplant_clicked"
        QT_MOC_LITERAL(63, 13),  // "showgrid_slot"
        QT_MOC_LITERAL(77, 26),  // "on_isrealtime_stateChanged"
        QT_MOC_LITERAL(104, 4),  // "arg1"
        QT_MOC_LITERAL(109, 22),  // "on_deleteplant_clicked"
        QT_MOC_LITERAL(132, 16),  // "on_clear_clicked"
        QT_MOC_LITERAL(149, 21)   // "on_plantplace_clicked"
    },
    "customplantplace",
    "on_exitbutton_clicked",
    "",
    "on_updateplant_clicked",
    "showgrid_slot",
    "on_isrealtime_stateChanged",
    "arg1",
    "on_deleteplant_clicked",
    "on_clear_clicked",
    "on_plantplace_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScustomplantplaceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    1,   58,    2, 0x08,    3 /* Private */,
       5,    1,   61,    2, 0x08,    5 /* Private */,
       7,    0,   64,    2, 0x08,    7 /* Private */,
       8,    0,   65,    2, 0x08,    8 /* Private */,
       9,    0,   66,    2, 0x08,    9 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject customplantplace::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASScustomplantplaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScustomplantplaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScustomplantplaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<customplantplace, std::true_type>,
        // method 'on_exitbutton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateplant_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showgrid_slot'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_isrealtime_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_deleteplant_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_plantplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void customplantplace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<customplantplace *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_exitbutton_clicked(); break;
        case 1: _t->on_updateplant_clicked(); break;
        case 2: _t->showgrid_slot((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->on_isrealtime_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_deleteplant_clicked(); break;
        case 5: _t->on_clear_clicked(); break;
        case 6: _t->on_plantplace_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *customplantplace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customplantplace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScustomplantplaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int customplantplace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP