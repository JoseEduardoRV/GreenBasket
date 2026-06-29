#include "sale.h"

Sale::Sale(const Menu *menu, QObject *parent)
    : QObject{parent}
    , m_menu{menu}
    , m_bills{}
    , m_editingBill{nullptr}
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
    Bill* b { new Bill(this) };
    m_bills.push_back(b);

    qDebug() << "Se agregó una nueva cuenta. Total de cuentas:" << m_bills.size();

    emit billCountChanged();
    emit addedBill();
}

void Sale::cancelBill(int item)
{
    //m_bills.push_back(Bill(this));
    qDebug() << "Se canselo la cuenta:" << item;
    emit billCountChanged();
    emit canceledBill();
}

void Sale::getPaidBill(int item)
{
    qDebug() << "Se pago la cuenta:" << item;
    //m_bills.push_back(Bill(this));
    emit billCountChanged();
    emit paidedBill();
}

void Sale::showMenu()
{
    if (m_menu)
        qDebug() << "Mostrar menu:" << *m_menu;
    else
        qDebug() << "Menu vacio";
}

void Sale::changeUser()
{
    //m_bills.push_back(Bill(this));
    qDebug() << "Se pago la cuenta:";
    emit changedUser();
}

void Sale::selectBill(const int index)
{
    m_editingBill = m_bills.value(index);
    qDebug() << "Selected tiket:" << index;
}
