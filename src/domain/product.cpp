#include <cmath>

#include "product.h"

void Product::authorizeProduct()
{
    m_validProduct = true;
}

void Product::invalidateProduct()
{
    m_validProduct = false;
}

bool Product::updateUnitValue(const double newValue)
{
         if(productIsValid())
              return false;
    else if (newValue < 1.0f)
              return false;
    else if (std::abs(newValue - unitValue()) > 0.00001f)
    {
              m_unitValue = newValue;
              return true;
    }
    else return false;
}

void Product::setName(const std::string &name)
{
    //Esta funcion tiene muchos puntos en los que
    // debo trabajar
    if(productIsValid())
        return;
    m_name = name;
}

Product::Product(const std::string &name, const double unitValue)
    : m_validProduct{false}
    , m_unitValue{unitValue}
    , m_name{name}
{

}

Product::Product(const Product &other)
    : m_validProduct{other.m_validProduct}
    , m_unitValue{other.m_unitValue}
    , m_name{other.m_name}
{}
