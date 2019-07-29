#pragma once

#include <QtWidgets/QWidget>
#include "ui_myhips.h"

class MyHips : public QWidget
{
    Q_OBJECT

public:
    MyHips(QWidget *parent = Q_NULLPTR);

private:
    Ui::MyHipsClass ui;
};
