#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include <vector>
using namespace std;

class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    int ord;
    int abs;
    vector<vector<char>> solution;
    explicit ClickableLabel(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ClickableLabel(int abs, int ord, vector<vector<char>> solution, QWidget* parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags()) ;
    ~ClickableLabel();
    void comparerCases();
    void creationGrille();

signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif
