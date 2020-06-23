#ifndef DIALOGDifficile_H
#define DIALOGDifficile_H

#include <QDialog>
#include "jeudifficile.h"

namespace Ui {
class dialogDifficile;
}

class dialogDifficile : public QDialog
{
    Q_OBJECT

public:
    explicit dialogDifficile(QWidget *parent = nullptr);
    dialogDifficile(vector<vector<char>> solution, QWidget *parent=nullptr);
    ~dialogDifficile();
    jeuDifficile jeuDif;
    vector<vector<char>> solution;

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogDifficile *ui;
};

#endif // DIALOGDifficile_H
