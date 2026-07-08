#ifndef BILLITEM_H
#define BILLITEM_H

#include <cstddef>

#include "menuproduct.h"

class ListItem
{
    std::size_t m_quantity;
    MenuProduct m_product;

    static void validateQuantity(std::size_t quantity);

public:
    ListItem() = delete;

    ListItem(const MenuProduct &product,
             std::size_t quantity);

    ListItem(const ListItem &other) = default;

    ListItem(ListItem &&other) noexcept = default;

    ~ListItem() = default;

    ListItem &operator=(const ListItem &other) = default;

    ListItem &operator=(ListItem &&other) noexcept = default;

    bool operator==(const ListItem &other) const;

    int productId() const;

    double unitPrice() const;

    double subtotal() const;

    std::size_t quantity() const { return m_quantity; }

    std::string_view productName() const;

    std::string_view presentation() const;

    void incrementQuantityByOne();

    void changeQuantity(std::size_t newQuantity);
};

#endif // BILLITEM_H
