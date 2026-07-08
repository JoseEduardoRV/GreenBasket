#include "sale.h"

Sale::Sale(const Menu & menu,  QObject *parent)
    : QObject{parent}
    , m_menu{menu}
    , m_selectedBill{nullptr}
    , m_bills{}
{
    qDebug() << "*** Building Sale ***" << Qt::endl;
}

Sale::~Sale()
{
    qDebug() << "*** Destroying Sale ***" << Qt::endl;
}

QQmlListProperty<Tickets> Sale::tickets()
{
    return QQmlListProperty<Tickets>(this, &m_ticket);
}

void Sale::openBill()
{
    Bill *bill = createBill();

    m_bills.push_back(bill);
    selectBill(bill);

    emit billsChanged();

    qDebug() << "Se agregó una nueva cuenta:" << bill;

    auto i = new MenuProduct(1001, "Cafe", "16 Oz", 20.50f);

    TicketItem * newProduct = new TicketItem(i, 4);

    Tickets *tikect = new Tickets;

    tikect->addProducto(newProduct);

    m_ticket.append(tikect);

}

void Sale::cancelBill()
{
    if (!m_selectedBill)
        return;

    if (!canCancelBill(*m_selectedBill))
        return;

    m_selectedBill->changeStatus(Bill::BillStatus::Canceled);

    emit billsChanged();
}

void Sale::getPaidBill()
{
    if (!m_selectedBill)
        return;

    if (!canGetPaidBill(*m_selectedBill))
        return;

    m_selectedBill->changeStatus(Bill::BillStatus::Paid);

    emit billsChanged();
}

void Sale::showMenu()
{

}

void Sale::changeUser()
{
    //m_bills.push_back(Bill(this));
    qDebug() << "Se pago la cuenta:";
}

void Sale::selectBill(Bill *bill)
{
    Bill *storedBill = findBill(bill);

    if (!storedBill)
        return;

    m_selectedBill = storedBill;

    qDebug() << "Selected ticket:" << m_selectedBill;
}

Bill *Sale::createBill()
{
    Bill *bill = new Bill(this);

    bill->changeStatus(Bill::BillStatus::Active);

    return bill;
}

Bill *Sale::findBill(Bill *bill) const
{
    const int index = m_bills.indexOf(bill);

    if (index < 0)
        return nullptr;

    return m_bills.at(index);
}

bool Sale::canCancelBill(const Bill &bill) const
{
    switch (bill.status()) {
    case Bill::BillStatus::Active:
    case Bill::BillStatus::ReadyToPay:
        return true;

    case Bill::BillStatus::Suspended:
    case Bill::BillStatus::Paid:
    case Bill::BillStatus::Canceled:
    case Bill::BillStatus::Refunded:
    default:
        return false;
    }
}

bool Sale::canGetPaidBill(const Bill &bill) const
{
    switch (bill.status()) {
    case Bill::BillStatus::Active:
    case Bill::BillStatus::ReadyToPay:
        return true;

    case Bill::BillStatus::Suspended:
    case Bill::BillStatus::Paid:
    case Bill::BillStatus::Canceled:
    case Bill::BillStatus::Refunded:
    default:
        break;
        return false;
    }

    return false;
}

