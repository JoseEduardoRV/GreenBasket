#include "bill.h"

BillItem *Bill::findItemByProduct(const ProductList *product)
{
    BillItem *ptr{nullptr};

    if (product) {
        for (BillItem &item : m_billItems) {
            if (item.productid() == product->id()) {
                ptr = &item;
                break;
            }
        }
    }

    return ptr;
}

void Bill::recalculateTotals()
{
    double newSubTotal { 0 };

    foreach (const BillItem &item, m_billItems) {
        newSubTotal += item.subtotal();
    }

    if (m_subTotal != newSubTotal) {
        m_subTotal = newSubTotal;
        emit subTotalChanged(m_subTotal);
    }

    const double newTotal = m_subTotal;

    if (m_total != newTotal) {
        m_total = newTotal; /*hay que agregar los cargos extrar*/;
        emit totalChanged(m_total);
    }
}

Bill::Bill(QObject *parent)
    : QObject{parent}
    , m_status{BillStatus::None}
    , m_total{}
    , m_ticketNumber{}
    , m_createdAt{}
    , m_billItems{}
{
    m_createdAt = QDateTime::currentDateTime();
    m_ticketNumber = "Ticket";
    qDebug() << "*** Building a new Bill ***" << this << Qt::endl;
}

Bill::~Bill()
{
    qDebug() << "*** Destroying Bill ***" << this << Qt::endl;
}

void Bill::addItem(const ProductList &product)
{
    addItem(product, 1);
}

void Bill::addItem(const ProductList &product, std::size_t quantity)
{
    BillItem *billItem = findItemByProduct(&product);

    if (billItem) {
        billItem->changeQuantity(quantity);
    }
    else {
        m_billItems.push_back(BillItem(product, quantity));
    }

    recalculateTotals();
}

void Bill::changeItemQuantity(const ProductList &product, std::size_t quantity)
{
    BillItem *item = findItemByProduct(&product);

    if (!item)
        return;

    item->changeQuantity(quantity);

    recalculateTotals();
}

void Bill::changeStatus(BillStatus newStatus)
{
    if (m_status == newStatus)
        return;

    m_status = newStatus;
    emit statusChanged();;
}
