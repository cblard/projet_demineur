#ifndef ClickableLabel2_H
#define ClickableLabel2_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <vector>
using namespace std;

class ClickableLabel2 : public QLabel {
    Q_OBJECT

public:
    int ord;
    int abs;
    bool checkFlag=false;
    vector<vector<char>> solution;
    explicit ClickableLabel2(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ClickableLabel2(int abs, int ord, vector<vector<char>> solution, QWidget* parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags()) ;
    ~ClickableLabel2();
    //void mouseDoubleClickEvent(QMouseEvent *event) override;
    void comparerCases();
    void creationGrille();
signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif
