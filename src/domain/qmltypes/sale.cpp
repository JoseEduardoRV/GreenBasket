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
    Bill *bill = new Bill(this);

    bill->setTicketNumber(m_bills.size());

    bill->setCreatedAt();

    m_bills.push_back(bill);

    m_editingBill = bill;

    emit billsChanged();

    qDebug() << "Se agregó una nueva cuenta. Total:" << m_bills.size();
}

void Sale::cancelBill(int item)
{
    //m_bills.push_back(Bill(this));
    qDebug() << "Se canselo la cuenta:" << item;
}

void Sale::getPaidBill(int item)
{
    qDebug() << "Se pago la cuenta:" << item;
    //m_bills.push_back(Bill(this));
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

void Sale::selectBill(const int index)
{
    m_editingBill = m_bills.value(index);
    qDebug() << "Selected tiket:" << index;
}
