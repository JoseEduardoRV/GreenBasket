#include "wticket.h"

WTicket::WTicket(QObject *parent)
    : QObject{parent}
    , m_index {0}
    , m_ticket{ }
{

}

QString WTicket::ticketNumber() const
{
    return QString::number(m_ticket.ticketNumber());
}

QString WTicket::date() const
{
    return { };/*toQString(m_ticket.date())*/
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

void WTicket::addProducto(TicketProduct *newProduct)
{
    if (!newProduct) {
        return;
    }

    if (m_ticket.addProduct(newProduct)) {
        emit listChanged();
        emit subtotalChanged();
        emit taxChanged();
        emit totalChanged();
    }
}

QString WTicket::productName() const
{
    const TicketProduct *item = m_ticket.findProductByIndex(index());

    if (!item){
        return { };
    }

    return toQString(item->name());
}

QString WTicket::productPresentation() const
{
    const TicketProduct *item = m_ticket.findProductByIndex(index());

    if (!item){
        return { };
    }

    return toQString(item->presentation());
}

double WTicket::productPrice() const
{
    const TicketProduct *item = m_ticket.findProductByIndex(index());

    if (!item){
        return 0.0f;
    }

    return item->unitValue();
}

int WTicket::quantity() const
{
    const TicketProduct *item = m_ticket.findProductByIndex(index());

    if (!item){
        return 0;
    }

    return item->quantity();
}

double WTicket::productSubtotal() const
{
    const TicketProduct *item = m_ticket.findProductByIndex(index());

    if (!item){
        return 0;
    }

    return item->subtotal();
}

void WTicket::selecteItem(const int index)
{
    m_index = index;
}

QString WTicket::toQString(std::string_view value)
{
    return QString::fromUtf8(value.data(), qsizetype(value.size()));
}
