#include <utility>

#include <QDebug>

#include "salecontroller.h"
#include "../menuproduct.h"

SaleController::SaleController(QObject *parent)
    : QObject{ parent }
    , m_index{ 0 }
    , m_sublist { }
{

}

SaleController::SaleController(SubList sublist, QObject *parent)
    : QObject{parent}
    , m_index{0}
    , m_sublist{std::move(sublist)}
{

}

int SaleController::id() const
{
    return m_sublist.id();
}

QString SaleController::name() const
{
    return toQString(m_sublist.name());
}

int SaleController::itemCount() const
{
    return m_sublist.itemCount();
}

void SaleController::addProducto(Product *newProduct)
{
    if (!newProduct){
        return;
    }

    if (m_sublist.addProduct(newProduct)){
        emit listChanged();
    }
}

QString SaleController::productName() const
{
    const Product *item = m_sublist.item(index());

    if (!item){
        return { };
    }

    return toQString(item->name());
}

QString SaleController::productPresentation() const
{

    const Product *item = m_sublist.item(index());

    if(item){
        auto product = dynamic_cast<const MenuProduct *>(item);

        if (product){
            return toQString(product->presentation());
        }
    }

    return { };
}

double SaleController::productPrice() const
{
    const Product *item = m_sublist.item(index());

    if(item){
        return item->unitValue();
    }

    return 0.0f;
}

void SaleController::selecteItem(const int index)
{
    m_index = index;
}

void SaleController::openBill()
{
    qDebug() << Q_FUNC_INFO;
    /*
     * ¿Debe crear un Ticket nuevo?
¿Debe seleccionarlo como ticket actual?
¿Debe agregarlo a la lista de tickets abiertos?
¿Debe cambiar la pantalla?
¿Debe deshabilitar otros botones?
¿Debe emitir señales?
     */
}

void SaleController::cancelBill()
{
    qDebug() << Q_FUNC_INFO;
}

void SaleController::getPaidBill()
{
    qDebug() << Q_FUNC_INFO;
}

void SaleController::showMenu()
{
    qDebug() << Q_FUNC_INFO;
}

void SaleController::showTickets()
{
    qDebug() << Q_FUNC_INFO;
}

void SaleController::changeUser()
{
    qDebug() << Q_FUNC_INFO;
}

QString SaleController::toQString(std::string_view value)
{
    return QString::fromUtf8(value.data(), qsizetype(value.size()));
}
