#ifndef PRODUCTLISTMODEL_H
#define PRODUCTLISTMODEL_H

#include <QAbstractListModel>
#include <QVariantList>
#include <QString>
#include <QList>

#include "../submenu.h"

class ProductListModel : public QAbstractListModel
{
    Q_OBJECT

    const QList<ProductGroup> *m_submenus;

public:
    enum ProductRoles {
        ProductRowRole = Qt::UserRole + 1,
        NameRole,
        PriceRole,
        CategoryIdRole,
        CategoryNameRole
    };

    explicit ProductListModel(const QList<ProductGroup> *submenus = nullptr, QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override
    {
        if (parent.isValid())
            return 0;

        if (m_submenus == nullptr)
            return 0;

        return m_submenus->size();
    }

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


    void updateCategories();

    void setProducts(const QList<ProductGroup> &submenu);




    QHash<int, QByteArray> roleNames() const override;

    QVariantList categoryIds() const;

    Q_INVOKABLE QString categoryName(int categoryId) const;

signals:
    void categoriesChanged();
};
#endif // PRODUCTLISTMODEL_H
