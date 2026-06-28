#include "submenu.h"

Submenu::Submenu(const ProductCategory &category)
    : m_category{category}
    , m_products{}
{}

Submenu::Submenu(const ProductCategory &category, const std::vector<SoldProduct> &products)
    : m_category{category}
    , m_products{products}
{
    //  /* Se debe de validar que todos los productos almacenados en el vector products
    // pertenezcan a la misma categoría, para poder almacenarlos en m_products*/
    //  for(const SoldProduct &item: products)
    //      if(item.category().id() == m_categoryID)
    //          m_products.push_back(item);
}

Submenu::Submenu(const Submenu &other)
    : m_category(other.m_category)
    , m_products(other.m_products)
{

}

Submenu::~Submenu()
{

}

void Submenu::addProduct(const SoldProduct &product)
{
    bool registeredProduct {false};

    for (const SoldProduct &item : m_products) {
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

