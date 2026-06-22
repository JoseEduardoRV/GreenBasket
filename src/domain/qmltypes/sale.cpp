#include "sale.h"

Sale::Sale(const Menu &menu, QObject *parent)
    : QObject{parent}
    , m_menu{menu}
    , m_bills{}
    , m_bill{nullptr}
{
    qDebug() << "*** Building Sale ***" << Qt::endl
             << "*** Menu disponible:"  << Qt::endl
             << m_menu;
}

Sale::~Sale()
{
    qDebug() << "*** Destroying Sale ***" << Qt::endl;
}

void Sale::openBill()
{
    m_bill = new Bill(this);
    m_bills.append(m_bill);
    qDebug() << "Se agregó una nueva cuenta. Total de cuentas:" << m_bills.size();
}

void Sale::addProduct()
{
    if(m_bill == nullptr)
        return;

    m_bill->addItem(m_menu.food().at(0),   4);
    m_bill->addItem(m_menu.food().at(1),   1);
    m_bill->addItem(m_menu.drinks().at(0), 3);
}

void Sale::closeBill()
{
    if(m_bill == nullptr)
        return;
    m_bill->calculateTotal();
    qDebug() << "*** Cobrar cuenta ***" << Qt::endl
             << *m_bill;



}
