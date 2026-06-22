#include <QString>

#include <algorithm>

#include "productlistmodel.h"

void ProductListModel::updateCategories()
{
    if(m_products == nullptr)
        return;

    m_categories.clear();

    for (const SoldProduct &product : *m_products)
    {
        int categoryId = product.category().id();

        if (categoryId <= 0)
            continue;

        auto it = std::find(m_categories.begin(), m_categories.end(), categoryId);

        if (it == m_categories.end())
            m_categories.push_back(categoryId);
    }

    emit categoriesChanged();
    qDebug() << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
}

ProductListModel::ProductListModel(QObject *parent)
    : QAbstractListModel{parent}
    , m_products{nullptr}
{
}

void ProductListModel::setProducts(const QList<SoldProduct> *products)
{
    beginResetModel();
    m_products = products;
    endResetModel();
}

int ProductListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    if (m_products == nullptr)
        return 0;

    return m_products->size();
}

QVariant ProductListModel::data(const QModelIndex &index, int role) const
{
    if (m_products == nullptr)
        return {};

    if (!index.isValid())
        return {};

    if (index.row() < 0 || index.row() >= m_products->size())
        return {};

    const int productRow = index.row();
    const SoldProduct &product = m_products->at(productRow);

    switch (role) {
    case ProductRoles::ProductRowRole:
        return productRow;
    case ProductRoles::NameRole:
        return QString::fromStdString(std::string(product.name()));

    case ProductRoles::SizeRole:
        return QString::fromStdString(std::string(product.size().toString()));

    case ProductRoles::PriceRole:
        return product.price();

    case ProductRoles::CategoryIdRole:
        return product.category().id();

    case ProductRoles::CategoryKeyRole:
        return QString::fromStdString(std::string(product.category().key()));

    case ProductRoles::CategoryNameRole:
        return QString::fromStdString(std::string(product.category().name()));

    default:
        return {};
    }
}

QHash<int, QByteArray> ProductListModel::roleNames() const
{
    return {
        { ProductRoles::ProductRowRole,   "productRow"   },
        { ProductRoles::NameRole,         "name"         },
        { ProductRoles::SizeRole,         "size"         },
        { ProductRoles::PriceRole,        "price"        },
        { ProductRoles::CategoryIdRole,   "categoryId"   },
        { ProductRoles::CategoryKeyRole,  "categoryKey"  },
        { ProductRoles::CategoryNameRole, "categoryName" }
    };
}

QVariantList ProductListModel::categoryIds() const
{
    QVariantList list;

    for (int categoryId : m_categories)
        list.append(categoryId);

    return list;
}

QString ProductListModel::categoryName(int categoryId) const
{
    if (m_products == nullptr)
        return {};

    for (const SoldProduct &product : *m_products) {
        if (product.category().id() == categoryId) {
            return QString::fromStdString(std::string(product.category().name()));
        }
    }

    return {};
}

QString ProductListModel::categoryKey(int categoryId) const
{
    if (m_products == nullptr)
        return {};

    for (const SoldProduct &product : *m_products) {
        if (product.category().id() == categoryId) {
            return QString::fromStdString(std::string(product.category().key()));
        }
    }

    return {};
}