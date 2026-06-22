/* Esta clase sera registrada en el motor de QML
*/

#ifndef SALE_H
#define SALE_H

#include <QObject>
#include <QDateTime>

#include "menu.h"
#include "bill.h"

/* Observaciones de diseño
 * Bills no deberia pertenecera a Sale? o si?
 * a la clase Sale le hace falta unatributo que haga referecnia al
 * mesero queatendio la cuenta y le falta un atributo que se llame comensal

La clase Sale nodeberia conocer a la clase menu, solo debe de conocer a bill,
como se agrega un producto a la cuenta al menu? eso se hace dese qml, en la interfaz se crear una
una lista dinamica que mjesrra los menus creados yndesd ahi sepasa una copia sea por referencia o por valor
eso depende del diseño



 
 */

class Sale : public QObject
{
    Q_OBJECT

    const Menu &m_menu;
    QList<Bill*> m_bills; // Hay que tener cuidado con este Objeto porlas copias ya que hereda de QObject
    Bill* m_bill; // apunta a la ultima cunata creada;

public:
    explicit Sale(const Menu &menu, QObject *parent = nullptr);
    ~Sale() override;

    inline const Menu  &menu()  const { return m_menu; } //probablemente se usa para QML
    /* Probablemente esta funcion desaparesca ya que se
       esta evaluando la posibilidad que la Case Menu tango
       pueda ser compatible con QML o se  use una funcion
       addProduct a la cuenta.
    */

    Q_INVOKABLE void openBill();
    /*Q_INVOKABLE*/ void changeBill(){}
    Q_INVOKABLE void closeBill();

    Q_INVOKABLE void addProductByRow(int productRow, int quantity)
    {
        if (m_bill == nullptr)
            return;

        if (quantity <= 0)
            return;

        const SoldProduct *product = m_menu.productAtRow(productRow);

        if (product == nullptr)
            return;

        m_bill->addItem(*product, static_cast<std::size_t>(quantity));
    }

signals:
    void paidBill(); // Esta señal desencadena todos los proceso necesarion para registrar que la cuenta debe de cobrar y se esta cobrando
};

#endif // SALE_H
