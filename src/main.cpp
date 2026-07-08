#include <memory>

#include <QGuiApplication>

#include "src/domain/qmltypes/greenbasket.h"

int main(int argc, char *argv[])
{
    std::locale::global(std::locale("C"));

    QGuiApplication app(argc, argv);

    auto engine = std::make_unique<QQmlApplicationEngine>();
    auto greenBasket = std::make_unique<GreenBasket>(*engine);

    QObject::connect(
        engine.get(),
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine->rootContext()->setContextProperty("greenBasket", greenBasket.get());

    engine->loadFromModule("GreenBasket", "Main");

    const int result = QGuiApplication::exec();

    engine.reset();
    greenBasket.reset();

    return result;
}
