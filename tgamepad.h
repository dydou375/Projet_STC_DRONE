#ifndef TGAMEPAD_H
#define TGAMEPAD_H

#include <QGamepad>

#include "tMonClientUDP.h"

#include "unistd.h"
#include <QLoggingCategory>


#include <QObject>


class tGamepad : public QObject
{

    Q_OBJECT
public:
    tGamepad();
   QString gestion_joystick_leftX(double value);
   QString gestion_joystick_leftY(double value);
/*   QString gestion_joystick_rightX(double value);
   QString gestion_joystick_rightY(double value)*/;

   QString on_button_Y(bool pressed);
   QString on_button_X(bool pressed);
   QString on_button_B(bool pressed);
   QString on_button_A(bool pressed);
   QString on_button_R1(bool pressed);
   QString on_button_L1(bool pressed);


public slots:



private:
    tMonClientUDP* gClient;
    QString aiptello;
    int aport;
    QGamepad* m_gamepad;

};

#endif // TGAMEPAD_H
