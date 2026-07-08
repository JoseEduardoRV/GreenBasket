#include <stdexcept>

#include "ticketitem.h"

void TicketItem::validateQuantity(std::size_t quantity)
{
    if (quantity < 1)
        throw std::invalid_argument("Quantity must be greater than zero");
}

TicketItem::TicketItem()
    : m_productId{ 0 }
    , m_unitPrice{ 0 }
    , m_subtotal { 0 }
    , m_quantity{ 0 }
    , m_productName{ " ******* " }
    , m_presentation{ "none" }
{

}

TicketItem::TicketItem(const Product *product, const int quantity)
    : TicketItem()
{
    if (!product)
        throw std::invalid_argument("Product cannot be null");

    if (quantity < 1)
        throw std::invalid_argument("Quantity must be greater than zero");

    copyProduct(product, quantity);
}

bool TicketItem::operator==(const TicketItem &other) const
{
    return productId() == other.productId()
           && quantity() == other.quantity();
}

bool TicketItem::copyProduct(const Product *newProduct)
{
    return copyProduct(newProduct, 1);
}

bool TicketItem::copyProduct(const Product *newProduct, const int quantity)
{
    if (!newProduct)
        return false;

    m_productId = newProduct->id();
    m_productName = newProduct->name();
    //m_presentation
    m_unitPrice = newProduct->unitValue();
    changeQuantity(quantity);

    return true;
}

void TicketItem::changeQuantity(const int quantity)
{
    validateQuantity(static_cast<std::size_t>(quantity));

    m_quantity = static_cast<std::size_t>(quantity);
}

double TicketItem::subtotal() const
{
    return m_unitPrice * static_cast<double>(quantity());
}
