#ifndef SUBMENU_H
#define SUBMENU_H

#include <QObject>
#include <QString>
#include <QList>

#include "../sublist.h"

class SubMenu : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int itemCount READ itemCount NOTIFY listChanged)

    SubList m_sublist;

public:
    SubMenu(SubList sublist, QObject *parent = nullptr);

    ~SubMenu() override = default;

    int id() const;

    QString name() const;

    int itemCount() const;

    void addProducto(Product* newProduct);

    Q_INVOKABLE QString productName(const int index) const;
    Q_INVOKABLE QString productPresentation(const int index) const;
    Q_INVOKABLE double productPrice(const int index) const;

private:
    static QString toQString(std::string_view value);

signals:
    void listChanged();
};

#endif // SUBMENU_H
