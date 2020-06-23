#ifndef DIALOGMOYEN_H
#define DIALOGMOYEN_H

#include <QDialog>
#include "jeumoyen.h"

namespace Ui {
class dialogMoyen;
}

class dialogMoyen : public QDialog
{
    Q_OBJECT

public:
    explicit dialogMoyen(QWidget *parent = nullptr);
    dialogMoyen(vector<vector<char>> solution, QWidget *parent=nullptr);
    ~dialogMoyen();
    jeuMoyen jeuMoy;
    vector<vector<char>> solution;

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogMoyen *ui;
};

#endif // DIALOGMOYEN_H
