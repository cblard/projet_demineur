#ifndef JEUFACILE_H
#define JEUFACILE_H

#include <QDialog>
#include <vector>
using namespace std;

namespace Ui {
class jeuFacile;
}

class jeuFacile : public QDialog
{
    Q_OBJECT

public:
    explicit jeuFacile(QWidget *parent = nullptr);
    void creationGrille();
    ~jeuFacile();

    vector<vector<char>> solution;
    vector<vector<int>> mines;

private:
    Ui::jeuFacile *ui;
};

#endif // JEUFACILE_H
