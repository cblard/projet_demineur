#ifndef JEU_H
#define JEU_H

#include <QDialog>

namespace Ui {
class jeu;
}

class jeu : public QDialog
{
    Q_OBJECT

public:
    explicit jeu(QWidget *parent = nullptr);
    ~jeu();

private:
    Ui::jeu *ui;
};

#endif // JEU_H
