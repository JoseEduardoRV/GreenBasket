#include "wticket.h"

WTicket::WTicket(QObject *parent)
    : QObject{parent} , m_ticket{ }
{

}

QString WTicket::ticketNumber() const
{
    return QString::number(m_ticket.ticketNumber());
}

QString WTicket::date() const
{
    return toQString(m_ticket.date());
}

double WTicket::tax() const
{
    return m_ticket.tax();
}

double WTicket::subtotal() const
{
    return m_ticket.subtotal();
}

double WTicket::total() const
{
    return m_ticket.total();
}

int WTicket::itemCount() const
{
    return m_ticket.itemCount();
}

void WTicket::addProducto(TicketItem *newProduct)
{
    if (!newProduct) {
        return;
    }

    if (m_ticket.addProduct(newProduct)) {
        emit listChanged();
    }
}

QString WTicket::productName(const int index) const
{
    const TicketItem *item = m_ticket.findProductByIndex(index);

    if (!item){
        return { };
    }

    return toQString(item->productName());
}

QString WTicket::productPresentation(const int index) const
{
    const TicketItem *item = m_ticket.findProductByIndex(index);

    if (!item){
        return { };
    }

    return toQString(item->presentation());
}

double WTicket::productPrice(const int index) const
{
    const TicketItem *item = m_ticket.findProductByIndex(index);

    if (!item){
        return 0.0f;
    }

    return item->unitPrice();
}

int WTicket::quantity(const int index) const
{
    const TicketItem *item = m_ticket.findProductByIndex(index);

    if (!item){
        return 0;
    }

    return item->quantity();
}

double WTicket::subtotal(const int index) const
{
    const TicketItem *item = m_ticket.findProductByIndex(index);

    if (!item){
        return 0;
    }

    return item->subtotal();
}

QString WTicket::toQString(std::string_view value)
{
    return QString::fromUtf8(value.data(), qsizetype(value.size()));
}
