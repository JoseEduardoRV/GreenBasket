#ifndef PRODUCTGROUP_H
#define PRODUCTGROUP_H

#include <list>
#include <string_view>

#include "sectioninfo.h"
#include "productlist.h"

class ProductGroup
{
    SectionInfo          m_category;
    std::list<ProductList> m_products;

public:

    explicit ProductGroup(const SectionInfo &category);

    ProductGroup(const SectionInfo &category, const std::list<ProductList> &products);

    ProductGroup(const ProductGroup &other);

    ~ProductGroup();

    int id() const;

    std::size_t items() const;

    bool isEmpty() const;

    std::string_view name() const;

    const std::list<ProductList> &products() const { return m_products; }

    void addProduct(const ProductList &product);
};

#endif // PRODUCTGROUP_H
