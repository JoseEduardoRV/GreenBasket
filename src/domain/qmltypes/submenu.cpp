#include <utility>

#include "submenu.h"
#include "../menuproduct.h"

SubMenu::SubMenu(SubList sublist, QObject *parent)
    : QObject{ parent },
    m_sublist{ std::move(sublist) }
{

}

int SubMenu::id() const
{
    return m_sublist.id();
}

QString SubMenu::name() const
{
    return toQString(m_sublist.name());
}

int SubMenu::itemCount() const
{
    return m_sublist.itemCount();
}

void SubMenu::addProducto(Product *newProduct)
{
    if (!newProduct){
        return;
    }

    if (m_sublist.addProduct(newProduct)){
        emit listChanged();
    }
}

QString SubMenu::productName(const int index) const
{
    const Product *item = m_sublist.item(index);

    if (!item){
        return { };
    }

    return toQString(item->name());
}

QString SubMenu::productPresentation(const int index) const
{

    const Product *item = m_sublist.item(index);

    if(item){
        auto product = dynamic_cast<const MenuProduct *>(item);

        if (product){
            return toQString(product->presentation());
        }
    }

    return { };
}

double SubMenu::productPrice(const int index) const
{
    const Product *item = m_sublist.item(index);

    if(item){
        return item->unitValue();
    }

    return 0.0f;
}

QString SubMenu::toQString(std::string_view value)
{
    return QString::fromUtf8(value.data(), qsizetype(value.size()));
}
