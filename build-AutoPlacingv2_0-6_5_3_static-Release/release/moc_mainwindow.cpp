/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AutoPlacingv2_0/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
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
struct qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS = QtMocHelpers::stringData(
    "ZombieInfoUpdateThread",
    "updatefinied",
    "",
    "ZombieInfoStruct"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS_t {
    uint offsetsAndSizes[8];
    char stringdata0[23];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[17];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS_t qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 22),  // "ZombieInfoUpdateThread"
        QT_MOC_LITERAL(23, 12),  // "updatefinied"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 16)   // "ZombieInfoStruct"
    },
    "ZombieInfoUpdateThread",
    "updatefinied",
    "",
    "ZombieInfoStruct"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZombieInfoUpdateThreadENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject ZombieInfoUpdateThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZombieInfoUpdateThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZombieInfoUpdateThread, std::true_type>,
        // method 'updatefinied'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ZombieInfoStruct, std::false_type>
    >,
    nullptr
} };

void ZombieInfoUpdateThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombieInfoUpdateThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatefinied((*reinterpret_cast< std::add_pointer_t<ZombieInfoStruct>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombieInfoUpdateThread::*)(ZombieInfoStruct );
            if (_t _q_method = &ZombieInfoUpdateThread::updatefinied; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ZombieInfoUpdateThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombieInfoUpdateThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZombieInfoUpdateThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ZombieInfoUpdateThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ZombieInfoUpdateThread::updatefinied(ZombieInfoStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS = QtMocHelpers::stringData(
    "ZombieStatusMoniter",
    "zombiedeadinfo",
    "",
    "ZombieInfoStruct",
    "num",
    "state",
    "findnewzombie",
    "type",
    "body",
    "armor1",
    "armor2",
    "row",
    "abnormaltermi"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS_t {
    uint offsetsAndSizes[26];
    char stringdata0[20];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[4];
    char stringdata5[6];
    char stringdata6[14];
    char stringdata7[5];
    char stringdata8[5];
    char stringdata9[7];
    char stringdata10[7];
    char stringdata11[4];
    char stringdata12[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS_t qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "ZombieStatusMoniter"
        QT_MOC_LITERAL(20, 14),  // "zombiedeadinfo"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 16),  // "ZombieInfoStruct"
        QT_MOC_LITERAL(53, 3),  // "num"
        QT_MOC_LITERAL(57, 5),  // "state"
        QT_MOC_LITERAL(63, 13),  // "findnewzombie"
        QT_MOC_LITERAL(77, 4),  // "type"
        QT_MOC_LITERAL(82, 4),  // "body"
        QT_MOC_LITERAL(87, 6),  // "armor1"
        QT_MOC_LITERAL(94, 6),  // "armor2"
        QT_MOC_LITERAL(101, 3),  // "row"
        QT_MOC_LITERAL(105, 13)   // "abnormaltermi"
    },
    "ZombieStatusMoniter",
    "zombiedeadinfo",
    "",
    "ZombieInfoStruct",
    "num",
    "state",
    "findnewzombie",
    "type",
    "body",
    "armor1",
    "armor2",
    "row",
    "abnormaltermi"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZombieStatusMoniterENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   32,    2, 0x06,    1 /* Public */,
       6,    7,   39,    2, 0x06,    5 /* Public */,
      12,    0,   54,    2, 0x06,   13 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    2,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    7,    8,    9,   10,    4,   11,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ZombieStatusMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZombieStatusMoniterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZombieStatusMoniter, std::true_type>,
        // method 'zombiedeadinfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<ZombieInfoStruct, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'findnewzombie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'abnormaltermi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ZombieStatusMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombieStatusMoniter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->zombiedeadinfo((*reinterpret_cast< std::add_pointer_t<ZombieInfoStruct>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 1: _t->findnewzombie((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7]))); break;
        case 2: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombieStatusMoniter::*)(ZombieInfoStruct , int , int );
            if (_t _q_method = &ZombieStatusMoniter::zombiedeadinfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZombieStatusMoniter::*)(int , int , int , int , int , int , bool );
            if (_t _q_method = &ZombieStatusMoniter::findnewzombie; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ZombieStatusMoniter::*)();
            if (_t _q_method = &ZombieStatusMoniter::abnormaltermi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ZombieStatusMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombieStatusMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZombieStatusMoniterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ZombieStatusMoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ZombieStatusMoniter::zombiedeadinfo(ZombieInfoStruct _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZombieStatusMoniter::findnewzombie(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, bool _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZombieStatusMoniter::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS = QtMocHelpers::stringData(
    "NewZombieMoniter",
    "abnormaltermi",
    "",
    "findnewzombie",
    "type",
    "body",
    "armor1",
    "armor2",
    "num",
    "row"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS_t {
    uint offsetsAndSizes[20];
    char stringdata0[17];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[5];
    char stringdata5[5];
    char stringdata6[7];
    char stringdata7[7];
    char stringdata8[4];
    char stringdata9[4];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS_t qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "NewZombieMoniter"
        QT_MOC_LITERAL(17, 13),  // "abnormaltermi"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 13),  // "findnewzombie"
        QT_MOC_LITERAL(46, 4),  // "type"
        QT_MOC_LITERAL(51, 4),  // "body"
        QT_MOC_LITERAL(56, 6),  // "armor1"
        QT_MOC_LITERAL(63, 6),  // "armor2"
        QT_MOC_LITERAL(70, 3),  // "num"
        QT_MOC_LITERAL(74, 3)   // "row"
    },
    "NewZombieMoniter",
    "abnormaltermi",
    "",
    "findnewzombie",
    "type",
    "body",
    "armor1",
    "armor2",
    "num",
    "row"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNewZombieMoniterENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   26,    2, 0x06,    1 /* Public */,
       3,    7,   27,    2, 0x06,    2 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    4,    5,    6,    7,    8,    9,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject NewZombieMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNewZombieMoniterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NewZombieMoniter, std::true_type>,
        // method 'abnormaltermi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'findnewzombie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
    >,
    nullptr
} };

void NewZombieMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewZombieMoniter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        case 1: _t->findnewzombie((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewZombieMoniter::*)();
            if (_t _q_method = &NewZombieMoniter::abnormaltermi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NewZombieMoniter::*)(int , int , int , int , int , int , bool );
            if (_t _q_method = &NewZombieMoniter::findnewzombie; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *NewZombieMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewZombieMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNewZombieMoniterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int NewZombieMoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void NewZombieMoniter::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void NewZombieMoniter::findnewzombie(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6, bool _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS = QtMocHelpers::stringData(
    "PlantInfoUpdateThread",
    "updatefinied",
    "",
    "row",
    "col",
    "num",
    "status"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[22];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[4];
    char stringdata5[4];
    char stringdata6[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS_t qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 21),  // "PlantInfoUpdateThread"
        QT_MOC_LITERAL(22, 12),  // "updatefinied"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 3),  // "row"
        QT_MOC_LITERAL(40, 3),  // "col"
        QT_MOC_LITERAL(44, 3),  // "num"
        QT_MOC_LITERAL(48, 6)   // "status"
    },
    "PlantInfoUpdateThread",
    "updatefinied",
    "",
    "row",
    "col",
    "num",
    "status"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlantInfoUpdateThreadENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlantInfoUpdateThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPlantInfoUpdateThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlantInfoUpdateThread, std::true_type>,
        // method 'updatefinied'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void PlantInfoUpdateThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlantInfoUpdateThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatefinied((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlantInfoUpdateThread::*)(int , int , int , int );
            if (_t _q_method = &PlantInfoUpdateThread::updatefinied; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *PlantInfoUpdateThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlantInfoUpdateThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPlantInfoUpdateThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PlantInfoUpdateThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void PlantInfoUpdateThread::updatefinied(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS = QtMocHelpers::stringData(
    "PlantStatusMoniter",
    "plantchange",
    "",
    "row",
    "col",
    "num",
    "status",
    "abnormaltermi"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[19];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[4];
    char stringdata4[4];
    char stringdata5[4];
    char stringdata6[7];
    char stringdata7[14];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS_t qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 18),  // "PlantStatusMoniter"
        QT_MOC_LITERAL(19, 11),  // "plantchange"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 3),  // "row"
        QT_MOC_LITERAL(36, 3),  // "col"
        QT_MOC_LITERAL(40, 3),  // "num"
        QT_MOC_LITERAL(44, 6),  // "status"
        QT_MOC_LITERAL(51, 13)   // "abnormaltermi"
    },
    "PlantStatusMoniter",
    "plantchange",
    "",
    "row",
    "col",
    "num",
    "status",
    "abnormaltermi"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPlantStatusMoniterENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    4,   26,    2, 0x06,    1 /* Public */,
       7,    0,   35,    2, 0x06,    6 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PlantStatusMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPlantStatusMoniterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PlantStatusMoniter, std::true_type>,
        // method 'plantchange'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'abnormaltermi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PlantStatusMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlantStatusMoniter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->plantchange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4]))); break;
        case 1: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlantStatusMoniter::*)(int , int , int , int );
            if (_t _q_method = &PlantStatusMoniter::plantchange; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlantStatusMoniter::*)();
            if (_t _q_method = &PlantStatusMoniter::abnormaltermi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *PlantStatusMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlantStatusMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPlantStatusMoniterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int PlantStatusMoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void PlantStatusMoniter::plantchange(int _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlantStatusMoniter::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS = QtMocHelpers::stringData(
    "NewPlantMoniter",
    "abnormaltermi",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[16];
    char stringdata1[14];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS_t qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "NewPlantMoniter"
        QT_MOC_LITERAL(16, 13),  // "abnormaltermi"
        QT_MOC_LITERAL(30, 0)   // ""
    },
    "NewPlantMoniter",
    "abnormaltermi",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSNewPlantMoniterENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject NewPlantMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSNewPlantMoniterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<NewPlantMoniter, std::true_type>,
        // method 'abnormaltermi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void NewPlantMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewPlantMoniter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewPlantMoniter::*)();
            if (_t _q_method = &NewPlantMoniter::abnormaltermi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *NewPlantMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewPlantMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSNewPlantMoniterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int NewPlantMoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void NewPlantMoniter::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBlindBoxPutENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBlindBoxPutENDCLASS = QtMocHelpers::stringData(
    "BlindBoxPut"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBlindBoxPutENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBlindBoxPutENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBlindBoxPutENDCLASS_t qt_meta_stringdata_CLASSBlindBoxPutENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11)   // "BlindBoxPut"
    },
    "BlindBoxPut"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBlindBoxPutENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject BlindBoxPut::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSBlindBoxPutENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBlindBoxPutENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBlindBoxPutENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BlindBoxPut, std::true_type>
    >,
    nullptr
} };

void BlindBoxPut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *BlindBoxPut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlindBoxPut::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBlindBoxPutENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int BlindBoxPut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS = QtMocHelpers::stringData(
    "BlindBoxMoniter",
    "abnormaltermi",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[16];
    char stringdata1[14];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS_t qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "BlindBoxMoniter"
        QT_MOC_LITERAL(16, 13),  // "abnormaltermi"
        QT_MOC_LITERAL(30, 0)   // ""
    },
    "BlindBoxMoniter",
    "abnormaltermi",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBlindBoxMoniterENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BlindBoxMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBlindBoxMoniterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BlindBoxMoniter, std::true_type>,
        // method 'abnormaltermi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BlindBoxMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BlindBoxMoniter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BlindBoxMoniter::*)();
            if (_t _q_method = &BlindBoxMoniter::abnormaltermi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *BlindBoxMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlindBoxMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBlindBoxMoniterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int BlindBoxMoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void BlindBoxMoniter::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS = QtMocHelpers::stringData(
    "BlindBoxSearch",
    "abnormaltermi",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[15];
    char stringdata1[14];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS_t qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS = {
    {
        QT_MOC_LITERAL(0, 14),  // "BlindBoxSearch"
        QT_MOC_LITERAL(15, 13),  // "abnormaltermi"
        QT_MOC_LITERAL(29, 0)   // ""
    },
    "BlindBoxSearch",
    "abnormaltermi",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSBlindBoxSearchENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject BlindBoxSearch::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSBlindBoxSearchENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<BlindBoxSearch, std::true_type>,
        // method 'abnormaltermi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void BlindBoxSearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BlindBoxSearch *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BlindBoxSearch::*)();
            if (_t _q_method = &BlindBoxSearch::abnormaltermi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *BlindBoxSearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlindBoxSearch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSBlindBoxSearchENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int BlindBoxSearch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void BlindBoxSearch::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSSpiceThreadENDCLASS = QtMocHelpers::stringData(
    "SpiceThread",
    "abnormaltermi",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[12];
    char stringdata1[14];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t qt_meta_stringdata_CLASSSpiceThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "SpiceThread"
        QT_MOC_LITERAL(12, 13),  // "abnormaltermi"
        QT_MOC_LITERAL(26, 0)   // ""
    },
    "SpiceThread",
    "abnormaltermi",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSpiceThreadENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject SpiceThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSSpiceThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSpiceThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SpiceThread, std::true_type>,
        // method 'abnormaltermi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void SpiceThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpiceThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpiceThread::*)();
            if (_t _q_method = &SpiceThread::abnormaltermi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *SpiceThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpiceThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSSpiceThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int SpiceThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SpiceThread::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSZombiePutThreadENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSZombiePutThreadENDCLASS = QtMocHelpers::stringData(
    "ZombiePutThread",
    "abnormaltermi",
    "",
    "updatetime",
    "updatezombiecount"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSZombiePutThreadENDCLASS_t {
    uint offsetsAndSizes[10];
    char stringdata0[16];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSZombiePutThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSZombiePutThreadENDCLASS_t qt_meta_stringdata_CLASSZombiePutThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "ZombiePutThread"
        QT_MOC_LITERAL(16, 13),  // "abnormaltermi"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 10),  // "updatetime"
        QT_MOC_LITERAL(42, 17)   // "updatezombiecount"
    },
    "ZombiePutThread",
    "abnormaltermi",
    "",
    "updatetime",
    "updatezombiecount"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZombiePutThreadENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,
       3,    1,   33,    2, 0x06,    2 /* Public */,
       4,    0,   36,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ZombiePutThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSZombiePutThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZombiePutThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZombiePutThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZombiePutThread, std::true_type>,
        // method 'abnormaltermi'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'updatetime'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'updatezombiecount'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ZombiePutThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombiePutThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        case 1: _t->updatetime((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->updatezombiecount(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombiePutThread::*)();
            if (_t _q_method = &ZombiePutThread::abnormaltermi; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZombiePutThread::*)(int );
            if (_t _q_method = &ZombiePutThread::updatetime; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ZombiePutThread::*)();
            if (_t _q_method = &ZombiePutThread::updatezombiecount; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *ZombiePutThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombiePutThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZombiePutThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ZombiePutThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ZombiePutThread::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ZombiePutThread::updatetime(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ZombiePutThread::updatezombiecount()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "closeEvent",
    "",
    "QCloseEvent*",
    "event",
    "on_lookbyprocess_clicked",
    "on_startlog_stateChanged",
    "arg1",
    "on_startbypath_clicked",
    "on_sunchange_clicked",
    "on_quickset_clicked",
    "on_resetall_clicked",
    "on_plantInvincible_stateChanged",
    "on_nocostsun_stateChanged",
    "on_freeplant_stateChanged",
    "on_nocool_stateChanged",
    "on_nocrater_stateChanged",
    "on_noawake_stateChanged",
    "on_nolimitonplant_stateChanged",
    "on_clearplant_stateChanged",
    "on_zombieInvincible_stateChanged",
    "on_pausesystemzombie_stateChanged",
    "on_zombiepause_stateChanged",
    "on_clearallzombies_stateChanged",
    "on_passthegame_stateChanged",
    "on_unlockglod_stateChanged",
    "on_unlockallmode_stateChanged",
    "on_lockspade_stateChanged",
    "on_hidespade_stateChanged",
    "on_hideslot_stateChanged",
    "on_hidemenu_stateChanged",
    "on_nosun_stateChanged",
    "on_autocollect_stateChanged",
    "on_pausegame_stateChanged",
    "on_allowrunback_stateChanged",
    "on_plantplace_clicked",
    "on_plantmoniter_clicked",
    "on_zombieplace_clicked",
    "on_zombiemoniter_clicked",
    "on_isdefaultplantbook_stateChanged",
    "on_updateplantbook_clicked",
    "on_sureupdateplantbook_clicked",
    "on_startforbidplace_stateChanged",
    "on_globalforbid_clicked",
    "on_rowforbid_clicked",
    "on_colforbid_clicked",
    "on_singleforbid_clicked",
    "on_surerowcol_clicked",
    "on_currentreset_clicked",
    "on_globalreset_clicked",
    "on_sureforbid_clicked",
    "on_randslot_stateChanged",
    "on_startforbid_stateChanged",
    "on_createselections_clicked",
    "on_forbidaffectrandslot_stateChanged",
    "on_randplantreset_clicked",
    "on_startrandplaceplant_clicked",
    "on_radioButton_clicked",
    "on_singleplantplace_clicked",
    "on_enableblood_stateChanged",
    "on_enableinterval_stateChanged",
    "on_rowtogether_stateChanged",
    "on_coltogether_stateChanged",
    "on_creatselections_freeplant_clicked",
    "on_suretoplant_free_clicked",
    "on_copy_clicked",
    "on_paste_clicked",
    "on_clearformationtext_clicked",
    "on_clearplant_form_clicked",
    "on_readfile_clicked",
    "on_savaasfile_clicked",
    "on_strtoform_clicked",
    "on_formtostr_clicked",
    "on_isdefaultplantbook_zombie_stateChanged",
    "on_updateplantbook_zombie_clicked",
    "on_sureupdatezombiebook_clicked",
    "on_suretosetblindbox_clicked",
    "on_startforbidplace_zombie_stateChanged",
    "on_globalreset_2_clicked",
    "on_sureforbid_2_clicked",
    "on_startmower_clicked",
    "on_clearmower_clicked",
    "on_resummower_clicked",
    "on_directputonce_clicked",
    "on_pushButton_clicked",
    "on_pausewithgame_stateChanged",
    "on_autospicy_stateChanged",
    "on_pauseputting_clicked",
    "on_stopputting_clicked",
    "on_addnode_clicked",
    "on_deletelist_clicked",
    "on_startputting_clicked",
    "on_saveile_autozombie_clicked",
    "on_readfile_autozombie_clicked",
    "on_pushButton_2_clicked",
    "on_randblindboxmode_stateChanged",
    "on_addfreezombie_clicked",
    "on_rowcolput_clicked",
    "on_coordinateput_clicked",
    "on_putfreezombie_clicked",
    "on_freezombiedelete_clicked",
    "on_freezombiereset_clicked",
    "on_freezombieput_clicked",
    "on_startplantmoniter_stateChanged",
    "on_disappear_stateChanged",
    "on_squish_clicked",
    "on_asleep_clicked",
    "on_enableshine_stateChanged",
    "on_invisible_clicked",
    "on_left_clicked",
    "on_right_clicked",
    "on_enableshine_clicked",
    "on_moniter_plantshoot_sliderPressed",
    "on_moniter_plantshoot_sliderReleased",
    "on_moniter_plantflash_sliderPressed",
    "on_moniter_plantflash_sliderReleased",
    "on_moniter_plantshine_sliderPressed",
    "on_moniter_plantshine_sliderReleased",
    "on_moniter_plantblood_selectionChanged",
    "on_moniter_plantinterval_selectionChanged",
    "on_moniter_plantblood_editingFinished",
    "on_moniter_plantinterval_editingFinished",
    "on_updateplantlist_clicked",
    "on_clearplantlist_clicked",
    "on_updateplantlist_2_clicked",
    "on_clearplantlist_2_clicked",
    "on_updateplantlist_3_clicked",
    "on_clearplantlist_3_clicked",
    "on_updateplantlist_4_clicked",
    "on_clearplantlist_4_clicked",
    "on_updateplantlist_5_clicked",
    "on_clearplantlist_5_clicked",
    "on_checkBox_stateChanged",
    "on_starttotal_stateChanged",
    "on_realtimefile_stateChanged",
    "on_zombiedisapear_stateChanged",
    "on_moniter_zombiex_selectionChanged",
    "on_moniter_zombiex_editingFinished",
    "on_moniter_zombiey_selectionChanged",
    "on_moniter_zombiey_editingFinished",
    "on_moniter_zombiebodyblood_selectionChanged",
    "on_moniter_zombiebodyblood_editingFinished",
    "on_moniter_zombiearmorblood1_selectionChanged",
    "on_moniter_zombiearmorblood1_editingFinished",
    "on_moniter_zombiearmorblood2_selectionChanged",
    "on_moniter_zombiearmorblood2_editingFinished",
    "on_moniter_zombieslowtime_sliderPressed",
    "on_moniter_zombieslowtime_sliderReleased",
    "on_moniter_zombiebuttertime_sliderPressed",
    "on_moniter_zombiebuttertime_sliderReleased",
    "on_moniter_zombiefrozetime_sliderPressed",
    "on_moniter_zombiefrozetime_sliderReleased",
    "on_moniter_zombiebodyshinetime_sliderPressed",
    "on_moniter_zombiebodyshinetime_sliderReleased",
    "on_moniter_zombiearmorshinetime_sliderPressed",
    "on_moniter_zombiearmorshinetime_sliderReleased",
    "on_moniter_zombiearmorshaketime_sliderPressed",
    "on_moniter_zombiearmorshaketime_sliderReleased",
    "on_ishypnoed_clicked",
    "on_isvisible_clicked",
    "on_zombie_blowaway_clicked",
    "on_zombie_near_dead_clicked",
    "on_zombie_inwater_clicked",
    "on_zombie_eatgarlic_clicked",
    "on_zombieoutfile_clicked",
    "on_main_exitButton_clicked",
    "on_checkBox_2_stateChanged",
    "on_nomowernozombie_stateChanged",
    "on_bulletchange_clicked",
    "on_bulletdefault_clicked",
    "on_bulletvalue_currentIndexChanged",
    "index",
    "on_disposablevalue_currentIndexChanged",
    "on_diposablechange_clicked",
    "on_disposabledefault_clicked",
    "on_goodsvalue_currentIndexChanged",
    "on_goodschange_clicked",
    "on_goodsdefault_clicked",
    "on_plantlistbase_currentIndexChanged",
    "on_plantlistbase_2_currentIndexChanged",
    "on_costchange_clicked",
    "on_coolchange_clicked",
    "on_costdefault_clicked",
    "on_cooldefault_clicked",
    "on_pushButton_13_clicked",
    "on_unlockmemorymaxmiun_stateChanged",
    "on_unlockshopitems_stateChanged",
    "on_addeffectplant_clicked",
    "on_deleteselectplanteffect_clicked",
    "on_plantaffectongame_clicked",
    "on_cancelaffenctongame_clicked",
    "on_clearallbullet_stateChanged",
    "on_savesettings_clicked",
    "on_readsettings_clicked",
    "xorFileData",
    "filePath"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[392];
    char stringdata0[11];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[13];
    char stringdata4[6];
    char stringdata5[25];
    char stringdata6[25];
    char stringdata7[5];
    char stringdata8[23];
    char stringdata9[21];
    char stringdata10[20];
    char stringdata11[20];
    char stringdata12[32];
    char stringdata13[26];
    char stringdata14[26];
    char stringdata15[23];
    char stringdata16[25];
    char stringdata17[24];
    char stringdata18[31];
    char stringdata19[27];
    char stringdata20[33];
    char stringdata21[34];
    char stringdata22[28];
    char stringdata23[32];
    char stringdata24[28];
    char stringdata25[27];
    char stringdata26[30];
    char stringdata27[26];
    char stringdata28[26];
    char stringdata29[25];
    char stringdata30[25];
    char stringdata31[22];
    char stringdata32[28];
    char stringdata33[26];
    char stringdata34[29];
    char stringdata35[22];
    char stringdata36[24];
    char stringdata37[23];
    char stringdata38[25];
    char stringdata39[35];
    char stringdata40[27];
    char stringdata41[31];
    char stringdata42[33];
    char stringdata43[24];
    char stringdata44[21];
    char stringdata45[21];
    char stringdata46[24];
    char stringdata47[22];
    char stringdata48[24];
    char stringdata49[23];
    char stringdata50[22];
    char stringdata51[25];
    char stringdata52[28];
    char stringdata53[28];
    char stringdata54[37];
    char stringdata55[26];
    char stringdata56[31];
    char stringdata57[23];
    char stringdata58[28];
    char stringdata59[28];
    char stringdata60[31];
    char stringdata61[28];
    char stringdata62[28];
    char stringdata63[37];
    char stringdata64[28];
    char stringdata65[16];
    char stringdata66[17];
    char stringdata67[30];
    char stringdata68[27];
    char stringdata69[20];
    char stringdata70[22];
    char stringdata71[21];
    char stringdata72[21];
    char stringdata73[42];
    char stringdata74[34];
    char stringdata75[32];
    char stringdata76[29];
    char stringdata77[40];
    char stringdata78[25];
    char stringdata79[24];
    char stringdata80[22];
    char stringdata81[22];
    char stringdata82[22];
    char stringdata83[25];
    char stringdata84[22];
    char stringdata85[30];
    char stringdata86[26];
    char stringdata87[24];
    char stringdata88[23];
    char stringdata89[19];
    char stringdata90[22];
    char stringdata91[24];
    char stringdata92[30];
    char stringdata93[31];
    char stringdata94[24];
    char stringdata95[33];
    char stringdata96[25];
    char stringdata97[21];
    char stringdata98[25];
    char stringdata99[25];
    char stringdata100[28];
    char stringdata101[27];
    char stringdata102[25];
    char stringdata103[34];
    char stringdata104[26];
    char stringdata105[18];
    char stringdata106[18];
    char stringdata107[28];
    char stringdata108[21];
    char stringdata109[16];
    char stringdata110[17];
    char stringdata111[23];
    char stringdata112[36];
    char stringdata113[37];
    char stringdata114[36];
    char stringdata115[37];
    char stringdata116[36];
    char stringdata117[37];
    char stringdata118[39];
    char stringdata119[42];
    char stringdata120[38];
    char stringdata121[41];
    char stringdata122[27];
    char stringdata123[26];
    char stringdata124[29];
    char stringdata125[28];
    char stringdata126[29];
    char stringdata127[28];
    char stringdata128[29];
    char stringdata129[28];
    char stringdata130[29];
    char stringdata131[28];
    char stringdata132[25];
    char stringdata133[27];
    char stringdata134[29];
    char stringdata135[31];
    char stringdata136[36];
    char stringdata137[35];
    char stringdata138[36];
    char stringdata139[35];
    char stringdata140[44];
    char stringdata141[43];
    char stringdata142[46];
    char stringdata143[45];
    char stringdata144[46];
    char stringdata145[45];
    char stringdata146[40];
    char stringdata147[41];
    char stringdata148[42];
    char stringdata149[43];
    char stringdata150[41];
    char stringdata151[42];
    char stringdata152[45];
    char stringdata153[46];
    char stringdata154[46];
    char stringdata155[47];
    char stringdata156[46];
    char stringdata157[47];
    char stringdata158[21];
    char stringdata159[21];
    char stringdata160[27];
    char stringdata161[28];
    char stringdata162[26];
    char stringdata163[28];
    char stringdata164[25];
    char stringdata165[27];
    char stringdata166[27];
    char stringdata167[32];
    char stringdata168[24];
    char stringdata169[25];
    char stringdata170[35];
    char stringdata171[6];
    char stringdata172[39];
    char stringdata173[27];
    char stringdata174[29];
    char stringdata175[34];
    char stringdata176[23];
    char stringdata177[24];
    char stringdata178[37];
    char stringdata179[39];
    char stringdata180[22];
    char stringdata181[22];
    char stringdata182[23];
    char stringdata183[23];
    char stringdata184[25];
    char stringdata185[36];
    char stringdata186[32];
    char stringdata187[26];
    char stringdata188[35];
    char stringdata189[29];
    char stringdata190[31];
    char stringdata191[31];
    char stringdata192[24];
    char stringdata193[24];
    char stringdata194[12];
    char stringdata195[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 10),  // "closeEvent"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 12),  // "QCloseEvent*"
        QT_MOC_LITERAL(36, 5),  // "event"
        QT_MOC_LITERAL(42, 24),  // "on_lookbyprocess_clicked"
        QT_MOC_LITERAL(67, 24),  // "on_startlog_stateChanged"
        QT_MOC_LITERAL(92, 4),  // "arg1"
        QT_MOC_LITERAL(97, 22),  // "on_startbypath_clicked"
        QT_MOC_LITERAL(120, 20),  // "on_sunchange_clicked"
        QT_MOC_LITERAL(141, 19),  // "on_quickset_clicked"
        QT_MOC_LITERAL(161, 19),  // "on_resetall_clicked"
        QT_MOC_LITERAL(181, 31),  // "on_plantInvincible_stateChanged"
        QT_MOC_LITERAL(213, 25),  // "on_nocostsun_stateChanged"
        QT_MOC_LITERAL(239, 25),  // "on_freeplant_stateChanged"
        QT_MOC_LITERAL(265, 22),  // "on_nocool_stateChanged"
        QT_MOC_LITERAL(288, 24),  // "on_nocrater_stateChanged"
        QT_MOC_LITERAL(313, 23),  // "on_noawake_stateChanged"
        QT_MOC_LITERAL(337, 30),  // "on_nolimitonplant_stateChanged"
        QT_MOC_LITERAL(368, 26),  // "on_clearplant_stateChanged"
        QT_MOC_LITERAL(395, 32),  // "on_zombieInvincible_stateChanged"
        QT_MOC_LITERAL(428, 33),  // "on_pausesystemzombie_stateCha..."
        QT_MOC_LITERAL(462, 27),  // "on_zombiepause_stateChanged"
        QT_MOC_LITERAL(490, 31),  // "on_clearallzombies_stateChanged"
        QT_MOC_LITERAL(522, 27),  // "on_passthegame_stateChanged"
        QT_MOC_LITERAL(550, 26),  // "on_unlockglod_stateChanged"
        QT_MOC_LITERAL(577, 29),  // "on_unlockallmode_stateChanged"
        QT_MOC_LITERAL(607, 25),  // "on_lockspade_stateChanged"
        QT_MOC_LITERAL(633, 25),  // "on_hidespade_stateChanged"
        QT_MOC_LITERAL(659, 24),  // "on_hideslot_stateChanged"
        QT_MOC_LITERAL(684, 24),  // "on_hidemenu_stateChanged"
        QT_MOC_LITERAL(709, 21),  // "on_nosun_stateChanged"
        QT_MOC_LITERAL(731, 27),  // "on_autocollect_stateChanged"
        QT_MOC_LITERAL(759, 25),  // "on_pausegame_stateChanged"
        QT_MOC_LITERAL(785, 28),  // "on_allowrunback_stateChanged"
        QT_MOC_LITERAL(814, 21),  // "on_plantplace_clicked"
        QT_MOC_LITERAL(836, 23),  // "on_plantmoniter_clicked"
        QT_MOC_LITERAL(860, 22),  // "on_zombieplace_clicked"
        QT_MOC_LITERAL(883, 24),  // "on_zombiemoniter_clicked"
        QT_MOC_LITERAL(908, 34),  // "on_isdefaultplantbook_stateCh..."
        QT_MOC_LITERAL(943, 26),  // "on_updateplantbook_clicked"
        QT_MOC_LITERAL(970, 30),  // "on_sureupdateplantbook_clicked"
        QT_MOC_LITERAL(1001, 32),  // "on_startforbidplace_stateChanged"
        QT_MOC_LITERAL(1034, 23),  // "on_globalforbid_clicked"
        QT_MOC_LITERAL(1058, 20),  // "on_rowforbid_clicked"
        QT_MOC_LITERAL(1079, 20),  // "on_colforbid_clicked"
        QT_MOC_LITERAL(1100, 23),  // "on_singleforbid_clicked"
        QT_MOC_LITERAL(1124, 21),  // "on_surerowcol_clicked"
        QT_MOC_LITERAL(1146, 23),  // "on_currentreset_clicked"
        QT_MOC_LITERAL(1170, 22),  // "on_globalreset_clicked"
        QT_MOC_LITERAL(1193, 21),  // "on_sureforbid_clicked"
        QT_MOC_LITERAL(1215, 24),  // "on_randslot_stateChanged"
        QT_MOC_LITERAL(1240, 27),  // "on_startforbid_stateChanged"
        QT_MOC_LITERAL(1268, 27),  // "on_createselections_clicked"
        QT_MOC_LITERAL(1296, 36),  // "on_forbidaffectrandslot_state..."
        QT_MOC_LITERAL(1333, 25),  // "on_randplantreset_clicked"
        QT_MOC_LITERAL(1359, 30),  // "on_startrandplaceplant_clicked"
        QT_MOC_LITERAL(1390, 22),  // "on_radioButton_clicked"
        QT_MOC_LITERAL(1413, 27),  // "on_singleplantplace_clicked"
        QT_MOC_LITERAL(1441, 27),  // "on_enableblood_stateChanged"
        QT_MOC_LITERAL(1469, 30),  // "on_enableinterval_stateChanged"
        QT_MOC_LITERAL(1500, 27),  // "on_rowtogether_stateChanged"
        QT_MOC_LITERAL(1528, 27),  // "on_coltogether_stateChanged"
        QT_MOC_LITERAL(1556, 36),  // "on_creatselections_freeplant_..."
        QT_MOC_LITERAL(1593, 27),  // "on_suretoplant_free_clicked"
        QT_MOC_LITERAL(1621, 15),  // "on_copy_clicked"
        QT_MOC_LITERAL(1637, 16),  // "on_paste_clicked"
        QT_MOC_LITERAL(1654, 29),  // "on_clearformationtext_clicked"
        QT_MOC_LITERAL(1684, 26),  // "on_clearplant_form_clicked"
        QT_MOC_LITERAL(1711, 19),  // "on_readfile_clicked"
        QT_MOC_LITERAL(1731, 21),  // "on_savaasfile_clicked"
        QT_MOC_LITERAL(1753, 20),  // "on_strtoform_clicked"
        QT_MOC_LITERAL(1774, 20),  // "on_formtostr_clicked"
        QT_MOC_LITERAL(1795, 41),  // "on_isdefaultplantbook_zombie_..."
        QT_MOC_LITERAL(1837, 33),  // "on_updateplantbook_zombie_cli..."
        QT_MOC_LITERAL(1871, 31),  // "on_sureupdatezombiebook_clicked"
        QT_MOC_LITERAL(1903, 28),  // "on_suretosetblindbox_clicked"
        QT_MOC_LITERAL(1932, 39),  // "on_startforbidplace_zombie_st..."
        QT_MOC_LITERAL(1972, 24),  // "on_globalreset_2_clicked"
        QT_MOC_LITERAL(1997, 23),  // "on_sureforbid_2_clicked"
        QT_MOC_LITERAL(2021, 21),  // "on_startmower_clicked"
        QT_MOC_LITERAL(2043, 21),  // "on_clearmower_clicked"
        QT_MOC_LITERAL(2065, 21),  // "on_resummower_clicked"
        QT_MOC_LITERAL(2087, 24),  // "on_directputonce_clicked"
        QT_MOC_LITERAL(2112, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(2134, 29),  // "on_pausewithgame_stateChanged"
        QT_MOC_LITERAL(2164, 25),  // "on_autospicy_stateChanged"
        QT_MOC_LITERAL(2190, 23),  // "on_pauseputting_clicked"
        QT_MOC_LITERAL(2214, 22),  // "on_stopputting_clicked"
        QT_MOC_LITERAL(2237, 18),  // "on_addnode_clicked"
        QT_MOC_LITERAL(2256, 21),  // "on_deletelist_clicked"
        QT_MOC_LITERAL(2278, 23),  // "on_startputting_clicked"
        QT_MOC_LITERAL(2302, 29),  // "on_saveile_autozombie_clicked"
        QT_MOC_LITERAL(2332, 30),  // "on_readfile_autozombie_clicked"
        QT_MOC_LITERAL(2363, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(2387, 32),  // "on_randblindboxmode_stateChanged"
        QT_MOC_LITERAL(2420, 24),  // "on_addfreezombie_clicked"
        QT_MOC_LITERAL(2445, 20),  // "on_rowcolput_clicked"
        QT_MOC_LITERAL(2466, 24),  // "on_coordinateput_clicked"
        QT_MOC_LITERAL(2491, 24),  // "on_putfreezombie_clicked"
        QT_MOC_LITERAL(2516, 27),  // "on_freezombiedelete_clicked"
        QT_MOC_LITERAL(2544, 26),  // "on_freezombiereset_clicked"
        QT_MOC_LITERAL(2571, 24),  // "on_freezombieput_clicked"
        QT_MOC_LITERAL(2596, 33),  // "on_startplantmoniter_stateCha..."
        QT_MOC_LITERAL(2630, 25),  // "on_disappear_stateChanged"
        QT_MOC_LITERAL(2656, 17),  // "on_squish_clicked"
        QT_MOC_LITERAL(2674, 17),  // "on_asleep_clicked"
        QT_MOC_LITERAL(2692, 27),  // "on_enableshine_stateChanged"
        QT_MOC_LITERAL(2720, 20),  // "on_invisible_clicked"
        QT_MOC_LITERAL(2741, 15),  // "on_left_clicked"
        QT_MOC_LITERAL(2757, 16),  // "on_right_clicked"
        QT_MOC_LITERAL(2774, 22),  // "on_enableshine_clicked"
        QT_MOC_LITERAL(2797, 35),  // "on_moniter_plantshoot_sliderP..."
        QT_MOC_LITERAL(2833, 36),  // "on_moniter_plantshoot_sliderR..."
        QT_MOC_LITERAL(2870, 35),  // "on_moniter_plantflash_sliderP..."
        QT_MOC_LITERAL(2906, 36),  // "on_moniter_plantflash_sliderR..."
        QT_MOC_LITERAL(2943, 35),  // "on_moniter_plantshine_sliderP..."
        QT_MOC_LITERAL(2979, 36),  // "on_moniter_plantshine_sliderR..."
        QT_MOC_LITERAL(3016, 38),  // "on_moniter_plantblood_selecti..."
        QT_MOC_LITERAL(3055, 41),  // "on_moniter_plantinterval_sele..."
        QT_MOC_LITERAL(3097, 37),  // "on_moniter_plantblood_editing..."
        QT_MOC_LITERAL(3135, 40),  // "on_moniter_plantinterval_edit..."
        QT_MOC_LITERAL(3176, 26),  // "on_updateplantlist_clicked"
        QT_MOC_LITERAL(3203, 25),  // "on_clearplantlist_clicked"
        QT_MOC_LITERAL(3229, 28),  // "on_updateplantlist_2_clicked"
        QT_MOC_LITERAL(3258, 27),  // "on_clearplantlist_2_clicked"
        QT_MOC_LITERAL(3286, 28),  // "on_updateplantlist_3_clicked"
        QT_MOC_LITERAL(3315, 27),  // "on_clearplantlist_3_clicked"
        QT_MOC_LITERAL(3343, 28),  // "on_updateplantlist_4_clicked"
        QT_MOC_LITERAL(3372, 27),  // "on_clearplantlist_4_clicked"
        QT_MOC_LITERAL(3400, 28),  // "on_updateplantlist_5_clicked"
        QT_MOC_LITERAL(3429, 27),  // "on_clearplantlist_5_clicked"
        QT_MOC_LITERAL(3457, 24),  // "on_checkBox_stateChanged"
        QT_MOC_LITERAL(3482, 26),  // "on_starttotal_stateChanged"
        QT_MOC_LITERAL(3509, 28),  // "on_realtimefile_stateChanged"
        QT_MOC_LITERAL(3538, 30),  // "on_zombiedisapear_stateChanged"
        QT_MOC_LITERAL(3569, 35),  // "on_moniter_zombiex_selectionC..."
        QT_MOC_LITERAL(3605, 34),  // "on_moniter_zombiex_editingFin..."
        QT_MOC_LITERAL(3640, 35),  // "on_moniter_zombiey_selectionC..."
        QT_MOC_LITERAL(3676, 34),  // "on_moniter_zombiey_editingFin..."
        QT_MOC_LITERAL(3711, 43),  // "on_moniter_zombiebodyblood_se..."
        QT_MOC_LITERAL(3755, 42),  // "on_moniter_zombiebodyblood_ed..."
        QT_MOC_LITERAL(3798, 45),  // "on_moniter_zombiearmorblood1_..."
        QT_MOC_LITERAL(3844, 44),  // "on_moniter_zombiearmorblood1_..."
        QT_MOC_LITERAL(3889, 45),  // "on_moniter_zombiearmorblood2_..."
        QT_MOC_LITERAL(3935, 44),  // "on_moniter_zombiearmorblood2_..."
        QT_MOC_LITERAL(3980, 39),  // "on_moniter_zombieslowtime_sli..."
        QT_MOC_LITERAL(4020, 40),  // "on_moniter_zombieslowtime_sli..."
        QT_MOC_LITERAL(4061, 41),  // "on_moniter_zombiebuttertime_s..."
        QT_MOC_LITERAL(4103, 42),  // "on_moniter_zombiebuttertime_s..."
        QT_MOC_LITERAL(4146, 40),  // "on_moniter_zombiefrozetime_sl..."
        QT_MOC_LITERAL(4187, 41),  // "on_moniter_zombiefrozetime_sl..."
        QT_MOC_LITERAL(4229, 44),  // "on_moniter_zombiebodyshinetim..."
        QT_MOC_LITERAL(4274, 45),  // "on_moniter_zombiebodyshinetim..."
        QT_MOC_LITERAL(4320, 45),  // "on_moniter_zombiearmorshineti..."
        QT_MOC_LITERAL(4366, 46),  // "on_moniter_zombiearmorshineti..."
        QT_MOC_LITERAL(4413, 45),  // "on_moniter_zombiearmorshaketi..."
        QT_MOC_LITERAL(4459, 46),  // "on_moniter_zombiearmorshaketi..."
        QT_MOC_LITERAL(4506, 20),  // "on_ishypnoed_clicked"
        QT_MOC_LITERAL(4527, 20),  // "on_isvisible_clicked"
        QT_MOC_LITERAL(4548, 26),  // "on_zombie_blowaway_clicked"
        QT_MOC_LITERAL(4575, 27),  // "on_zombie_near_dead_clicked"
        QT_MOC_LITERAL(4603, 25),  // "on_zombie_inwater_clicked"
        QT_MOC_LITERAL(4629, 27),  // "on_zombie_eatgarlic_clicked"
        QT_MOC_LITERAL(4657, 24),  // "on_zombieoutfile_clicked"
        QT_MOC_LITERAL(4682, 26),  // "on_main_exitButton_clicked"
        QT_MOC_LITERAL(4709, 26),  // "on_checkBox_2_stateChanged"
        QT_MOC_LITERAL(4736, 31),  // "on_nomowernozombie_stateChanged"
        QT_MOC_LITERAL(4768, 23),  // "on_bulletchange_clicked"
        QT_MOC_LITERAL(4792, 24),  // "on_bulletdefault_clicked"
        QT_MOC_LITERAL(4817, 34),  // "on_bulletvalue_currentIndexCh..."
        QT_MOC_LITERAL(4852, 5),  // "index"
        QT_MOC_LITERAL(4858, 38),  // "on_disposablevalue_currentInd..."
        QT_MOC_LITERAL(4897, 26),  // "on_diposablechange_clicked"
        QT_MOC_LITERAL(4924, 28),  // "on_disposabledefault_clicked"
        QT_MOC_LITERAL(4953, 33),  // "on_goodsvalue_currentIndexCha..."
        QT_MOC_LITERAL(4987, 22),  // "on_goodschange_clicked"
        QT_MOC_LITERAL(5010, 23),  // "on_goodsdefault_clicked"
        QT_MOC_LITERAL(5034, 36),  // "on_plantlistbase_currentIndex..."
        QT_MOC_LITERAL(5071, 38),  // "on_plantlistbase_2_currentInd..."
        QT_MOC_LITERAL(5110, 21),  // "on_costchange_clicked"
        QT_MOC_LITERAL(5132, 21),  // "on_coolchange_clicked"
        QT_MOC_LITERAL(5154, 22),  // "on_costdefault_clicked"
        QT_MOC_LITERAL(5177, 22),  // "on_cooldefault_clicked"
        QT_MOC_LITERAL(5200, 24),  // "on_pushButton_13_clicked"
        QT_MOC_LITERAL(5225, 35),  // "on_unlockmemorymaxmiun_stateC..."
        QT_MOC_LITERAL(5261, 31),  // "on_unlockshopitems_stateChanged"
        QT_MOC_LITERAL(5293, 25),  // "on_addeffectplant_clicked"
        QT_MOC_LITERAL(5319, 34),  // "on_deleteselectplanteffect_cl..."
        QT_MOC_LITERAL(5354, 28),  // "on_plantaffectongame_clicked"
        QT_MOC_LITERAL(5383, 30),  // "on_cancelaffenctongame_clicked"
        QT_MOC_LITERAL(5414, 30),  // "on_clearallbullet_stateChanged"
        QT_MOC_LITERAL(5445, 23),  // "on_savesettings_clicked"
        QT_MOC_LITERAL(5469, 23),  // "on_readsettings_clicked"
        QT_MOC_LITERAL(5493, 11),  // "xorFileData"
        QT_MOC_LITERAL(5505, 8)   // "filePath"
    },
    "MainWindow",
    "closeEvent",
    "",
    "QCloseEvent*",
    "event",
    "on_lookbyprocess_clicked",
    "on_startlog_stateChanged",
    "arg1",
    "on_startbypath_clicked",
    "on_sunchange_clicked",
    "on_quickset_clicked",
    "on_resetall_clicked",
    "on_plantInvincible_stateChanged",
    "on_nocostsun_stateChanged",
    "on_freeplant_stateChanged",
    "on_nocool_stateChanged",
    "on_nocrater_stateChanged",
    "on_noawake_stateChanged",
    "on_nolimitonplant_stateChanged",
    "on_clearplant_stateChanged",
    "on_zombieInvincible_stateChanged",
    "on_pausesystemzombie_stateChanged",
    "on_zombiepause_stateChanged",
    "on_clearallzombies_stateChanged",
    "on_passthegame_stateChanged",
    "on_unlockglod_stateChanged",
    "on_unlockallmode_stateChanged",
    "on_lockspade_stateChanged",
    "on_hidespade_stateChanged",
    "on_hideslot_stateChanged",
    "on_hidemenu_stateChanged",
    "on_nosun_stateChanged",
    "on_autocollect_stateChanged",
    "on_pausegame_stateChanged",
    "on_allowrunback_stateChanged",
    "on_plantplace_clicked",
    "on_plantmoniter_clicked",
    "on_zombieplace_clicked",
    "on_zombiemoniter_clicked",
    "on_isdefaultplantbook_stateChanged",
    "on_updateplantbook_clicked",
    "on_sureupdateplantbook_clicked",
    "on_startforbidplace_stateChanged",
    "on_globalforbid_clicked",
    "on_rowforbid_clicked",
    "on_colforbid_clicked",
    "on_singleforbid_clicked",
    "on_surerowcol_clicked",
    "on_currentreset_clicked",
    "on_globalreset_clicked",
    "on_sureforbid_clicked",
    "on_randslot_stateChanged",
    "on_startforbid_stateChanged",
    "on_createselections_clicked",
    "on_forbidaffectrandslot_stateChanged",
    "on_randplantreset_clicked",
    "on_startrandplaceplant_clicked",
    "on_radioButton_clicked",
    "on_singleplantplace_clicked",
    "on_enableblood_stateChanged",
    "on_enableinterval_stateChanged",
    "on_rowtogether_stateChanged",
    "on_coltogether_stateChanged",
    "on_creatselections_freeplant_clicked",
    "on_suretoplant_free_clicked",
    "on_copy_clicked",
    "on_paste_clicked",
    "on_clearformationtext_clicked",
    "on_clearplant_form_clicked",
    "on_readfile_clicked",
    "on_savaasfile_clicked",
    "on_strtoform_clicked",
    "on_formtostr_clicked",
    "on_isdefaultplantbook_zombie_stateChanged",
    "on_updateplantbook_zombie_clicked",
    "on_sureupdatezombiebook_clicked",
    "on_suretosetblindbox_clicked",
    "on_startforbidplace_zombie_stateChanged",
    "on_globalreset_2_clicked",
    "on_sureforbid_2_clicked",
    "on_startmower_clicked",
    "on_clearmower_clicked",
    "on_resummower_clicked",
    "on_directputonce_clicked",
    "on_pushButton_clicked",
    "on_pausewithgame_stateChanged",
    "on_autospicy_stateChanged",
    "on_pauseputting_clicked",
    "on_stopputting_clicked",
    "on_addnode_clicked",
    "on_deletelist_clicked",
    "on_startputting_clicked",
    "on_saveile_autozombie_clicked",
    "on_readfile_autozombie_clicked",
    "on_pushButton_2_clicked",
    "on_randblindboxmode_stateChanged",
    "on_addfreezombie_clicked",
    "on_rowcolput_clicked",
    "on_coordinateput_clicked",
    "on_putfreezombie_clicked",
    "on_freezombiedelete_clicked",
    "on_freezombiereset_clicked",
    "on_freezombieput_clicked",
    "on_startplantmoniter_stateChanged",
    "on_disappear_stateChanged",
    "on_squish_clicked",
    "on_asleep_clicked",
    "on_enableshine_stateChanged",
    "on_invisible_clicked",
    "on_left_clicked",
    "on_right_clicked",
    "on_enableshine_clicked",
    "on_moniter_plantshoot_sliderPressed",
    "on_moniter_plantshoot_sliderReleased",
    "on_moniter_plantflash_sliderPressed",
    "on_moniter_plantflash_sliderReleased",
    "on_moniter_plantshine_sliderPressed",
    "on_moniter_plantshine_sliderReleased",
    "on_moniter_plantblood_selectionChanged",
    "on_moniter_plantinterval_selectionChanged",
    "on_moniter_plantblood_editingFinished",
    "on_moniter_plantinterval_editingFinished",
    "on_updateplantlist_clicked",
    "on_clearplantlist_clicked",
    "on_updateplantlist_2_clicked",
    "on_clearplantlist_2_clicked",
    "on_updateplantlist_3_clicked",
    "on_clearplantlist_3_clicked",
    "on_updateplantlist_4_clicked",
    "on_clearplantlist_4_clicked",
    "on_updateplantlist_5_clicked",
    "on_clearplantlist_5_clicked",
    "on_checkBox_stateChanged",
    "on_starttotal_stateChanged",
    "on_realtimefile_stateChanged",
    "on_zombiedisapear_stateChanged",
    "on_moniter_zombiex_selectionChanged",
    "on_moniter_zombiex_editingFinished",
    "on_moniter_zombiey_selectionChanged",
    "on_moniter_zombiey_editingFinished",
    "on_moniter_zombiebodyblood_selectionChanged",
    "on_moniter_zombiebodyblood_editingFinished",
    "on_moniter_zombiearmorblood1_selectionChanged",
    "on_moniter_zombiearmorblood1_editingFinished",
    "on_moniter_zombiearmorblood2_selectionChanged",
    "on_moniter_zombiearmorblood2_editingFinished",
    "on_moniter_zombieslowtime_sliderPressed",
    "on_moniter_zombieslowtime_sliderReleased",
    "on_moniter_zombiebuttertime_sliderPressed",
    "on_moniter_zombiebuttertime_sliderReleased",
    "on_moniter_zombiefrozetime_sliderPressed",
    "on_moniter_zombiefrozetime_sliderReleased",
    "on_moniter_zombiebodyshinetime_sliderPressed",
    "on_moniter_zombiebodyshinetime_sliderReleased",
    "on_moniter_zombiearmorshinetime_sliderPressed",
    "on_moniter_zombiearmorshinetime_sliderReleased",
    "on_moniter_zombiearmorshaketime_sliderPressed",
    "on_moniter_zombiearmorshaketime_sliderReleased",
    "on_ishypnoed_clicked",
    "on_isvisible_clicked",
    "on_zombie_blowaway_clicked",
    "on_zombie_near_dead_clicked",
    "on_zombie_inwater_clicked",
    "on_zombie_eatgarlic_clicked",
    "on_zombieoutfile_clicked",
    "on_main_exitButton_clicked",
    "on_checkBox_2_stateChanged",
    "on_nomowernozombie_stateChanged",
    "on_bulletchange_clicked",
    "on_bulletdefault_clicked",
    "on_bulletvalue_currentIndexChanged",
    "index",
    "on_disposablevalue_currentIndexChanged",
    "on_diposablechange_clicked",
    "on_disposabledefault_clicked",
    "on_goodsvalue_currentIndexChanged",
    "on_goodschange_clicked",
    "on_goodsdefault_clicked",
    "on_plantlistbase_currentIndexChanged",
    "on_plantlistbase_2_currentIndexChanged",
    "on_costchange_clicked",
    "on_coolchange_clicked",
    "on_costdefault_clicked",
    "on_cooldefault_clicked",
    "on_pushButton_13_clicked",
    "on_unlockmemorymaxmiun_stateChanged",
    "on_unlockshopitems_stateChanged",
    "on_addeffectplant_clicked",
    "on_deleteselectplanteffect_clicked",
    "on_plantaffectongame_clicked",
    "on_cancelaffenctongame_clicked",
    "on_clearallbullet_stateChanged",
    "on_savesettings_clicked",
    "on_readsettings_clicked",
    "xorFileData",
    "filePath"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
     189,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1, 1148,    2, 0x08,    1 /* Private */,
       5,    0, 1151,    2, 0x08,    3 /* Private */,
       6,    1, 1152,    2, 0x08,    4 /* Private */,
       8,    0, 1155,    2, 0x08,    6 /* Private */,
       9,    0, 1156,    2, 0x08,    7 /* Private */,
      10,    0, 1157,    2, 0x08,    8 /* Private */,
      11,    0, 1158,    2, 0x08,    9 /* Private */,
      12,    1, 1159,    2, 0x08,   10 /* Private */,
      13,    1, 1162,    2, 0x08,   12 /* Private */,
      14,    1, 1165,    2, 0x08,   14 /* Private */,
      15,    1, 1168,    2, 0x08,   16 /* Private */,
      16,    1, 1171,    2, 0x08,   18 /* Private */,
      17,    1, 1174,    2, 0x08,   20 /* Private */,
      18,    1, 1177,    2, 0x08,   22 /* Private */,
      19,    1, 1180,    2, 0x08,   24 /* Private */,
      20,    1, 1183,    2, 0x08,   26 /* Private */,
      21,    1, 1186,    2, 0x08,   28 /* Private */,
      22,    1, 1189,    2, 0x08,   30 /* Private */,
      23,    1, 1192,    2, 0x08,   32 /* Private */,
      24,    1, 1195,    2, 0x08,   34 /* Private */,
      25,    1, 1198,    2, 0x08,   36 /* Private */,
      26,    1, 1201,    2, 0x08,   38 /* Private */,
      27,    1, 1204,    2, 0x08,   40 /* Private */,
      28,    1, 1207,    2, 0x08,   42 /* Private */,
      29,    1, 1210,    2, 0x08,   44 /* Private */,
      30,    1, 1213,    2, 0x08,   46 /* Private */,
      31,    1, 1216,    2, 0x08,   48 /* Private */,
      32,    1, 1219,    2, 0x08,   50 /* Private */,
      33,    1, 1222,    2, 0x08,   52 /* Private */,
      34,    1, 1225,    2, 0x08,   54 /* Private */,
      35,    0, 1228,    2, 0x08,   56 /* Private */,
      36,    0, 1229,    2, 0x08,   57 /* Private */,
      37,    0, 1230,    2, 0x08,   58 /* Private */,
      38,    0, 1231,    2, 0x08,   59 /* Private */,
      39,    1, 1232,    2, 0x08,   60 /* Private */,
      40,    0, 1235,    2, 0x08,   62 /* Private */,
      41,    0, 1236,    2, 0x08,   63 /* Private */,
      42,    1, 1237,    2, 0x08,   64 /* Private */,
      43,    0, 1240,    2, 0x08,   66 /* Private */,
      44,    0, 1241,    2, 0x08,   67 /* Private */,
      45,    0, 1242,    2, 0x08,   68 /* Private */,
      46,    0, 1243,    2, 0x08,   69 /* Private */,
      47,    0, 1244,    2, 0x08,   70 /* Private */,
      48,    0, 1245,    2, 0x08,   71 /* Private */,
      49,    0, 1246,    2, 0x08,   72 /* Private */,
      50,    0, 1247,    2, 0x08,   73 /* Private */,
      51,    1, 1248,    2, 0x08,   74 /* Private */,
      52,    1, 1251,    2, 0x08,   76 /* Private */,
      53,    0, 1254,    2, 0x08,   78 /* Private */,
      54,    1, 1255,    2, 0x08,   79 /* Private */,
      55,    0, 1258,    2, 0x08,   81 /* Private */,
      56,    0, 1259,    2, 0x08,   82 /* Private */,
      57,    0, 1260,    2, 0x08,   83 /* Private */,
      58,    0, 1261,    2, 0x08,   84 /* Private */,
      59,    1, 1262,    2, 0x08,   85 /* Private */,
      60,    1, 1265,    2, 0x08,   87 /* Private */,
      61,    1, 1268,    2, 0x08,   89 /* Private */,
      62,    1, 1271,    2, 0x08,   91 /* Private */,
      63,    0, 1274,    2, 0x08,   93 /* Private */,
      64,    0, 1275,    2, 0x08,   94 /* Private */,
      65,    0, 1276,    2, 0x08,   95 /* Private */,
      66,    0, 1277,    2, 0x08,   96 /* Private */,
      67,    0, 1278,    2, 0x08,   97 /* Private */,
      68,    0, 1279,    2, 0x08,   98 /* Private */,
      69,    0, 1280,    2, 0x08,   99 /* Private */,
      70,    0, 1281,    2, 0x08,  100 /* Private */,
      71,    0, 1282,    2, 0x08,  101 /* Private */,
      72,    0, 1283,    2, 0x08,  102 /* Private */,
      73,    1, 1284,    2, 0x08,  103 /* Private */,
      74,    0, 1287,    2, 0x08,  105 /* Private */,
      75,    0, 1288,    2, 0x08,  106 /* Private */,
      76,    0, 1289,    2, 0x08,  107 /* Private */,
      77,    1, 1290,    2, 0x08,  108 /* Private */,
      78,    0, 1293,    2, 0x08,  110 /* Private */,
      79,    0, 1294,    2, 0x08,  111 /* Private */,
      80,    0, 1295,    2, 0x08,  112 /* Private */,
      81,    0, 1296,    2, 0x08,  113 /* Private */,
      82,    0, 1297,    2, 0x08,  114 /* Private */,
      83,    0, 1298,    2, 0x08,  115 /* Private */,
      84,    0, 1299,    2, 0x08,  116 /* Private */,
      85,    1, 1300,    2, 0x08,  117 /* Private */,
      86,    1, 1303,    2, 0x08,  119 /* Private */,
      87,    0, 1306,    2, 0x08,  121 /* Private */,
      88,    0, 1307,    2, 0x08,  122 /* Private */,
      89,    0, 1308,    2, 0x08,  123 /* Private */,
      90,    0, 1309,    2, 0x08,  124 /* Private */,
      91,    0, 1310,    2, 0x08,  125 /* Private */,
      92,    0, 1311,    2, 0x08,  126 /* Private */,
      93,    0, 1312,    2, 0x08,  127 /* Private */,
      94,    0, 1313,    2, 0x08,  128 /* Private */,
      95,    1, 1314,    2, 0x08,  129 /* Private */,
      96,    0, 1317,    2, 0x08,  131 /* Private */,
      97,    0, 1318,    2, 0x08,  132 /* Private */,
      98,    0, 1319,    2, 0x08,  133 /* Private */,
      99,    0, 1320,    2, 0x08,  134 /* Private */,
     100,    0, 1321,    2, 0x08,  135 /* Private */,
     101,    0, 1322,    2, 0x08,  136 /* Private */,
     102,    0, 1323,    2, 0x08,  137 /* Private */,
     103,    1, 1324,    2, 0x08,  138 /* Private */,
     104,    1, 1327,    2, 0x08,  140 /* Private */,
     105,    0, 1330,    2, 0x08,  142 /* Private */,
     106,    0, 1331,    2, 0x08,  143 /* Private */,
     107,    1, 1332,    2, 0x08,  144 /* Private */,
     108,    0, 1335,    2, 0x08,  146 /* Private */,
     109,    0, 1336,    2, 0x08,  147 /* Private */,
     110,    0, 1337,    2, 0x08,  148 /* Private */,
     111,    0, 1338,    2, 0x08,  149 /* Private */,
     112,    0, 1339,    2, 0x08,  150 /* Private */,
     113,    0, 1340,    2, 0x08,  151 /* Private */,
     114,    0, 1341,    2, 0x08,  152 /* Private */,
     115,    0, 1342,    2, 0x08,  153 /* Private */,
     116,    0, 1343,    2, 0x08,  154 /* Private */,
     117,    0, 1344,    2, 0x08,  155 /* Private */,
     118,    0, 1345,    2, 0x08,  156 /* Private */,
     119,    0, 1346,    2, 0x08,  157 /* Private */,
     120,    0, 1347,    2, 0x08,  158 /* Private */,
     121,    0, 1348,    2, 0x08,  159 /* Private */,
     122,    0, 1349,    2, 0x08,  160 /* Private */,
     123,    0, 1350,    2, 0x08,  161 /* Private */,
     124,    0, 1351,    2, 0x08,  162 /* Private */,
     125,    0, 1352,    2, 0x08,  163 /* Private */,
     126,    0, 1353,    2, 0x08,  164 /* Private */,
     127,    0, 1354,    2, 0x08,  165 /* Private */,
     128,    0, 1355,    2, 0x08,  166 /* Private */,
     129,    0, 1356,    2, 0x08,  167 /* Private */,
     130,    0, 1357,    2, 0x08,  168 /* Private */,
     131,    0, 1358,    2, 0x08,  169 /* Private */,
     132,    1, 1359,    2, 0x08,  170 /* Private */,
     133,    1, 1362,    2, 0x08,  172 /* Private */,
     134,    1, 1365,    2, 0x08,  174 /* Private */,
     135,    1, 1368,    2, 0x08,  176 /* Private */,
     136,    0, 1371,    2, 0x08,  178 /* Private */,
     137,    0, 1372,    2, 0x08,  179 /* Private */,
     138,    0, 1373,    2, 0x08,  180 /* Private */,
     139,    0, 1374,    2, 0x08,  181 /* Private */,
     140,    0, 1375,    2, 0x08,  182 /* Private */,
     141,    0, 1376,    2, 0x08,  183 /* Private */,
     142,    0, 1377,    2, 0x08,  184 /* Private */,
     143,    0, 1378,    2, 0x08,  185 /* Private */,
     144,    0, 1379,    2, 0x08,  186 /* Private */,
     145,    0, 1380,    2, 0x08,  187 /* Private */,
     146,    0, 1381,    2, 0x08,  188 /* Private */,
     147,    0, 1382,    2, 0x08,  189 /* Private */,
     148,    0, 1383,    2, 0x08,  190 /* Private */,
     149,    0, 1384,    2, 0x08,  191 /* Private */,
     150,    0, 1385,    2, 0x08,  192 /* Private */,
     151,    0, 1386,    2, 0x08,  193 /* Private */,
     152,    0, 1387,    2, 0x08,  194 /* Private */,
     153,    0, 1388,    2, 0x08,  195 /* Private */,
     154,    0, 1389,    2, 0x08,  196 /* Private */,
     155,    0, 1390,    2, 0x08,  197 /* Private */,
     156,    0, 1391,    2, 0x08,  198 /* Private */,
     157,    0, 1392,    2, 0x08,  199 /* Private */,
     158,    0, 1393,    2, 0x08,  200 /* Private */,
     159,    0, 1394,    2, 0x08,  201 /* Private */,
     160,    0, 1395,    2, 0x08,  202 /* Private */,
     161,    0, 1396,    2, 0x08,  203 /* Private */,
     162,    0, 1397,    2, 0x08,  204 /* Private */,
     163,    0, 1398,    2, 0x08,  205 /* Private */,
     164,    0, 1399,    2, 0x08,  206 /* Private */,
     165,    0, 1400,    2, 0x08,  207 /* Private */,
     166,    1, 1401,    2, 0x08,  208 /* Private */,
     167,    1, 1404,    2, 0x08,  210 /* Private */,
     168,    0, 1407,    2, 0x08,  212 /* Private */,
     169,    0, 1408,    2, 0x08,  213 /* Private */,
     170,    1, 1409,    2, 0x08,  214 /* Private */,
     172,    1, 1412,    2, 0x08,  216 /* Private */,
     173,    0, 1415,    2, 0x08,  218 /* Private */,
     174,    0, 1416,    2, 0x08,  219 /* Private */,
     175,    1, 1417,    2, 0x08,  220 /* Private */,
     176,    0, 1420,    2, 0x08,  222 /* Private */,
     177,    0, 1421,    2, 0x08,  223 /* Private */,
     178,    1, 1422,    2, 0x08,  224 /* Private */,
     179,    1, 1425,    2, 0x08,  226 /* Private */,
     180,    0, 1428,    2, 0x08,  228 /* Private */,
     181,    0, 1429,    2, 0x08,  229 /* Private */,
     182,    0, 1430,    2, 0x08,  230 /* Private */,
     183,    0, 1431,    2, 0x08,  231 /* Private */,
     184,    0, 1432,    2, 0x08,  232 /* Private */,
     185,    1, 1433,    2, 0x08,  233 /* Private */,
     186,    1, 1436,    2, 0x08,  235 /* Private */,
     187,    0, 1439,    2, 0x08,  237 /* Private */,
     188,    0, 1440,    2, 0x08,  238 /* Private */,
     189,    0, 1441,    2, 0x08,  239 /* Private */,
     190,    0, 1442,    2, 0x08,  240 /* Private */,
     191,    1, 1443,    2, 0x08,  241 /* Private */,
     192,    0, 1446,    2, 0x08,  243 /* Private */,
     193,    0, 1447,    2, 0x08,  244 /* Private */,
     194,    1, 1448,    2, 0x08,  245 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
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
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
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
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  171,
    QMetaType::Void, QMetaType::Int,  171,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  171,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  171,
    QMetaType::Void, QMetaType::Int,  171,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,  195,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'closeEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QCloseEvent *, std::false_type>,
        // method 'on_lookbyprocess_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startlog_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_startbypath_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sunchange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_quickset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resetall_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_plantInvincible_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nocostsun_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_freeplant_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nocool_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nocrater_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_noawake_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nolimitonplant_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_clearplant_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_zombieInvincible_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pausesystemzombie_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_zombiepause_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_clearallzombies_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_passthegame_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_unlockglod_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_unlockallmode_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_lockspade_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_hidespade_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_hideslot_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_hidemenu_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nosun_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_autocollect_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pausegame_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_allowrunback_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_plantplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_plantmoniter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zombieplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zombiemoniter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_isdefaultplantbook_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_updateplantbook_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sureupdateplantbook_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startforbidplace_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_globalforbid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rowforbid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_colforbid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_singleforbid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_surerowcol_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_currentreset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_globalreset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sureforbid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_randslot_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_startforbid_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_createselections_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_forbidaffectrandslot_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_randplantreset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startrandplaceplant_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_radioButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_singleplantplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_enableblood_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_enableinterval_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_rowtogether_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_coltogether_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_creatselections_freeplant_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_suretoplant_free_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_copy_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_paste_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearformationtext_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearplant_form_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_readfile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_savaasfile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_strtoform_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_formtostr_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_isdefaultplantbook_zombie_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_updateplantbook_zombie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sureupdatezombiebook_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_suretosetblindbox_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startforbidplace_zombie_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_globalreset_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sureforbid_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startmower_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearmower_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resummower_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_directputonce_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pausewithgame_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_autospicy_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pauseputting_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_stopputting_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addnode_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deletelist_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startputting_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_saveile_autozombie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_readfile_autozombie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_randblindboxmode_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_addfreezombie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_rowcolput_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_coordinateput_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_putfreezombie_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_freezombiedelete_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_freezombiereset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_freezombieput_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startplantmoniter_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_disappear_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_squish_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_asleep_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_enableshine_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_invisible_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_left_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_right_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_enableshine_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantshoot_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantshoot_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantflash_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantflash_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantshine_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantshine_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantblood_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantinterval_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantblood_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_plantinterval_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateplantlist_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearplantlist_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateplantlist_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearplantlist_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateplantlist_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearplantlist_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateplantlist_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearplantlist_4_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_updateplantlist_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearplantlist_5_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_starttotal_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_realtimefile_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_zombiedisapear_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_moniter_zombiex_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiex_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiey_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiey_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiebodyblood_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiebodyblood_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiearmorblood1_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiearmorblood1_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiearmorblood2_selectionChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiearmorblood2_editingFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombieslowtime_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombieslowtime_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiebuttertime_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiebuttertime_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiefrozetime_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiefrozetime_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiebodyshinetime_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiebodyshinetime_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiearmorshinetime_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiearmorshinetime_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiearmorshaketime_sliderPressed'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_moniter_zombiearmorshaketime_sliderReleased'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_ishypnoed_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_isvisible_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zombie_blowaway_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zombie_near_dead_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zombie_inwater_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zombie_eatgarlic_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_zombieoutfile_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_main_exitButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_checkBox_2_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nomowernozombie_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_bulletchange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bulletdefault_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_bulletvalue_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_disposablevalue_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_diposablechange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_disposabledefault_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_goodsvalue_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_goodschange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_goodsdefault_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_plantlistbase_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_plantlistbase_2_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_costchange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_coolchange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_costdefault_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cooldefault_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_13_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_unlockmemorymaxmiun_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_unlockshopitems_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_addeffectplant_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deleteselectplanteffect_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_plantaffectongame_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_cancelaffenctongame_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearallbullet_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_savesettings_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_readsettings_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'xorFileData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->closeEvent((*reinterpret_cast< std::add_pointer_t<QCloseEvent*>>(_a[1]))); break;
        case 1: _t->on_lookbyprocess_clicked(); break;
        case 2: _t->on_startlog_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->on_startbypath_clicked(); break;
        case 4: _t->on_sunchange_clicked(); break;
        case 5: _t->on_quickset_clicked(); break;
        case 6: _t->on_resetall_clicked(); break;
        case 7: _t->on_plantInvincible_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_nocostsun_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_freeplant_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_nocool_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_nocrater_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_noawake_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_nolimitonplant_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_clearplant_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->on_zombieInvincible_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_pausesystemzombie_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_zombiepause_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_clearallzombies_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_passthegame_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_unlockglod_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_unlockallmode_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_lockspade_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_hidespade_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->on_hideslot_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->on_hidemenu_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->on_nosun_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_autocollect_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_pausegame_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->on_allowrunback_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->on_plantplace_clicked(); break;
        case 31: _t->on_plantmoniter_clicked(); break;
        case 32: _t->on_zombieplace_clicked(); break;
        case 33: _t->on_zombiemoniter_clicked(); break;
        case 34: _t->on_isdefaultplantbook_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 35: _t->on_updateplantbook_clicked(); break;
        case 36: _t->on_sureupdateplantbook_clicked(); break;
        case 37: _t->on_startforbidplace_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 38: _t->on_globalforbid_clicked(); break;
        case 39: _t->on_rowforbid_clicked(); break;
        case 40: _t->on_colforbid_clicked(); break;
        case 41: _t->on_singleforbid_clicked(); break;
        case 42: _t->on_surerowcol_clicked(); break;
        case 43: _t->on_currentreset_clicked(); break;
        case 44: _t->on_globalreset_clicked(); break;
        case 45: _t->on_sureforbid_clicked(); break;
        case 46: _t->on_randslot_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 47: _t->on_startforbid_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 48: _t->on_createselections_clicked(); break;
        case 49: _t->on_forbidaffectrandslot_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 50: _t->on_randplantreset_clicked(); break;
        case 51: _t->on_startrandplaceplant_clicked(); break;
        case 52: _t->on_radioButton_clicked(); break;
        case 53: _t->on_singleplantplace_clicked(); break;
        case 54: _t->on_enableblood_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 55: _t->on_enableinterval_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 56: _t->on_rowtogether_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 57: _t->on_coltogether_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 58: _t->on_creatselections_freeplant_clicked(); break;
        case 59: _t->on_suretoplant_free_clicked(); break;
        case 60: _t->on_copy_clicked(); break;
        case 61: _t->on_paste_clicked(); break;
        case 62: _t->on_clearformationtext_clicked(); break;
        case 63: _t->on_clearplant_form_clicked(); break;
        case 64: _t->on_readfile_clicked(); break;
        case 65: _t->on_savaasfile_clicked(); break;
        case 66: _t->on_strtoform_clicked(); break;
        case 67: _t->on_formtostr_clicked(); break;
        case 68: _t->on_isdefaultplantbook_zombie_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 69: _t->on_updateplantbook_zombie_clicked(); break;
        case 70: _t->on_sureupdatezombiebook_clicked(); break;
        case 71: _t->on_suretosetblindbox_clicked(); break;
        case 72: _t->on_startforbidplace_zombie_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 73: _t->on_globalreset_2_clicked(); break;
        case 74: _t->on_sureforbid_2_clicked(); break;
        case 75: _t->on_startmower_clicked(); break;
        case 76: _t->on_clearmower_clicked(); break;
        case 77: _t->on_resummower_clicked(); break;
        case 78: _t->on_directputonce_clicked(); break;
        case 79: _t->on_pushButton_clicked(); break;
        case 80: _t->on_pausewithgame_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 81: _t->on_autospicy_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 82: _t->on_pauseputting_clicked(); break;
        case 83: _t->on_stopputting_clicked(); break;
        case 84: _t->on_addnode_clicked(); break;
        case 85: _t->on_deletelist_clicked(); break;
        case 86: _t->on_startputting_clicked(); break;
        case 87: _t->on_saveile_autozombie_clicked(); break;
        case 88: _t->on_readfile_autozombie_clicked(); break;
        case 89: _t->on_pushButton_2_clicked(); break;
        case 90: _t->on_randblindboxmode_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 91: _t->on_addfreezombie_clicked(); break;
        case 92: _t->on_rowcolput_clicked(); break;
        case 93: _t->on_coordinateput_clicked(); break;
        case 94: _t->on_putfreezombie_clicked(); break;
        case 95: _t->on_freezombiedelete_clicked(); break;
        case 96: _t->on_freezombiereset_clicked(); break;
        case 97: _t->on_freezombieput_clicked(); break;
        case 98: _t->on_startplantmoniter_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 99: _t->on_disappear_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 100: _t->on_squish_clicked(); break;
        case 101: _t->on_asleep_clicked(); break;
        case 102: _t->on_enableshine_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 103: _t->on_invisible_clicked(); break;
        case 104: _t->on_left_clicked(); break;
        case 105: _t->on_right_clicked(); break;
        case 106: _t->on_enableshine_clicked(); break;
        case 107: _t->on_moniter_plantshoot_sliderPressed(); break;
        case 108: _t->on_moniter_plantshoot_sliderReleased(); break;
        case 109: _t->on_moniter_plantflash_sliderPressed(); break;
        case 110: _t->on_moniter_plantflash_sliderReleased(); break;
        case 111: _t->on_moniter_plantshine_sliderPressed(); break;
        case 112: _t->on_moniter_plantshine_sliderReleased(); break;
        case 113: _t->on_moniter_plantblood_selectionChanged(); break;
        case 114: _t->on_moniter_plantinterval_selectionChanged(); break;
        case 115: _t->on_moniter_plantblood_editingFinished(); break;
        case 116: _t->on_moniter_plantinterval_editingFinished(); break;
        case 117: _t->on_updateplantlist_clicked(); break;
        case 118: _t->on_clearplantlist_clicked(); break;
        case 119: _t->on_updateplantlist_2_clicked(); break;
        case 120: _t->on_clearplantlist_2_clicked(); break;
        case 121: _t->on_updateplantlist_3_clicked(); break;
        case 122: _t->on_clearplantlist_3_clicked(); break;
        case 123: _t->on_updateplantlist_4_clicked(); break;
        case 124: _t->on_clearplantlist_4_clicked(); break;
        case 125: _t->on_updateplantlist_5_clicked(); break;
        case 126: _t->on_clearplantlist_5_clicked(); break;
        case 127: _t->on_checkBox_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 128: _t->on_starttotal_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 129: _t->on_realtimefile_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 130: _t->on_zombiedisapear_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 131: _t->on_moniter_zombiex_selectionChanged(); break;
        case 132: _t->on_moniter_zombiex_editingFinished(); break;
        case 133: _t->on_moniter_zombiey_selectionChanged(); break;
        case 134: _t->on_moniter_zombiey_editingFinished(); break;
        case 135: _t->on_moniter_zombiebodyblood_selectionChanged(); break;
        case 136: _t->on_moniter_zombiebodyblood_editingFinished(); break;
        case 137: _t->on_moniter_zombiearmorblood1_selectionChanged(); break;
        case 138: _t->on_moniter_zombiearmorblood1_editingFinished(); break;
        case 139: _t->on_moniter_zombiearmorblood2_selectionChanged(); break;
        case 140: _t->on_moniter_zombiearmorblood2_editingFinished(); break;
        case 141: _t->on_moniter_zombieslowtime_sliderPressed(); break;
        case 142: _t->on_moniter_zombieslowtime_sliderReleased(); break;
        case 143: _t->on_moniter_zombiebuttertime_sliderPressed(); break;
        case 144: _t->on_moniter_zombiebuttertime_sliderReleased(); break;
        case 145: _t->on_moniter_zombiefrozetime_sliderPressed(); break;
        case 146: _t->on_moniter_zombiefrozetime_sliderReleased(); break;
        case 147: _t->on_moniter_zombiebodyshinetime_sliderPressed(); break;
        case 148: _t->on_moniter_zombiebodyshinetime_sliderReleased(); break;
        case 149: _t->on_moniter_zombiearmorshinetime_sliderPressed(); break;
        case 150: _t->on_moniter_zombiearmorshinetime_sliderReleased(); break;
        case 151: _t->on_moniter_zombiearmorshaketime_sliderPressed(); break;
        case 152: _t->on_moniter_zombiearmorshaketime_sliderReleased(); break;
        case 153: _t->on_ishypnoed_clicked(); break;
        case 154: _t->on_isvisible_clicked(); break;
        case 155: _t->on_zombie_blowaway_clicked(); break;
        case 156: _t->on_zombie_near_dead_clicked(); break;
        case 157: _t->on_zombie_inwater_clicked(); break;
        case 158: _t->on_zombie_eatgarlic_clicked(); break;
        case 159: _t->on_zombieoutfile_clicked(); break;
        case 160: _t->on_main_exitButton_clicked(); break;
        case 161: _t->on_checkBox_2_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 162: _t->on_nomowernozombie_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 163: _t->on_bulletchange_clicked(); break;
        case 164: _t->on_bulletdefault_clicked(); break;
        case 165: _t->on_bulletvalue_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 166: _t->on_disposablevalue_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 167: _t->on_diposablechange_clicked(); break;
        case 168: _t->on_disposabledefault_clicked(); break;
        case 169: _t->on_goodsvalue_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 170: _t->on_goodschange_clicked(); break;
        case 171: _t->on_goodsdefault_clicked(); break;
        case 172: _t->on_plantlistbase_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 173: _t->on_plantlistbase_2_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 174: _t->on_costchange_clicked(); break;
        case 175: _t->on_coolchange_clicked(); break;
        case 176: _t->on_costdefault_clicked(); break;
        case 177: _t->on_cooldefault_clicked(); break;
        case 178: _t->on_pushButton_13_clicked(); break;
        case 179: _t->on_unlockmemorymaxmiun_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 180: _t->on_unlockshopitems_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 181: _t->on_addeffectplant_clicked(); break;
        case 182: _t->on_deleteselectplanteffect_clicked(); break;
        case 183: _t->on_plantaffectongame_clicked(); break;
        case 184: _t->on_cancelaffenctongame_clicked(); break;
        case 185: _t->on_clearallbullet_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 186: _t->on_savesettings_clicked(); break;
        case 187: _t->on_readsettings_clicked(); break;
        case 188: _t->xorFileData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 189)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 189;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 189)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 189;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSslotsetplantENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSslotsetplantENDCLASS = QtMocHelpers::stringData(
    "slotsetplant"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSslotsetplantENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSslotsetplantENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSslotsetplantENDCLASS_t qt_meta_stringdata_CLASSslotsetplantENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12)   // "slotsetplant"
    },
    "slotsetplant"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSslotsetplantENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject slotsetplant::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSslotsetplantENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSslotsetplantENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSslotsetplantENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<slotsetplant, std::true_type>
    >,
    nullptr
} };

void slotsetplant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *slotsetplant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *slotsetplant::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSslotsetplantENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int slotsetplant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSslotplantmoniterENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSslotplantmoniterENDCLASS = QtMocHelpers::stringData(
    "slotplantmoniter",
    "threadend",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSslotplantmoniterENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[17];
    char stringdata1[10];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSslotplantmoniterENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSslotplantmoniterENDCLASS_t qt_meta_stringdata_CLASSslotplantmoniterENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "slotplantmoniter"
        QT_MOC_LITERAL(17, 9),  // "threadend"
        QT_MOC_LITERAL(27, 0)   // ""
    },
    "slotplantmoniter",
    "threadend",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSslotplantmoniterENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x06,    1 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject slotplantmoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSslotplantmoniterENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSslotplantmoniterENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSslotplantmoniterENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<slotplantmoniter, std::true_type>,
        // method 'threadend'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void slotplantmoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<slotplantmoniter *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->threadend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (slotplantmoniter::*)();
            if (_t _q_method = &slotplantmoniter::threadend; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *slotplantmoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *slotplantmoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSslotplantmoniterENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int slotplantmoniter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void slotplantmoniter::threadend()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
