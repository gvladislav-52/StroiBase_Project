#include "database_sql.h"

#include "thread"
#include <QSet>

Database_sql::Database_sql(QObject *parent)
    : QObject{parent}
{
    std::thread th([&](){
        qDebug() << "Constructor thread: " << QThread::currentThreadId();
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setDatabaseName("ts_company");
        db.setUserName("postgres");
        db.setPassword("12345");
        db.setHostName("127.0.0.1");
        if (!db.open()) {
            qDebug() << "Erro open database!";
        }
    });
    th.join();
}

//////////////////////////////////////////////////////////////////////////ORDERS////////////////////////////////////////////////////////////////////////////
//console.log(Database.getSupplierId(marksComboBox[i]),Database.getIdCarName(modelsComboBox[i]),kolText[i],saleText[i], Transport_company.Order_vector[0])

void Database_sql::invoice_truncate(QString index)
{
    QEventLoop loop;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("DELETE FROM invoice WHERE id_order = "+index+"");

        loop.quit();
    });
    loop.exec();
    th.join();
}

void Database_sql::invoices_createNewData(QString supplierId, QString carId, QString kol, QString sale, QString orderId)
{
    //qDebug() << vec;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        //selectQuery.exec("INSERT INTO Orders (client_id, id, delivery_address, placement_date, assignment_date, execution_date, sumcost_new) VALUES ("+vec[1]+", '"+ vec[2] +"', '"+ vec[6] +"', "+ vec[3] +", "+ vec[4] +", '"+ vec[5] +"', '"+ vec[7] +"'");
        selectQuery.exec("INSERT INTO Invoice (id_supplier, id_material, kolvo, sale, id_order) VALUES ('"+supplierId+"', '"+carId+"', '"+kol+"', '"+sale+"', '"+orderId+"')");
    });
    qDebug() << "invoice";
    th.join();
}

void Database_sql::invoices_addNewData(QString supplierId, QString materialId, QString kol, QString sale, QString invoiceId)
{
    //std::thread th([&](){
    QSqlQuery selectQuery(db);
    selectQuery.exec("UPDATE Invoice SET id_supplier = '"+supplierId+"', id_material = '"+materialId+"', kolvo = '"+kol+"', sale = '"+sale+"' WHERE id_invoice = '"+invoiceId+"'");
    //selectQuery.exec("UPDATE Orders SET client_id = '" + vector.at(1) +"', id = '" + vector.at(2)+"', delivery_address = '" + vector.at(6) +"',placement_date = '" + vector.at(3) +"', assignment_date = '" + vector.at(4) +"', execution_date = '" + vector.at(5) +"', sumcost_new = '" + vector.at(7) +"' WHERE id_order = '" + vector.at(0) +"'");
    //);

    //th.join();
}

QVector<QString> Database_sql::getIdInvoice(int index)
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Invoice  WHERE id_order = '"+QString::number(index)+"' ");

        while (selectQuery.next()) {
            temp_vector.append(selectQuery.value(0).toString());
        }
    });
    th.join();
    return temp_vector;
}

int Database_sql::getLastIndexOrder()
{
    int index;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT id_order FROM Orders ORDER BY id_order DESC LIMIT 1");

        while (selectQuery.next()) {
            index = selectQuery.value(0).toInt();
        }
    });
    th.join();
    return index;
}
QVector<QString> Database_sql::getInvoiceDataVector(QString name, QString sort, int order)
{
    QVector<QString> temp_vector;

    std::thread th([&](){
        QSqlQuery selectQuery(db);

        selectQuery.exec("SELECT * FROM "+ name +" WHERE id_order = '"+QString::number(order)+"' ORDER BY "+sort+" ASC");

        while(selectQuery.next())
        {
            QSqlRecord record = selectQuery.record();
            for (int i = 0; i < record.count(); ++i)
                temp_vector.append(selectQuery.value(i).toString());
        }
    });
    th.join();
    return temp_vector;
}

QString Database_sql::getTextSupplier(QString vecData)
{
    QString str;
    // qDebug() << vecData;
    // qDebug() << vecName;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Supplier WHERE id_supplier = '"+vecData+"' ORDER BY id_supplier ASC");

        while (selectQuery.next())
            str = selectQuery.value(1).toString();

    });
    th.join();
    return str;
}

QString Database_sql::getTextMaterials(QString vecData)
{
    QString str;
    // qDebug() << vecData;
    // qDebug() << vecName;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Materials WHERE id_material = '"+vecData+"' ORDER BY id_material ASC");

        while (selectQuery.next())
            str = selectQuery.value(3).toString();

    });
    th.join();
    return str;
}

QVector<QString> Database_sql::getSupplierVectorName(int index)
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT Company FROM Invoice INNER JOIN Supplier ON Invoice.id_supplier = Supplier.id_supplier WHERE Invoice.id_order = '"+QString::number(index)+"'ORDER BY id_invoice asc");

        while (selectQuery.next()) {
            // Получаем первое значение (индекс 0) из текущей строки
            temp_vector.append(selectQuery.value(0).toString());
        }
    });
    th.join();
    return temp_vector;
}

QVector<QString> Database_sql::getMaterialsVectorName(int index)
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT material FROM Materials INNER JOIN Invoice ON Materials.id_material = Invoice.id_material WHERE Invoice.id_order = '"+QString::number(index)+"'ORDER BY id_invoice asc");

        while (selectQuery.next()) {
            // Получаем первое значение (индекс 0) из текущей строки
            temp_vector.append(selectQuery.value(0).toString());
        }
    });
    th.join();
    return temp_vector;
}

int Database_sql::getIndexOrder(int vecData, bool curs)
{
    int str;
        //qDebug() << vecData;
    // qDebug() << vecName;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        if(curs)
            selectQuery.exec("SELECT MIN(id_order) FROM Orders WHERE id_order > "+QString::number(vecData)+"");
        else
            selectQuery.exec("SELECT MAX(id_order) FROM Orders WHERE id_order < "+QString::number(vecData)+"");
        while (selectQuery.next())
            str = selectQuery.value(0).toInt();

    });
    th.join();
    return str;
}

// int Database_sql::getMaxIndexInvoice()
// {
//     int str;
//     std::thread th([&](){
//         QSqlQuery selectQuery(db);
//             selectQuery.exec("SELECT COUNT(DISTINCT id_order) AS unique_orders FROM Invoice WHERE id_order > -1;");
//         while (selectQuery.next())
//             str = selectQuery.value(0).toInt();
//     });
//     th.join();
//     return str;
// }

int Database_sql::getIndexClients(QVector<QString> vecName, QString vecData)
{
    int index;
    QString str;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Clients WHERE client_id = '"+vecData+"' ORDER BY client_id ASC");

        while (selectQuery.next())
            str = selectQuery.value(1).toString();

        for(int i = 0; i <vecName.size(); i++)
            if(vecName[i] == str)
            {
                index = i;
                break;
            }
    });
    th.join();
    return index;
}

int Database_sql::getIndexDrivers(QVector<QString> vecName, QString vecData)
{
    int index;
    QString str;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Drivers WHERE id = '"+vecData+"' ORDER BY id ASC");

        while (selectQuery.next())
            str = selectQuery.value(1).toString();

        for(int i = 0; i <vecName.size(); i++)
            if(vecName[i] == str)
            {
                index = i;
                break;
            }
    });
    th.join();
    return index;
}

QVector<QString> Database_sql::getAllClientsName()
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT full_name FROM Clients");

        while (selectQuery.next()) {
            temp_vector.append(selectQuery.value(0).toString());
        }
    });
    th.join();
    return temp_vector;
}

QVector<QString> Database_sql::getAllDriversName()
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT lastName FROM Drivers");

        while (selectQuery.next()) {
            temp_vector.append(selectQuery.value(0).toString());
        }
    });
    th.join();
    return temp_vector;
}

int Database_sql::getIdClientName(QString company)
{
    int temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Clients WHERE full_name = '"+company+"' ORDER BY client_id ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(0).toInt();

    });
    th.join();
    return temp_vector;
}

QString Database_sql::getIdMaterialsName(QString mark)
{
    QString temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Materials WHERE material = '"+mark+"' ORDER BY id_material ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(0).toString();

    });
    th.join();
    return temp_vector;
}

QString Database_sql::getClientName(QString id)
{
    QString temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Clients WHERE client_id = '"+id+"' ORDER BY client_id ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(1).toString();

    });
    th.join();
    return temp_vector;
}

QString Database_sql::getDriverName(QString id)
{
    QString temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Drivers WHERE id = '"+id+"' ORDER BY id ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(1).toString();

    });
    th.join();
    return temp_vector;
}

int Database_sql::getIdDriverName(QString company)
{
    int temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Drivers WHERE LastName = '"+company+"' ORDER BY id ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(0).toInt();

    });
    th.join();
    return temp_vector;
}

//////////////////////////////////////////////////////////////////////////ORDERS////////////////////////////////////////////////////////////////////////////

void Database_sql::orders_createNewData(QVector<QString> vec)
{
    //std::thread th([&](){
    QSqlQuery selectQuery(db);
    selectQuery.exec("INSERT INTO Orders (client_id, id, placement_date, delivery_address, sumcost_new) VALUES ('"+vec[1]+"', '"+vec[2]+"', '"+vec[3]+"', '"+vec[4]+"', '"+vec[5]+"')");
    //});
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    qDebug() << "order";
    //th.join();
}

void Database_sql::orders_addNewData(QVector<QString> vector)
{
    qDebug() << vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Orders SET client_id = '"+vector[1]+"', id = '"+vector[2]+"', placement_date = '"+vector[3]+"', delivery_address = '"+vector[4]+"',  sumcost_new = '"+vector[5]+"'  WHERE id_order = '"+vector[0]+"';");
        //selectQuery.exec("UPDATE Orders SET client_id = '" + vector.at(1) +"', id = '" + vector.at(2)+"', delivery_address = '" + vector.at(6) +"',placement_date = '" + vector.at(3) +"', assignment_date = '" + vector.at(4) +"', execution_date = '" + vector.at(5) +"', sumcost_new = '" + vector.at(7) +"' WHERE id_order = '" + vector.at(0) +"'");
    });
    th.join();
}

QVector<QString> Database_sql::getAllModelMaterials(QString temp, bool botemp)
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        if(botemp)
            selectQuery.exec("SELECT * FROM Materials WHERE id_Supplier = '"+getSupplierId(temp)+"'ORDER BY id_material ASC");
        else
            selectQuery.exec("SELECT * FROM Materials ORDER BY id_material ASC");

        while (selectQuery.next()) {
            // Получаем первое значение (индекс 0) из текущей строки
            temp_vector.append(selectQuery.value(3).toString());
        }
    });
    th.join();
    return temp_vector;
}

int Database_sql::getItemMaterials(QString temp, int index)
{
    qDebug() << temp << index;
    int temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Materials WHERE material = '"+temp+"' ORDER BY id_material ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(index).toInt();
    });
    th.join();
    return temp_vector;
}

QString Database_sql::getMaterialsId(QString company)
{
    QString temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Materials WHERE material = '"+company+"' ORDER BY id_material ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(0).toString();

    });
    th.join();
    return temp_vector;
}

/////////////////////////////////////////////////////////////////////////DRIVERS////////////////////////////////////////////////////////////////////////////

void Database_sql::drivers_createNewData(QVector<QString> vec)
{
    //qDebug() << vec;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Drivers (LastName, FirstName, DadName, DriverLicense, Phone, Email, CarNumber,Image) VALUES ('"+vec[1]+"', '"+ vec[2] +"', '"+ vec[3] +"', '"+ vec[4] +"','"+vec[5]+"', '"+ vec[6] +"', '"+ vec[7] +"', '"+ vec[8] +"');");
    });
    th.join();
}

void Database_sql::drivers_addNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Drivers SET LastName = '" + vector.at(1) +"', FirstName = '" + vector.at(2)+"', DadName = '" + vector.at(3) +"',DriverLicense = '" + vector.at(4) +"',Phone = '" + vector.at(5) +"',Email = '" + vector.at(6) +"',CarNumber = '" + vector.at(7) +"',Image = '" + vector.at(8) +"' WHERE id = '" + vector.at(0) +"'");
    });
    th.join();
}

//////////////////////////////////////////////////////////////////////////CLIENTS////////////////////////////////////////////////////////////////////////////

void Database_sql::clients_createNewData(QVector<QString> vec)
{
    //qDebug() << vec;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Clients (full_name, phone, email, address) VALUES ('"+vec[1]+"', '"+ vec[2] +"', '"+ vec[3] +"', '"+ vec[4] +"');");
    });
    th.join();
}

void Database_sql::clients_addNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Clients SET full_name = '" + vector.at(1) +"', phone = '" + vector.at(2)+"', email = '" + vector.at(3) +"',address = '" + vector.at(4) +"' WHERE client_id = '" + vector.at(0) +"'");
    });
    th.join();
}

QVector<QString> Database_sql::getReportDataVector()
{
    QVector<QString> temp_vector;

    QSqlQuery selectQuery(db);
    selectQuery.exec("SELECT * FROM Clients ORDER BY client_id ASC");

    while (selectQuery.next()) {
        QSqlRecord record = selectQuery.record();
        for (int i = 0; i < record.count(); ++i) {
            temp_vector.append(selectQuery.value(i).toString());
        }
    }

    qDebug() << temp_vector;
    return temp_vector;
}

///////////////////////////////////////////////////////////////////////////Materials/////////////////////////////////////////////////////////////////////////////

void Database_sql::materials_createNewData(QVector<QString> vec)
{
    //qDebug() << vec;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Materials (Id_Supplier, Name, Material, Country, Term, Number, Cost, Image) VALUES ("+vec[1]+", '"+ vec[2] +"', '"+ vec[3] +"', "+ vec[4] +", "+ vec[5] +", '"+ vec[6] +"', '"+ vec[7] +"', '"+ vec[8] +"');");
    });
    th.join();
}

void Database_sql::materials_addNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Materials SET Id_supplier = '" + vector.at(1) +"', Name = '" + vector.at(2)+"', Material = '" + vector.at(3) +"',Country = '" + vector.at(4) +"', Term = '" + vector.at(5) +"', Number = '" + vector.at(6) +"', Cost = '" + vector.at(7) +"', Image = '"+vector.at(8)+"' WHERE id_material = '" + vector.at(0) +"'");
    });
    th.join();
}

QVector<QString> Database_sql::getAllSupplierName()
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        //qDebug() << "getDataVector thread: " << QThread::currentThreadId();
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Supplier ORDER BY id_supplier ASC");

        while (selectQuery.next()) {
            // Получаем первое значение (индекс 0) из текущей строки
            temp_vector.append(selectQuery.value(1).toString());
        }
    });
    th.join();
    return temp_vector;
}

QString Database_sql::getSupplierId(QString company)
{
    QString temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Supplier WHERE Company = '"+company+"' ORDER BY id_supplier ASC");

        while (selectQuery.next())
            temp_vector = selectQuery.value(0).toString();

    });
    th.join();
    return temp_vector;
}

int Database_sql::getIndexSupplier(QVector<QString> vecName, QString vecData)
{
    int index;
    QString str;

    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM Supplier WHERE id_supplier = '"+vecData+"' ORDER BY id_supplier ASC");

        while (selectQuery.next())
            str = selectQuery.value(1).toString();

        for(int i = 0; i <vecName.size(); i++)
            if(vecName[i] == str)
            {
                index = i;
                break;
            }
    });
    th.join();
    return index;
}

/////////////////////////////////////////////////////////////////////////SUPPLIER///////////////////////////////////////////////////////////////////////////

void Database_sql::supplier_createNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("INSERT INTO Supplier (Company, Address, Representative, Phone, Email,Image) VALUES ('"+vector[1]+"', '"+vector[2]+"', '"+vector[3]+"', '"+vector[4]+"', '"+vector[5]+"','"+vector[6]+"')");
    });
    th.join();
}

void Database_sql::supplier_addNewData(QVector<QString> vector)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("UPDATE Supplier SET Company = '" + vector.at(1) +"', Address = '" + vector.at(2)+"', Representative = '" + vector.at(3) +"',Phone = '" + vector.at(4) +"', Email = '" + vector.at(5) +"', Image = '" + vector.at(6) +"' WHERE Id_Supplier = '" + vector.at(0) +"'");
    });
    th.join();
}

//////////////////////////////////////////////////////////////////////////SOCIAL////////////////////////////////////////////////////////////////////////////

QVector<QString> Database_sql::getDataVector(int index, QString name, QString sort)
{
    QVector<QString> temp_vector;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM "+ name +" ORDER BY "+sort+" ASC");

        if(selectQuery.seek(index))
        {
            QSqlRecord record = selectQuery.record();
            for (int i = 0; i < record.count(); ++i)
                temp_vector.append(selectQuery.value(i).toString());
        }
        qDebug() << temp_vector;
    });
    th.join();
    return temp_vector;
}

int Database_sql::getMaxElement(QString name)
{
    int max_element = 0;
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("SELECT * FROM "+name+"");

        while(selectQuery.next())
            ++max_element;
    });
    th.join();
    return max_element;
}

void Database_sql::delete_Data(int index,QString nameData, QString id_name)
{
    std::thread th([&](){
        QSqlQuery selectQuery(db);
        selectQuery.exec("DELETE FROM "+nameData+" WHERE "+ id_name +" = "+QString::number(index)+"");
    });
    th.join();
}
