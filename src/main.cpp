#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/domain/qmltypes/sale.h"



/*
    Menu → Catálogo disponible de productos vendibles.

    Sale
    → Controla la sesión de ventas.
    → Administra varias cuentas abiertas.

    Bill
    → Representa una cuenta individual.
    → Agrega productos del menú.
    → Calcula totales.
 */

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    /////                     /////
    QObject parent;
    Menu menu(&parent);

    menu.loadProducts();

    qDebug() << menu;

    // Sale sale(menu, &parent);

    // sale.openBill();
    // sale.closeBill();


    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    //Se registran los tipos qml debe de concer antes de que se lance main

    //engine.rootContext()->setContextProperty("menuController", &menu);
    //engine.rootContext()->setContextProperty("saleController", &sale);

    engine.loadFromModule("GreenBasket", "Main");

    return QGuiApplication::exec();
}
