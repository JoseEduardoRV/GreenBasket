#include "greenbasket.h"

#include "src/domain/qmltypes/wticket.h"


GreenBasket::GreenBasket(QQmlApplicationEngine &engine, QObject *parent)
    : QObject{parent}
    , menu(parent)
    , tickets(parent)
{
/* =========================================================================
   REGISTRO DE TIPOS C++ PARA QML (Colócalo aquí)
=========================================================================*/

    qmlRegisterUncreatableType<SubMenu>(
        "GreenBasket.Domain",         // Nombre del módulo a importar en QML
        1, 0,                         // Versión Mayor (1), Versión Menor (0)
        "SubMenu",                    // Nombre del tipo en QML
        "SubMenu is created from C++" // Mensaje de error si QML intenta instanciarlo
        );

    qmlRegisterUncreatableType<WTicket>(
        "GreenBasket.Domain",        // Nombre del módulo a importar en QML
        1, 0,                        // Versión Mayor (1), Versión Menor (0)
        "Ticket",                    // Nombre del tipo en QML
        "Ticket is created from C++" // Mensaje de error si QML intenta instanciarlo
        );

    qmlRegisterUncreatableType<TicketList>(
        "GreenBasket.Domain",            // Nombre del módulo a importar en QML
        1, 0,                            // Versión Mayor (1), Versión Menor (0)
        "TicketList",                    // Nombre del tipo en QML
        "TicketList is created from C++" // Mensaje de error si QML intenta instanciarlo
        );

/* =========================================================================
   CARGA DE TIPOS C++ PARA CONTEXTO QML (Colócalo aquí)
=========================================================================*/

    engine.rootContext()->setContextProperty("menuController", &menu);
    engine.rootContext()->setContextProperty("ticketsController", &tickets);
}

void GreenBasket::openBill()
{
    qDebug() << Q_FUNC_INFO;
}

void GreenBasket::cancelBill()
{
    qDebug() << Q_FUNC_INFO;
}

void GreenBasket::getPaidBill()
{
    qDebug() << Q_FUNC_INFO;
}

void GreenBasket::showMenu()
{
    qDebug() << Q_FUNC_INFO;
}

void GreenBasket::showTickets()
{
    qDebug() << Q_FUNC_INFO;
}

void GreenBasket::changeUser() {}
