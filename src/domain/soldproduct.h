#ifndef SOLDPRODUCT_H
#define SOLDPRODUCT_H

#include <string_view>
// nombre para lcase que lee de JASON loader o storage
#include "product.h"

enum class Category {
    None, Drink, Food, Dessert
};

enum class e_size {
    None,
    Small,
    Medium,
    Large,
    _12oz,
    _16oz,
    _20oz
};

class Size
{
    e_size m_size;

public:
    Size(e_size newSize = e_size::None)
        : m_size{newSize}
    {

    }
    std::string_view toString() const
    {
        switch (m_size) {
        case e_size::Small:  return "Small";
        case e_size::Medium: return "Medium";
        case e_size::Large:  return "Large";
        case e_size::None:   return " ";
        case e_size::_12oz:  return "12oz";
        case e_size::_16oz:  return "16oz";
        case e_size::_20oz:  return "20oz";
        default:             return " ";
        }
    }
    e_size toCode() const { return m_size; }
};

class SoldProduct : public Product
{
    Size m_size;
    Category m_category;

protected:
    void verifyProductData() override;

public:
    explicit SoldProduct(const std::string &name = "unknown", e_size size = e_size::None,
                         double price = 0.0f, Category category = Category::None);
    explicit SoldProduct(const Product &product, e_size size = e_size::None,
                         Category category = Category::None);
    SoldProduct(const SoldProduct& other);

    inline double price() const      { return Product::unitValue(); }
    inline Size   size() const       { return m_size;               }
    inline Category category() const { return m_category;           }

    void updatePrice(const double newPrice);
};

#endif // SOLDPRODUCT_H
