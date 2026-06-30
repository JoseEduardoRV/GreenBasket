#include <stdexcept>

#include "product.h"

void Product::validateId(int id)
{
    if (id <= 0)
        throw std::invalid_argument("Product id must be greater than zero");
}

void Product::validateName(std::string_view name)
{
    if (name.empty())
        throw std::invalid_argument("Product name cannot be empty");
}

void Product::rename(std::string_view newName)
{
    validateName(newName);

    if (m_name == newName)
        return;

    m_name = newName;
}

Product::Product(const int id, std::string_view name)
    : m_id{id}
    , m_name{name}
{
    validateId(id);
    validateName(name);
}

Product::Product(const Product &other)
    : m_id{other.m_id}
    , m_name{other.m_name}
{

}
