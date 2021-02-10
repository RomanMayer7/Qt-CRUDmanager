#include <QApplication>
#include <QKeyEvent>
#include "KeyPress.h"

KeyPress::KeyPress(QWidget *parent) :
    QWidget(parent)
{
   // myLabelText = new QLabel ("You Didn't Pressed / Released any Key");
}

void KeyPress::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Q)
    {
      //  myLabelText->setText("You Pressed Key Q");
    }
    else
    {
       // myLabelText->setText("You Pressed Other Key");
    }
}

void KeyPress::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Q)
    {
      //  myLabelText->setText("You Released Key Q");
    }
    else
    {
        //myLabelText->setText("You Released Other Key");
    }
}
