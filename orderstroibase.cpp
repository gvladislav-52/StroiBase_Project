#include "orderstroibase.h"

OrderStroiBase::OrderStroiBase(){}

void OrderStroiBase::setOrderIndex(int num)
{
    order_index = num;
}

void OrderStroiBase::setOrderMaxIndex(int element)
{
    order_maxIndex = element;
}

void OrderStroiBase::setInvoiceIndex(int num)
{
    invoice_index = num;
}

void OrderStroiBase::order_clearVector()
{
    m_Order_vector.clear();
    m_Order_vector.assign(6,"");
    emit Order_vectorChanged();
}

void OrderStroiBase::invoice_clearVector()
{
    m_Invoice_vector.clear();
    m_Invoice_vector.assign(7,"");
    emit Invoice_vectorChanged();
}

int OrderStroiBase::getOrderIndex(int num)
{
    return order_index+=num;
}

int OrderStroiBase::getOrderMaxIndex()
{
    return order_maxIndex;
}

int OrderStroiBase::getInvoiceIndex(int num)
{
    return invoice_index+=num;
}

QVector<QString> OrderStroiBase::getInvoice_vector() const
{
    return m_Invoice_vector;
}

void OrderStroiBase::setInvoice_vector(const QVector<QString> &newInvoice_vector)
{
    if (m_Invoice_vector == newInvoice_vector)
        return;
    m_Invoice_vector = newInvoice_vector;
    emit Invoice_vectorChanged();
}

QVector<QString> OrderStroiBase::getOrder_vector() const
{
    return m_Order_vector;
}

void OrderStroiBase::setOrder_vector(const QVector<QString> &newOrder_vector)
{
    if (m_Order_vector == newOrder_vector)
        return;
    m_Order_vector = newOrder_vector;
    emit Order_vectorChanged();
}
