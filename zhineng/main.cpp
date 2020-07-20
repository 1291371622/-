#include "widget.h"
#include <string.h>
#include <string.h>
#include <QApplication>
#include <math.h>
#include <Python.h>

#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
