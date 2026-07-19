#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include <QObject>
#include <QtQml/qqmlregistration.h>

class SettingsController : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_UNCREATABLE("SettingsController is created by GreenBasket")

public:
    explicit SettingsController(QObject *parent = nullptr);

signals:
};

#endif // SETTINGSCONTROLLER_H
