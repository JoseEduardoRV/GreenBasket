#ifndef GREENBASKET_H
#define GREENBASKET_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

#include "salecontroller.h"
#include "menucontroller.h"
#include "usercontroller.h"
#include "inventorycontroller.h"

class GreenBasket : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

    Q_PROPERTY(SaleController* sale READ sale CONSTANT)
    Q_PROPERTY(MenuController* menu READ menu CONSTANT)
    Q_PROPERTY(UserController* users READ users CONSTANT)
    Q_PROPERTY(InventoryController* inventory READ inventory CONSTANT)

public:
    explicit  GreenBasket(QObject *parent = nullptr );

    ~GreenBasket() = default;

    SaleController *sale() { return &m_sale; }
    MenuController *menu() { return &m_menu; }
    UserController *users() { return &m_users; }
    InventoryController *inventory() { return &m_inventory; }

private:
    SaleController m_sale;
    MenuController m_menu;
    UserController m_users;
    InventoryController m_inventory;
};

#endif // GREENBASKET_H

// 1. TicketList/Menu crean sus wrappers internamente.
//                 2. QML nunca recibe ni pasa punteros del dominio puro.
//                 3. Eliminar índices internos ocultos.
//                 4. Usar métodos con parámetros claros.
//                 5. Unificar nombres.
//                 6. GreenBasket concentra los casos de uso.
//                 7. Wrappers QML marcados como no-creables desde QML.
