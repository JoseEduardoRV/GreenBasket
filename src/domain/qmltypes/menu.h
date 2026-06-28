
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

#include "../submenu.h"

class Menu : public QObject
{
    Q_OBJECT

    QList<Submenu> m_submenus;

public:
    explicit Menu(QObject *parent = nullptr);
    ~Menu() override;

    void loadProducts();

    void addSubmenu(const Submenu &newSubmenu);

    const QList<Submenu> &submenus() const { return m_submenus; }

signals:
};

QDebug operator<<(QDebug debug, const Menu &menu);
#endif // MENU_H
