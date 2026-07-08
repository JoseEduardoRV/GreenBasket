#ifndef TICKETLIST_H
#define TICKETLIST_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>

#include "wticket.h"

class TicketList : public QObject
{

    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<WTicket> tickets READ tickets NOTIFY ticketsChanged)

    QList<WTicket*> m_tickets;

public:
    explicit TicketList(QObject *parent = nullptr);

    ~TicketList() override;

    QQmlListProperty<WTicket> tickets();

    void addSubmenu(WTicket *newTicket);

signals:
    void ticketsChanged();

private:
    WTicket *findSubmenu(const WTicket *newTicket) const;
};

#endif // TICKETLIST_H
