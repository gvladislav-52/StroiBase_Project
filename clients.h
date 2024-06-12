#ifndef CLIENTS_H
#define CLIENTS_H

#include <QObject>

class Clients: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<QString> Clients_vector READ getClients_vector WRITE setClients_vector NOTIFY Clients_vectorChanged FINAL)
    Q_PROPERTY(QVector<QString> Report_Clients_Vector READ getReport_Clients_Vector WRITE setReport_Clients_Vector NOTIFY Report_Clients_VectorChanged FINAL)
public:
    Clients();
    QVector<QString> getClients_vector() const;


signals:
    void Clients_vectorChanged();
    void Report_Clients_VectorChanged();

public slots:
        QVector<QString> getReport_Clients_Vector() const;
    int getClientsIndex(int num);
    int getClientsMaxIndex();
    void setClientsIndex(int num);
    void setClientsMaxIndex(int element);
    void clients_clearVector();
    void setClients_vector(const QVector<QString> &newClients_vector);

    void setReport_Clients_Vector(const QVector<QString> &newReport_Clients_Vector);

private:
    QVector<QString> m_Clients_vector;
    int clients_index = 0;
    int clients_maxIndex;
    QVector<QString> m_Report_Clients_Vector;
};

#endif // CLIENTS_H
