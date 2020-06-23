#ifndef ClickableLabel4_H
#define ClickableLabel4_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <vector>
using namespace std;

class ClickableLabel4 : public QLabel {
    Q_OBJECT

public:
    int ord;
    int abs;
    bool checkFlag=false;
    vector<vector<char>> solution;
    explicit ClickableLabel4(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ClickableLabel4(int abs, int ord, vector<vector<char>> solution, QWidget* parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags()) ;
    ~ClickableLabel4();
    void comparerCases();
    void creationGrille();

signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif
