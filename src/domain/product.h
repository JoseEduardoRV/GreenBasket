#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <string_view>

class Product
{
    int         m_id;
    std::string m_name;

protected:
    void setName(std::string_view newName);
    void setId(const int newId);

public:
    explicit Product(const int id, std::string_view name);

    Product(const Product &other);

    virtual ~Product() = default;

    inline int id() const { return m_id; }

    inline const std::string_view name() const { return m_name; }
};

#endif // PRODUCT_H
