#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

class UserController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("UserController is created by GreenBasket")

public:
    explicit UserController(QObject *parent = nullptr);

signals:
};

#endif // USERCONTROLLER_H
