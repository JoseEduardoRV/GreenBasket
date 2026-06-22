#include "bill.h"

Bill::Bill(QObject *parent)
    : QObject{parent}
    , m_drinkTotal{}
    , m_foodTotal{}
    , m_total{}
{
    qDebug() << "*** Building a new Bill ***" << this << Qt::endl;
}

Bill::~Bill()
{
    qDebug() << "*** Destroying Bill ***" << this << Qt::endl;
}

void Bill::addItem(const SoldProduct &item, std::size_t quantity)
{
    m_billItem.append(BillItem(item, quantity));
}

void Bill::calculateTotal()
{
    m_total      = 0.0f;
    m_drinkTotal = 0.0f;
    m_foodTotal  = 0.0f;

    foreach(const BillItem &item, m_billItem)
        m_total  += item.price() * item.quantity();
}
