#ifndef TICKET_H
#define TICKET_H

#include <list>
#include <chrono>

#include "ticketitem.h"

class Ticket
{ 
    int m_ticketNumber;
    std::chrono::system_clock::time_point m_date;
    // Branch* m_branch {};
    // Client* m_client {};
    // Cashier* m_cashier {};
    double m_subtotal;
    double m_tax;
    double m_total;

    std::list<TicketItem*> m_items;

    void recalculateTotals();

public:
    Ticket();

    Ticket(const Ticket &other) = delete;

    ~Ticket();

    Ticket &operator=(const Ticket & other) = delete;

    int ticketNumber() const { return m_ticketNumber; }

    std::string_view date() const { return { "DD/MM/AAAA" }; }

    double subtotal() const { return m_subtotal; }

    double tax() const { return m_tax; }

    double total() const { return m_total; }

    std::size_t itemCount() const;

    bool findProduct(const TicketItem *newProduct);

    const TicketItem *findProductByIndex(const int index) const;

    bool addProduct(TicketItem *newProduct);
};

#endif // TICKET_H
