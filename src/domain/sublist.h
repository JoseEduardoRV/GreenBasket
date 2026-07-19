#ifndef SUBLIST_H
#define SUBLIST_H

#include <list>

#include "product.h"

//Clase candidata para cambiar y ser una clase plantilla


class SubList
{
    int m_id;
    std::string m_name;

    std::list<Product*> m_products;

    bool findProduct(const Product *newProduct);

    static void validateId(int id);

    static void validateName(std::string_view name);

public:

    SubList() = /*delete*/default;

    SubList(const int id, std::string_view name);

    SubList(const int id, std::string_view name,
            std::list<Product*> &&products);

    SubList(const SubList &other) = delete;

    SubList(SubList &&other) noexcept;

    ~SubList();

    SubList &operator=(const SubList &other) = delete;

    SubList &operator=(SubList &&other) noexcept;

    bool operator==(const SubList &other) const;

    int id() const { return m_id; }

    std::string_view name() const { return m_name; }

    std::size_t itemCount() const;

    const Product *item(const int index) const;

    bool addProduct(Product *newProduct);

    void rename(std::string_view newName);
};

#endif
