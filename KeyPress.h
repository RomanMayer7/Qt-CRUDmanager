#ifndef KEYPRESS_H
#define KEYPRESS_H

#endif // KEYPRESS_H

#include <QWidget>
#include <QtGui>
#include<QLabel>

class KeyPress : public QWidget
{
    Q_OBJECT

public:
    KeyPress(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:

};
