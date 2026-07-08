#ifndef WTICKET_H
#define WTICKET_H

#include <QObject>
#include <QString>

#include "../ticket.h"

class WTicket : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString ticketNumber READ ticketNumber CONSTANT)
    Q_PROPERTY(QString date READ date CONSTANT)
    Q_PROPERTY(double tax READ tax NOTIFY taxChanged)
    Q_PROPERTY(double subtotal READ subtotal NOTIFY subtotalChanged)
    Q_PROPERTY(double total READ total NOTIFY totalChanged)
    Q_PROPERTY(int itemCount READ itemCount NOTIFY listChanged)

    Ticket m_ticket;

public:
    explicit WTicket(QObject *parent = nullptr);

    ~WTicket() = default;

    QString ticketNumber() const;

    QString date() const;

    double tax() const;

    double subtotal() const;

    double total() const;

    int itemCount() const;

    void addProducto(TicketItem *newProduct);

    Q_INVOKABLE QString productName(const int index) const;
    Q_INVOKABLE QString productPresentation(const int index) const;
    Q_INVOKABLE double productPrice(const int index) const;
    Q_INVOKABLE int quantity(const int index) const;
    Q_INVOKABLE double subtotal(const int index) const;

private:
    static QString toQString(std::string_view value);

signals:
    void taxChanged();
    void subtotalChanged();
    void totalChanged();
    void listChanged();
};

#endif // WTICKET_H
