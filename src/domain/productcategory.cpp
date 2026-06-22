#include "productcategory.h"

ProductCategory::ProductCategory(std::string_view key, std::string_view name, int id)
    : m_id{id}
    , m_key{key}
    , m_name{name}
{

}

ProductCategory::ProductCategory(const ProductCategory &other)
    : m_id{other.m_id}
    , m_key{other.m_key}
    , m_name{other.m_name}
{

}

bool ProductCategory::isValid() const
{
    return m_id > 0 && !m_key.empty() && !m_name.empty() && m_key != "unknown"
           && m_name != "unknown";
}
