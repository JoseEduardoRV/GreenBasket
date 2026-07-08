#include <stdexcept>

#include "listitem.h"

void ListItem::validateQuantity(std::size_t quantity)
{
    if (quantity < 1)
        throw std::invalid_argument("Quantity must be greater than zero");
}

ListItem::ListItem(const MenuProduct &product, std::size_t quantity)
    : m_quantity{quantity}
    , m_product{product}
{
    validateQuantity(quantity);
}

bool ListItem::operator==(const ListItem &other) const
{
    return m_product == other.m_product
           && m_quantity == other.quantity();
}

int ListItem::productId() const
{
    return m_product.id();
}

double ListItem::unitPrice() const
{
    return m_product.unitValue();
}

double ListItem::subtotal() const
{
    return unitPrice() * static_cast<double>(m_quantity);
}

std::string_view ListItem::productName() const
{
    return m_product.name();
}

std::string_view ListItem::presentation() const
{
    return m_product.presentation();
}

void ListItem::incrementQuantityByOne()
{
    ++m_quantity;
}

void ListItem::changeQuantity(std::size_t newQuantity)
{
    validateQuantity(newQuantity);

    m_quantity = newQuantity;
}
