
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
#include <QList>
#include <QQmlListProperty>

#include "submenu.h"

class Menu : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<SubMenu> submenus READ submenus NOTIFY submenusChanged)

    QList<SubMenu*> m_submenus;

public:
    explicit Menu(QObject *parent = nullptr);
    ~Menu() override;

    int count() const { return m_submenus.size(); }

    QQmlListProperty<SubMenu> submenus();

    void addSubmenu(SubMenu *newSubmenu);

signals:
    void submenusChanged();

private:
    SubMenu *findSubmenu(const SubMenu *newSubmenu) const;
};

#endif // MENU_H
