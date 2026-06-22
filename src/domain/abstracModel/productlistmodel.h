#ifndef PRODUCTLISTMODEL_H
#define PRODUCTLISTMODEL_H

#include <QAbstractListModel>
#include <QList>
#include <QVariantList>
#include <QString>

#include <vector>

#include "../soldproduct.h"

class ProductListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QVariantList categoryIds READ categoryIds NOTIFY categoriesChanged)

    std::vector<int> m_categories;

    const QList<SoldProduct> *m_products;


public:
    enum ProductRoles {
        ProductRowRole = Qt::UserRole + 1,
        NameRole,
        SizeRole,
        PriceRole,
        CategoryIdRole,
        CategoryKeyRole,
        CategoryNameRole
    };

    explicit ProductListModel(QObject *parent = nullptr);

    void updateCategories();

    void setProducts(const QList<SoldProduct> *products);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

    QVariantList categoryIds() const;

    Q_INVOKABLE QString categoryName(int categoryId) const;
    Q_INVOKABLE QString categoryKey(int categoryId) const;

signals:
    void categoriesChanged();
};
#endif // PRODUCTLISTMODEL_H
