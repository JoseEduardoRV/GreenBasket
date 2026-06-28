#ifndef PRODUCTCATEGORY_H
#define PRODUCTCATEGORY_H

#include <string>
#include <string_view>

class ProductCategory
{
    int         m_id;
    std::string m_name;
    std::string m_key;

public:
    explicit ProductCategory(std::string_view name, int id = 0);

    ProductCategory(const ProductCategory & other);

    ~ProductCategory() = default;

    //bool operator==(const ProductCategory& other) const { return m_id == other.m_id; }

    inline int id() const { return m_id; }

    inline const std::string_view name() const { return m_name; }

    bool isValid() const;
};

#endif // PRODUCTCATEGORY_H
