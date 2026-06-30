#include "menu.h"
#include "src/domain/sectioninfo.h"

Menu::Menu(QObject *parent) : QObject{parent}
{
    //Consideraciones pendientes
    //Opción A: si ya hay datos, no volver a cargar
    //Opción B: limpiar la lista antes de cargar.

    int c {1};
    addSubmenu(
        ProductGroup(
            SectionInfo("hot-drink", c),
            std::list<ProductList> {
                ProductList(Product(1001, "Cafe"), 20.50f, "16 Oz"),
                ProductList(Product(1002, "Cafe"), 26.50f, "20 Oz"),
                ProductList(Product(1003, "Cafe"), 32.50f, "24 Oz")}));

    c = 2;
    addSubmenu(
        ProductGroup(
            SectionInfo("cold-drink", c),
            std::list<ProductList> {
                ProductList(Product(1004, "Agua"), 10.50f, "350ml"),
                ProductList(Product(1005, "Agua"), 16.50f, "500ml"),
                ProductList(Product(1006, "Agua"), 26.50f, "1L") }));

    addSubmenu(
        ProductGroup(
            SectionInfo("cold-drink", c),
            std::list<ProductList> {
                ProductList(Product(1007, "Agua fresca"), 13.50f, "16 Oz"),
                ProductList(Product(1008, "Agua fresca"), 17.50f, "20 Oz"),
                ProductList(Product(1009, "Agua fresca"), 28.50f, "24 Oz") }));

    c = 2;
    addSubmenu(
        ProductGroup(
            SectionInfo(
                "cold-drink", c),
            std::list<ProductList> {
                ProductList(Product(1010, "juge"), 25.50f, "16 Oz"),
                ProductList(Product(1011, "juge"), 35.50f, "20 Oz"),
                ProductList(Product(1012, "juge"), 45.50f, "24 Oz") }));

    c = 4;
    addSubmenu(
        ProductGroup(
            SectionInfo("healthy-food", c),
            std::list<ProductList> {
                ProductList(Product(1010, "Ensalada"), 25.50f, "Small"),
                ProductList(Product(1011, "Ensalada"), 35.50f, "Medium"),
                ProductList(Product(1012, "Ensalada"), 45.50f, "Large") }));

    c = 5;
    addSubmenu(
        ProductGroup(
            SectionInfo("Italian fast-food", c),
            std::list<ProductList> {
                ProductList(Product(1013, "Baguette"), 75.50f, "Pollo"),
                ProductList(Product(1014, "Baguette"), 85.50f, "Combinado"),
                ProductList(Product(1015, "Baguette"), 95.50f, "Milaneza"), }));

    addSubmenu(
        ProductGroup(
            SectionInfo("Italian fast-food", c),
            std::list<ProductList> {
                ProductList(Product(1015, "Baguette"), 95.50f, "Milaneza") }));

    qDebug() << "*** Building the Menu *** " << this;
}

Menu::~Menu()
{
    //Se debe de gestionar la memoria de los contenedores sea QList o QVector etc.
    qDebug() << "*** detroying the Menu *** " << this;
}

void Menu::addSubmenu(const ProductGroup &newSubmenu)
{
    ProductGroup *submenu = findSubmenu(newSubmenu);

    if (submenu) {
        addProduct(submenu, newSubmenu);
    } else {
        m_submenus.push_back(newSubmenu);
    }
}

ProductGroup *Menu::findSubmenu(const ProductGroup &newSubmenu)
{
    ProductGroup *submenu { nullptr };

    for (ProductGroup &item : m_submenus) {
        if (item.id() == newSubmenu.id()) {
            submenu = &item;
            break;
        }
    }

    return submenu;
}

void Menu::addProduct(ProductGroup *submenu, const ProductGroup &newSubmenu)
{
    if (submenu) {
        for (const ProductList &item : newSubmenu.products()) {
            submenu->addProduct(item);
        }
    }
}

QDebug operator<<(QDebug debug, const Menu &menu)
{
    debug << "---                     Menu                     ---" << Qt::endl;
    foreach (const auto &m, menu.submenus()) {
        debug << Qt::endl << Qt::endl << "---" << m.name() << m.id() << Qt::endl << Qt::endl;
        foreach (const auto i, m.products())
            debug << "---" << i.name() << i.presentation() << "$" << i.salePrice() << Qt::endl;
    }
    return debug;
}
