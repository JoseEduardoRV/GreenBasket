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

    Q_PROPERTY(double total READ total NOTIFY totalChanged)
    Q_PROPERTY(double subTotal READ subTotal NOTIFY subTotalChanged)
    Q_PROPERTY(QString ticketNumber READ ticketNumber CONSTANT)
    Q_PROPERTY(QDateTime createdAt READ createdAt CONSTANT)
    Q_PROPERTY(BillStatus status READ status NOTIFY statusChanged)
/*  Estos datos seran obtenidos cunado se tenga el usuarios que abrió la cuenta (mesero/cliente)
    int m_customerId;   //!>Mesa/Cliente
    int m_waiterId;     //!>Mesero/Cajero
    int m_cashierId;    //!>Cajero
*/
    double m_total;
    double m_subTotal;

    QString m_ticketNumber;
    QDateTime m_createdAt; //!> Hora / Fecha
    QDate m;

    QList<BillItem> m_billItems;

    BillItem *findItemByProduct(const ProductList *product);

    void recalculateTotals();

public:

    enum BillStatus
    {
        None,
        Active,     // Cuenta activa
        Suspended,  // Cuenta suspendida/en espera
        ReadyToPay, // Lista para cobrar
        Paid,       // Cobrada
        Canceled,   // Cuenta Cancelada
        Refunded    // Reembolsada
    }; Q_ENUM(BillStatus)

    explicit Bill(QObject *parent = nullptr);
    ~Bill() override;

    double total() const { return m_total; }

    double subTotal() const { return m_subTotal; }

    BillStatus status() const { return m_status; }

    const QString &ticketNumber() const { return m_ticketNumber; }

    const QDateTime &createdAt() const { return m_createdAt; }

    const QList<BillItem> &Items() const { return m_billItems; }

    void addItem(const ProductList &product);

    void addItem(const ProductList &product, std::size_t quantity);

    void changeItemQuantity(const ProductList &product, std::size_t quantity);

    void changeStatus(BillStatus newStatus);


signals:
    void totalChanged(double);
    void subTotalChanged(double);
    void statusChanged();

private:
    BillStatus m_status;    
};

inline QDebug operator<<(QDebug debug, const Bill &bill)
{
    debug << "-------------- Bill -----------------------" << Qt::endl;

    foreach (auto p, bill.Items())
        debug << p.productName() << " $" << p.unitPrice() << " cant."
              << p.quantity() << " subtotal: $"<< p.subtotal() << Qt::endl;

    debug << "Total:           " << bill.total()      << Qt::endl;
    return debug;
}

#endif // BILL_H