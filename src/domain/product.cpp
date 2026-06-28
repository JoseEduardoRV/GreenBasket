#include <cmath>

#include "product.h"

void Product::setName(std::string_view newName)
{
    if(m_name == newName)
        return;
    m_name = newName;
}

void Product::setId(const int newId)
{
    if ((m_id > 0) && (m_id != newId))
        m_id = newId;
}

Product::Product(const int id, std::string_view name)
    : m_id{id}
    , m_name{name}
{

}

Product::Product(const Product &other)
    : m_id{other.m_id}
    , m_name{other.m_name}
{

}

