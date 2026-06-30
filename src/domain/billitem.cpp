#include <stdexcept>

#include "billitem.h"

void BillItem::validateQuantity(std::size_t quantity)
{
    if (quantity < 1)
        throw std::invalid_argument("Quantity must be greater than zero");
}

BillItem::BillItem(const ProductList &product, std::size_t quantity)
    : m_quantity{quantity}
    , m_product{product}
{
    validateQuantity(quantity);
}

bool BillItem::operator==(const BillItem &other) const
{
    return other.m_product == m_product;
}

int BillItem::productid() const
{
    return m_product.id();
}

double BillItem::unitPrice() const
{
    return m_product.salePrice();
}

double BillItem::subtotal() const
{
    return unitPrice() * static_cast<double>(m_quantity);
}

std::string_view BillItem::productName() const
{
    return m_product.name();
}

std::string_view BillItem::presentation() const
{
    return m_product.presentation();
}

void BillItem::incrementQuantityByOne()
{
    m_quantity += 1;
}

void BillItem::changeQuantity(std::size_t newQuantity)
{
    validateQuantity(newQuantity);
    m_quantity = newQuantity;
}
