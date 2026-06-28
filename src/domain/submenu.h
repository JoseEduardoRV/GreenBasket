#ifndef SUBMENU_H
#define SUBMENU_H

#include <vector>
#include <string_view>

#include "productcategory.h"
#include "soldproduct.h"

class Submenu
{
    ProductCategory          m_category;
    std::vector<SoldProduct> m_products;

public:

    explicit Submenu(const ProductCategory &category);

    Submenu(const ProductCategory &category, const std::vector<SoldProduct> &products);

    Submenu(const Submenu &other);

    ~Submenu();

    inline int id() const { return m_category.id(); }

    inline std::size_t items() const { return m_products.size(); }

    inline bool isEmpty() const { return m_products.empty(); }

    std::string_view name() const { return m_category.name(); }

    const std::vector<SoldProduct> &products() const { return m_products; }

    void addProduct(const SoldProduct &product);
};

#endif // SUBMENU_H
