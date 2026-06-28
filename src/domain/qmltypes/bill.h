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

    QList<BillItem> m_billItems;

public:
    explicit Bill(QObject *parent = nullptr);
    ~Bill() override;

    inline double total() const { return m_total; }

    const QList<BillItem> &Items() const { return m_billItems; }

    void addItem(const SoldProduct &product ,const int category);
    void addItem(const SoldProduct &product, const int category, std::size_t quantity);

signals:
};

inline QDebug operator<<(QDebug debug, const Bill &bill)
{
    debug << "-------------- Bill -----------------------" << Qt::endl;

    foreach (auto p, bill.Items())
        debug << p.name() << " $" << p.price() << " Pz" << p.quantity() << Qt::endl;

    debug << "Total:           " << bill.total()      << Qt::endl;
    return debug;
}

#endif // BILL_H