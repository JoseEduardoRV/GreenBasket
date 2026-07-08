#ifndef TICKET_ITEM_H
#define TICKET_ITEM_H

#include <string>
#include <string_view>

#include "product.h"

class TicketItem
{
    int m_productId;
    double m_unitPrice;
    double m_subtotal;
    std::size_t m_quantity;
    std::string m_productName;
    std::string m_presentation;

    static void validateQuantity(std::size_t quantity);

public:
    TicketItem();

    TicketItem(const Product *product, const int quantity);

    TicketItem(const TicketItem &other) = default;

    TicketItem(TicketItem &&other) noexcept = default;

    ~TicketItem() = default;

    TicketItem &operator=(const TicketItem &other) = default;

    TicketItem &operator=(TicketItem &&other) noexcept = default;

    bool operator==(const TicketItem &other) const;

    bool copyProduct(const Product *newProduct);

    bool copyProduct(const Product *newProduct, const int quantity);

    void changeQuantity(const int quantity);

    int productId() const { return m_productId; }

    std::string_view productName() const { return m_productName; }

    std::string_view presentation() const { return m_presentation; }

    double unitPrice() const { return m_unitPrice; }

    std::size_t quantity() const { return m_quantity; }

    double subtotal() const;
};

#endif
