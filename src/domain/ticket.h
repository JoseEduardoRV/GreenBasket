#ifndef TICKET_H
#define TICKET_H

#include <list>
#include <chrono>

#include "ticketproduct.h"

using date = std::chrono::system_clock::time_point;

class Ticket
{ 
    int m_ticketNumber;
    date m_date;
    // Branch* m_branch {};
    // Client* m_client {};
    // Cashier* m_cashier {};
    double m_subtotal;
    double m_tax;
    double m_total;

    std::list<TicketProduct*> m_items;

    void recalculateTotals();

public:
    Ticket();

    Ticket(const Ticket &other) = delete;

    ~Ticket();

    Ticket &operator=(const Ticket & other) = delete;

    int ticketNumber() const { return m_ticketNumber; }

    date date() const { return m_date; }

    double subtotal() const { return m_subtotal; }

    double tax() const { return m_tax; }

    double total() const { return m_total; }

    std::size_t itemCount() const;

    bool findProduct(const TicketProduct *newProduct);

    const TicketProduct *findProductByIndex(const int index) const;

    bool addProduct(TicketProduct *newProduct);
};

#endif // TICKET_H
