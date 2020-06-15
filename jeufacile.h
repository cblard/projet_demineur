#ifndef JEUFACILE_H
#define JEUFACILE_H

#include <QDialog>

namespace Ui {
class jeuFacile;
}

class jeuFacile : public QDialog
{
    Q_OBJECT

public:
    explicit jeuFacile(QWidget *parent = nullptr);
    ~jeuFacile();

private:
    Ui::jeuFacile *ui;
};

#endif // JEUFACILE_H
