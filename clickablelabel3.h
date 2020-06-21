#ifndef ClickableLabel3_H
#define ClickableLabel3_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <vector>
using namespace std;

class ClickableLabel3 : public QLabel {
    Q_OBJECT

public:
    int ord;
    int abs;
    vector<vector<char>> solution;
    explicit ClickableLabel3(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ClickableLabel3(int abs, int ord, vector<vector<char>> solution, QWidget* parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags()) ;
    ~ClickableLabel3();
    void comparerCases();
    void creationGrille();

signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif
