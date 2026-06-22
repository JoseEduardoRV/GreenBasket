#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product
{
    bool        m_validProduct;
    double      m_unitValue;
    std::string m_name;

protected:

            void authorizeProduct();
            void invalidateProduct();
            void setName(const std::string &name);
    virtual void verifyProductData() =  0;

            bool updateUnitValue(const double newValue);

public:
    explicit Product(const std::string& name = "unknown", const double unitValue = 0.0f);
    Product(const Product &other);
    virtual ~Product() = default;

    inline const std::string &name()   const { return m_name;         }
    inline       bool productIsValid() const { return m_validProduct; }
    inline       double unitValue()    const { return m_unitValue;    }
};

#endif // PRODUCT_H
