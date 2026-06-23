#include "menu.h"

Menu::Menu(QObject *parent)
    : QObject{parent}
{
    qDebug() << "*** Building the Menu *** " << this;
    m_productsModel.setProducts(&m_products);
}

Menu::~Menu()
{
    qDebug() << "*** detroying the Menu *** " << this;
}

void Menu::loadDrink()
{
    //Consideraciones pendientes
    //Opción A: si ya hay datos, no volver a cargar
    //Opción B: limpiar la lista antes de cargar.

    qDebug() << "*** Loading drinks to Menu *** ";

    m_products.append(SoldProduct(ProductCategory("hot-drink", "16 oz",  1), "Cafe", 26.50f));
    m_products.append(SoldProduct(ProductCategory("hot-drink", "20 oz",  1), "Cafe", 36.50f));
    m_products.append(SoldProduct(ProductCategory("hot-drink", "24 oz",  1), "Cafe", 46.50f));

    m_products.append(SoldProduct(ProductCategory("cold-drink", "350ml", 2), "Agua", 10.50f));
    m_products.append(SoldProduct(ProductCategory("cold-drink", "500ml", 2), "Agua", 16.50f));
    m_products.append(SoldProduct(ProductCategory("cold-drink", "1L   ", 2), "Agua", 26.50f));

    m_products.append(SoldProduct(ProductCategory("cold-drink", "16 oz", 2), "Agua fresca", 16.50f));
    m_products.append(SoldProduct(ProductCategory("cold-drink", "20 oz", 2), "Agua fresca", 26.50f));
    m_products.append(SoldProduct(ProductCategory("cold-drink", "24 oz", 2), "Agua fresca", 36.50f));

    m_products.append(SoldProduct(ProductCategory("juge", "16 oz", 3), "Jugo verde", 25.50f));
    m_products.append(SoldProduct(ProductCategory("juge", "20 oz", 3), "Jugo verde", 35.50f));
    m_products.append(SoldProduct(ProductCategory("juge", "24 oz", 3), "Jugo verde", 45.50f));

    m_productsModel.updateCategories();
}

void Menu::loadFood()
{
    //Consideraciones pendientes
    //Opción A: si ya hay datos, no volver a cargar
    //Opción B: limpiar la lista antes de cargar.

    qDebug() << "*** Loading food to Menu *** ";

    m_products.append(SoldProduct(ProductCategory("healthy-food","Small ", 4), "Ensalada", 60.00f));
    m_products.append(SoldProduct(ProductCategory("healthy-food","Medium", 4), "Ensalada", 78.00f));
    m_products.append(SoldProduct(ProductCategory("healthy-food","Large ", 4), "Ensalada", 95.00f));

    m_products.append(SoldProduct(ProductCategory("Italian fast-food"," ", 5), "Baguette Pollo    ", 80.00f));
    m_products.append(SoldProduct(ProductCategory("Italian fast-food"," ", 5), "Baguette Combinado", 85.00f));
    m_products.append(SoldProduct(ProductCategory("Italian fast-food"," ", 5), "Baguette Milaneza ", 95.00f));

    m_productsModel.updateCategories();
}

void Menu::loadDesserts()
{
    qDebug() << "*** Loading desserts to Menu *** ";

    m_productsModel.updateCategories();
}
