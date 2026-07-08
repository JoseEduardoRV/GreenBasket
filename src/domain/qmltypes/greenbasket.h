#ifndef GREENBASKET_H
#define GREENBASKET_H

#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>

#include "src/domain/qmltypes/ticketlist.h"
#include "src/domain/qmltypes/menu.h"

class GreenBasket : public QObject
{
    Q_OBJECT

    Menu menu;
    TicketList tickets;

public:
    explicit GreenBasket(QQmlApplicationEngine &engine, QObject *parent = nullptr);

    Q_INVOKABLE void openBill();
    Q_INVOKABLE void cancelBill();
    Q_INVOKABLE void getPaidBill();
    Q_INVOKABLE void showMenu();
    Q_INVOKABLE void showTickets();
    Q_INVOKABLE void changeUser();

signals:
};

#endif // GREENBASKET_H
