#ifndef DATABASE_SQL_H
#define DATABASE_SQL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QtSql>

class Database_sql : public QObject
{
    Q_OBJECT
public:
    explicit Database_sql(QObject *parent = nullptr);
public slots:
    int getLastIndexOrder();
    void invoice_truncate(QString index);
    QVector<QString> getIdInvoice(int index);
    void invoices_addNewData(QString supplierId, QString materialId, QString kol, QString sale, QString orderId);
    void invoices_createNewData(QString supplierId, QString materialId, QString kol, QString sale, QString orderId);
    void orders_addNewData(QVector<QString> vector);
    void orders_createNewData(QVector<QString> vec);
    int getIndexOrder(int vecData, bool curs);
    //int getMaxIndexInvoice();
    //QString getLengthOrder(QString index, bool boltemp);
    QString getDriverName(QString id);
    QString getClientName(QString company);
    QVector<QString> getAllDriversName();
    QVector<QString> getAllClientsName();
    QVector<QString> getMaterialsVectorName(int index);
    QVector<QString> getSupplierVectorName(int index);
    QVector<QString> getInvoiceDataVector(QString name, QString sort, int order);
    QVector<QString> getDataVector(int index, QString name, QString sort);
    QVector<QString> getAllSupplierName();
    QVector<QString> getAllModelMaterials(QString temp,bool botemp = false);
    int getItemMaterials(QString temp,int index);
    QString getSupplierId(QString company);
    int getIdDriverName(QString company);
    int getIdClientName(QString company);
    QString getIdMaterialsName(QString mark);

    QString getMaterialsId(QString company);
    QString getTextSupplier(QString vecData);
    QString getTextMaterials(QString vecData);

    int getIndexClients(QVector<QString> vecName, QString vecData);
    int getIndexSupplier(QVector<QString> temp1, QString temp2);
    int getIndexDrivers(QVector<QString> vecName, QString vecData);

    int getMaxElement(QString name);
    void delete_Data(int index, QString nameData, QString id_name);

    void supplier_createNewData(QVector<QString> vector);
    void supplier_addNewData(QVector<QString> vector);

    void materials_createNewData(QVector<QString> vec);
    void materials_addNewData(QVector<QString> vector);

    void clients_createNewData(QVector<QString> vec);
    void clients_addNewData(QVector<QString> vector);

    void drivers_createNewData(QVector<QString> vec);
    void drivers_addNewData(QVector<QString> vector);
private:
    QSqlDatabase db;
signals:
};

#endif // DATABASE_SQL_H
