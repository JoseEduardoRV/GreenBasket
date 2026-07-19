#include <stdexcept>

#include "ticket.h"

void Ticket::recalculateTotals()
{
    m_subtotal = 0;

    for (const TicketProduct *item : m_items) {
        m_subtotal += item->subtotal();
    }

    m_tax = m_subtotal * 0.16f;

    m_total = m_subtotal + m_tax;
}

Ticket::Ticket()
    : m_ticketNumber{ 0 }
    , m_date{} // Branch* m_branch {};
    // Client* m_client {};
    // Cashier* m_cashier {};
    , m_subtotal{ 0 }
    , m_tax{ 0 }
    , m_total{ 0 }
    , m_items{ }
{
    m_date = std::chrono::system_clock::now();
}

Ticket::~Ticket()
{
    //std::list<std::unique_ptr<Product>> m_products;

    if (!m_items.empty()) {
        for (TicketProduct *product : m_items) {
            delete product;
        }
    }

    m_items.clear();
}

std::size_t Ticket::itemCount() const
{
    return m_items.size();
}

bool Ticket::findProduct(const TicketProduct *newProduct)
{
    if (!newProduct) {
        throw std::invalid_argument("newProduct is invalid pointer");
    }

    for (const TicketProduct *item : m_items) {
        if (*item == *newProduct) {
            return true;
        }
    }

    return false;
}

const TicketProduct *Ticket::findProductByIndex(const int index) const
{
    if (index < 0 || index >= static_cast<int>(m_items.size())) {
        return nullptr;
    }

    auto product = std::next(m_items.cbegin(), index);

    if (product == m_items.cend()) {
        return nullptr;
    }

    return *product;
}

bool Ticket::addProduct(TicketProduct *newProduct)
{
    if (!newProduct) {
        return false;
    }

    if (findProduct(newProduct)) {
        delete newProduct;
        return false;
    }

    m_items.emplace_back(std::move(newProduct));

    recalculateTotals();

    return true;
}
