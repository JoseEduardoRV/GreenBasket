#ifndef SOLDPRODUCT_H
#define SOLDPRODUCT_H

#include "product.h"
#include "productcategory.h"

class SoldProduct : public Product
{
    ProductCategory m_category;

protected:
    void verifyProductData() override;

public:
    explicit SoldProduct(const ProductCategory &category, std::string_view name,
                         double price = 0.0f);

    explicit SoldProduct(const Product &product, const ProductCategory &category);

    SoldProduct(const SoldProduct& other);

    ~SoldProduct() override;

    const ProductCategory &category() const { return m_category; }

    inline double price() const { return Product::unitValue(); }


    void updatePrice(const double newPrice);
};

#endif // SOLDPRODUCT_H
