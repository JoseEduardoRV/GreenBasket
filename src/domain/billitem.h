#ifndef BILLITEM_H
#define BILLITEM_H

#include <cstddef>

#include "soldproduct.h"

class BillItem
{
    std::size_t m_quantity;
    SoldProduct m_product;

public:
    explicit BillItem(const SoldProduct &product, std::size_t quantity = 1);

    ~BillItem();

    inline double price() const         { return m_product.price(); }
    inline std::size_t quantity() const { return m_quantity;        }

    inline const std::string_view name() const     { return m_product.name(); }

    const ProductCategory &category() const { return m_product.category();}

    void updateQuantity(std::size_t newQuantity);
};

#endif // BILLITEM_H
