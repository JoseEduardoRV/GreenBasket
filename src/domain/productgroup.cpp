#include "productgroup.h"

ProductGroup::ProductGroup(const SectionInfo &category)
    : m_category{category}
    , m_products{ }
{}

ProductGroup::ProductGroup(const SectionInfo &category, const std::list<ProductList> &products)
    : m_category{category}
    , m_products{products}
{

}

ProductGroup::ProductGroup(const ProductGroup &other)
    : m_category(other.m_category)
    , m_products(other.m_products)
{

}

ProductGroup::~ProductGroup()
{

}

int ProductGroup::id() const
{
    return m_category.id();
}

std::size_t ProductGroup::items() const
{
    return m_products.size();
}

bool ProductGroup::isEmpty() const
{
    return m_products.empty();
}

std::string_view ProductGroup::name() const
{
    return m_category.name();
}

void ProductGroup::addProduct(const ProductList &product)
{
    bool registeredProduct {false};

    for (const ProductList &item : m_products) {
        if(item.id() == product.id()) {
            registeredProduct = true;
        }
    }

    if(registeredProduct) {
        return;
    }
    else {
        m_products.emplace_back(product);
    }
}

