#ifndef PRODUCTCATEGORY_H
#define PRODUCTCATEGORY_H

#include <string>
#include <string_view>

class ProductCategory
{
    int         m_id;
    std::string m_key;
    std::string m_name;

public:
    explicit ProductCategory(std::string_view key, std::string_view name, int id = 0);

    ProductCategory(const ProductCategory & other);

    ~ProductCategory() = default;

    inline int id() const { return m_id; }
    inline const std::string_view key() const  { return m_key;  }
    inline const std::string_view name() const { return m_name; }

    bool isValid() const;
};

#endif // PRODUCTCATEGORY_H
