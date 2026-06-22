#ifndef BILLITEM_H
#define BILLITEM_H

/* Como se realizaron cambios en la clase Product, la funcion 
"const std::string_view size() const     { return m_product.size().toString(); }", ya
no tiene sentido porque la categoria se encuentra en el miembro category de la clase SoldProduct

*/

#include <cstddef>

#include "soldproduct.h"

class BillItem
{
    std::size_t m_quantity;
    SoldProduct m_product;

public:
    explicit BillItem(const SoldProduct &product, std::size_t quantity = 1);


    inline double price() const         { return m_product.price();           }
    inline std::size_t quantity() const { return m_quantity;                  }

    const std::string_view size() const     { return m_product.size().toString(); }
    const ProductCategory &category() const { return m_product.category();        }
    const std::string_view name() const     { return m_product.name();            }

    void updateQuantity(std::size_t newQuantity);
};

#endif // BILLITEM_H
