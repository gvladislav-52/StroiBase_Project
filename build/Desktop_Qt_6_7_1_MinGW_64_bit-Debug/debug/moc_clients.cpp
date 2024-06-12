/****************************************************************************
** Meta object code from reading C++ file 'clients.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../clients.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clients.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.1. It"
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
struct qt_meta_stringdata_CLASSClientsENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSClientsENDCLASS = QtMocHelpers::stringData(
    "Clients",
    "Clients_vectorChanged",
    "",
    "Report_Clients_VectorChanged",
    "getReport_Clients_Vector",
    "getClientsIndex",
    "num",
    "getClientsMaxIndex",
    "setClientsIndex",
    "setClientsMaxIndex",
    "element",
    "clients_clearVector",
    "setClients_vector",
    "newClients_vector",
    "setReport_Clients_Vector",
    "newReport_Clients_Vector",
    "Clients_vector",
    "Report_Clients_Vector"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSClientsENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       2,   94, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    3 /* Public */,
       3,    0,   75,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   76,    2, 0x10a,    5 /* Public | MethodIsConst  */,
       5,    1,   77,    2, 0x0a,    6 /* Public */,
       7,    0,   80,    2, 0x0a,    8 /* Public */,
       8,    1,   81,    2, 0x0a,    9 /* Public */,
       9,    1,   84,    2, 0x0a,   11 /* Public */,
      11,    0,   87,    2, 0x0a,   13 /* Public */,
      12,    1,   88,    2, 0x0a,   14 /* Public */,
      14,    1,   91,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::QStringList,
    QMetaType::Int, QMetaType::Int,    6,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   13,
    QMetaType::Void, QMetaType::QStringList,   15,

 // properties: name, type, flags
      16, QMetaType::QStringList, 0x00015903, uint(0), 0,
      17, QMetaType::QStringList, 0x00015903, uint(1), 0,

       0        // eod
};

Q_CONSTINIT const QMetaObject Clients::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSClientsENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSClientsENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSClientsENDCLASS_t,
        // property 'Clients_vector'
        QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>,
        // property 'Report_Clients_Vector'
        QtPrivate::TypeAndForceComplete<QList<QString>, std::true_type>,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Clients, std::true_type>,
        // method 'Clients_vectorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'Report_Clients_VectorChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'getReport_Clients_Vector'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'getClientsIndex'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getClientsMaxIndex'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setClientsIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'setClientsMaxIndex'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'clients_clearVector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setClients_vector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QString> &, std::false_type>,
        // method 'setReport_Clients_Vector'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QVector<QString> &, std::false_type>
    >,
    nullptr
} };

void Clients::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Clients *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Clients_vectorChanged(); break;
        case 1: _t->Report_Clients_VectorChanged(); break;
        case 2: { QList<QString> _r = _t->getReport_Clients_Vector();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->getClientsIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: { int _r = _t->getClientsMaxIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setClientsIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->setClientsMaxIndex((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->clients_clearVector(); break;
        case 8: _t->setClients_vector((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 9: _t->setReport_Clients_Vector((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Clients::*)();
            if (_t _q_method = &Clients::Clients_vectorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Clients::*)();
            if (_t _q_method = &Clients::Report_Clients_VectorChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Clients *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QList<QString>*>(_v) = _t->getClients_vector(); break;
        case 1: *reinterpret_cast< QList<QString>*>(_v) = _t->getReport_Clients_Vector(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Clients *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setClients_vector(*reinterpret_cast< QList<QString>*>(_v)); break;
        case 1: _t->setReport_Clients_Vector(*reinterpret_cast< QList<QString>*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    } else if (_c == QMetaObject::BindableProperty) {
    }
}

const QMetaObject *Clients::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Clients::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSClientsENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Clients::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
    }else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Clients::Clients_vectorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Clients::Report_Clients_VectorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
