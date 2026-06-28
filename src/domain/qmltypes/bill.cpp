#include "bill.h"

Bill::Bill(QObject *parent)
    : QObject{parent}
    , m_drinkTotal{ }
    , m_foodTotal{ }
    , m_total{ }
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
