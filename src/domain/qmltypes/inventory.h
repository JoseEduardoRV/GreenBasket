/* Esta clase sera registrada en el motor de QML
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>

class Inventory : public QObject
{
    Q_OBJECT
public:
    explicit Inventory(QObject *parent = nullptr);

signals:
};

#endif // INVENTORY_H
