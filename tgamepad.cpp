#include "tgamepad.h"


tGamepad::tGamepad()
{

}

QString tGamepad::gestion_joystick_leftX(double value) //Methode pour aller a droite ou gauche selon la valeur du joystick
{
    QString Cmd = "";
    //qDebug() << value << "www";
    if(value > 0  && value <= 1 ){
        Cmd = "right 50";
        return Cmd;
    }
    else if(value < 0 && value >= -1){
        Cmd = "left 50";
        return Cmd;
    }
    else
        return "";
}

QString tGamepad::gestion_joystick_leftY(double value) //Methode pour avancer ou reculer en fonctione de la valeur du joystick
{
    qDebug() << value << "xxx";
    if (value > 0)
        return "back 50";
    else if(value < 0)
        return "forward 50";
    else
        return "";
}

QString tGamepad::on_button_Y(bool pressed) //Methode pour prendre de l'altitude
{

    if (pressed == true)
    return "up 50";
    else
        return "";
}

QString tGamepad::on_button_A(bool pressed) //Methode pour perdre de l'altitude
{

    if (pressed == true)
    return "down 50";
    else
        return "";

}

QString tGamepad::on_button_B(bool pressed) //Methode pour tourner l'axe de rotation du drone dans le sens horaire
{

    if (pressed == true)
    return "cw 50";
    else
        return "";
}

QString tGamepad::on_button_X(bool pressed)//Methode pour tourner l'axe de rotation du drone dans le sens anti-horaire
{
    if (pressed != false)
    return "ccw 50";
    else
        return "";

}

QString tGamepad::on_button_R1(bool pressed) //Methode pour décoller
{

    if (pressed == true)
    return "takeoff";
    else
        return "";
}

QString tGamepad::on_button_L1(bool pressed) //Methode pour atterir
{
    if (pressed != false)
    return "land";
    else
        return "";

}



