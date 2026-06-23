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

SoldProduct::SoldProduct(const ProductCategory &category, std::string_view name, double price)
    : Product{name, price}
    , m_category{category}
{}

SoldProduct::SoldProduct(const Product &product, const ProductCategory &category)
    : Product{product}
    , m_category{category}
{}

SoldProduct::SoldProduct(const SoldProduct &other)
    : Product{other}
    , m_category{other.m_category}
{

}

SoldProduct::~SoldProduct()
{

}

void SoldProduct::updatePrice(const double newPrice)
{
    Product::updateUnitValue(newPrice);
}
