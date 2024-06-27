#ifndef TCLAVIER_H
#define TCLAVIER_H

#include <QKeyEvent>
#include "tMonClientUDP.h"


class tClavier : public QObject
{

    Q_OBJECT
public:
    tClavier();

public slots:
    QString gererTouche(QKeyEvent *ev);

signals:

    void on_pressed_key(QKeyEvent* event);


private:
    bool keyIsPressed = false;
    tMonClientUDP* aClient;
    QString aiptello;
    int aport;
};

#endif // TCLAVIER_H
