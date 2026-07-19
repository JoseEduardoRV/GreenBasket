#include "menuproduct.h"

MenuProduct::MenuProduct(const int id,
                         std::string_view name,
                         std::string_view presentation,
                         const double price)
    : Product(id, name, presentation, price)
    , m_available{ true }
{

}

bool MenuProduct::operator==(const MenuProduct &other) const
{
    return Product::operator==(other)
           && m_available == other.m_available
           && Product::samePrice(unitValue(), other.unitValue())
           && Product::presentation() == other.presentation();
}

void MenuProduct::markAvailable()
{
    m_available = true;
}

void MenuProduct::markUnavailable()
{
    m_available = false;
}

void MenuProduct::changeSalePrice(double newPrice)
{
    Product::chageUnitValue(newPrice);
}

void MenuProduct::changePresentation(std::string_view newPresentation)
{
    Product::changePresentation(newPresentation);
}
