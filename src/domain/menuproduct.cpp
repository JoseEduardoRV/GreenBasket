#include <stdexcept>

#include "menuproduct.h"

void MenuProduct::validatePresentation(std::string_view presentation)
{
    if (presentation.empty())
        throw std::invalid_argument("SoldProduct presentation cannot be empty");
}

MenuProduct::MenuProduct(const int id,
                         std::string_view name,
                         std::string_view presentation,
                         const double price)
    : Product(id, name, price)
    , m_available{ true }
    , m_presentation{ presentation }
{
    validatePresentation(presentation);
}

bool MenuProduct::operator==(const MenuProduct &other) const
{
    return Product::operator==(other)
           && m_available == other.m_available
           && Product::samePrice(unitValue(), other.unitValue())
           && m_presentation == other.m_presentation;
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
    validatePresentation(newPresentation);

    if (m_presentation == newPresentation)
        return;

    m_presentation = newPresentation;
}
