#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jeumoyen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    explicit MainWindow(jeuMoyen jeuMoyen, QWidget *parent=nullptr);
    ~MainWindow();

private slots:
    void on_facile_clicked();

    void on_moyen_clicked();

    void on_difficile_clicked();

    void on_perso_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
