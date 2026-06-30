#include "sale.h"

Sale::Sale(const Menu *menu, QObject *parent)
    : QObject{ parent }
    , m_menu{ menu }
    , m_editingBill{ nullptr }
    , m_bills{}
{
    qDebug() << "*** Building Sale ***" << Qt::endl
             << "*** Menu disponible:"  << Qt::endl;
}

Sale::~Sale()
{
    qDebug() << "*** Destroying Sale ***" << Qt::endl;
}

QQmlListProperty<Bill> Sale::bills()
{
    return QQmlListProperty<Bill>(this, &m_bills);
}

void Sale::openBill()
{
    Bill *bill = createBill();

    m_bills.push_back(bill);
    selectBill(bill);

    emit billsChanged();

    qDebug() << "Se agregó una nueva cuenta:" << bill;
}

void Sale::cancelBill()
{
    if (!m_editingBill)
        return;

    if (!canCancelBill(*m_editingBill))
        return;

    m_editingBill->changeStatus(Bill::BillStatus::Canceled);

    emit billsChanged();
}

void Sale::getPaidBill()
{
    if (!m_editingBill)
        return;

    if (!canGetPaidBill(*m_editingBill))
        return;

    m_editingBill->changeStatus(Bill::BillStatus::Paid);

    emit billsChanged();
}

void Sale::showMenu()
{
    // if (m_menu)
    //     qDebug() << "Mostrar menu:" << *m_menu;
    // else
        qDebug() << "Menu vacio";
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

    m_editingBill = storedBill;

    qDebug() << "Selected ticket:" << m_editingBill;
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
