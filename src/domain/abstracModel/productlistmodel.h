#ifndef PRODUCTLISTMODEL_H
#define PRODUCTLISTMODEL_H

#include <QAbstractListModel>
#include <QList>

#include "../soldproduct.h"

class ProductListModel : public QAbstractListModel
{
    Q_OBJECT
    const QList<SoldProduct> *m_products;

public:
    enum ProductRoles {
        NameRole = Qt::UserRole + 1,
        SizeRole,
        PriceRole
    };

    explicit ProductListModel(QObject *parent = nullptr);

    void setProducts(const QList<SoldProduct> *products);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    QHash<int, QByteArray> roleNames() const override;

};
#endif // PRODUCTLISTMODEL_H
