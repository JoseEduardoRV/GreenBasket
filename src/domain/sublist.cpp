#include <stdexcept>
#include <iterator>
#include <utility>

#include "sublist.h"

bool SubList::findProduct(const Product *newProduct)
{
    if (!newProduct){
        throw std::invalid_argument("newProduct is invalid pointer");
    }

    for (const Product *item : m_products){
        if (*item == *newProduct){
            return true;
        }
    }

    return false;
}

void SubList::validateId(int id)
{
    if (id < 0)
        throw std::invalid_argument("Product Category id must be greater than zero");
}

void SubList::validateName(std::string_view name)
{
    if (name.empty())
        throw std::invalid_argument("Product Category name cannot be empty");
}

SubList::SubList(const int id, std::string_view name)
    : m_id { id }
    , m_name { name }
    , m_products { }
{

}

SubList::SubList(const int id, std::string_view name,
                 std::list<Product *> &&products)
    : SubList(id, name)
{
    m_products = std::move(products);
}

SubList::SubList(SubList &&other) noexcept
    : m_id { other.m_id }
    , m_name { std::move(other.m_name) }
    , m_products{ std::move(other.m_products) }
{

}

SubList::~SubList()
{
    //std::list<std::unique_ptr<Product>> m_products;

    if (!m_products.empty()){
        for (Product* product : m_products){
            delete product;
        }
    }

    m_products.clear();
}

SubList &SubList::operator=(SubList &&other) noexcept
{
    if (this == &other) {
        return *this;
    }

    for (Product *product : m_products) {
        delete product;
    }

    m_products.clear();

    m_id = other.m_id;
    m_name = std::move(other.m_name);
    m_products = std::move(other.m_products);

    return *this;
}

bool SubList::operator==(const SubList &other) const
{
    return id() == other.id()
        && m_products.size() == other.itemCount();
}

std::size_t SubList::itemCount() const
{
    return m_products.size();
}

const Product *SubList::item(const int index) const
{
    if (index < 0 || index >= static_cast<int>(m_products.size())){
        return nullptr;
    }

    auto product = std::next(m_products.cbegin(), index);

    if (product == m_products.cend()){
        return nullptr;
    }

    return *product;
}

bool SubList::addProduct(Product *newProduct)
{
    if (!newProduct){
        return false;
    }

    if (findProduct(newProduct)){
        delete newProduct;
        return false;
    }

    m_products.emplace_back(std::move(newProduct));

    return true;
}

void SubList::rename(std::string_view newName)
{
    validateName(newName);

    if (m_name == newName)
        return;

    m_name = newName;
}
