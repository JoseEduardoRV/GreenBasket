#include "stockproduct.h"

void StockProduct::verifyProductData()
{
    if (name() == "unknown")
        Product::invalidateProduct();
    else if (name().empty())
        Product::invalidateProduct();
    else if (cost() < 1.0f)
        Product::invalidateProduct();
    else
        Product::authorizeProduct();
}

StockProduct::StockProduct(const std::string &name, const double cost)
    : Product(name, cost)
{

}

void StockProduct::updateCost(const double newCost)
{
    Product::updateUnitValue(newCost);
}
