/* Esta clase sera registrada en el motor de QML
*/

#ifndef BILL_H
#define BILL_H

#include <QObject>
#include <QDebug>
#include <QList>
#include "../billitem.h"

class Bill : public QObject
{
    Q_OBJECT

    double m_drinkTotal;
    double m_foodTotal;
    double m_total;

    QList<BillItem> m_billItem;

public:
    explicit Bill(QObject *parent = nullptr);
    ~Bill() override;

    inline double total()      const { return m_total;      }
    inline double drinkTotal() const { return m_drinkTotal; }
    inline double foodTotal()  const { return m_foodTotal;  }

    const QList<BillItem> &Items() const { return m_billItem; }

    void addItem(const SoldProduct &item, std::size_t quantity = 1);

    void deleteDrink(){}
    void deleteFood(){}
    void calculateTotal();

signals:
};

inline QDebug operator<<(QDebug debug, const Bill &bill)
{
    debug << "-------------- Bill -----------------------" << Qt::endl;

    foreach (auto p, bill.Items())
        debug << p.name() << " $" << p.price() << " Pz" << p.quantity() << Qt::endl;

    debug << "Total de comida: " << bill.foodTotal()  << Qt::endl;
    debug << "Total de bebidas:" << bill.drinkTotal() << Qt::endl;
    debug << "Total:           " << bill.total()      << Qt::endl;
    return debug;
}

#endif // BILL_H