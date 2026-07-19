#ifndef TICKET_ITEM_H
#define TICKET_ITEM_H

#include "product.h"

class TicketProduct : public Product
{
    double m_subtotal;
    std::size_t m_quantity;

    static void validateQuantity(std::size_t quantity);

public:
    TicketProduct();

    TicketProduct(const Product *product, const int quantity);

    TicketProduct(const TicketProduct &other) = default;

    TicketProduct(TicketProduct &&other) noexcept = default;

    ~TicketProduct() = default;

    TicketProduct &operator=(const TicketProduct &other) = default;

    TicketProduct &operator=(TicketProduct &&other) noexcept = default;

    bool operator==(const TicketProduct &other) const;

    bool copyProduct(const Product *newProduct);

    bool copyProduct(const Product *newProduct, const int quantity);

    void changeQuantity(const int quantity);

    std::size_t quantity() const { return m_quantity; }

    double subtotal() const;
};

#endif
