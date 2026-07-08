#include <stdexcept>
#include <cmath>

#include <QDebug>

#include "product.h"

void Product::validateId(const int id)
{
    if (id <= 0)
        throw std::invalid_argument("Product id must be greater than zero");
}

void Product::validateUnitValue(const double unitValue)
{
    if (unitValue < 0.1f) // Se eligio 0.1 porque hay monedas de 10 centavos
        throw std::invalid_argument("Unit value product must be greater than zero");
}

void Product::validateName(std::string_view name)
{
    if (name.empty())
        throw std::invalid_argument("Product name cannot be empty");
}

bool Product::samePrice(double lhs, double rhs)
{
    return std::abs(lhs - rhs) < 0.000001;
}

Product::Product(const int id, std::string_view name, const double unitValue)
    : m_id{ id }
    , m_unitValue{ unitValue }
    , m_name{ name }
{
    validateId(id);
    validateName(name);
    validateUnitValue(unitValue);

    qDebug() << Q_FUNC_INFO << "New created product - id:"<< id << " name: " << name;
}

void Product::rename(std::string_view newName)
{
    validateName(newName);

    if (m_name == newName)
        return;

    m_name = newName;
}

void Product::chageUnitValue(const double newUnitValue)
{
    validateUnitValue(newUnitValue);

    if (samePrice(m_unitValue, newUnitValue))
        return;

    m_unitValue = newUnitValue;
}

Product::~Product()
{
    qDebug() << Q_FUNC_INFO << "Destroyed product - id:"<< id() << " name: " << name();
}

bool Product::operator==(const Product &other) const
{
    return id() == other.id();
}
