
/*El siguiente texto es para redactar la descripción general de la clase.
 * Menu
→ recibe la lista de productos.
→ administra el modelo para QML.
→ permite buscar productos.


Falta codificar
ProductProvider / Repository / Loader
→ obtiene productos desde JSON, SQLite, archivo o memoria.


 */

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
    Q_PROPERTY(QAbstractListModel* productsModel READ productsModel CONSTANT)

    QList<SoldProduct> m_products;
    ProductListModel m_productsModel;

public:
    explicit Menu(QObject *parent = nullptr);
    ~Menu() override;

    /*Aqui va el argumenteo para pasarle el archivo JSOM de bebidas*/
    void loadDrink();
    /*Aqui va el argumenteo para pasarle el archivo JSOM de alimentos*/
    void loadFood();
    /*Aqui va el argumenteo para pasarle el archivo JSOM de alimentos*/
    void loadDesserts();

    const SoldProduct *productAtRow(int row) const
    {
        if (row < 0 || row >= m_products.size())
            return nullptr;

        return &m_products.at(row);
    }

    const QList<SoldProduct> &products() const { return m_products;   }

    QAbstractListModel *productsModel() { return &m_productsModel;   }

signals:
};

inline QDebug operator<<(QDebug debug, const Menu &menu)
{
    debug << "-------------- Menu  class -----------------------" << Qt::endl;
    debug << "--------------   bebidas   -----------------------" << Qt::endl;
    foreach (const SoldProduct &p, menu.products())
        debug << p.name() << p.size().toString() << p.price() << Qt::endl;
    return debug;
}
#endif // MENU_H
