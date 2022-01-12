/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../include/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[34];
    char stringdata0[306];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 15), // "onLoadMeshClick"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 10), // "updateView"
QT_MOC_LITERAL(39, 15), // "updateSelection"
QT_MOC_LITERAL(55, 15), // "onReselectClick"
QT_MOC_LITERAL(71, 16), // "onMouseModeClick"
QT_MOC_LITERAL(88, 22), // "onSelectionMethodClick"
QT_MOC_LITERAL(111, 22), // "onTranspVolSliderMoved"
QT_MOC_LITERAL(134, 22), // "onTranspFacSliderMoved"
QT_MOC_LITERAL(157, 22), // "onTranspEdgSliderMoved"
QT_MOC_LITERAL(180, 22), // "onTranspNodSliderMoved"
QT_MOC_LITERAL(203, 22), // "onSelectionSliderMoved"
QT_MOC_LITERAL(226, 22), // "onSelectionSpinChanged"
QT_MOC_LITERAL(249, 20), // "onShowSelectionClick"
QT_MOC_LITERAL(270, 20), // "onHideSelectionClick"
QT_MOC_LITERAL(291, 14) // "onShowAllClick"

    },
    "MainWindow\0onLoadMeshClick\0\0updateView\0"
    "updateSelection\0onReselectClick\0"
    "onMouseModeClick\0onSelectionMethodClick\0"
    "onTranspVolSliderMoved\0onTranspFacSliderMoved\0"
    "onTranspEdgSliderMoved\0onTranspNodSliderMoved\0"
    "onSelectionSliderMoved\0onSelectionSpinChanged\0"
    "onShowSelectionClick\0onHideSelectionClick\0"
    "onShowAllClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x0a,    1 /* Public */,
       3,    0,  105,    2, 0x0a,    2 /* Public */,
       4,    0,  106,    2, 0x0a,    3 /* Public */,
       5,    0,  107,    2, 0x0a,    4 /* Public */,
       6,    0,  108,    2, 0x0a,    5 /* Public */,
       7,    0,  109,    2, 0x0a,    6 /* Public */,
       8,    0,  110,    2, 0x0a,    7 /* Public */,
       9,    0,  111,    2, 0x0a,    8 /* Public */,
      10,    0,  112,    2, 0x0a,    9 /* Public */,
      11,    0,  113,    2, 0x0a,   10 /* Public */,
      12,    0,  114,    2, 0x0a,   11 /* Public */,
      13,    0,  115,    2, 0x0a,   12 /* Public */,
      14,    0,  116,    2, 0x0a,   13 /* Public */,
      15,    0,  117,    2, 0x0a,   14 /* Public */,
      16,    0,  118,    2, 0x0a,   15 /* Public */,

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

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onLoadMeshClick(); break;
        case 1: _t->updateView(); break;
        case 2: _t->updateSelection(); break;
        case 3: _t->onReselectClick(); break;
        case 4: _t->onMouseModeClick(); break;
        case 5: _t->onSelectionMethodClick(); break;
        case 6: _t->onTranspVolSliderMoved(); break;
        case 7: _t->onTranspFacSliderMoved(); break;
        case 8: _t->onTranspEdgSliderMoved(); break;
        case 9: _t->onTranspNodSliderMoved(); break;
        case 10: _t->onSelectionSliderMoved(); break;
        case 11: _t->onSelectionSpinChanged(); break;
        case 12: _t->onShowSelectionClick(); break;
        case 13: _t->onHideSelectionClick(); break;
        case 14: _t->onShowAllClick(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
