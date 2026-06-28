#include "billitem.h"

BillItem::BillItem(const SoldProduct &product, const int category, std::size_t quantity)
    : m_category{category}
    , m_quantity{quantity > 0 ? quantity : 1}
    , m_product{product}
{

}

void BillItem::addOne()
{
    m_quantity++;
}

void BillItem::setQuantity(std::size_t newQuantity)
{
    if (newQuantity > 0)
        m_quantity = newQuantity;
}
