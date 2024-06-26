#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QApplication>
#include "database_sql.h"
#include <QThread>
#include "orderstroibase.h"
#include "suppliers.h"
#include "materials.h"
#include "clients.h"
#include "drivers.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    OrderStroiBase ts_company;
    Suppliers supplier;
    Materials materials;
    Clients client;
    Drivers driver;

    Database_sql db;
    qDebug() << "Main thread: " << QThread::currentThreadId();
    supplier.setSupplier_vector(db.getDataVector(0,"Supplier","Id_supplier"));
    supplier.setSupplierMaxIndex(db.getMaxElement("Supplier"));
    supplier.setSupplierIndex(0);

    materials.setMaterials_vector(db.getDataVector(0,"Materials","id_material"));
    materials.setMaterialsMaxIndex(db.getMaxElement("Materials"));
    materials.setMaterialsIndex(0);

    client.setClients_vector(db.getDataVector(0,"Clients","client_id"));
    client.setClientsMaxIndex(db.getMaxElement("Clients"));
    client.setClientsIndex(0);

    driver.setDrivers_vector(db.getDataVector(0,"Drivers","id"));
    driver.setDriversMaxIndex(db.getMaxElement("Drivers"));
    driver.setDriversIndex(0);

    ts_company.setOrder_vector(db.getDataVector(0,"Orders","id_order"));
    ts_company.setOrderMaxIndex(db.getMaxElement("Orders"));
    ts_company.setOrderIndex(0);

    client.setReport_Clients_Vector(db.getReportDataVector());
    qDebug() << client.getReport_Clients_Vector();

    ts_company.setInvoice_vector(db.getInvoiceDataVector("Invoice","id_order",4));
    qDebug() << ts_company.getInvoice_vector();
    //ts_company.setInvoiceMaxIndex(db.getMaxElement("Invoice"));
    //ts_company.setInvoiceIndex(0);

    //qDebug() << db.getMaxElement("Invoice");
    //qDebug() << db.getIndexOrder(4,true);
    //qDebug() << db.getIndexOrder(6,false);
    ts_company.setInvoiceIndex(db.getIndexOrder(0,true));
    //ts_company.setInvoiceMaxIndex(db.getMaxIndexInvoice());
    //ts_company.setInvoiceIndexTable(0);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QQmlContext *rootContext = engine.rootContext();
    rootContext->setContextProperty("Transport_company", &ts_company);
    rootContext->setContextProperty("Supplier_com", &supplier);
    rootContext->setContextProperty("Materials_com", &materials);
    rootContext->setContextProperty("Client_com", &client);
    rootContext->setContextProperty("Driver_com", &driver);
    rootContext->setContextProperty("Database", &db);


    engine.load(url);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

    return app.exec();
}
