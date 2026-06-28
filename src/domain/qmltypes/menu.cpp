#include "menu.h"
#include "src/domain/productcategory.h"

Menu::Menu(QObject *parent) : QObject{parent}
{
    qDebug() << "*** Building the Menu *** " << this;
    //m_productsModel.setProducts(&m_products);
}

Menu::~Menu()
{
    //Se debe de gestionar la memoria de los contenedores sea QList o QVector etc.
    qDebug() << "*** detroying the Menu *** " << this;
}

void Menu::loadProducts() // Esta funcion solo es para depurar
{
    //Consideraciones pendientes
    //Opción A: si ya hay datos, no volver a cargar
    //Opción B: limpiar la lista antes de cargar.

    qDebug() << "*** Loading drinks to Menu *** ";

     // Submenu(const ProductCategory &category, const std::vector<SoldProduct> &products);

    int c {1};
    addSubmenu(Submenu(ProductCategory("hot-drink", c), std::vector<SoldProduct> { SoldProduct(Product(1001, "Cafe"), 20.50f, "16 Oz"),
                                                                                   SoldProduct(Product(1002, "Cafe"), 26.50f, "20 Oz"),
                                                                                   SoldProduct(Product(1003, "Cafe"), 32.50f, "24 Oz") }));
        c = 2;
    addSubmenu(Submenu(ProductCategory("cold-drink", c), std::vector<SoldProduct> { SoldProduct(Product(1004, "Agua"), 10.50f, "350ml"),
                                                                                    SoldProduct(Product(1005, "Agua"), 16.50f, "500ml"),
                                                                                    SoldProduct(Product(1006, "Agua"), 26.50f, "1L") }));
    addSubmenu(Submenu(ProductCategory("cold-drink", c), std::vector<SoldProduct> { SoldProduct(Product(1007, "Agua fresca"), 13.50f, "16 Oz"),
                                                                                    SoldProduct(Product(1008, "Agua fresca"), 17.50f, "20 Oz"),
                                                                                    SoldProduct(Product(1009, "Agua fresca"), 28.50f, "24 Oz") }));
        c = 2;
    addSubmenu(Submenu(ProductCategory("cold-drink", c), std::vector<SoldProduct> { SoldProduct(Product(1010, "juge"), 25.50f, "16 Oz"),
                                                                                    SoldProduct(Product(1011, "juge"), 35.50f, "20 Oz"),
                                                                                    SoldProduct(Product(1012, "juge"), 45.50f, "24 Oz") }));
    qDebug() << "*** Loading food to Menu *** ";
    c = 4;
    addSubmenu(Submenu(ProductCategory("healthy-food", c), std::vector<SoldProduct> { SoldProduct(Product(1010, "Ensalada"), 25.50f, "Small"),
                                                                                      SoldProduct(Product(1011, "Ensalada"), 35.50f, "Medium"),
                                                                                      SoldProduct(Product(1012, "Ensalada"), 45.50f, "Large") }));
        c = 5;
    addSubmenu(Submenu(ProductCategory("Italian fast-food", c), std::vector<SoldProduct> { SoldProduct(Product(1013, "Baguette"), 75.50f, "Pollo"),
                                                                                           SoldProduct(Product(1014, "Baguette"), 85.50f, "Combinado"),
                                                                                           SoldProduct(Product(1015, "Baguette"), 95.50f, "Milaneza"), }));
    addSubmenu(Submenu(ProductCategory("Italian fast-food", c), std::vector<SoldProduct> { SoldProduct(Product(1015, "Baguette"), 95.50f, "Milaneza") }));
}

void Menu::addSubmenu(const Submenu &newSubmenu)
{
    Submenu *submenu{nullptr};

    for (Submenu &item : m_submenus) {
        if (item.id() == newSubmenu.id()) {
            submenu = &item;
            break;
        }
    }

    if (submenu) {
        for (const SoldProduct &item : newSubmenu.products()) {
            submenu->addProduct(item);
        }
    } else {
        m_submenus.push_back(newSubmenu);
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
