#include "clients.h"

Clients::Clients() {}

void Clients::setClientsIndex(int num)
{
    clients_index = num;
}

void Clients::setClientsMaxIndex(int element)
{
    clients_maxIndex = element;
}

void Clients::clients_clearVector()
{
    m_Clients_vector.clear();
    m_Clients_vector.assign(5,"");
    emit Clients_vectorChanged();
}

int Clients::getClientsIndex(int num)
{
    return clients_index+=num;
}

int Clients::getClientsMaxIndex()
{
    return clients_maxIndex;
}

QVector<QString> Clients::getClients_vector() const
{
    return m_Clients_vector;
}

void Clients::setClients_vector(const QVector<QString> &newClients_vector)
{
    if (m_Clients_vector == newClients_vector)
        return;
    m_Clients_vector = newClients_vector;
    emit Clients_vectorChanged();
}

QVector<QString> Clients::getReport_Clients_Vector() const
{
    return m_Report_Clients_Vector;
}

void Clients::setReport_Clients_Vector(const QVector<QString> &newReport_Clients_Vector)
{
    if (m_Report_Clients_Vector == newReport_Clients_Vector)
        return;
    m_Report_Clients_Vector = newReport_Clients_Vector;
    emit Report_Clients_VectorChanged();
}
