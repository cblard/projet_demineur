#ifndef DIALOGPerso_H
#define DIALOGPerso_H

#include <QDialog>
#include "jeuperso.h"

namespace Ui {
class dialogPerso;
}

class dialogPerso : public QDialog
{
    Q_OBJECT

public:
    explicit dialogPerso(QWidget *parent = nullptr);
    dialogPerso(vector<vector<char>> solution, int taille, int mines, QWidget *parent=nullptr);
    ~dialogPerso();
    int taille;
    int mines;
    jeuPerso jeuPers;
    vector<vector<char>> solution;

private slots:
    void on_pushButton_clicked();

private:
    Ui::dialogPerso *ui;
};

#endif // DIALOGPerso_H
