#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <string_view>

class Product
{
    bool        m_validProduct;
    double      m_unitValue;
    std::string m_name;
    /* Se debe de analizar si m_validProduct es un nombre adecuado porque es una buena idea
    tener un miembro que sea usado para guardar el estado de la minima consistencia del valor
    que contiene m_uniitValu3 y m_name.
    ejemplo:
    n_unitValue deve ser siempre mayor a 1.
    n_mname no debe se ser un string vacio.
    */

protected:

            void authorizeProduct();
            void invalidateProduct();
            void setName(std::string_view name);
    virtual void verifyProductData() =  0;

            bool updateUnitValue(const double newValue);

public:
    explicit Product(std::string_view name, const double unitValue = 0.0f);

    Product(const Product &other);

    virtual ~Product();

    inline const std::string_view name() const { return m_name;         }
    inline       bool productIsValid()   const { return m_validProduct; }
    inline       double unitValue()      const { return m_unitValue;    }
};

#endif // PRODUCT_H
