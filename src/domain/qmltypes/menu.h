
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

#include <QObject>
#include <QDebug>
#include <QList>

#include "../productgroup.h"
#include "submenu.h"

class Menu : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QQmlListProperty<ProductGroup> bills READ bills NOTIFY billsChanged)

    QList<ProductGroup> m_submenus;

public:
    explicit Menu(QObject *parent = nullptr);
    ~Menu() override;

    void addSubmenu(const ProductGroup &newSubmenu);

    const QList<ProductGroup> &submenus() const { return m_submenus; }

signals:

private:
    ProductGroup *findSubmenu(const ProductGroup &newSubmenu);
    void addProduct(ProductGroup *submenu, const ProductGroup &newSubmenu);
};

QDebug operator<<(QDebug debug, const Menu &menu);
#endif // MENU_H
