#include <stdexcept>

#include "productlist.h"

bool ProductList::samePrice(double lhs, double rhs) //Falta pensar mejor el codigo
{
    return std::abs(lhs - rhs) < 0.000001;
}

void ProductList::validatePrice(double price)
{
    if (price < 0.0)
        throw std::invalid_argument("SoldProduct price cannot be negative");
}

void ProductList::validatePresentation(std::string_view presentation)
{
    if (presentation.empty())
        throw std::invalid_argument("SoldProduct presentation cannot be empty");
}

ProductList::ProductList(const Product &product, const double price, std::string_view presentation)
    : Product(product)
    , m_price{price}
    , m_available{true}
    , m_presentation{presentation}
{
    validatePrice(price);
    validatePresentation(presentation);
}

ProductList::ProductList(const ProductList &other)
    : Product{other}
    , m_price{other.m_price}
    , m_available{other.m_available}
    , m_presentation{other.m_presentation}
{

}

ProductList::~ProductList()
{

}

bool ProductList::operator==(const ProductList &other) const
{
    return other.id() == id();
}

void ProductList::markAvailable()
{
    m_available = true;
}

void ProductList::markUnavailable()
{
    m_available = false;
}

void ProductList::changeSalePrice(double newPrice)
{
    validatePrice(newPrice);

    if (samePrice(m_price, newPrice))
        return;

    m_price = newPrice;
}

void ProductList::changePresentation(std::string_view newPresentation)
{
    validatePresentation(newPresentation);

    if (m_presentation == newPresentation)
        return;

    m_presentation = newPresentation;
}
