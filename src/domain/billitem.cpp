#include "billitem.h"

BillItem::BillItem(const SoldProduct &product, std::size_t quantity)
    : m_quantity {quantity}
    , m_product {product}
{

}

BillItem::~BillItem()
{

}

void BillItem::updateQuantity(std::size_t newQuantity)
{
    if (newQuantity > 0)
        m_quantity = newQuantity;
}
