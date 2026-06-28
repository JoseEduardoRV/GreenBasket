#include "soldproduct.h"

SoldProduct::SoldProduct(const Product &product,
                         const double price,
                         std::string_view presentation)
    : Product(product)
    , m_price{price}
    , m_available{true}
    , m_presentation{presentation}
{

}

SoldProduct::SoldProduct(const SoldProduct &other)
    : Product{other}
    , m_price{other.m_price}
    , m_available{other.m_available}
    , m_presentation{other.m_presentation}
{

}

SoldProduct::~SoldProduct()
{

}

void SoldProduct::enable()
{
    m_available = true;
}

void SoldProduct::disable()
{
    m_available = false;
}

void SoldProduct::setSalePrice(const double newPrice)
{
    double x = newPrice - m_price;
    if (std::abs(x) > 0.000001)
        m_price = newPrice;
}

void SoldProduct::setPresentation(std::string_view newPresentation)
{
    if (m_presentation == newPresentation)
        return;
    m_presentation = newPresentation;
}
