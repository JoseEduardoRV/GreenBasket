/*
 * 1. Acciones de navegación
   showMenu()
   showTickets()

2. Acciones de estado de venta
   openBill()
   cancelBill()
   payBill()

3. Acciones de contenido
   addProductToCurrentBill(...)
   removeProductFromCurrentBill(...)
   changeQuantity(...)

*************************************************************************************************
GreenBasket
  -> punto de entrada global

SaleController
  -> controla el flujo de venta actual

MenuController
  -> expone productos/submenús

TicketList / WTicket
  -> expone tickets y ticket actual


 */


#ifndef SALECONTROLLER_H
#define SALECONTROLLER_H

#include <QObject>
#include <QList>
#include <QString>
#include <QtQml/qqmlregistration.h>

#include "../sublist.h"

class SaleController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("SaleController is created by GreenBasket")

    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int itemCount READ itemCount NOTIFY listChanged)

    int m_index;
    SubList m_sublist;

    int index() const { return m_index; }

public:
    explicit  SaleController(QObject *parent = nullptr);

    SaleController(SubList sublist, QObject *parent = nullptr);

    ~SaleController() override = default;

    int id() const;

    QString name() const;

    int itemCount() const;

    void addProducto(Product* newProduct);

    Q_INVOKABLE QString productName() const;
    Q_INVOKABLE QString productPresentation() const;
    Q_INVOKABLE double productPrice() const;

    void selecteItem(const int index);


    //****************************   Logica de negocio  *******************************

    Q_INVOKABLE void openBill();

    Q_INVOKABLE void cancelBill();

    Q_INVOKABLE void getPaidBill();

    Q_INVOKABLE void showMenu();

    Q_INVOKABLE void showTickets();

    Q_INVOKABLE void changeUser();

    //****************************************************************************

private:
    static QString toQString(std::string_view value);

signals:
    void listChanged();
};

#endif // SALECONTROLLER_H
