#ifndef INVENTORYCONTROLLER_H
#define INVENTORYCONTROLLER_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

class InventoryController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("InventoryController is created by GreenBasket")

public:
    explicit InventoryController(QObject *parent = nullptr);

signals:
};

#endif // INVENTORYCONTROLLER_H
