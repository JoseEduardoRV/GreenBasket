#ifndef STOCK_H
#define STOCK_H

#include <QObject>

#include "../stockproduct.h"

class Stock : public QObject
{
    Q_OBJECT

    double number;
    char unit;
    StockProduct product;

public:
    explicit Stock(QObject *parent = nullptr);

signals:
};

#endif // STOCK_H
