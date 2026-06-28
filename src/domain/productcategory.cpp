#include "productcategory.h"

ProductCategory::ProductCategory(std::string_view name, int id)
    : m_id{id}
    , m_name{name}
    , m_key{ }
{

}

ProductCategory::ProductCategory(const ProductCategory &other)
    : m_id{other.m_id}
    , m_name{other.m_name}
    , m_key{other.m_key}

{

}

bool ProductCategory::isValid() const
{
    return m_id > 0 && !m_name.empty() /*&& !m_size.empty()*/;
}
