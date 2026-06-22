#ifndef STOCKPRODUCT_H
#define STOCKPRODUCT_H

#include "product.h"

class StockProduct : public Product
{
protected:
    void verifyProductData() override;

public:
    explicit StockProduct(std::string_view name, const double cost = 1.0f);

    ~StockProduct() override;

    inline double cost() const { return Product::unitValue(); }

    void updateCost(const double newCost);
};

#endif // STOCKPRODUCT_H
