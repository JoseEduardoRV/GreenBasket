#include "greenbasket.h"

GreenBasket::GreenBasket(QObject *parent)
    : QObject{parent}
    , m_sale{this}
    , m_menu{this}
    , m_users{this}
    , m_inventory{this}
{
        qDebug() << "GreenBasket singleton created";
}
