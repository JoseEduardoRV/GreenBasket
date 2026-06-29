#include "bill.h"

void Bill::setStatus(BillStatus newStatus)
{
    m_status = newStatus;
}

Bill::Bill(QObject *parent)
    : QObject{parent}
    , m_status{BillStatus::None}
    , m_customerIdentity{}
    , m_accountLabel{}
    , m_total{}
    , m_ticketNumber{}
    , m_createdAt{}
    , m_billItems{}
{
    qDebug() << "*** Building a new Bill ***" << this << Qt::endl;
}

Bill::~Bill()
{
    qDebug() << "*** Destroying Bill ***" << this << Qt::endl;
}

void Bill::addItem(const SoldProduct &product, const int category)
{
    BillItem *billItem{nullptr};

    for (BillItem &item : m_billItems) {
        if (item.id() == product.id()) {
            billItem = &item;
            break;
        }
    }

    if (billItem) {
        billItem->addOne();
    } else {
        m_billItems.push_back(BillItem(product, category));
    }
}

void Bill::addItem(const SoldProduct &product, const int category, std::size_t quantity)
{
    BillItem *billItem{nullptr};

    for (BillItem &item : m_billItems) {
        if (item.id() == product.id()) {
            billItem = &item;
            break;
        }
    }

    if (billItem) {
        billItem->setQuantity(billItem->quantity() + quantity);
    } else {
        m_billItems.push_back(BillItem(product, category, quantity));
    }
}

void Bill::setTicketNumber(int index)
{
    m_ticketNumber = { QString("Ticket B20-1203-%1").arg(index) };
    emit ticketNumberChanged();
}

void Bill::setCreatedAt()
{
    m_createdAt.setDate(QDate::currentDate());
    emit createdAtChanged();
}
