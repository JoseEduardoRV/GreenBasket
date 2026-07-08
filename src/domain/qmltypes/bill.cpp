#include "bill.h"

ListItem *Bill::findItemByProduct(const MenuProduct *product)
{
    if (!product)
        return nullptr;

    for (ListItem &item : m_billItems) {
        if (item.productId() == product->id()) {
            return &item;
        }
    }

    return nullptr;
}

void Bill::recalculateTotals()
{
    double newSubTotal { 0 };

    foreach (const ListItem &item, m_billItems) {
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

void Bill::addItem(const MenuProduct &product)
{
    addItem(product, 1);
}

void Bill::addItem(const MenuProduct &product, std::size_t quantity)
{
    ListItem *billItem = findItemByProduct(&product);

    if (billItem) {
        billItem->changeQuantity(quantity);
    }
    else {
        m_billItems.push_back(ListItem(product, quantity));
    }

    recalculateTotals();
}

void Bill::changeItemQuantity(const MenuProduct &product, std::size_t quantity)
{
    ListItem *item = findItemByProduct(&product);

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

double Bill::unitPrice(const int index) const
{
    return {};
}

double Bill::subtotal(const int index) const
{
    return {};
}

int Bill::quantity(const int index) const
{
    return {};
}

QString Bill::productName(const int index) const
{
    return {};
}

QString Bill::presentation(const int index) const
{
    return {};
}
