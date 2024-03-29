/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AutoPlacingforPVZ/mainwindow.h"
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_main_commitButton_clicked",
    "",
    "on_main_exitButton_clicked",
    "on_main_plantplace_clicked",
    "on_pushButton_2_clicked",
    "open_versioninfo",
    "open_randplantplace",
    "open_customplantplace",
    "open_randzombieplace",
    "open_customzombieplace",
    "open_browshelpinfo",
    "on_pushButton_clicked",
    "on_pushButton_3_clicked",
    "on_sunchange_clicked",
    "on_nocostsun_stateChanged",
    "arg1",
    "on_allowrunback_stateChanged",
    "on_pausegame_stateChanged",
    "on_freeplant_stateChanged",
    "on_lockspade_stateChanged",
    "on_hideslot_stateChanged",
    "on_plantInvincible_stateChanged",
    "on_unlockallmode_stateChanged",
    "on_unlockglod_stateChanged",
    "on_passthegame_stateChanged",
    "on_hidespade_stateChanged",
    "on_hidemenu_stateChanged",
    "on_nosun_stateChanged",
    "on_autocollect_stateChanged",
    "on_zombieInvincible_stateChanged",
    "on_noawake_stateChanged",
    "on_pausesystemzombie_stateChanged",
    "on_zombiepause_stateChanged",
    "on_nocrater_stateChanged",
    "on_nocool_stateChanged",
    "on_clearallzombies_stateChanged",
    "on_clearplant_stateChanged",
    "on_nolimitonplant_stateChanged",
    "on_resetall_clicked",
    "on_quickset_clicked",
    "on_selectall_clicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[84];
    char stringdata0[11];
    char stringdata1[29];
    char stringdata2[1];
    char stringdata3[27];
    char stringdata4[27];
    char stringdata5[24];
    char stringdata6[17];
    char stringdata7[20];
    char stringdata8[22];
    char stringdata9[21];
    char stringdata10[23];
    char stringdata11[19];
    char stringdata12[22];
    char stringdata13[24];
    char stringdata14[21];
    char stringdata15[26];
    char stringdata16[5];
    char stringdata17[29];
    char stringdata18[26];
    char stringdata19[26];
    char stringdata20[26];
    char stringdata21[25];
    char stringdata22[32];
    char stringdata23[30];
    char stringdata24[27];
    char stringdata25[28];
    char stringdata26[26];
    char stringdata27[25];
    char stringdata28[22];
    char stringdata29[28];
    char stringdata30[33];
    char stringdata31[24];
    char stringdata32[34];
    char stringdata33[28];
    char stringdata34[25];
    char stringdata35[23];
    char stringdata36[32];
    char stringdata37[27];
    char stringdata38[31];
    char stringdata39[20];
    char stringdata40[20];
    char stringdata41[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 28),  // "on_main_commitButton_clicked"
        QT_MOC_LITERAL(40, 0),  // ""
        QT_MOC_LITERAL(41, 26),  // "on_main_exitButton_clicked"
        QT_MOC_LITERAL(68, 26),  // "on_main_plantplace_clicked"
        QT_MOC_LITERAL(95, 23),  // "on_pushButton_2_clicked"
        QT_MOC_LITERAL(119, 16),  // "open_versioninfo"
        QT_MOC_LITERAL(136, 19),  // "open_randplantplace"
        QT_MOC_LITERAL(156, 21),  // "open_customplantplace"
        QT_MOC_LITERAL(178, 20),  // "open_randzombieplace"
        QT_MOC_LITERAL(199, 22),  // "open_customzombieplace"
        QT_MOC_LITERAL(222, 18),  // "open_browshelpinfo"
        QT_MOC_LITERAL(241, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(263, 23),  // "on_pushButton_3_clicked"
        QT_MOC_LITERAL(287, 20),  // "on_sunchange_clicked"
        QT_MOC_LITERAL(308, 25),  // "on_nocostsun_stateChanged"
        QT_MOC_LITERAL(334, 4),  // "arg1"
        QT_MOC_LITERAL(339, 28),  // "on_allowrunback_stateChanged"
        QT_MOC_LITERAL(368, 25),  // "on_pausegame_stateChanged"
        QT_MOC_LITERAL(394, 25),  // "on_freeplant_stateChanged"
        QT_MOC_LITERAL(420, 25),  // "on_lockspade_stateChanged"
        QT_MOC_LITERAL(446, 24),  // "on_hideslot_stateChanged"
        QT_MOC_LITERAL(471, 31),  // "on_plantInvincible_stateChanged"
        QT_MOC_LITERAL(503, 29),  // "on_unlockallmode_stateChanged"
        QT_MOC_LITERAL(533, 26),  // "on_unlockglod_stateChanged"
        QT_MOC_LITERAL(560, 27),  // "on_passthegame_stateChanged"
        QT_MOC_LITERAL(588, 25),  // "on_hidespade_stateChanged"
        QT_MOC_LITERAL(614, 24),  // "on_hidemenu_stateChanged"
        QT_MOC_LITERAL(639, 21),  // "on_nosun_stateChanged"
        QT_MOC_LITERAL(661, 27),  // "on_autocollect_stateChanged"
        QT_MOC_LITERAL(689, 32),  // "on_zombieInvincible_stateChanged"
        QT_MOC_LITERAL(722, 23),  // "on_noawake_stateChanged"
        QT_MOC_LITERAL(746, 33),  // "on_pausesystemzombie_stateCha..."
        QT_MOC_LITERAL(780, 27),  // "on_zombiepause_stateChanged"
        QT_MOC_LITERAL(808, 24),  // "on_nocrater_stateChanged"
        QT_MOC_LITERAL(833, 22),  // "on_nocool_stateChanged"
        QT_MOC_LITERAL(856, 31),  // "on_clearallzombies_stateChanged"
        QT_MOC_LITERAL(888, 26),  // "on_clearplant_stateChanged"
        QT_MOC_LITERAL(915, 30),  // "on_nolimitonplant_stateChanged"
        QT_MOC_LITERAL(946, 19),  // "on_resetall_clicked"
        QT_MOC_LITERAL(966, 19),  // "on_quickset_clicked"
        QT_MOC_LITERAL(986, 20)   // "on_selectall_clicked"
    },
    "MainWindow",
    "on_main_commitButton_clicked",
    "",
    "on_main_exitButton_clicked",
    "on_main_plantplace_clicked",
    "on_pushButton_2_clicked",
    "open_versioninfo",
    "open_randplantplace",
    "open_customplantplace",
    "open_randzombieplace",
    "open_customzombieplace",
    "open_browshelpinfo",
    "on_pushButton_clicked",
    "on_pushButton_3_clicked",
    "on_sunchange_clicked",
    "on_nocostsun_stateChanged",
    "arg1",
    "on_allowrunback_stateChanged",
    "on_pausegame_stateChanged",
    "on_freeplant_stateChanged",
    "on_lockspade_stateChanged",
    "on_hideslot_stateChanged",
    "on_plantInvincible_stateChanged",
    "on_unlockallmode_stateChanged",
    "on_unlockglod_stateChanged",
    "on_passthegame_stateChanged",
    "on_hidespade_stateChanged",
    "on_hidemenu_stateChanged",
    "on_nosun_stateChanged",
    "on_autocollect_stateChanged",
    "on_zombieInvincible_stateChanged",
    "on_noawake_stateChanged",
    "on_pausesystemzombie_stateChanged",
    "on_zombiepause_stateChanged",
    "on_nocrater_stateChanged",
    "on_nocool_stateChanged",
    "on_clearallzombies_stateChanged",
    "on_clearplant_stateChanged",
    "on_nolimitonplant_stateChanged",
    "on_resetall_clicked",
    "on_quickset_clicked",
    "on_selectall_clicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  248,    2, 0x08,    1 /* Private */,
       3,    0,  249,    2, 0x08,    2 /* Private */,
       4,    0,  250,    2, 0x08,    3 /* Private */,
       5,    0,  251,    2, 0x08,    4 /* Private */,
       6,    0,  252,    2, 0x08,    5 /* Private */,
       7,    0,  253,    2, 0x08,    6 /* Private */,
       8,    0,  254,    2, 0x08,    7 /* Private */,
       9,    0,  255,    2, 0x08,    8 /* Private */,
      10,    0,  256,    2, 0x08,    9 /* Private */,
      11,    0,  257,    2, 0x08,   10 /* Private */,
      12,    0,  258,    2, 0x08,   11 /* Private */,
      13,    0,  259,    2, 0x08,   12 /* Private */,
      14,    0,  260,    2, 0x08,   13 /* Private */,
      15,    1,  261,    2, 0x08,   14 /* Private */,
      17,    1,  264,    2, 0x08,   16 /* Private */,
      18,    1,  267,    2, 0x08,   18 /* Private */,
      19,    1,  270,    2, 0x08,   20 /* Private */,
      20,    1,  273,    2, 0x08,   22 /* Private */,
      21,    1,  276,    2, 0x08,   24 /* Private */,
      22,    1,  279,    2, 0x08,   26 /* Private */,
      23,    1,  282,    2, 0x08,   28 /* Private */,
      24,    1,  285,    2, 0x08,   30 /* Private */,
      25,    1,  288,    2, 0x08,   32 /* Private */,
      26,    1,  291,    2, 0x08,   34 /* Private */,
      27,    1,  294,    2, 0x08,   36 /* Private */,
      28,    1,  297,    2, 0x08,   38 /* Private */,
      29,    1,  300,    2, 0x08,   40 /* Private */,
      30,    1,  303,    2, 0x08,   42 /* Private */,
      31,    1,  306,    2, 0x08,   44 /* Private */,
      32,    1,  309,    2, 0x08,   46 /* Private */,
      33,    1,  312,    2, 0x08,   48 /* Private */,
      34,    1,  315,    2, 0x08,   50 /* Private */,
      35,    1,  318,    2, 0x08,   52 /* Private */,
      36,    1,  321,    2, 0x08,   54 /* Private */,
      37,    1,  324,    2, 0x08,   56 /* Private */,
      38,    1,  327,    2, 0x08,   58 /* Private */,
      39,    0,  330,    2, 0x08,   60 /* Private */,
      40,    0,  331,    2, 0x08,   61 /* Private */,
      41,    0,  332,    2, 0x08,   62 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
        // method 'on_main_commitButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_main_exitButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_main_plantplace_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'open_versioninfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'open_randplantplace'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'open_customplantplace'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'open_randzombieplace'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'open_customzombieplace'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'open_browshelpinfo'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_sunchange_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_nocostsun_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_allowrunback_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pausegame_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_freeplant_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_lockspade_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_hideslot_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_plantInvincible_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_unlockallmode_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_unlockglod_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_passthegame_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_hidespade_stateChanged'
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
        // method 'on_zombieInvincible_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_noawake_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_pausesystemzombie_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_zombiepause_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nocrater_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nocool_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_clearallzombies_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_clearplant_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_nolimitonplant_stateChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_resetall_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_quickset_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_selectall_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_main_commitButton_clicked(); break;
        case 1: _t->on_main_exitButton_clicked(); break;
        case 2: _t->on_main_plantplace_clicked(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->open_versioninfo(); break;
        case 5: _t->open_randplantplace(); break;
        case 6: _t->open_customplantplace(); break;
        case 7: _t->open_randzombieplace(); break;
        case 8: _t->open_customzombieplace(); break;
        case 9: _t->open_browshelpinfo(); break;
        case 10: _t->on_pushButton_clicked(); break;
        case 11: _t->on_pushButton_3_clicked(); break;
        case 12: _t->on_sunchange_clicked(); break;
        case 13: _t->on_nocostsun_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_allowrunback_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->on_pausegame_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->on_freeplant_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->on_lockspade_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->on_hideslot_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->on_plantInvincible_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->on_unlockallmode_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->on_unlockglod_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->on_passthegame_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->on_hidespade_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->on_hidemenu_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->on_nosun_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->on_autocollect_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->on_zombieInvincible_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->on_noawake_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->on_pausesystemzombie_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->on_zombiepause_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->on_nocrater_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 32: _t->on_nocool_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->on_clearallzombies_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 34: _t->on_clearplant_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 35: _t->on_nolimitonplant_stateChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 36: _t->on_resetall_clicked(); break;
        case 37: _t->on_quickset_clicked(); break;
        case 38: _t->on_selectall_clicked(); break;
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
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 39;
    }
    return _id;
}
QT_WARNING_POP
