#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <string_view>

/*Esta clase es una abstracción de un producto y como regla general
 ningun producto puede tener un id igual.
Además, como clase base solo los hijos pueden crear una instancia.
*/

class Product
{
    int m_id;
    double m_unitValue;
    std::string m_name;

    static void validateId(const int id);

    static void validateUnitValue(const double unitValue);

    static void validateName(std::string_view name);

protected:

    static bool samePrice(double lhs, double rhs);

    Product() = delete;

    Product(const int id,
            std::string_view name,
            const double unitValue);

    void rename(std::string_view newName);

    void chageUnitValue(const double newUnitValue);

public:

    Product(const Product &other) = default;

    Product(Product &&other) noexcept = default;

    virtual ~Product();

    Product &operator=(const Product &other) = default;

    Product &operator=(Product &&other) noexcept = default;

    bool operator==(const Product &other) const;

    int id() const { return m_id; }

    double unitValue() const { return m_unitValue; }

    std::string_view name() const { return m_name; }
};

#endif // PRODUCT_H
