#include "mainwindow.h"
#include <QCoreApplication>
#include <QtGui>
#include <QGridLayout>
#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
