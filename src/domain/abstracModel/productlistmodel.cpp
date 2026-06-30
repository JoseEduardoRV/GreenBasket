#include "productlistmodel.h"

ProductListModel::ProductListModel(const QList<ProductGroup> *submenus, QObject *parent)
    : QAbstractListModel{parent}
    , m_submenus{submenus}
{

}

void ProductListModel::updateCategories()
{
    emit categoriesChanged();
    qDebug() << "GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG";
}



void ProductListModel::setProducts(const QList<ProductGroup> &submenu)
{
    beginResetModel();
    // m_submenu = submenu;
    endResetModel();
}


QVariant ProductListModel::data(const QModelIndex &index, int role) const
{
    if (m_submenus == nullptr)
        return {};

    if (!index.isValid())
        return {};

    if (index.row() < 0 || index.row() >= m_submenus->size())
        return {};

    const ProductGroup &submenu = m_submenus->at(index.row());

    // switch (role) {
    // case NameRole:
    //     return submenu.name();
    // case IdRole:
    //     return submenu.id();
    // case ItemsRole:
    //     return submenu.products();
    // }
    return {};
}

QHash<int, QByteArray> ProductListModel::roleNames() const
{
    return {};
    // return {
    //     { NameRole, "name" },
    //     { IdRole, "id" },
    //     { ItemsRole, "items" }
    // };
}

QVariantList ProductListModel::categoryIds() const
{
    QVariantList list;

    // for (int categoryId : m_categories)
    //     list.append(categoryId);

    return list;
}

QString ProductListModel::categoryName(int categoryId) const
{
    // if (m_products == nullptr)
    //     return {};

    // for (const SoldProduct &product : *m_products) {
    //     if (product.id() == categoryId) {
    //         return QString::fromStdString(std::string(product.name()));
    //     }
    // }

    return {};
}
