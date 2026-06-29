/* Esta clase sera registrada en el motor de QML
*/

#ifndef BILL_H
#define BILL_H

#include <QObject>
#include <QDateTime>
#include <QDebug>
#include <QList>
#include "../billitem.h"

class Bill : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double total READ total NOTIFY totalChanged FINAL)
    Q_PROPERTY(QString ticketNumber READ ticketNumber NOTIFY ticketNumberChanged)
    Q_PROPERTY(QDateTime createdAt READ createdAt NOTIFY createdAtChanged)

    int m_customerIdentity; //!>Mesa/Cliente
    int m_accountLabel;     //!>Mesero/Cajero
    double m_total;

    QString m_ticketNumber;
    QDateTime m_createdAt; //!> Hora / Fecha

    QList<BillItem> m_billItems;

public:
    explicit Bill(QObject *parent = nullptr);
    ~Bill() override;

    inline double total() const { return m_total; }

    const QString &ticketNumber() const { return m_ticketNumber; }

    const QDateTime &createdAt() const { return m_createdAt; }

    const QList<BillItem> &Items() const { return m_billItems; }

    void addItem(const SoldProduct &product ,const int category);

    void addItem(const SoldProduct &product, const int category, std::size_t quantity);

    void setTicketNumber(int index);

    void setCreatedAt();

signals:
    void totalChanged();
    void ticketNumberChanged();
    void createdAtChanged();
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