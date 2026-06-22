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
    Q_INVOKABLE void addProduct();
    /*Q_INVOKABLE*/ void changeBill(){}
    Q_INVOKABLE void closeBill();

    Q_INVOKABLE void addDrink(int index, int quantity)
    {
        if (m_bill == nullptr)
            return;

        if (quantity <= 0)
            return;

        if (index < 0 || index >= m_menu.drinks().size())
            return;

        m_bill->addItem(m_menu.drinks().at(index), static_cast<std::size_t>(quantity));
    }

    Q_INVOKABLE void addFood(int index, int quantity)
    {
        if (m_bill == nullptr)
            return;

        if (quantity <= 0)
            return;

        if (index < 0 || index >= m_menu.drinks().size())
            return;

        m_bill->addItem(m_menu.food().at(index), static_cast<std::size_t>(quantity));
    }

    Q_INVOKABLE void addDessert(int index, int quantity)
    {
        if (m_bill == nullptr)
            return;

        if (quantity <= 0)
            return;

        if (index < 0 || index >= m_menu.drinks().size())
            return;

        m_bill->addItem(m_menu.desserts().at(index), static_cast<std::size_t>(quantity));
    }

signals:
    void paidBill(); // Esta señal desencadena todos los proceso necesarion para registrar que la cuenta debe de cobrar y se esta cobrando
};

#endif // SALE_H
