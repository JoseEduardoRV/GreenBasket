#ifndef PRODUCTCATEGORY_H
#define PRODUCTCATEGORY_H

#include <string>
#include <string_view>

class ProductCategory
{
    int         m_id;
    std::string m_name;
    std::string m_size;

public:
    explicit ProductCategory(std::string_view name, std::string_view size, int id = 0);

    ProductCategory(const ProductCategory & other);

    ~ProductCategory() = default;

    inline int id() const { return m_id; }

    inline const std::string_view name() const { return m_name; }
    inline const std::string_view size() const { return m_size; }

    bool isValid() const;
};

#endif // PRODUCTCATEGORY_H
