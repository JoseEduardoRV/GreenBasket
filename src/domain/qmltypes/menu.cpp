#include "menu.h"

Menu::Menu(QObject *parent)
    : QObject{parent}
{
    qDebug() << "*** Building the Menu *** " << this;
    m_drinksModel.setProducts(&m_drinks);
    m_foodModel.setProducts(&m_food);
    m_dessertsModel.setProducts(&m_desserts);
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

    m_drinks.append(SoldProduct("Cafe", e_size::_12oz, 16.50f, Category::Drink));
    m_drinks.append(SoldProduct("Cafe", e_size::_16oz, 22.50f, Category::Drink));
    m_drinks.append(SoldProduct("Cafe", e_size::_20oz, 28.50f, Category::Drink));

    m_drinks.append(SoldProduct("Agua fresca", e_size::_12oz, 16.50f, Category::Drink));
    m_drinks.append(SoldProduct("Agua fresca", e_size::_16oz, 22.50f, Category::Drink));
    m_drinks.append(SoldProduct("Agua fresca", e_size::_20oz, 28.50f, Category::Drink));

    m_drinks.append(SoldProduct("Jugo verde", e_size::_12oz, 16.50f, Category::Drink));
    m_drinks.append(SoldProduct("Jugo verde", e_size::_16oz, 22.50f, Category::Drink));
    m_drinks.append(SoldProduct("Jugo verde", e_size::_20oz, 28.50f, Category::Drink));
}

void Menu::loadFood()
{
    //Consideraciones pendientes
    //Opción A: si ya hay datos, no volver a cargar
    //Opción B: limpiar la lista antes de cargar.

    qDebug() << "*** Loading food to Menu *** ";

    m_food.append(SoldProduct("Ensalada", e_size::Small,  60.00f, Category::Food));
    m_food.append(SoldProduct("Ensalada", e_size::Medium, 78.00f, Category::Food));
    m_food.append(SoldProduct("Ensalada", e_size::Large,  95.00f, Category::Food));

    m_food.append(SoldProduct("Baguette Pollo",     e_size::None, 80.00f, Category::Food));
    m_food.append(SoldProduct("Baguette Combinado", e_size::None, 85.00f, Category::Food));
    m_food.append(SoldProduct("Baguette Milaneza",  e_size::None, 95.00f, Category::Food));
}

void Menu::loadDesserts()
{
    qDebug() << "*** Loading desserts to Menu *** ";
}
