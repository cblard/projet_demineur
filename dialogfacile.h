#ifndef DIALOGFacile_H
#define DIALOGFacile_H

#include <QDialog>
#include "jeufacile.h"

namespace Ui {
class dialogFacile;
}

class dialogFacile : public QDialog
{
    Q_OBJECT

public:
    explicit dialogFacile(QWidget *parent = nullptr);
    dialogFacile(vector<vector<char>> solution, QWidget *parent=nullptr);
    ~dialogFacile();
    jeuFacile jeuFac;
    vector<vector<char>> solution;

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogFacile *ui;
};

#endif // DIALOGFacile_H
