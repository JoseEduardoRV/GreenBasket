#include "sale.h"

Sale::Sale(QObject *parent)
    : QObject{parent}
    , m_bills{}
    , m_editingBill{nullptr}
{
    qDebug() << "*** Building Sale ***" << Qt::endl
             << "*** Menu disponible:"  << Qt::endl;
}

Sale::~Sale()
{
    qDebug() << "*** Destroying Sale ***" << Qt::endl;
}

void Sale::openBill()
{
    Bill *bill = createBill();

    if(bill) {
        m_bills.push_back(bill);

        m_editingBill = bill;

        emit billsChanged();

        qDebug() << "Se agregó una nueva cuenta:" << bill;
    }
}

void Sale::cancelBill()
{
    if (m_editingBill) {

        if (canCancelBill(*m_editingBill)) {

            m_editingBill->clean();

            m_editingBill->setStatus(Bill::BillStatus::Canceled);

            emit billsChanged();
        }
    }
}

void Sale::getPaidBill()
{
    if (m_editingBill) {

        if (canGetPaidBill(*m_editingBill)) {

            //m_editingBill->clean(); Algoritmo para cobro

            m_editingBill->setStatus(Bill::BillStatus::Paid);

            emit billsChanged();
        }
    }
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
    if (m_bills.contains(bill)) {
        m_editingBill = bill;
        m_editingBill->settotal();

        qDebug() << "Selected ticket:" << m_editingBill;
    }
}

Bill *Sale::createBill()
{
    Bill *bill = new Bill(this);

    if(bill) {
        bill->setTicketNumber(m_bills.size() + 1);
        bill->setCreatedAt();
        bill->setStatus(Bill::BillStatus::Active);
    }

    return bill;
}

bool Sale::canCancelBill(const Bill &bill) const
{
    switch (bill.status()) {
    case Bill::BillStatus::Active:
    case Bill::BillStatus::Suspended:
    case Bill::BillStatus::ReadyToPay:
        return true;

    case Bill::BillStatus::Closed:
    case Bill::BillStatus::Paid:
    case Bill::BillStatus::Canceled:
    case Bill::BillStatus::Refunded:
    default:
        break;
        return false;
    }

    return false;
}

bool Sale::canGetPaidBill(const Bill &bill) const
{
    switch (bill.status()) {
    case Bill::BillStatus::Active:
    case Bill::BillStatus::ReadyToPay:
        return true;

    case Bill::BillStatus::Suspended:
    case Bill::BillStatus::Closed:
    case Bill::BillStatus::Paid:
    case Bill::BillStatus::Canceled:
    case Bill::BillStatus::Refunded:
    default:
        break;
        return false;
    }

    return false;
}
