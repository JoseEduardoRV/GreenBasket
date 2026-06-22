#ifndef MENU_H
#define MENU_H

#include <QAbstractListModel>
#include "../abstracModel/productlistmodel.h"

#include <QObject>
#include <QDebug>
#include <QList>

#include "../soldproduct.h"

class Menu : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QAbstractListModel* drinksModel   READ drinksModel   CONSTANT)
    Q_PROPERTY(QAbstractListModel* foodModel     READ foodModel     CONSTANT)
    Q_PROPERTY(QAbstractListModel* dessertsModel READ dessertsModel CONSTANT)

    QList<SoldProduct> m_drinks;
    QList<SoldProduct> m_food;
    QList<SoldProduct> m_desserts;

    ProductListModel m_drinksModel;
    ProductListModel m_foodModel;
    ProductListModel m_dessertsModel;

public:
    explicit Menu(QObject *parent = nullptr);
    ~Menu() override;

    /*Aqui va el argumenteo para pasarle el archivo JSOM de bebidas*/
    void loadDrink();
    /*Aqui va el argumenteo para pasarle el archivo JSOM de alimentos*/
    void loadFood();
    /*Aqui va el argumenteo para pasarle el archivo JSOM de alimentos*/
    void loadDesserts();

    const QList<SoldProduct> &drinks()   const { return m_drinks;   }
    const QList<SoldProduct> &food()     const { return m_food;     }
    const QList<SoldProduct> &desserts() const { return m_desserts; }

    QAbstractListModel *drinksModel()   { return &m_drinksModel;   }
    QAbstractListModel *foodModel()     { return &m_foodModel;     }
    QAbstractListModel *dessertsModel() { return &m_dessertsModel; }

signals:
};

inline QDebug operator<<(QDebug debug, const Menu &menu)
{
    debug << "-------------- Menu  class -----------------------" << Qt::endl;
    debug << "--------------   bebidas   -----------------------" << Qt::endl;
    foreach (const SoldProduct &p, menu.drinks()) {
        debug << p.name() << p.size().toString() << p.price() << Qt::endl;
    }
    debug << "--------------   Alimentos   -----------------------" << Qt::endl;
    foreach (const SoldProduct &p, menu.food()) {
        debug << p.name() << p.size().toString() << p.price() << Qt::endl;
    }
    debug << "--------------    Postres    -----------------------" << Qt::endl;
    foreach (const SoldProduct &p, menu.desserts()) {
        debug << p.name() << p.size().toString() << p.price() << Qt::endl;
    }
    return debug;
}
#endif // MENU_H
