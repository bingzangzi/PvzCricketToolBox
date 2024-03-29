/****************************************************************************
** Meta object code from reading C++ file 'randzombieplace.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AutoPlacingforPVZ/randzombieplace.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'randzombieplace.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSSpiceThreadENDCLASS = QtMocHelpers::stringData(
    "SpiceThread"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t qt_meta_stringdata_CLASSSpiceThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11)   // "SpiceThread"
    },
    "SpiceThread"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSSpiceThreadENDCLASS[] = {

 // content:
      12,       // revision
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

Q_CONSTINIT const QMetaObject SpiceThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSSpiceThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSSpiceThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSSpiceThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<SpiceThread, std::true_type>
    >,
    nullptr
} };

void SpiceThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
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
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSZombieThreadENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSZombieThreadENDCLASS = QtMocHelpers::stringData(
    "ZombieThread",
    "updateValues",
    "",
    "zombies",
    "rate",
    "threadFinished"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSZombieThreadENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[13];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[5];
    char stringdata5[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSZombieThreadENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSZombieThreadENDCLASS_t qt_meta_stringdata_CLASSZombieThreadENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "ZombieThread"
        QT_MOC_LITERAL(13, 12),  // "updateValues"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 7),  // "zombies"
        QT_MOC_LITERAL(35, 4),  // "rate"
        QT_MOC_LITERAL(40, 14)   // "threadFinished"
    },
    "ZombieThread",
    "updateValues",
    "",
    "zombies",
    "rate",
    "threadFinished"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZombieThreadENDCLASS[] = {

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
       5,    0,   31,    2, 0x06,    4 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    3,    4,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject ZombieThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSZombieThreadENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZombieThreadENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZombieThreadENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZombieThread, std::true_type>,
        // method 'updateValues'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<double, std::false_type>,
        // method 'threadFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ZombieThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombieThread *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateValues((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 1: _t->threadFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombieThread::*)(int , double );
            if (_t _q_method = &ZombieThread::updateValues; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ZombieThread::*)();
            if (_t _q_method = &ZombieThread::threadFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *ZombieThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombieThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZombieThreadENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ZombieThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ZombieThread::updateValues(int _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ZombieThread::threadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS = QtMocHelpers::stringData(
    "ZombieSafeCheck",
    "threadFinished",
    ""
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS_t {
    uint offsetsAndSizes[6];
    char stringdata0[16];
    char stringdata1[15];
    char stringdata2[1];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS_t qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "ZombieSafeCheck"
        QT_MOC_LITERAL(16, 14),  // "threadFinished"
        QT_MOC_LITERAL(31, 0)   // ""
    },
    "ZombieSafeCheck",
    "threadFinished",
    ""
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSZombieSafeCheckENDCLASS[] = {

 // content:
      12,       // revision
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

Q_CONSTINIT const QMetaObject ZombieSafeCheck::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSZombieSafeCheckENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ZombieSafeCheck, std::true_type>,
        // method 'threadFinished'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void ZombieSafeCheck::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ZombieSafeCheck *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->threadFinished(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ZombieSafeCheck::*)();
            if (_t _q_method = &ZombieSafeCheck::threadFinished; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *ZombieSafeCheck::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ZombieSafeCheck::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSZombieSafeCheckENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ZombieSafeCheck::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void ZombieSafeCheck::threadFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSrandzombieplaceENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSrandzombieplaceENDCLASS = QtMocHelpers::stringData(
    "randzombieplace",
    "PauseThread",
    "",
    "StopThread",
    "StartThread",
    "stopThread",
    "autospicythread",
    "setgamepause_zom",
    "safecheckstop",
    "on_returnmain_clicked",
    "on_resetall_clicked",
    "on_skipandput_clicked",
    "on_initratesure_clicked",
    "on_addsure_clicked",
    "on_deletedata_clicked",
    "on_addfinish_clicked",
    "on_beginput_clicked",
    "on_startmower_clicked",
    "on_clearmower_clicked",
    "on_resumemower_clicked",
    "on_killallzombies_clicked",
    "on_editdatalist_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSrandzombieplaceENDCLASS_t {
    uint offsetsAndSizes[44];
    char stringdata0[16];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[11];
    char stringdata4[12];
    char stringdata5[11];
    char stringdata6[16];
    char stringdata7[17];
    char stringdata8[14];
    char stringdata9[22];
    char stringdata10[20];
    char stringdata11[22];
    char stringdata12[24];
    char stringdata13[19];
    char stringdata14[22];
    char stringdata15[21];
    char stringdata16[20];
    char stringdata17[22];
    char stringdata18[22];
    char stringdata19[23];
    char stringdata20[26];
    char stringdata21[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSrandzombieplaceENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSrandzombieplaceENDCLASS_t qt_meta_stringdata_CLASSrandzombieplaceENDCLASS = {
    {
        QT_MOC_LITERAL(0, 15),  // "randzombieplace"
        QT_MOC_LITERAL(16, 11),  // "PauseThread"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 10),  // "StopThread"
        QT_MOC_LITERAL(40, 11),  // "StartThread"
        QT_MOC_LITERAL(52, 10),  // "stopThread"
        QT_MOC_LITERAL(63, 15),  // "autospicythread"
        QT_MOC_LITERAL(79, 16),  // "setgamepause_zom"
        QT_MOC_LITERAL(96, 13),  // "safecheckstop"
        QT_MOC_LITERAL(110, 21),  // "on_returnmain_clicked"
        QT_MOC_LITERAL(132, 19),  // "on_resetall_clicked"
        QT_MOC_LITERAL(152, 21),  // "on_skipandput_clicked"
        QT_MOC_LITERAL(174, 23),  // "on_initratesure_clicked"
        QT_MOC_LITERAL(198, 18),  // "on_addsure_clicked"
        QT_MOC_LITERAL(217, 21),  // "on_deletedata_clicked"
        QT_MOC_LITERAL(239, 20),  // "on_addfinish_clicked"
        QT_MOC_LITERAL(260, 19),  // "on_beginput_clicked"
        QT_MOC_LITERAL(280, 21),  // "on_startmower_clicked"
        QT_MOC_LITERAL(302, 21),  // "on_clearmower_clicked"
        QT_MOC_LITERAL(324, 22),  // "on_resumemower_clicked"
        QT_MOC_LITERAL(347, 25),  // "on_killallzombies_clicked"
        QT_MOC_LITERAL(373, 23)   // "on_editdatalist_clicked"
    },
    "randzombieplace",
    "PauseThread",
    "",
    "StopThread",
    "StartThread",
    "stopThread",
    "autospicythread",
    "setgamepause_zom",
    "safecheckstop",
    "on_returnmain_clicked",
    "on_resetall_clicked",
    "on_skipandput_clicked",
    "on_initratesure_clicked",
    "on_addsure_clicked",
    "on_deletedata_clicked",
    "on_addfinish_clicked",
    "on_beginput_clicked",
    "on_startmower_clicked",
    "on_clearmower_clicked",
    "on_resumemower_clicked",
    "on_killallzombies_clicked",
    "on_editdatalist_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSrandzombieplaceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  134,    2, 0x0a,    1 /* Public */,
       3,    0,  135,    2, 0x0a,    2 /* Public */,
       4,    0,  136,    2, 0x0a,    3 /* Public */,
       5,    0,  137,    2, 0x0a,    4 /* Public */,
       6,    0,  138,    2, 0x0a,    5 /* Public */,
       7,    0,  139,    2, 0x0a,    6 /* Public */,
       8,    0,  140,    2, 0x0a,    7 /* Public */,
       9,    0,  141,    2, 0x08,    8 /* Private */,
      10,    0,  142,    2, 0x08,    9 /* Private */,
      11,    0,  143,    2, 0x08,   10 /* Private */,
      12,    0,  144,    2, 0x08,   11 /* Private */,
      13,    0,  145,    2, 0x08,   12 /* Private */,
      14,    0,  146,    2, 0x08,   13 /* Private */,
      15,    0,  147,    2, 0x08,   14 /* Private */,
      16,    0,  148,    2, 0x08,   15 /* Private */,
      17,    0,  149,    2, 0x08,   16 /* Private */,
      18,    0,  150,    2, 0x08,   17 /* Private */,
      19,    0,  151,    2, 0x08,   18 /* Private */,
      20,    0,  152,    2, 0x08,   19 /* Private */,
      21,    0,  153,    2, 0x08,   20 /* Private */,

 // slots: parameters
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

       0        // eod
};

Q_CONSTINIT const QMetaObject randzombieplace::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSrandzombieplaceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSrandzombieplaceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSrandzombieplaceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<randzombieplace, std::true_type>,
        // method 'PauseThread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'StopThread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'StartThread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'stopThread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'autospicythread'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setgamepause_zom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'safecheckstop'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_returnmain_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resetall_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_skipandput_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_initratesure_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addsure_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_deletedata_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_addfinish_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_beginput_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_startmower_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_clearmower_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_resumemower_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_killallzombies_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_editdatalist_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void randzombieplace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<randzombieplace *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->PauseThread(); break;
        case 1: _t->StopThread(); break;
        case 2: _t->StartThread(); break;
        case 3: _t->stopThread(); break;
        case 4: _t->autospicythread(); break;
        case 5: _t->setgamepause_zom(); break;
        case 6: _t->safecheckstop(); break;
        case 7: _t->on_returnmain_clicked(); break;
        case 8: _t->on_resetall_clicked(); break;
        case 9: _t->on_skipandput_clicked(); break;
        case 10: _t->on_initratesure_clicked(); break;
        case 11: _t->on_addsure_clicked(); break;
        case 12: _t->on_deletedata_clicked(); break;
        case 13: _t->on_addfinish_clicked(); break;
        case 14: _t->on_beginput_clicked(); break;
        case 15: _t->on_startmower_clicked(); break;
        case 16: _t->on_clearmower_clicked(); break;
        case 17: _t->on_resumemower_clicked(); break;
        case 18: _t->on_killallzombies_clicked(); break;
        case 19: _t->on_editdatalist_clicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *randzombieplace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *randzombieplace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSrandzombieplaceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int randzombieplace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
