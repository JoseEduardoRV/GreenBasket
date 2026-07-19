#include <stdexcept>

#include "ticketproduct.h"

void TicketProduct::validateQuantity(std::size_t quantity)
{
    if (quantity < 1)
        throw std::invalid_argument("Quantity must be greater than zero");
}

TicketProduct::TicketProduct()
    : Product(0, "***", "none", 0)
    , m_quantity{ 0 }
{

}

TicketProduct::TicketProduct(const Product *product, const int quantity)
    :  Product{ *product }
    , m_quantity{ static_cast<std::size_t>(quantity) }
{
    if (!product)
        throw std::invalid_argument("Product cannot be null");

    if (quantity < 1)
        throw std::invalid_argument("Quantity must be greater than zero");
}

bool TicketProduct::operator==(const TicketProduct &other) const
{
    return id() == other.id()
           && quantity() == other.quantity();
}

bool TicketProduct::copyProduct(const Product *newProduct)
{
    return copyProduct(newProduct, 1);
}

bool TicketProduct::copyProduct(const Product *newProduct, const int quantity)
{
    if (!newProduct)
        return false;

    Product::operator=(*newProduct);

    changeQuantity(quantity);

    return true;
}

void TicketProduct::changeQuantity(const int quantity)
{
    validateQuantity(static_cast<std::size_t>(quantity));

    m_quantity = static_cast<std::size_t>(quantity);
}

double TicketProduct::subtotal() const
{
    return Product::unitValue() * static_cast<double>(quantity());
}
