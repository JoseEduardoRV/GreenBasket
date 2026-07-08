#include "ticketlist.h"

TicketList::TicketList(QObject *parent)
    : QObject{parent}
    , m_tickets{}
{}

TicketList::~TicketList()
{
    qDebug() << "*** detroying the Menu *** " << this;
}

QQmlListProperty<WTicket> TicketList::tickets()
{
    return QQmlListProperty<WTicket>(this, &m_tickets);
}

void TicketList::addSubmenu(WTicket *newTicket)
{
    if (!newTicket)
        return;

    if (!newTicket->parent())
        newTicket->setParent(this);

    qDebug() << Q_FUNC_INFO << " : SubMenu : " << newTicket;

    m_tickets.emplaceBack(newTicket);
    emit ticketsChanged();
}

WTicket *TicketList::findSubmenu(const WTicket *newTicket) const
{
    if (!newTicket)
        return nullptr;

    for (WTicket *item : m_tickets) {
        if (item->ticketNumber() == newTicket->ticketNumber()) {
            return item;
        }
    }

    return nullptr;
}
