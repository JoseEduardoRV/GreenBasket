#ifndef STOCK_H
#define STOCK_H

#include <QObject>

class Stock : public QObject
{
    Q_OBJECT

    double number;
    char unit;

public:
    explicit Stock(QObject *parent = nullptr);

signals:
};

#endif // STOCK_H
