/****************************************************************************
** Meta object code from reading C++ file 'database_sql.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../database_sql.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'database_sql.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSDatabase_sqlENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSDatabase_sqlENDCLASS = QtMocHelpers::stringData(
    "Database_sql",
    "getReportDataVector",
    "",
    "getLastIndexOrder",
    "invoice_truncate",
    "index",
    "getIdInvoice",
    "invoices_addNewData",
    "supplierId",
    "materialId",
    "kol",
    "sale",
    "orderId",
    "invoices_createNewData",
    "orders_addNewData",
    "vector",
    "orders_createNewData",
    "vec",
    "getIndexOrder",
    "vecData",
    "curs",
    "getDriverName",
    "id",
    "getClientName",
    "company",
    "getAllDriversName",
    "getAllClientsName",
    "getMaterialsVectorName",
    "getSupplierVectorName",
    "getInvoiceDataVector",
    "name",
    "sort",
    "order",
    "getDataVector",
    "getAllSupplierName",
    "getAllModelMaterials",
    "temp",
    "botemp",
    "getItemMaterials",
    "getSupplierId",
    "getIdDriverName",
    "getIdClientName",
    "getIdMaterialsName",
    "mark",
    "getMaterialsId",
    "getTextSupplier",
    "getTextMaterials",
    "getIndexClients",
    "vecName",
    "getIndexSupplier",
    "temp1",
    "temp2",
    "getIndexDrivers",
    "getMaxElement",
    "delete_Data",
    "nameData",
    "id_name",
    "supplier_createNewData",
    "supplier_addNewData",
    "materials_createNewData",
    "materials_addNewData",
    "clients_createNewData",
    "clients_addNewData",
    "drivers_createNewData",
    "drivers_addNewData"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSDatabase_sqlENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  260,    2, 0x0a,    1 /* Public */,
       3,    0,  261,    2, 0x0a,    2 /* Public */,
       4,    1,  262,    2, 0x0a,    3 /* Public */,
       6,    1,  265,    2, 0x0a,    5 /* Public */,
       7,    5,  268,    2, 0x0a,    7 /* Public */,
      13,    5,  279,    2, 0x0a,   13 /* Public */,
      14,    1,  290,    2, 0x0a,   19 /* Public */,
      16,    1,  293,    2, 0x0a,   21 /* Public */,
      18,    2,  296,    2, 0x0a,   23 /* Public */,
      21,    1,  301,    2, 0x0a,   26 /* Public */,
      23,    1,  304,    2, 0x0a,   28 /* Public */,
      25,    0,  307,    2, 0x0a,   30 /* Public */,
      26,    0,  308,    2, 0x0a,   31 /* Public */,
      27,    1,  309,    2, 0x0a,   32 /* Public */,
      28,    1,  312,    2, 0x0a,   34 /* Public */,
      29,    3,  315,    2, 0x0a,   36 /* Public */,
      33,    3,  322,    2, 0x0a,   40 /* Public */,
      34,    0,  329,    2, 0x0a,   44 /* Public */,
      35,    2,  330,    2, 0x0a,   45 /* Public */,
      35,    1,  335,    2, 0x2a,   48 /* Public | MethodCloned */,
      38,    2,  338,    2, 0x0a,   50 /* Public */,
      39,    1,  343,    2, 0x0a,   53 /* Public */,
      40,    1,  346,    2, 0x0a,   55 /* Public */,
      41,    1,  349,    2, 0x0a,   57 /* Public */,
      42,    1,  352,    2, 0x0a,   59 /* Public */,
      44,    1,  355,    2, 0x0a,   61 /* Public */,
      45,    1,  358,    2, 0x0a,   63 /* Public */,
      46,    1,  361,    2, 0x0a,   65 /* Public */,
      47,    2,  364,    2, 0x0a,   67 /* Public */,
      49,    2,  369,    2, 0x0a,   70 /* Public */,
      52,    2,  374,    2, 0x0a,   73 /* Public */,
      53,    1,  379,    2, 0x0a,   76 /* Public */,
      54,    3,  382,    2, 0x0a,   78 /* Public */,
      57,    1,  389,    2, 0x0a,   82 /* Public */,
      58,    1,  392,    2, 0x0a,   84 /* Public */,
      59,    1,  395,    2, 0x0a,   86 /* Public */,
      60,    1,  398,    2, 0x0a,   88 /* Public */,
      61,    1,  401,    2, 0x0a,   90 /* Public */,
      62,    1,  404,    2, 0x0a,   92 /* Public */,
      63,    1,  407,    2, 0x0a,   94 /* Public */,
      64,    1,  410,    2, 0x0a,   96 /* Public */,

 // slots: parameters
    QMetaType::QStringList,
    QMetaType::Int,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::QStringList, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList,   17,
    QMetaType::Int, QMetaType::Int, QMetaType::Bool,   19,   20,
    QMetaType::QString, QMetaType::QString,   22,
    QMetaType::QString, QMetaType::QString,   24,
    QMetaType::QStringList,
    QMetaType::QStringList,
    QMetaType::QStringList, QMetaType::Int,    5,
    QMetaType::QStringList, QMetaType::Int,    5,
    QMetaType::QStringList, QMetaType::QString, QMetaType::QString, QMetaType::Int,   30,   31,   32,
    QMetaType::QStringList, QMetaType::Int, QMetaType::QString, QMetaType::QString,    5,   30,   31,
    QMetaType::QStringList,
    QMetaType::QStringList, QMetaType::QString, QMetaType::Bool,   36,   37,
    QMetaType::QStringList, QMetaType::QString,   36,
    QMetaType::Int, QMetaType::QString, QMetaType::Int,   36,    5,
    QMetaType::QString, QMetaType::QString,   24,
    QMetaType::Int, QMetaType::QString,   24,
    QMetaType::Int, QMetaType::QString,   24,
    QMetaType::QString, QMetaType::QString,   43,
    QMetaType::QString, QMetaType::QString,   24,
    QMetaType::QString, QMetaType::QString,   19,
    QMetaType::QString, QMetaType::QString,   19,
    QMetaType::Int, QMetaType::QStringList, QMetaType::QString,   48,   19,
    QMetaType::Int, QMetaType::QStringList, QMetaType::QString,   50,   51,
    QMetaType::Int, QMetaType::QStringList, QMetaType::QString,   48,   19,
    QMetaType::Int, QMetaType::QString,   30,
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::QString,    5,   55,   56,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList,   17,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList,   17,
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QStringList,   17,
    QMetaType::Void, QMetaType::QStringList,   15,

       0        // eod
};

Q_CONSTINIT const QMetaObject Database_sql::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSDatabase_sqlENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSDatabase_sqlENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSDatabase_sqlENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Database_sql, std::true_type>,
        // method 'getReportDataVector'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'getLastIndexOrder'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'invoice_truncate'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getIdInvoice'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'invoices_addNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'invoices_createNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'orders_addNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'orders_createNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'getIndexOrder'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getDriverName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getClientName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getAllDriversName'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'getAllClientsName'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'getMaterialsVectorName'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getSupplierVectorName'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getInvoiceDataVector'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getDataVector'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getAllSupplierName'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'getAllModelMaterials'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'getAllModelMaterials'
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getItemMaterials'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'getSupplierId'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getIdDriverName'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getIdClientName'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getIdMaterialsName'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getMaterialsId'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getTextSupplier'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getTextMaterials'
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getIndexClients'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getIndexSupplier'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getIndexDrivers'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'getMaxElement'
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'delete_Data'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'supplier_createNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'supplier_addNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'materials_createNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'materials_addNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'clients_createNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'clients_addNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'drivers_createNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>,
        // method 'drivers_addNewData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVector<QString>, std::false_type>
    >,
    nullptr
} };

void Database_sql::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Database_sql *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QList<QString> _r = _t->getReportDataVector();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 1: { int _r = _t->getLastIndexOrder();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->invoice_truncate((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: { QList<QString> _r = _t->getIdInvoice((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->invoices_addNewData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 5: _t->invoices_createNewData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[5]))); break;
        case 6: _t->orders_addNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 7: _t->orders_createNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 8: { int _r = _t->getIndexOrder((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { QString _r = _t->getDriverName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->getClientName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: { QList<QString> _r = _t->getAllDriversName();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 12: { QList<QString> _r = _t->getAllClientsName();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 13: { QList<QString> _r = _t->getMaterialsVectorName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 14: { QList<QString> _r = _t->getSupplierVectorName((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 15: { QList<QString> _r = _t->getInvoiceDataVector((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 16: { QList<QString> _r = _t->getDataVector((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 17: { QList<QString> _r = _t->getAllSupplierName();
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 18: { QList<QString> _r = _t->getAllModelMaterials((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 19: { QList<QString> _r = _t->getAllModelMaterials((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QString>*>(_a[0]) = std::move(_r); }  break;
        case 20: { int _r = _t->getItemMaterials((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 21: { QString _r = _t->getSupplierId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 22: { int _r = _t->getIdDriverName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 23: { int _r = _t->getIdClientName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 24: { QString _r = _t->getIdMaterialsName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 25: { QString _r = _t->getMaterialsId((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 26: { QString _r = _t->getTextSupplier((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 27: { QString _r = _t->getTextMaterials((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 28: { int _r = _t->getIndexClients((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 29: { int _r = _t->getIndexSupplier((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 30: { int _r = _t->getIndexDrivers((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 31: { int _r = _t->getMaxElement((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 32: _t->delete_Data((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 33: _t->supplier_createNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 34: _t->supplier_addNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 35: _t->materials_createNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 36: _t->materials_addNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 37: _t->clients_createNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 38: _t->clients_addNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 39: _t->drivers_createNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        case 40: _t->drivers_addNewData((*reinterpret_cast< std::add_pointer_t<QList<QString>>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Database_sql::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Database_sql::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSDatabase_sqlENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Database_sql::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
