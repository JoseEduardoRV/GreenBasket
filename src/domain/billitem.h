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

    inline const std::string name() const     { return m_product.name();            }
    inline       double price() const         { return m_product.price();           }
    inline const std::string_view size() const     { return m_product.size().toString(); }
    inline       std::size_t quantity() const { return m_quantity;                  }
    inline       Category category() const    { return m_product.category();        }

    void updateQuantity(std::size_t newQuantity);
};

#endif // BILLITEM_H
