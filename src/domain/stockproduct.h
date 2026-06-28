#ifndef STOCKPRODUCT_H
#define STOCKPRODUCT_H

#include "product.h"

class StockProduct : public Product
{
protected:

public:
    explicit StockProduct(const Product &product);

    ~StockProduct() override;
};

#endif // STOCKPRODUCT_H
