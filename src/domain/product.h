#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <string_view>

//Palta implementar el operador de ==

class Product
{
    int m_id;
    std::string m_name;

    static void validateId(int id);
    static void validateName(std::string_view name);

protected:
    void rename(std::string_view newName);

public:
    explicit Product(const int id, std::string_view name);
    Product(const Product &other);
    virtual ~Product() = default;

    int id() const { return m_id; }

    std::string_view name() const { return m_name; }
};

#endif // PRODUCT_H
