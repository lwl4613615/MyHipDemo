#include "stdafx.h"
#include "myhips.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyHips w;
    w.show();
    return a.exec();
}
