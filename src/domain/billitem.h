#ifndef BILLITEM_H
#define BILLITEM_H

#include <cstddef>

#include "productlist.h"

class BillItem
{
    std::size_t m_quantity;
    ProductList m_product;

    static void validateQuantity(std::size_t quantity);

public:
    explicit BillItem(const ProductList &product, std::size_t quantity);

    ~BillItem() = default;

    bool operator==(const BillItem &other) const;

    int productid() const;

    double unitPrice() const;

    double subtotal() const;

    std::size_t quantity() const { return m_quantity; }

    std::string_view productName() const;

    std::string_view presentation() const;

    void incrementQuantityByOne();

    void changeQuantity(std::size_t newQuantity);
};

#endif // BILLITEM_H
