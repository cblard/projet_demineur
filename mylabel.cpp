#include <QLabel>
class myLabel : public QLabel
{
   Q_OBJECT

public:
   myLabel(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0);
   ~myLabel();

signals:
   void clicked();
protected:
   void mousePressEvent(QMouseEvent*);
}

//cpp
myLabel::myLabel(const QString & text, QWidget * parent = 0, Qt::WindowFlags f = 0)
    :QLabel(text, parent, f)
{
}

myLabel::~myLabel()
{
}

void myLabel::mousePressEvent(QMouseEvent*)
{
    emit clicked();
}
