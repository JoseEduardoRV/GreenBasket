
/*El siguiente texto es para redactar la descripción general de la clase.
 * MenuController
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
#include <QtQml/qqmlregistration.h>

#include "salecontroller.h"

class MenuController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("MenuController is created by GreenBasket")

    Q_PROPERTY(QQmlListProperty<SaleController> submenus READ submenus NOTIFY submenusChanged)

    QList<SaleController*> m_submenus;

public:
    explicit MenuController(QObject *parent = nullptr);
    ~MenuController() override;

    int count() const { return m_submenus.size(); }

    QQmlListProperty<SaleController> submenus();

    void addSubmenu(SaleController *newSubmenu);

signals:
    void submenusChanged();

private:
    SaleController *findSubmenu(const SaleController *newSubmenu) const;
};

#endif // MENU_H
