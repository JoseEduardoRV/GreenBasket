/* Esta clase sera registrada en el motor de QML
*/

#ifndef SALE_H
#define SALE_H

#include <QQmlListProperty>

#include "bill.h"

/* Observaciones de diseño
 * Bills no deberia pertenecera a Sale? o si?
 * a la clase Sale le hace falta unatributo que haga referecnia al
 * mesero queatendio la cuenta y le falta un atributo que se llame comensal

La clase Sale nodeberia conocer a la clase menu, solo debe de conocer a bill,
como se agrega un producto a la cuenta al menu? eso se hace dese qml, en la interfaz se crear una
una lista dinamica que mjesrra los menus creados yndesd ahi sepasa una copia sea por referencia o por valor
eso depende del diseño

Sería conveniente que QML pasará un id o apartir de una referencia pasar una copiar directamente
de MenuSubset y los modelos
→ debe recibir modelos Qt: MenuSubsetListModel y modelos de productos por submenú
 */

class Sale : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int billCount READ billCount NOTIFY billCountChanged) // Esta variable se eliminará
    Q_PROPERTY(QQmlListProperty<Bill> bills READ bills NOTIFY billsChanged)

    QList<Bill*> m_bills;
    Bill* m_editingBill;

public:
    explicit Sale(QObject *parent = nullptr);

    ~Sale() override;

    QQmlListProperty<Bill> bills() { return QQmlListProperty<Bill>(this, &m_bills); }

    int billCount() const { return m_bills.size(); }

    Q_INVOKABLE void openBill();
    Q_INVOKABLE void cancelBill(int item);
    Q_INVOKABLE void getPaidBill(int item);
    Q_INVOKABLE void showMenu();
    Q_INVOKABLE void changeUser();
    Q_INVOKABLE void selectBill(const int index);

signals:
    void billCountChanged();
    void billsChanged();
};

#endif // SALE_H
