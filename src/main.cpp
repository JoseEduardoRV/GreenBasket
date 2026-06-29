#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "src/domain/qmltypes/sale.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    /////                     /////
    QObject parent;

    Sale sale(&parent);

    QQmlApplicationEngine engine;

/* =========================================================================
       REGISTRO DE TIPOS C++ PARA QML (Colócalo aquí)
   =========================================================================*/

    qmlRegisterUncreatableType<Bill>(
        "GreenBasket.Domain",  // Nombre del módulo a importar en QML
        1, 0,                  // Versión Mayor (1), Versión Menor (0)
        "Bill",                // Nombre del tipo en QML
        "Bill is created from C++" // Mensaje de error si QML intenta instanciarlo
        );






    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    //Se registran los tipos qml debe de concer antes de que se lance main

    //engine.rootContext()->setContextProperty("menuController", &menu);
    engine.rootContext()->setContextProperty("saleController", &sale);

    engine.loadFromModule("GreenBasket", "Main");

    return QGuiApplication::exec();
}
