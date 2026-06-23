#include "productcategory.h"

ProductCategory::ProductCategory(std::string_view name, std::string_view size, int id)
    : m_id{id}
    , m_name{name}
    , m_size{size}
{

}

ProductCategory::ProductCategory(const ProductCategory &other)
    : m_id{other.m_id}
    , m_name{other.m_name}
    , m_size{other.m_size}

{

}

bool ProductCategory::isValid() const
{
    return m_id > 0 && !m_name.empty() && !m_size.empty();
}
