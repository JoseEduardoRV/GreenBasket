#ifndef BILLITEM_H
#define BILLITEM_H

#include <cstddef>

#include "soldproduct.h"

class BillItem
{
    int m_category;
    std::size_t m_quantity;
    SoldProduct m_product;

public:
    explicit BillItem(const SoldProduct &product,
                      const int category,
                      std::size_t quantity = 1);

    ~BillItem() = default;

    inline int id() const { return m_product.id();}

    inline int category() const { return m_category; }

    inline double price() const { return m_product.salePrice(); }

    inline std::size_t quantity() const { return m_quantity;        }

    const std::string_view name() const { return m_product.name(); }

    void addOne();
    void setQuantity(std::size_t newQuantity);
};

#endif // BILLITEM_H
