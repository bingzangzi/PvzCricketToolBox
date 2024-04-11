/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AutoPlacingv2_0/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ZombieInfoUpdateThread_t {
    QByteArrayData data[4];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZombieInfoUpdateThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZombieInfoUpdateThread_t qt_meta_stringdata_ZombieInfoUpdateThread = {
    {
QT_MOC_LITERAL(0, 0, 22), // "ZombieInfoUpdateThread"
QT_MOC_LITERAL(1, 23, 12), // "updatefinied"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 16) // "ZombieInfoStruct"

    },
    "ZombieInfoUpdateThread\0updatefinied\0"
    "\0ZombieInfoStruct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZombieInfoUpdateThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void ZombieInfoUpdateThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombieInfoUpdateThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatefinied((*reinterpret_cast< ZombieInfoStruct(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombieInfoUpdateThread::*)(ZombieInfoStruct );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZombieInfoUpdateThread::updatefinied)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ZombieInfoUpdateThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_ZombieInfoUpdateThread.data,
    qt_meta_data_ZombieInfoUpdateThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ZombieInfoUpdateThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombieInfoUpdateThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZombieInfoUpdateThread.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
struct qt_meta_stringdata_ZombieStatusMoniter_t {
    QByteArrayData data[13];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZombieStatusMoniter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZombieStatusMoniter_t qt_meta_stringdata_ZombieStatusMoniter = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ZombieStatusMoniter"
QT_MOC_LITERAL(1, 20, 14), // "zombiedeadinfo"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "ZombieInfoStruct"
QT_MOC_LITERAL(4, 53, 3), // "num"
QT_MOC_LITERAL(5, 57, 5), // "state"
QT_MOC_LITERAL(6, 63, 13), // "findnewzombie"
QT_MOC_LITERAL(7, 77, 4), // "type"
QT_MOC_LITERAL(8, 82, 4), // "body"
QT_MOC_LITERAL(9, 87, 6), // "armor1"
QT_MOC_LITERAL(10, 94, 6), // "armor2"
QT_MOC_LITERAL(11, 101, 3), // "row"
QT_MOC_LITERAL(12, 105, 13) // "abnormaltermi"

    },
    "ZombieStatusMoniter\0zombiedeadinfo\0\0"
    "ZombieInfoStruct\0num\0state\0findnewzombie\0"
    "type\0body\0armor1\0armor2\0row\0abnormaltermi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZombieStatusMoniter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       6,    7,   36,    2, 0x06 /* Public */,
      12,    0,   51,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    2,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    7,    8,    9,   10,    4,   11,    2,
    QMetaType::Void,

       0        // eod
};

void ZombieStatusMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombieStatusMoniter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->zombiedeadinfo((*reinterpret_cast< ZombieInfoStruct(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->findnewzombie((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7]))); break;
        case 2: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombieStatusMoniter::*)(ZombieInfoStruct , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZombieStatusMoniter::zombiedeadinfo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZombieStatusMoniter::*)(int , int , int , int , int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZombieStatusMoniter::findnewzombie)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ZombieStatusMoniter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZombieStatusMoniter::abnormaltermi)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ZombieStatusMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_ZombieStatusMoniter.data,
    qt_meta_data_ZombieStatusMoniter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ZombieStatusMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombieStatusMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZombieStatusMoniter.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
struct qt_meta_stringdata_NewZombieMoniter_t {
    QByteArrayData data[10];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewZombieMoniter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewZombieMoniter_t qt_meta_stringdata_NewZombieMoniter = {
    {
QT_MOC_LITERAL(0, 0, 16), // "NewZombieMoniter"
QT_MOC_LITERAL(1, 17, 13), // "abnormaltermi"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "findnewzombie"
QT_MOC_LITERAL(4, 46, 4), // "type"
QT_MOC_LITERAL(5, 51, 4), // "body"
QT_MOC_LITERAL(6, 56, 6), // "armor1"
QT_MOC_LITERAL(7, 63, 6), // "armor2"
QT_MOC_LITERAL(8, 70, 3), // "num"
QT_MOC_LITERAL(9, 74, 3) // "row"

    },
    "NewZombieMoniter\0abnormaltermi\0\0"
    "findnewzombie\0type\0body\0armor1\0armor2\0"
    "num\0row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewZombieMoniter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    7,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    4,    5,    6,    7,    8,    9,    2,

       0        // eod
};

void NewZombieMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewZombieMoniter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        case 1: _t->findnewzombie((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< bool(*)>(_a[7]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewZombieMoniter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NewZombieMoniter::abnormaltermi)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NewZombieMoniter::*)(int , int , int , int , int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NewZombieMoniter::findnewzombie)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NewZombieMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_NewZombieMoniter.data,
    qt_meta_data_NewZombieMoniter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NewZombieMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewZombieMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewZombieMoniter.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
struct qt_meta_stringdata_PlantInfoUpdateThread_t {
    QByteArrayData data[7];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlantInfoUpdateThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlantInfoUpdateThread_t qt_meta_stringdata_PlantInfoUpdateThread = {
    {
QT_MOC_LITERAL(0, 0, 21), // "PlantInfoUpdateThread"
QT_MOC_LITERAL(1, 22, 12), // "updatefinied"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 3), // "row"
QT_MOC_LITERAL(4, 40, 3), // "col"
QT_MOC_LITERAL(5, 44, 3), // "num"
QT_MOC_LITERAL(6, 48, 6) // "status"

    },
    "PlantInfoUpdateThread\0updatefinied\0\0"
    "row\0col\0num\0status"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlantInfoUpdateThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,

       0        // eod
};

void PlantInfoUpdateThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlantInfoUpdateThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatefinied((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlantInfoUpdateThread::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlantInfoUpdateThread::updatefinied)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlantInfoUpdateThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_PlantInfoUpdateThread.data,
    qt_meta_data_PlantInfoUpdateThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlantInfoUpdateThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlantInfoUpdateThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlantInfoUpdateThread.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
struct qt_meta_stringdata_PlantStatusMoniter_t {
    QByteArrayData data[8];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlantStatusMoniter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlantStatusMoniter_t qt_meta_stringdata_PlantStatusMoniter = {
    {
QT_MOC_LITERAL(0, 0, 18), // "PlantStatusMoniter"
QT_MOC_LITERAL(1, 19, 11), // "plantchange"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 3), // "row"
QT_MOC_LITERAL(4, 36, 3), // "col"
QT_MOC_LITERAL(5, 40, 3), // "num"
QT_MOC_LITERAL(6, 44, 6), // "status"
QT_MOC_LITERAL(7, 51, 13) // "abnormaltermi"

    },
    "PlantStatusMoniter\0plantchange\0\0row\0"
    "col\0num\0status\0abnormaltermi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlantStatusMoniter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   24,    2, 0x06 /* Public */,
       7,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void,

       0        // eod
};

void PlantStatusMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlantStatusMoniter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->plantchange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlantStatusMoniter::*)(int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlantStatusMoniter::plantchange)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlantStatusMoniter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlantStatusMoniter::abnormaltermi)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlantStatusMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_PlantStatusMoniter.data,
    qt_meta_data_PlantStatusMoniter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlantStatusMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlantStatusMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlantStatusMoniter.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
struct qt_meta_stringdata_NewPlantMoniter_t {
    QByteArrayData data[3];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NewPlantMoniter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NewPlantMoniter_t qt_meta_stringdata_NewPlantMoniter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "NewPlantMoniter"
QT_MOC_LITERAL(1, 16, 13), // "abnormaltermi"
QT_MOC_LITERAL(2, 30, 0) // ""

    },
    "NewPlantMoniter\0abnormaltermi\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NewPlantMoniter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void NewPlantMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NewPlantMoniter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NewPlantMoniter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NewPlantMoniter::abnormaltermi)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject NewPlantMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_NewPlantMoniter.data,
    qt_meta_data_NewPlantMoniter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NewPlantMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NewPlantMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NewPlantMoniter.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void NewPlantMoniter::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_BlindBoxPut_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlindBoxPut_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlindBoxPut_t qt_meta_stringdata_BlindBoxPut = {
    {
QT_MOC_LITERAL(0, 0, 11) // "BlindBoxPut"

    },
    "BlindBoxPut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlindBoxPut[] = {

 // content:
       8,       // revision
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

void BlindBoxPut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BlindBoxPut::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_BlindBoxPut.data,
    qt_meta_data_BlindBoxPut,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BlindBoxPut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlindBoxPut::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlindBoxPut.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int BlindBoxPut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_BlindBoxMoniter_t {
    QByteArrayData data[3];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlindBoxMoniter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlindBoxMoniter_t qt_meta_stringdata_BlindBoxMoniter = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BlindBoxMoniter"
QT_MOC_LITERAL(1, 16, 13), // "abnormaltermi"
QT_MOC_LITERAL(2, 30, 0) // ""

    },
    "BlindBoxMoniter\0abnormaltermi\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlindBoxMoniter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void BlindBoxMoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BlindBoxMoniter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BlindBoxMoniter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlindBoxMoniter::abnormaltermi)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BlindBoxMoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_BlindBoxMoniter.data,
    qt_meta_data_BlindBoxMoniter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BlindBoxMoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlindBoxMoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlindBoxMoniter.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void BlindBoxMoniter::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_BlindBoxSearch_t {
    QByteArrayData data[3];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlindBoxSearch_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlindBoxSearch_t qt_meta_stringdata_BlindBoxSearch = {
    {
QT_MOC_LITERAL(0, 0, 14), // "BlindBoxSearch"
QT_MOC_LITERAL(1, 15, 13), // "abnormaltermi"
QT_MOC_LITERAL(2, 29, 0) // ""

    },
    "BlindBoxSearch\0abnormaltermi\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlindBoxSearch[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void BlindBoxSearch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BlindBoxSearch *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BlindBoxSearch::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlindBoxSearch::abnormaltermi)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject BlindBoxSearch::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_BlindBoxSearch.data,
    qt_meta_data_BlindBoxSearch,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BlindBoxSearch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlindBoxSearch::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlindBoxSearch.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void BlindBoxSearch::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_SpiceThread_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SpiceThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SpiceThread_t qt_meta_stringdata_SpiceThread = {
    {
QT_MOC_LITERAL(0, 0, 11), // "SpiceThread"
QT_MOC_LITERAL(1, 12, 13), // "abnormaltermi"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "SpiceThread\0abnormaltermi\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SpiceThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void SpiceThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SpiceThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SpiceThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SpiceThread::abnormaltermi)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SpiceThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_SpiceThread.data,
    qt_meta_data_SpiceThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SpiceThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SpiceThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SpiceThread.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void SpiceThread::abnormaltermi()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_ZombiePutThread_t {
    QByteArrayData data[5];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ZombiePutThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ZombiePutThread_t qt_meta_stringdata_ZombiePutThread = {
    {
QT_MOC_LITERAL(0, 0, 15), // "ZombiePutThread"
QT_MOC_LITERAL(1, 16, 13), // "abnormaltermi"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "updatetime"
QT_MOC_LITERAL(4, 42, 17) // "updatezombiecount"

    },
    "ZombiePutThread\0abnormaltermi\0\0"
    "updatetime\0updatezombiecount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ZombiePutThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    1,   30,    2, 0x06 /* Public */,
       4,    0,   33,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,

       0        // eod
};

void ZombiePutThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombiePutThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->abnormaltermi(); break;
        case 1: _t->updatetime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->updatezombiecount(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombiePutThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZombiePutThread::abnormaltermi)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZombiePutThread::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZombiePutThread::updatetime)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ZombiePutThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ZombiePutThread::updatezombiecount)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ZombiePutThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_ZombiePutThread.data,
    qt_meta_data_ZombiePutThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ZombiePutThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombiePutThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ZombiePutThread.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[196];
    char stringdata0[5514];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "closeEvent"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 12), // "QCloseEvent*"
QT_MOC_LITERAL(4, 36, 5), // "event"
QT_MOC_LITERAL(5, 42, 24), // "on_lookbyprocess_clicked"
QT_MOC_LITERAL(6, 67, 24), // "on_startlog_stateChanged"
QT_MOC_LITERAL(7, 92, 4), // "arg1"
QT_MOC_LITERAL(8, 97, 22), // "on_startbypath_clicked"
QT_MOC_LITERAL(9, 120, 20), // "on_sunchange_clicked"
QT_MOC_LITERAL(10, 141, 19), // "on_quickset_clicked"
QT_MOC_LITERAL(11, 161, 19), // "on_resetall_clicked"
QT_MOC_LITERAL(12, 181, 31), // "on_plantInvincible_stateChanged"
QT_MOC_LITERAL(13, 213, 25), // "on_nocostsun_stateChanged"
QT_MOC_LITERAL(14, 239, 25), // "on_freeplant_stateChanged"
QT_MOC_LITERAL(15, 265, 22), // "on_nocool_stateChanged"
QT_MOC_LITERAL(16, 288, 24), // "on_nocrater_stateChanged"
QT_MOC_LITERAL(17, 313, 23), // "on_noawake_stateChanged"
QT_MOC_LITERAL(18, 337, 30), // "on_nolimitonplant_stateChanged"
QT_MOC_LITERAL(19, 368, 26), // "on_clearplant_stateChanged"
QT_MOC_LITERAL(20, 395, 32), // "on_zombieInvincible_stateChanged"
QT_MOC_LITERAL(21, 428, 33), // "on_pausesystemzombie_stateCha..."
QT_MOC_LITERAL(22, 462, 27), // "on_zombiepause_stateChanged"
QT_MOC_LITERAL(23, 490, 31), // "on_clearallzombies_stateChanged"
QT_MOC_LITERAL(24, 522, 27), // "on_passthegame_stateChanged"
QT_MOC_LITERAL(25, 550, 26), // "on_unlockglod_stateChanged"
QT_MOC_LITERAL(26, 577, 29), // "on_unlockallmode_stateChanged"
QT_MOC_LITERAL(27, 607, 25), // "on_lockspade_stateChanged"
QT_MOC_LITERAL(28, 633, 25), // "on_hidespade_stateChanged"
QT_MOC_LITERAL(29, 659, 24), // "on_hideslot_stateChanged"
QT_MOC_LITERAL(30, 684, 24), // "on_hidemenu_stateChanged"
QT_MOC_LITERAL(31, 709, 21), // "on_nosun_stateChanged"
QT_MOC_LITERAL(32, 731, 27), // "on_autocollect_stateChanged"
QT_MOC_LITERAL(33, 759, 25), // "on_pausegame_stateChanged"
QT_MOC_LITERAL(34, 785, 28), // "on_allowrunback_stateChanged"
QT_MOC_LITERAL(35, 814, 21), // "on_plantplace_clicked"
QT_MOC_LITERAL(36, 836, 23), // "on_plantmoniter_clicked"
QT_MOC_LITERAL(37, 860, 22), // "on_zombieplace_clicked"
QT_MOC_LITERAL(38, 883, 24), // "on_zombiemoniter_clicked"
QT_MOC_LITERAL(39, 908, 34), // "on_isdefaultplantbook_stateCh..."
QT_MOC_LITERAL(40, 943, 26), // "on_updateplantbook_clicked"
QT_MOC_LITERAL(41, 970, 30), // "on_sureupdateplantbook_clicked"
QT_MOC_LITERAL(42, 1001, 32), // "on_startforbidplace_stateChanged"
QT_MOC_LITERAL(43, 1034, 23), // "on_globalforbid_clicked"
QT_MOC_LITERAL(44, 1058, 20), // "on_rowforbid_clicked"
QT_MOC_LITERAL(45, 1079, 20), // "on_colforbid_clicked"
QT_MOC_LITERAL(46, 1100, 23), // "on_singleforbid_clicked"
QT_MOC_LITERAL(47, 1124, 21), // "on_surerowcol_clicked"
QT_MOC_LITERAL(48, 1146, 23), // "on_currentreset_clicked"
QT_MOC_LITERAL(49, 1170, 22), // "on_globalreset_clicked"
QT_MOC_LITERAL(50, 1193, 21), // "on_sureforbid_clicked"
QT_MOC_LITERAL(51, 1215, 24), // "on_randslot_stateChanged"
QT_MOC_LITERAL(52, 1240, 27), // "on_startforbid_stateChanged"
QT_MOC_LITERAL(53, 1268, 27), // "on_createselections_clicked"
QT_MOC_LITERAL(54, 1296, 36), // "on_forbidaffectrandslot_state..."
QT_MOC_LITERAL(55, 1333, 25), // "on_randplantreset_clicked"
QT_MOC_LITERAL(56, 1359, 30), // "on_startrandplaceplant_clicked"
QT_MOC_LITERAL(57, 1390, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(58, 1413, 27), // "on_singleplantplace_clicked"
QT_MOC_LITERAL(59, 1441, 27), // "on_enableblood_stateChanged"
QT_MOC_LITERAL(60, 1469, 30), // "on_enableinterval_stateChanged"
QT_MOC_LITERAL(61, 1500, 27), // "on_rowtogether_stateChanged"
QT_MOC_LITERAL(62, 1528, 27), // "on_coltogether_stateChanged"
QT_MOC_LITERAL(63, 1556, 36), // "on_creatselections_freeplant_..."
QT_MOC_LITERAL(64, 1593, 27), // "on_suretoplant_free_clicked"
QT_MOC_LITERAL(65, 1621, 15), // "on_copy_clicked"
QT_MOC_LITERAL(66, 1637, 16), // "on_paste_clicked"
QT_MOC_LITERAL(67, 1654, 29), // "on_clearformationtext_clicked"
QT_MOC_LITERAL(68, 1684, 26), // "on_clearplant_form_clicked"
QT_MOC_LITERAL(69, 1711, 19), // "on_readfile_clicked"
QT_MOC_LITERAL(70, 1731, 21), // "on_savaasfile_clicked"
QT_MOC_LITERAL(71, 1753, 20), // "on_strtoform_clicked"
QT_MOC_LITERAL(72, 1774, 20), // "on_formtostr_clicked"
QT_MOC_LITERAL(73, 1795, 41), // "on_isdefaultplantbook_zombie_..."
QT_MOC_LITERAL(74, 1837, 33), // "on_updateplantbook_zombie_cli..."
QT_MOC_LITERAL(75, 1871, 31), // "on_sureupdatezombiebook_clicked"
QT_MOC_LITERAL(76, 1903, 28), // "on_suretosetblindbox_clicked"
QT_MOC_LITERAL(77, 1932, 39), // "on_startforbidplace_zombie_st..."
QT_MOC_LITERAL(78, 1972, 24), // "on_globalreset_2_clicked"
QT_MOC_LITERAL(79, 1997, 23), // "on_sureforbid_2_clicked"
QT_MOC_LITERAL(80, 2021, 21), // "on_startmower_clicked"
QT_MOC_LITERAL(81, 2043, 21), // "on_clearmower_clicked"
QT_MOC_LITERAL(82, 2065, 21), // "on_resummower_clicked"
QT_MOC_LITERAL(83, 2087, 24), // "on_directputonce_clicked"
QT_MOC_LITERAL(84, 2112, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(85, 2134, 29), // "on_pausewithgame_stateChanged"
QT_MOC_LITERAL(86, 2164, 25), // "on_autospicy_stateChanged"
QT_MOC_LITERAL(87, 2190, 23), // "on_pauseputting_clicked"
QT_MOC_LITERAL(88, 2214, 22), // "on_stopputting_clicked"
QT_MOC_LITERAL(89, 2237, 18), // "on_addnode_clicked"
QT_MOC_LITERAL(90, 2256, 21), // "on_deletelist_clicked"
QT_MOC_LITERAL(91, 2278, 23), // "on_startputting_clicked"
QT_MOC_LITERAL(92, 2302, 29), // "on_saveile_autozombie_clicked"
QT_MOC_LITERAL(93, 2332, 30), // "on_readfile_autozombie_clicked"
QT_MOC_LITERAL(94, 2363, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(95, 2387, 32), // "on_randblindboxmode_stateChanged"
QT_MOC_LITERAL(96, 2420, 24), // "on_addfreezombie_clicked"
QT_MOC_LITERAL(97, 2445, 20), // "on_rowcolput_clicked"
QT_MOC_LITERAL(98, 2466, 24), // "on_coordinateput_clicked"
QT_MOC_LITERAL(99, 2491, 24), // "on_putfreezombie_clicked"
QT_MOC_LITERAL(100, 2516, 27), // "on_freezombiedelete_clicked"
QT_MOC_LITERAL(101, 2544, 26), // "on_freezombiereset_clicked"
QT_MOC_LITERAL(102, 2571, 24), // "on_freezombieput_clicked"
QT_MOC_LITERAL(103, 2596, 33), // "on_startplantmoniter_stateCha..."
QT_MOC_LITERAL(104, 2630, 25), // "on_disappear_stateChanged"
QT_MOC_LITERAL(105, 2656, 17), // "on_squish_clicked"
QT_MOC_LITERAL(106, 2674, 17), // "on_asleep_clicked"
QT_MOC_LITERAL(107, 2692, 27), // "on_enableshine_stateChanged"
QT_MOC_LITERAL(108, 2720, 20), // "on_invisible_clicked"
QT_MOC_LITERAL(109, 2741, 15), // "on_left_clicked"
QT_MOC_LITERAL(110, 2757, 16), // "on_right_clicked"
QT_MOC_LITERAL(111, 2774, 22), // "on_enableshine_clicked"
QT_MOC_LITERAL(112, 2797, 35), // "on_moniter_plantshoot_sliderP..."
QT_MOC_LITERAL(113, 2833, 36), // "on_moniter_plantshoot_sliderR..."
QT_MOC_LITERAL(114, 2870, 35), // "on_moniter_plantflash_sliderP..."
QT_MOC_LITERAL(115, 2906, 36), // "on_moniter_plantflash_sliderR..."
QT_MOC_LITERAL(116, 2943, 35), // "on_moniter_plantshine_sliderP..."
QT_MOC_LITERAL(117, 2979, 36), // "on_moniter_plantshine_sliderR..."
QT_MOC_LITERAL(118, 3016, 38), // "on_moniter_plantblood_selecti..."
QT_MOC_LITERAL(119, 3055, 41), // "on_moniter_plantinterval_sele..."
QT_MOC_LITERAL(120, 3097, 37), // "on_moniter_plantblood_editing..."
QT_MOC_LITERAL(121, 3135, 40), // "on_moniter_plantinterval_edit..."
QT_MOC_LITERAL(122, 3176, 26), // "on_updateplantlist_clicked"
QT_MOC_LITERAL(123, 3203, 25), // "on_clearplantlist_clicked"
QT_MOC_LITERAL(124, 3229, 28), // "on_updateplantlist_2_clicked"
QT_MOC_LITERAL(125, 3258, 27), // "on_clearplantlist_2_clicked"
QT_MOC_LITERAL(126, 3286, 28), // "on_updateplantlist_3_clicked"
QT_MOC_LITERAL(127, 3315, 27), // "on_clearplantlist_3_clicked"
QT_MOC_LITERAL(128, 3343, 28), // "on_updateplantlist_4_clicked"
QT_MOC_LITERAL(129, 3372, 27), // "on_clearplantlist_4_clicked"
QT_MOC_LITERAL(130, 3400, 28), // "on_updateplantlist_5_clicked"
QT_MOC_LITERAL(131, 3429, 27), // "on_clearplantlist_5_clicked"
QT_MOC_LITERAL(132, 3457, 24), // "on_checkBox_stateChanged"
QT_MOC_LITERAL(133, 3482, 26), // "on_starttotal_stateChanged"
QT_MOC_LITERAL(134, 3509, 28), // "on_realtimefile_stateChanged"
QT_MOC_LITERAL(135, 3538, 30), // "on_zombiedisapear_stateChanged"
QT_MOC_LITERAL(136, 3569, 35), // "on_moniter_zombiex_selectionC..."
QT_MOC_LITERAL(137, 3605, 34), // "on_moniter_zombiex_editingFin..."
QT_MOC_LITERAL(138, 3640, 35), // "on_moniter_zombiey_selectionC..."
QT_MOC_LITERAL(139, 3676, 34), // "on_moniter_zombiey_editingFin..."
QT_MOC_LITERAL(140, 3711, 43), // "on_moniter_zombiebodyblood_se..."
QT_MOC_LITERAL(141, 3755, 42), // "on_moniter_zombiebodyblood_ed..."
QT_MOC_LITERAL(142, 3798, 45), // "on_moniter_zombiearmorblood1_..."
QT_MOC_LITERAL(143, 3844, 44), // "on_moniter_zombiearmorblood1_..."
QT_MOC_LITERAL(144, 3889, 45), // "on_moniter_zombiearmorblood2_..."
QT_MOC_LITERAL(145, 3935, 44), // "on_moniter_zombiearmorblood2_..."
QT_MOC_LITERAL(146, 3980, 39), // "on_moniter_zombieslowtime_sli..."
QT_MOC_LITERAL(147, 4020, 40), // "on_moniter_zombieslowtime_sli..."
QT_MOC_LITERAL(148, 4061, 41), // "on_moniter_zombiebuttertime_s..."
QT_MOC_LITERAL(149, 4103, 42), // "on_moniter_zombiebuttertime_s..."
QT_MOC_LITERAL(150, 4146, 40), // "on_moniter_zombiefrozetime_sl..."
QT_MOC_LITERAL(151, 4187, 41), // "on_moniter_zombiefrozetime_sl..."
QT_MOC_LITERAL(152, 4229, 44), // "on_moniter_zombiebodyshinetim..."
QT_MOC_LITERAL(153, 4274, 45), // "on_moniter_zombiebodyshinetim..."
QT_MOC_LITERAL(154, 4320, 45), // "on_moniter_zombiearmorshineti..."
QT_MOC_LITERAL(155, 4366, 46), // "on_moniter_zombiearmorshineti..."
QT_MOC_LITERAL(156, 4413, 45), // "on_moniter_zombiearmorshaketi..."
QT_MOC_LITERAL(157, 4459, 46), // "on_moniter_zombiearmorshaketi..."
QT_MOC_LITERAL(158, 4506, 20), // "on_ishypnoed_clicked"
QT_MOC_LITERAL(159, 4527, 20), // "on_isvisible_clicked"
QT_MOC_LITERAL(160, 4548, 26), // "on_zombie_blowaway_clicked"
QT_MOC_LITERAL(161, 4575, 27), // "on_zombie_near_dead_clicked"
QT_MOC_LITERAL(162, 4603, 25), // "on_zombie_inwater_clicked"
QT_MOC_LITERAL(163, 4629, 27), // "on_zombie_eatgarlic_clicked"
QT_MOC_LITERAL(164, 4657, 24), // "on_zombieoutfile_clicked"
QT_MOC_LITERAL(165, 4682, 26), // "on_main_exitButton_clicked"
QT_MOC_LITERAL(166, 4709, 26), // "on_checkBox_2_stateChanged"
QT_MOC_LITERAL(167, 4736, 31), // "on_nomowernozombie_stateChanged"
QT_MOC_LITERAL(168, 4768, 23), // "on_bulletchange_clicked"
QT_MOC_LITERAL(169, 4792, 24), // "on_bulletdefault_clicked"
QT_MOC_LITERAL(170, 4817, 34), // "on_bulletvalue_currentIndexCh..."
QT_MOC_LITERAL(171, 4852, 5), // "index"
QT_MOC_LITERAL(172, 4858, 38), // "on_disposablevalue_currentInd..."
QT_MOC_LITERAL(173, 4897, 26), // "on_diposablechange_clicked"
QT_MOC_LITERAL(174, 4924, 28), // "on_disposabledefault_clicked"
QT_MOC_LITERAL(175, 4953, 33), // "on_goodsvalue_currentIndexCha..."
QT_MOC_LITERAL(176, 4987, 22), // "on_goodschange_clicked"
QT_MOC_LITERAL(177, 5010, 23), // "on_goodsdefault_clicked"
QT_MOC_LITERAL(178, 5034, 36), // "on_plantlistbase_currentIndex..."
QT_MOC_LITERAL(179, 5071, 38), // "on_plantlistbase_2_currentInd..."
QT_MOC_LITERAL(180, 5110, 21), // "on_costchange_clicked"
QT_MOC_LITERAL(181, 5132, 21), // "on_coolchange_clicked"
QT_MOC_LITERAL(182, 5154, 22), // "on_costdefault_clicked"
QT_MOC_LITERAL(183, 5177, 22), // "on_cooldefault_clicked"
QT_MOC_LITERAL(184, 5200, 24), // "on_pushButton_13_clicked"
QT_MOC_LITERAL(185, 5225, 35), // "on_unlockmemorymaxmiun_stateC..."
QT_MOC_LITERAL(186, 5261, 31), // "on_unlockshopitems_stateChanged"
QT_MOC_LITERAL(187, 5293, 25), // "on_addeffectplant_clicked"
QT_MOC_LITERAL(188, 5319, 34), // "on_deleteselectplanteffect_cl..."
QT_MOC_LITERAL(189, 5354, 28), // "on_plantaffectongame_clicked"
QT_MOC_LITERAL(190, 5383, 30), // "on_cancelaffenctongame_clicked"
QT_MOC_LITERAL(191, 5414, 30), // "on_clearallbullet_stateChanged"
QT_MOC_LITERAL(192, 5445, 23), // "on_savesettings_clicked"
QT_MOC_LITERAL(193, 5469, 23), // "on_readsettings_clicked"
QT_MOC_LITERAL(194, 5493, 11), // "xorFileData"
QT_MOC_LITERAL(195, 5505, 8) // "filePath"

    },
    "MainWindow\0closeEvent\0\0QCloseEvent*\0"
    "event\0on_lookbyprocess_clicked\0"
    "on_startlog_stateChanged\0arg1\0"
    "on_startbypath_clicked\0on_sunchange_clicked\0"
    "on_quickset_clicked\0on_resetall_clicked\0"
    "on_plantInvincible_stateChanged\0"
    "on_nocostsun_stateChanged\0"
    "on_freeplant_stateChanged\0"
    "on_nocool_stateChanged\0on_nocrater_stateChanged\0"
    "on_noawake_stateChanged\0"
    "on_nolimitonplant_stateChanged\0"
    "on_clearplant_stateChanged\0"
    "on_zombieInvincible_stateChanged\0"
    "on_pausesystemzombie_stateChanged\0"
    "on_zombiepause_stateChanged\0"
    "on_clearallzombies_stateChanged\0"
    "on_passthegame_stateChanged\0"
    "on_unlockglod_stateChanged\0"
    "on_unlockallmode_stateChanged\0"
    "on_lockspade_stateChanged\0"
    "on_hidespade_stateChanged\0"
    "on_hideslot_stateChanged\0"
    "on_hidemenu_stateChanged\0on_nosun_stateChanged\0"
    "on_autocollect_stateChanged\0"
    "on_pausegame_stateChanged\0"
    "on_allowrunback_stateChanged\0"
    "on_plantplace_clicked\0on_plantmoniter_clicked\0"
    "on_zombieplace_clicked\0on_zombiemoniter_clicked\0"
    "on_isdefaultplantbook_stateChanged\0"
    "on_updateplantbook_clicked\0"
    "on_sureupdateplantbook_clicked\0"
    "on_startforbidplace_stateChanged\0"
    "on_globalforbid_clicked\0on_rowforbid_clicked\0"
    "on_colforbid_clicked\0on_singleforbid_clicked\0"
    "on_surerowcol_clicked\0on_currentreset_clicked\0"
    "on_globalreset_clicked\0on_sureforbid_clicked\0"
    "on_randslot_stateChanged\0"
    "on_startforbid_stateChanged\0"
    "on_createselections_clicked\0"
    "on_forbidaffectrandslot_stateChanged\0"
    "on_randplantreset_clicked\0"
    "on_startrandplaceplant_clicked\0"
    "on_radioButton_clicked\0"
    "on_singleplantplace_clicked\0"
    "on_enableblood_stateChanged\0"
    "on_enableinterval_stateChanged\0"
    "on_rowtogether_stateChanged\0"
    "on_coltogether_stateChanged\0"
    "on_creatselections_freeplant_clicked\0"
    "on_suretoplant_free_clicked\0on_copy_clicked\0"
    "on_paste_clicked\0on_clearformationtext_clicked\0"
    "on_clearplant_form_clicked\0"
    "on_readfile_clicked\0on_savaasfile_clicked\0"
    "on_strtoform_clicked\0on_formtostr_clicked\0"
    "on_isdefaultplantbook_zombie_stateChanged\0"
    "on_updateplantbook_zombie_clicked\0"
    "on_sureupdatezombiebook_clicked\0"
    "on_suretosetblindbox_clicked\0"
    "on_startforbidplace_zombie_stateChanged\0"
    "on_globalreset_2_clicked\0"
    "on_sureforbid_2_clicked\0on_startmower_clicked\0"
    "on_clearmower_clicked\0on_resummower_clicked\0"
    "on_directputonce_clicked\0on_pushButton_clicked\0"
    "on_pausewithgame_stateChanged\0"
    "on_autospicy_stateChanged\0"
    "on_pauseputting_clicked\0on_stopputting_clicked\0"
    "on_addnode_clicked\0on_deletelist_clicked\0"
    "on_startputting_clicked\0"
    "on_saveile_autozombie_clicked\0"
    "on_readfile_autozombie_clicked\0"
    "on_pushButton_2_clicked\0"
    "on_randblindboxmode_stateChanged\0"
    "on_addfreezombie_clicked\0on_rowcolput_clicked\0"
    "on_coordinateput_clicked\0"
    "on_putfreezombie_clicked\0"
    "on_freezombiedelete_clicked\0"
    "on_freezombiereset_clicked\0"
    "on_freezombieput_clicked\0"
    "on_startplantmoniter_stateChanged\0"
    "on_disappear_stateChanged\0on_squish_clicked\0"
    "on_asleep_clicked\0on_enableshine_stateChanged\0"
    "on_invisible_clicked\0on_left_clicked\0"
    "on_right_clicked\0on_enableshine_clicked\0"
    "on_moniter_plantshoot_sliderPressed\0"
    "on_moniter_plantshoot_sliderReleased\0"
    "on_moniter_plantflash_sliderPressed\0"
    "on_moniter_plantflash_sliderReleased\0"
    "on_moniter_plantshine_sliderPressed\0"
    "on_moniter_plantshine_sliderReleased\0"
    "on_moniter_plantblood_selectionChanged\0"
    "on_moniter_plantinterval_selectionChanged\0"
    "on_moniter_plantblood_editingFinished\0"
    "on_moniter_plantinterval_editingFinished\0"
    "on_updateplantlist_clicked\0"
    "on_clearplantlist_clicked\0"
    "on_updateplantlist_2_clicked\0"
    "on_clearplantlist_2_clicked\0"
    "on_updateplantlist_3_clicked\0"
    "on_clearplantlist_3_clicked\0"
    "on_updateplantlist_4_clicked\0"
    "on_clearplantlist_4_clicked\0"
    "on_updateplantlist_5_clicked\0"
    "on_clearplantlist_5_clicked\0"
    "on_checkBox_stateChanged\0"
    "on_starttotal_stateChanged\0"
    "on_realtimefile_stateChanged\0"
    "on_zombiedisapear_stateChanged\0"
    "on_moniter_zombiex_selectionChanged\0"
    "on_moniter_zombiex_editingFinished\0"
    "on_moniter_zombiey_selectionChanged\0"
    "on_moniter_zombiey_editingFinished\0"
    "on_moniter_zombiebodyblood_selectionChanged\0"
    "on_moniter_zombiebodyblood_editingFinished\0"
    "on_moniter_zombiearmorblood1_selectionChanged\0"
    "on_moniter_zombiearmorblood1_editingFinished\0"
    "on_moniter_zombiearmorblood2_selectionChanged\0"
    "on_moniter_zombiearmorblood2_editingFinished\0"
    "on_moniter_zombieslowtime_sliderPressed\0"
    "on_moniter_zombieslowtime_sliderReleased\0"
    "on_moniter_zombiebuttertime_sliderPressed\0"
    "on_moniter_zombiebuttertime_sliderReleased\0"
    "on_moniter_zombiefrozetime_sliderPressed\0"
    "on_moniter_zombiefrozetime_sliderReleased\0"
    "on_moniter_zombiebodyshinetime_sliderPressed\0"
    "on_moniter_zombiebodyshinetime_sliderReleased\0"
    "on_moniter_zombiearmorshinetime_sliderPressed\0"
    "on_moniter_zombiearmorshinetime_sliderReleased\0"
    "on_moniter_zombiearmorshaketime_sliderPressed\0"
    "on_moniter_zombiearmorshaketime_sliderReleased\0"
    "on_ishypnoed_clicked\0on_isvisible_clicked\0"
    "on_zombie_blowaway_clicked\0"
    "on_zombie_near_dead_clicked\0"
    "on_zombie_inwater_clicked\0"
    "on_zombie_eatgarlic_clicked\0"
    "on_zombieoutfile_clicked\0"
    "on_main_exitButton_clicked\0"
    "on_checkBox_2_stateChanged\0"
    "on_nomowernozombie_stateChanged\0"
    "on_bulletchange_clicked\0"
    "on_bulletdefault_clicked\0"
    "on_bulletvalue_currentIndexChanged\0"
    "index\0on_disposablevalue_currentIndexChanged\0"
    "on_diposablechange_clicked\0"
    "on_disposabledefault_clicked\0"
    "on_goodsvalue_currentIndexChanged\0"
    "on_goodschange_clicked\0on_goodsdefault_clicked\0"
    "on_plantlistbase_currentIndexChanged\0"
    "on_plantlistbase_2_currentIndexChanged\0"
    "on_costchange_clicked\0on_coolchange_clicked\0"
    "on_costdefault_clicked\0on_cooldefault_clicked\0"
    "on_pushButton_13_clicked\0"
    "on_unlockmemorymaxmiun_stateChanged\0"
    "on_unlockshopitems_stateChanged\0"
    "on_addeffectplant_clicked\0"
    "on_deleteselectplanteffect_clicked\0"
    "on_plantaffectongame_clicked\0"
    "on_cancelaffenctongame_clicked\0"
    "on_clearallbullet_stateChanged\0"
    "on_savesettings_clicked\0on_readsettings_clicked\0"
    "xorFileData\0filePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     189,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  959,    2, 0x08 /* Private */,
       5,    0,  962,    2, 0x08 /* Private */,
       6,    1,  963,    2, 0x08 /* Private */,
       8,    0,  966,    2, 0x08 /* Private */,
       9,    0,  967,    2, 0x08 /* Private */,
      10,    0,  968,    2, 0x08 /* Private */,
      11,    0,  969,    2, 0x08 /* Private */,
      12,    1,  970,    2, 0x08 /* Private */,
      13,    1,  973,    2, 0x08 /* Private */,
      14,    1,  976,    2, 0x08 /* Private */,
      15,    1,  979,    2, 0x08 /* Private */,
      16,    1,  982,    2, 0x08 /* Private */,
      17,    1,  985,    2, 0x08 /* Private */,
      18,    1,  988,    2, 0x08 /* Private */,
      19,    1,  991,    2, 0x08 /* Private */,
      20,    1,  994,    2, 0x08 /* Private */,
      21,    1,  997,    2, 0x08 /* Private */,
      22,    1, 1000,    2, 0x08 /* Private */,
      23,    1, 1003,    2, 0x08 /* Private */,
      24,    1, 1006,    2, 0x08 /* Private */,
      25,    1, 1009,    2, 0x08 /* Private */,
      26,    1, 1012,    2, 0x08 /* Private */,
      27,    1, 1015,    2, 0x08 /* Private */,
      28,    1, 1018,    2, 0x08 /* Private */,
      29,    1, 1021,    2, 0x08 /* Private */,
      30,    1, 1024,    2, 0x08 /* Private */,
      31,    1, 1027,    2, 0x08 /* Private */,
      32,    1, 1030,    2, 0x08 /* Private */,
      33,    1, 1033,    2, 0x08 /* Private */,
      34,    1, 1036,    2, 0x08 /* Private */,
      35,    0, 1039,    2, 0x08 /* Private */,
      36,    0, 1040,    2, 0x08 /* Private */,
      37,    0, 1041,    2, 0x08 /* Private */,
      38,    0, 1042,    2, 0x08 /* Private */,
      39,    1, 1043,    2, 0x08 /* Private */,
      40,    0, 1046,    2, 0x08 /* Private */,
      41,    0, 1047,    2, 0x08 /* Private */,
      42,    1, 1048,    2, 0x08 /* Private */,
      43,    0, 1051,    2, 0x08 /* Private */,
      44,    0, 1052,    2, 0x08 /* Private */,
      45,    0, 1053,    2, 0x08 /* Private */,
      46,    0, 1054,    2, 0x08 /* Private */,
      47,    0, 1055,    2, 0x08 /* Private */,
      48,    0, 1056,    2, 0x08 /* Private */,
      49,    0, 1057,    2, 0x08 /* Private */,
      50,    0, 1058,    2, 0x08 /* Private */,
      51,    1, 1059,    2, 0x08 /* Private */,
      52,    1, 1062,    2, 0x08 /* Private */,
      53,    0, 1065,    2, 0x08 /* Private */,
      54,    1, 1066,    2, 0x08 /* Private */,
      55,    0, 1069,    2, 0x08 /* Private */,
      56,    0, 1070,    2, 0x08 /* Private */,
      57,    0, 1071,    2, 0x08 /* Private */,
      58,    0, 1072,    2, 0x08 /* Private */,
      59,    1, 1073,    2, 0x08 /* Private */,
      60,    1, 1076,    2, 0x08 /* Private */,
      61,    1, 1079,    2, 0x08 /* Private */,
      62,    1, 1082,    2, 0x08 /* Private */,
      63,    0, 1085,    2, 0x08 /* Private */,
      64,    0, 1086,    2, 0x08 /* Private */,
      65,    0, 1087,    2, 0x08 /* Private */,
      66,    0, 1088,    2, 0x08 /* Private */,
      67,    0, 1089,    2, 0x08 /* Private */,
      68,    0, 1090,    2, 0x08 /* Private */,
      69,    0, 1091,    2, 0x08 /* Private */,
      70,    0, 1092,    2, 0x08 /* Private */,
      71,    0, 1093,    2, 0x08 /* Private */,
      72,    0, 1094,    2, 0x08 /* Private */,
      73,    1, 1095,    2, 0x08 /* Private */,
      74,    0, 1098,    2, 0x08 /* Private */,
      75,    0, 1099,    2, 0x08 /* Private */,
      76,    0, 1100,    2, 0x08 /* Private */,
      77,    1, 1101,    2, 0x08 /* Private */,
      78,    0, 1104,    2, 0x08 /* Private */,
      79,    0, 1105,    2, 0x08 /* Private */,
      80,    0, 1106,    2, 0x08 /* Private */,
      81,    0, 1107,    2, 0x08 /* Private */,
      82,    0, 1108,    2, 0x08 /* Private */,
      83,    0, 1109,    2, 0x08 /* Private */,
      84,    0, 1110,    2, 0x08 /* Private */,
      85,    1, 1111,    2, 0x08 /* Private */,
      86,    1, 1114,    2, 0x08 /* Private */,
      87,    0, 1117,    2, 0x08 /* Private */,
      88,    0, 1118,    2, 0x08 /* Private */,
      89,    0, 1119,    2, 0x08 /* Private */,
      90,    0, 1120,    2, 0x08 /* Private */,
      91,    0, 1121,    2, 0x08 /* Private */,
      92,    0, 1122,    2, 0x08 /* Private */,
      93,    0, 1123,    2, 0x08 /* Private */,
      94,    0, 1124,    2, 0x08 /* Private */,
      95,    1, 1125,    2, 0x08 /* Private */,
      96,    0, 1128,    2, 0x08 /* Private */,
      97,    0, 1129,    2, 0x08 /* Private */,
      98,    0, 1130,    2, 0x08 /* Private */,
      99,    0, 1131,    2, 0x08 /* Private */,
     100,    0, 1132,    2, 0x08 /* Private */,
     101,    0, 1133,    2, 0x08 /* Private */,
     102,    0, 1134,    2, 0x08 /* Private */,
     103,    1, 1135,    2, 0x08 /* Private */,
     104,    1, 1138,    2, 0x08 /* Private */,
     105,    0, 1141,    2, 0x08 /* Private */,
     106,    0, 1142,    2, 0x08 /* Private */,
     107,    1, 1143,    2, 0x08 /* Private */,
     108,    0, 1146,    2, 0x08 /* Private */,
     109,    0, 1147,    2, 0x08 /* Private */,
     110,    0, 1148,    2, 0x08 /* Private */,
     111,    0, 1149,    2, 0x08 /* Private */,
     112,    0, 1150,    2, 0x08 /* Private */,
     113,    0, 1151,    2, 0x08 /* Private */,
     114,    0, 1152,    2, 0x08 /* Private */,
     115,    0, 1153,    2, 0x08 /* Private */,
     116,    0, 1154,    2, 0x08 /* Private */,
     117,    0, 1155,    2, 0x08 /* Private */,
     118,    0, 1156,    2, 0x08 /* Private */,
     119,    0, 1157,    2, 0x08 /* Private */,
     120,    0, 1158,    2, 0x08 /* Private */,
     121,    0, 1159,    2, 0x08 /* Private */,
     122,    0, 1160,    2, 0x08 /* Private */,
     123,    0, 1161,    2, 0x08 /* Private */,
     124,    0, 1162,    2, 0x08 /* Private */,
     125,    0, 1163,    2, 0x08 /* Private */,
     126,    0, 1164,    2, 0x08 /* Private */,
     127,    0, 1165,    2, 0x08 /* Private */,
     128,    0, 1166,    2, 0x08 /* Private */,
     129,    0, 1167,    2, 0x08 /* Private */,
     130,    0, 1168,    2, 0x08 /* Private */,
     131,    0, 1169,    2, 0x08 /* Private */,
     132,    1, 1170,    2, 0x08 /* Private */,
     133,    1, 1173,    2, 0x08 /* Private */,
     134,    1, 1176,    2, 0x08 /* Private */,
     135,    1, 1179,    2, 0x08 /* Private */,
     136,    0, 1182,    2, 0x08 /* Private */,
     137,    0, 1183,    2, 0x08 /* Private */,
     138,    0, 1184,    2, 0x08 /* Private */,
     139,    0, 1185,    2, 0x08 /* Private */,
     140,    0, 1186,    2, 0x08 /* Private */,
     141,    0, 1187,    2, 0x08 /* Private */,
     142,    0, 1188,    2, 0x08 /* Private */,
     143,    0, 1189,    2, 0x08 /* Private */,
     144,    0, 1190,    2, 0x08 /* Private */,
     145,    0, 1191,    2, 0x08 /* Private */,
     146,    0, 1192,    2, 0x08 /* Private */,
     147,    0, 1193,    2, 0x08 /* Private */,
     148,    0, 1194,    2, 0x08 /* Private */,
     149,    0, 1195,    2, 0x08 /* Private */,
     150,    0, 1196,    2, 0x08 /* Private */,
     151,    0, 1197,    2, 0x08 /* Private */,
     152,    0, 1198,    2, 0x08 /* Private */,
     153,    0, 1199,    2, 0x08 /* Private */,
     154,    0, 1200,    2, 0x08 /* Private */,
     155,    0, 1201,    2, 0x08 /* Private */,
     156,    0, 1202,    2, 0x08 /* Private */,
     157,    0, 1203,    2, 0x08 /* Private */,
     158,    0, 1204,    2, 0x08 /* Private */,
     159,    0, 1205,    2, 0x08 /* Private */,
     160,    0, 1206,    2, 0x08 /* Private */,
     161,    0, 1207,    2, 0x08 /* Private */,
     162,    0, 1208,    2, 0x08 /* Private */,
     163,    0, 1209,    2, 0x08 /* Private */,
     164,    0, 1210,    2, 0x08 /* Private */,
     165,    0, 1211,    2, 0x08 /* Private */,
     166,    1, 1212,    2, 0x08 /* Private */,
     167,    1, 1215,    2, 0x08 /* Private */,
     168,    0, 1218,    2, 0x08 /* Private */,
     169,    0, 1219,    2, 0x08 /* Private */,
     170,    1, 1220,    2, 0x08 /* Private */,
     172,    1, 1223,    2, 0x08 /* Private */,
     173,    0, 1226,    2, 0x08 /* Private */,
     174,    0, 1227,    2, 0x08 /* Private */,
     175,    1, 1228,    2, 0x08 /* Private */,
     176,    0, 1231,    2, 0x08 /* Private */,
     177,    0, 1232,    2, 0x08 /* Private */,
     178,    1, 1233,    2, 0x08 /* Private */,
     179,    1, 1236,    2, 0x08 /* Private */,
     180,    0, 1239,    2, 0x08 /* Private */,
     181,    0, 1240,    2, 0x08 /* Private */,
     182,    0, 1241,    2, 0x08 /* Private */,
     183,    0, 1242,    2, 0x08 /* Private */,
     184,    0, 1243,    2, 0x08 /* Private */,
     185,    1, 1244,    2, 0x08 /* Private */,
     186,    1, 1247,    2, 0x08 /* Private */,
     187,    0, 1250,    2, 0x08 /* Private */,
     188,    0, 1251,    2, 0x08 /* Private */,
     189,    0, 1252,    2, 0x08 /* Private */,
     190,    0, 1253,    2, 0x08 /* Private */,
     191,    1, 1254,    2, 0x08 /* Private */,
     192,    0, 1257,    2, 0x08 /* Private */,
     193,    0, 1258,    2, 0x08 /* Private */,
     194,    1, 1259,    2, 0x08 /* Private */,

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

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 1: _t->on_lookbyprocess_clicked(); break;
        case 2: _t->on_startlog_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_startbypath_clicked(); break;
        case 4: _t->on_sunchange_clicked(); break;
        case 5: _t->on_quickset_clicked(); break;
        case 6: _t->on_resetall_clicked(); break;
        case 7: _t->on_plantInvincible_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_nocostsun_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_freeplant_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_nocool_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_nocrater_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_noawake_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_nolimitonplant_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_clearplant_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_zombieInvincible_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_pausesystemzombie_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_zombiepause_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_clearallzombies_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_passthegame_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_unlockglod_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_unlockallmode_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_lockspade_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_hidespade_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_hideslot_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_hidemenu_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_nosun_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_autocollect_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_pausegame_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_allowrunback_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_plantplace_clicked(); break;
        case 31: _t->on_plantmoniter_clicked(); break;
        case 32: _t->on_zombieplace_clicked(); break;
        case 33: _t->on_zombiemoniter_clicked(); break;
        case 34: _t->on_isdefaultplantbook_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_updateplantbook_clicked(); break;
        case 36: _t->on_sureupdateplantbook_clicked(); break;
        case 37: _t->on_startforbidplace_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->on_globalforbid_clicked(); break;
        case 39: _t->on_rowforbid_clicked(); break;
        case 40: _t->on_colforbid_clicked(); break;
        case 41: _t->on_singleforbid_clicked(); break;
        case 42: _t->on_surerowcol_clicked(); break;
        case 43: _t->on_currentreset_clicked(); break;
        case 44: _t->on_globalreset_clicked(); break;
        case 45: _t->on_sureforbid_clicked(); break;
        case 46: _t->on_randslot_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 47: _t->on_startforbid_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 48: _t->on_createselections_clicked(); break;
        case 49: _t->on_forbidaffectrandslot_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 50: _t->on_randplantreset_clicked(); break;
        case 51: _t->on_startrandplaceplant_clicked(); break;
        case 52: _t->on_radioButton_clicked(); break;
        case 53: _t->on_singleplantplace_clicked(); break;
        case 54: _t->on_enableblood_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 55: _t->on_enableinterval_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 56: _t->on_rowtogether_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->on_coltogether_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        case 68: _t->on_isdefaultplantbook_zombie_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 69: _t->on_updateplantbook_zombie_clicked(); break;
        case 70: _t->on_sureupdatezombiebook_clicked(); break;
        case 71: _t->on_suretosetblindbox_clicked(); break;
        case 72: _t->on_startforbidplace_zombie_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 73: _t->on_globalreset_2_clicked(); break;
        case 74: _t->on_sureforbid_2_clicked(); break;
        case 75: _t->on_startmower_clicked(); break;
        case 76: _t->on_clearmower_clicked(); break;
        case 77: _t->on_resummower_clicked(); break;
        case 78: _t->on_directputonce_clicked(); break;
        case 79: _t->on_pushButton_clicked(); break;
        case 80: _t->on_pausewithgame_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 81: _t->on_autospicy_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 82: _t->on_pauseputting_clicked(); break;
        case 83: _t->on_stopputting_clicked(); break;
        case 84: _t->on_addnode_clicked(); break;
        case 85: _t->on_deletelist_clicked(); break;
        case 86: _t->on_startputting_clicked(); break;
        case 87: _t->on_saveile_autozombie_clicked(); break;
        case 88: _t->on_readfile_autozombie_clicked(); break;
        case 89: _t->on_pushButton_2_clicked(); break;
        case 90: _t->on_randblindboxmode_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 91: _t->on_addfreezombie_clicked(); break;
        case 92: _t->on_rowcolput_clicked(); break;
        case 93: _t->on_coordinateput_clicked(); break;
        case 94: _t->on_putfreezombie_clicked(); break;
        case 95: _t->on_freezombiedelete_clicked(); break;
        case 96: _t->on_freezombiereset_clicked(); break;
        case 97: _t->on_freezombieput_clicked(); break;
        case 98: _t->on_startplantmoniter_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 99: _t->on_disappear_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 100: _t->on_squish_clicked(); break;
        case 101: _t->on_asleep_clicked(); break;
        case 102: _t->on_enableshine_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        case 127: _t->on_checkBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 128: _t->on_starttotal_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 129: _t->on_realtimefile_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 130: _t->on_zombiedisapear_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        case 161: _t->on_checkBox_2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 162: _t->on_nomowernozombie_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 163: _t->on_bulletchange_clicked(); break;
        case 164: _t->on_bulletdefault_clicked(); break;
        case 165: _t->on_bulletvalue_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 166: _t->on_disposablevalue_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 167: _t->on_diposablechange_clicked(); break;
        case 168: _t->on_disposabledefault_clicked(); break;
        case 169: _t->on_goodsvalue_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 170: _t->on_goodschange_clicked(); break;
        case 171: _t->on_goodsdefault_clicked(); break;
        case 172: _t->on_plantlistbase_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 173: _t->on_plantlistbase_2_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 174: _t->on_costchange_clicked(); break;
        case 175: _t->on_coolchange_clicked(); break;
        case 176: _t->on_costdefault_clicked(); break;
        case 177: _t->on_cooldefault_clicked(); break;
        case 178: _t->on_pushButton_13_clicked(); break;
        case 179: _t->on_unlockmemorymaxmiun_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 180: _t->on_unlockshopitems_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 181: _t->on_addeffectplant_clicked(); break;
        case 182: _t->on_deleteselectplanteffect_clicked(); break;
        case 183: _t->on_plantaffectongame_clicked(); break;
        case 184: _t->on_cancelaffenctongame_clicked(); break;
        case 185: _t->on_clearallbullet_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 186: _t->on_savesettings_clicked(); break;
        case 187: _t->on_readsettings_clicked(); break;
        case 188: _t->xorFileData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 189;
    }
    return _id;
}
struct qt_meta_stringdata_slotsetplant_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_slotsetplant_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_slotsetplant_t qt_meta_stringdata_slotsetplant = {
    {
QT_MOC_LITERAL(0, 0, 12) // "slotsetplant"

    },
    "slotsetplant"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_slotsetplant[] = {

 // content:
       8,       // revision
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

void slotsetplant::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject slotsetplant::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_slotsetplant.data,
    qt_meta_data_slotsetplant,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *slotsetplant::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *slotsetplant::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_slotsetplant.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int slotsetplant::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_slotplantmoniter_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_slotplantmoniter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_slotplantmoniter_t qt_meta_stringdata_slotplantmoniter = {
    {
QT_MOC_LITERAL(0, 0, 16), // "slotplantmoniter"
QT_MOC_LITERAL(1, 17, 9), // "threadend"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "slotplantmoniter\0threadend\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_slotplantmoniter[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void slotplantmoniter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<slotplantmoniter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->threadend(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (slotplantmoniter::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&slotplantmoniter::threadend)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject slotplantmoniter::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_slotplantmoniter.data,
    qt_meta_data_slotplantmoniter,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *slotplantmoniter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *slotplantmoniter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_slotplantmoniter.stringdata0))
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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
QT_END_MOC_NAMESPACE
