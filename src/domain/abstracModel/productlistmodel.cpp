#include "productlistmodel.h"

#include <QString>

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

    const SoldProduct &product = m_products->at(index.row());

    switch (role) {
    case NameRole:
        return QString::fromStdString(product.name());

    case SizeRole:
        return QString::fromStdString(std::string(product.size().toString()));

    case PriceRole:
        return product.price();

    default:
        return {};
    }
}

QHash<int, QByteArray> ProductListModel::roleNames() const
{
    return {
        { NameRole,  "name"  },
        { SizeRole,  "size"  },
        { PriceRole, "price" }
    };
}