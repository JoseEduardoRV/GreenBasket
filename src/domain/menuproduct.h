#ifndef MENUPRODUCT_H
#define MENUPRODUCT_H

#include "product.h"

class MenuProduct : public Product
{
    bool m_available;

public:
    MenuProduct() = delete;

    MenuProduct(const int id,
                std::string_view name,
                std::string_view presentation,
                const double price);

    MenuProduct(const MenuProduct& other) = default ;

    MenuProduct(MenuProduct&& other) noexcept = default;

    ~MenuProduct() override = default;

    MenuProduct &operator=(const MenuProduct &other) = default;

    MenuProduct &operator=(MenuProduct &&other) noexcept = default;

    bool operator==(const MenuProduct &other) const;

    bool available() const { return m_available; }

    void markAvailable();

    void markUnavailable();

    void changeSalePrice(double newPrice);

    void changePresentation(std::string_view newPresentation);
};

#endif // MENUPRODUCT_H
