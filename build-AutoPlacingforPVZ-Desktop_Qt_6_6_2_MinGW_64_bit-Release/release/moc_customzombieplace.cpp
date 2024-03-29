/****************************************************************************
** Meta object code from reading C++ file 'customzombieplace.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AutoPlacingforPVZ/customzombieplace.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'customzombieplace.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSZombieMoniterENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSZombieMoniterENDCLASS = QtMocHelpers::stringData(
    "ZombieMoniter",
    "updateValue",
    "",
    "uint32_t",
    "num",
    "currentDateTime",
    "deadzombie"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSZombieMoniterENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[14];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[4];
    char stringdata5[16];
    char stringdata6[11];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSZombieMoniterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSZombieMoniterENDCLASS_t qt_meta_stringdata_CLASSZombieMoniterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "ZombieMoniter"
        QT_MOC_LITERAL(14, 11),  // "updateValue"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 8),  // "uint32_t"
        QT_MOC_LITERAL(36, 3),  // "num"
        QT_MOC_LITERAL(40, 15),  // "currentDateTime"
        QT_MOC_LITERAL(56, 10)   // "deadzombie"
    },
    "ZombieMoniter",
    "updateValue",
    "",
    "uint32_t",
    "num",
    "currentDateTime",
    "deadzombie"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZombieMoniterENDCLASS[] = {

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
       1,    2,   26,    2, 0x06,    1 /* Public */,
       6,    2,   31,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDateTime,    4,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QDateTime,    4,    5,

       0        // eod
};

Q_CONSTINIT const QMetaObject ZombieMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSZombieMoniterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZombieMoniterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZombieMoniterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZombieMoniter, std::true_type>,
        // method 'updateValue'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>,
        // method 'deadzombie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<uint32_t, std::false_type>,
        QtPrivate::TypeAndForceComplete<QDateTime, std::false_type>
    >,
    nullptr
} };

void ZombieMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombieMoniter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateValue((*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2]))); break;
        case 1: _t->deadzombie((*reinterpret_cast< std::add_pointer_t<uint32_t>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombieMoniter::*)(uint32_t , QDateTime );
            if (_t _q_method = &ZombieMoniter::updateValue; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZombieMoniter::*)(uint32_t , QDateTime );
            if (_t _q_method = &ZombieMoniter::deadzombie; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ZombieMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombieMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZombieMoniterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ZombieMoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ZombieMoniter::updateValue(uint32_t _t1, QDateTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZombieMoniter::deadzombie(uint32_t _t1, QDateTime _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASScustomzombieplaceENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASScustomzombieplaceENDCLASS = QtMocHelpers::stringData(
    "customzombieplace",
    "on_reset_clicked",
    "",
    "on_singleplace_clicked",
    "on_rowplace_clicked",
    "on_colplace_clicked",
    "on_realtime_stateChanged",
    "arg1",
    "on_zombielist_currentRowChanged",
    "currentRow",
    "on_pushButton_clicked",
    "on_isdead_stateChanged",
    "on_startcount_clicked",
    "on_stopcount_clicked",
    "on_tofile_clicked",
    "on_exitbutton_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASScustomzombieplaceENDCLASS_t {
    uint offsetsAndSizes[32];
    char stringdata0[18];
    char stringdata1[17];
    char stringdata2[1];
    char stringdata3[23];
    char stringdata4[20];
    char stringdata5[20];
    char stringdata6[25];
    char stringdata7[5];
    char stringdata8[32];
    char stringdata9[11];
    char stringdata10[22];
    char stringdata11[23];
    char stringdata12[22];
    char stringdata13[21];
    char stringdata14[18];
    char stringdata15[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASScustomzombieplaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASScustomzombieplaceENDCLASS_t qt_meta_stringdata_CLASScustomzombieplaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 17),  // "customzombieplace"
        QT_MOC_LITERAL(18, 16),  // "on_reset_clicked"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 22),  // "on_singleplace_clicked"
        QT_MOC_LITERAL(59, 19),  // "on_rowplace_clicked"
        QT_MOC_LITERAL(79, 19),  // "on_colplace_clicked"
        QT_MOC_LITERAL(99, 24),  // "on_realtime_stateChanged"
        QT_MOC_LITERAL(124, 4),  // "arg1"
        QT_MOC_LITERAL(129, 31),  // "on_zombielist_currentRowChanged"
        QT_MOC_LITERAL(161, 10),  // "currentRow"
        QT_MOC_LITERAL(172, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(194, 22),  // "on_isdead_stateChanged"
        QT_MOC_LITERAL(217, 21),  // "on_startcount_clicked"
        QT_MOC_LITERAL(239, 20),  // "on_stopcount_clicked"
        QT_MOC_LITERAL(260, 17),  // "on_tofile_clicked"
        QT_MOC_LITERAL(278, 21)   // "on_exitbutton_clicked"
    },
    "customzombieplace",
    "on_reset_clicked",
    "",
    "on_singleplace_clicked",
    "on_rowplace_clicked",
    "on_colplace_clicked",
    "on_realtime_stateChanged",
    "arg1",
    "on_zombielist_currentRowChanged",
    "currentRow",
    "on_pushButton_clicked",
    "on_isdead_stateChanged",
    "on_startcount_clicked",
    "on_stopcount_clicked",
    "on_tofile_clicked",
    "on_exitbutton_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASScustomzombieplaceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    1,   90,    2, 0x08,    5 /* Private */,
       8,    1,   93,    2, 0x08,    7 /* Private */,
      10,    0,   96,    2, 0x08,    9 /* Private */,
      11,    1,   97,    2, 0x08,   10 /* Private */,
      12,    0,  100,    2, 0x08,   12 /* Private */,
      13,    0,  101,    2, 0x08,   13 /* Private */,
      14,    0,  102,    2, 0x08,   14 /* Private */,
      15,    0,  103,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject customzombieplace::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASScustomzombieplaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASScustomzombieplaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASScustomzombieplaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<customzombieplace, std::true_type>,
        // method 'on_reset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_singleplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rowplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_colplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_realtime_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_zombielist_currentRowChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_isdead_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_startcount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stopcount_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tofile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_exitbutton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void customzombieplace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<customzombieplace *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_reset_clicked(); break;
        case 1: _t->on_singleplace_clicked(); break;
        case 2: _t->on_rowplace_clicked(); break;
        case 3: _t->on_colplace_clicked(); break;
        case 4: _t->on_realtime_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_zombielist_currentRowChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_pushButton_clicked(); break;
        case 7: _t->on_isdead_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_startcount_clicked(); break;
        case 9: _t->on_stopcount_clicked(); break;
        case 10: _t->on_tofile_clicked(); break;
        case 11: _t->on_exitbutton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *customzombieplace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *customzombieplace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASScustomzombieplaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int customzombieplace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
