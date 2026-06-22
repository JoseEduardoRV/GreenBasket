#include "soldproduct.h"

void SoldProduct::verifyProductData()
{
    if (name() == "unknown")
        Product::invalidateProduct();
    else if (name().empty())
        Product::invalidateProduct();
    else if (price() < 1.0f)
        Product::invalidateProduct();
    else
        Product::authorizeProduct();
}

SoldProduct::SoldProduct(const std::string &name, e_size size, double price, Category category)
    : Product {name, price}
    , m_size {size}
    , m_category{category}
{

}

SoldProduct::SoldProduct(const Product &product, e_size size, Category category)
    : Product{product}
    , m_size{size}
    , m_category{category}
{

}

SoldProduct::SoldProduct(const SoldProduct &other)
    : Product{other}
    , m_size{other.m_size}
    , m_category{other.m_category}
{

}

void SoldProduct::updatePrice(const double newPrice)
{
    Product::updateUnitValue(newPrice);
}
