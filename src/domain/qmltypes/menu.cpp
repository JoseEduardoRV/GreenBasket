#include "menu.h"
#include "src/domain/menuproduct.h"

Menu::Menu(QObject *parent) : QObject{parent}
{
    //Consideraciones pendientes
    //Opción A: si ya hay datos, no volver a cargar
    //Opción B: limpiar la lista antes de cargar.

    addSubmenu(
        new SubMenu(
            SubList(101, "cold-drink",
                std::list<Product*> {
                    new MenuProduct(1001, "Cafe", "16 Oz", 20.50f),
                    new MenuProduct(1002, "Cafe", "20 Oz", 26.50f),
                    new MenuProduct(1003, "Cafe", "24 Oz", 32.50f)
                })));


    addSubmenu(
        new SubMenu(
            SubList(102, "cold-drink",
                std::list<Product*> {
                    new MenuProduct(1004, "Agua", "350ml", 10.50f),
                    new MenuProduct(1005, "Agua", "500ml", 16.50f),
                    new MenuProduct(1006, "Agua", "1L",    26.50f)
                })));
    addSubmenu(
        new SubMenu(
            SubList(102, "cold-drink",
                std::list<Product*> {
                    new MenuProduct(1007, "Agua fresca", "16 Oz", 13.50f),
                    new MenuProduct(1008, "Agua fresca", "20 Oz", 17.50f),
                    new MenuProduct(1009, "Agua fresca", "24 Oz", 28.50f)
                })));
    addSubmenu(
        new SubMenu(
            SubList(102, "cold-drink",
                std::list<Product*> {
                    new MenuProduct(1010, "juge", "16 Oz", 25.50f),
                    new MenuProduct(1011, "juge", "20 Oz", 35.50f),
                    new MenuProduct(1012, "juge", "24 Oz", 45.50f)
                })));
    addSubmenu(
        new SubMenu(
            SubList(103, "healthy-food",
                std::list<Product*> {
                    new MenuProduct(1010, "Ensalada", "Small",  25.50f),
                    new MenuProduct(1011, "Ensalada", "Medium", 35.50f),
                    new MenuProduct(1012, "Ensalada", "Large",  45.50f)
                })));
    addSubmenu(
        new SubMenu(
            SubList(104, "Italian fast-food",
                std::list<Product*> {
                    new MenuProduct(1013, "Baguette", "Pollo", 75.50f),
                    new MenuProduct(1014, "Baguette", "Combinado", 85.50f),
                    new MenuProduct(1015, "Baguette", "Milaneza", 95.50f)
                })));
    addSubmenu(
        new SubMenu(
            SubList(104, "Italian fast-food",
                std::list<Product*> {
                    new MenuProduct(1015, "Baguette", "Milaneza", 95.50f)
                })));

    qDebug() << "*** Building the Menu *** " << this;
}

Menu::~Menu()
{
    m_submenus.clear();
    qDebug() << "*** detroying the Menu *** " << this;
}

QQmlListProperty<SubMenu> Menu::submenus()
{
    return QQmlListProperty<SubMenu>(this, &m_submenus);
}

void Menu::addSubmenu(SubMenu *newSubmenu)
{
    if (!newSubmenu)
        return;

    if (!newSubmenu->parent())
        newSubmenu->setParent(this);

    qDebug() << Q_FUNC_INFO << " : SubMenu : " << newSubmenu;

    m_submenus.emplaceBack(newSubmenu);
    emit submenusChanged();
}


SubMenu *Menu::findSubmenu(const SubMenu *newSubmenu) const
{
    if (!newSubmenu)
        return nullptr;

    for (SubMenu *item : m_submenus) {
        if (item->id() == newSubmenu->id()) {
            return item;
        }
    }

    return nullptr;
}
