#ifndef SOLDPRODUCT_H
#define SOLDPRODUCT_H

#include "product.h"

class SoldProduct : public Product
{
    double      m_price;
    bool        m_available;
    std::string m_presentation;

public:
    explicit SoldProduct(const Product &product,
                         const double price,
                         std::string_view presentation);

    SoldProduct(const SoldProduct& other);

    ~SoldProduct() override;

    inline double salePrice() const { return m_price; }

    inline bool   available() const { return m_available; }

    const std::string_view presentation() const { return m_presentation; }

    void enable();

    void disable();

    void setSalePrice(const double newPrice);

    void setPresentation(std::string_view newPresentation);
};

#endif // SOLDPRODUCT_H
