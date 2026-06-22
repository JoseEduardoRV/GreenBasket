#ifndef STOCKPRODUCT_H
#define STOCKPRODUCT_H

#include "product.h"

class StockProduct : public Product
{
protected:
    void verifyProductData() override;

public:
    explicit StockProduct(const std::string &name = "unknow", const double cost = 1.0f);

    inline const double cost() const { return Product::unitValue(); }

    void updateCost(const double newCost);
};

#endif // STOCKPRODUCT_H
