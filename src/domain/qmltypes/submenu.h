#ifndef SUBMENU_H
#define SUBMENU_H

#include <QObject>

class SubMenu : public QObject
{
    Q_OBJECT

public:
    SubMenu(QObject *parent = nullptr);
};

#endif // SUBMENU_H
