#ifndef PRODUCTLIST_H
#define PRODUCTLIST_H

#include "product.h"

//Palta implementar el operador de ==

class ProductList : public Product
{
    double      m_price;
    bool        m_available;
    std::string m_presentation;

    static bool samePrice(double lhs, double rhs);

    static void validatePrice(double price);

    static void validatePresentation(std::string_view presentation);

public:
    explicit ProductList(const Product &product,
                         const double price,
                         std::string_view presentation);

    ProductList(const ProductList& other);
    ~ProductList() override;

    bool operator==(const ProductList &other) const;

    double salePrice() const { return m_price; }

    bool available() const { return m_available; }

    std::string_view presentation() const { return m_presentation; }

    void markAvailable();

    void markUnavailable();

    void changeSalePrice(double newPrice);

    void changePresentation(std::string_view newPresentation);
};

#endif // PRODUCTLIST_H
