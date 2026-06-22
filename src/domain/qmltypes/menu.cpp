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

    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Cafe", e_size::_12oz, 16.50f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Cafe", e_size::_16oz, 22.50f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Cafe", e_size::_20oz, 28.50f));

    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Agua fresca", e_size::_12oz, 16.50f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Agua fresca", e_size::_16oz, 22.50f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Agua fresca", e_size::_20oz, 28.50f));

    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Jugo verde", e_size::_12oz, 16.50f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Jugo verde", e_size::_16oz, 22.50f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 1), "Jugo verde", e_size::_20oz, 28.50f));

    m_productsModel.updateCategories();
}

void Menu::loadFood()
{
    //Consideraciones pendientes
    //Opción A: si ya hay datos, no volver a cargar
    //Opción B: limpiar la lista antes de cargar.

    qDebug() << "*** Loading food to Menu *** ";

    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 2), "Ensalada", e_size::Small,  60.00f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 2), "Ensalada", e_size::Medium, 78.00f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 2), "Ensalada", e_size::Large,  95.00f));

    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 3), "Baguette Pollo",     e_size::None, 80.00f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 3), "Baguette Combinado", e_size::None, 85.00f));
    m_products.append(SoldProduct(ProductCategory("food","Alimentos", 2), "Baguette Milaneza",  e_size::None, 95.00f));

    m_productsModel.updateCategories();
}

void Menu::loadDesserts()
{
    qDebug() << "*** Loading desserts to Menu *** ";

    m_productsModel.updateCategories();
}
