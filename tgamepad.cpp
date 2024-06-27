#include "tgamepad.h"


tGamepad::tGamepad()
{

}

QString tGamepad::gestion_joystick_leftX(double value)
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

QString tGamepad::gestion_joystick_leftY(double value)
{
    qDebug() << value << "xxx";
    if (value > 0)
        return "back 50";
    else if(value < 0)
        return "forward 50";
    else
        return "";
}

//QString tGamepad::gestion_joystick_rightX(double value)
//{
//    qDebug() << value;
//    if (value > 0)
//        return "cw 50";
//    else if(value < 0)
//        return "ccw 50";
//    else
//        return "stop";
//}

//QString tGamepad::gestion_joystick_rightY(double value)
//{
//    qDebug() << value;
//    if (value > 0)
//        return "up 50";
//    else if(value < 0)
//        return "down 50";
//    else
//        return "stop";
//}

QString tGamepad::on_button_Y(bool pressed)
{

    if (pressed == true)
    return "up 50";
    else
        return "";
}

QString tGamepad::on_button_A(bool pressed)
{

    if (pressed == true)
    return "down 50";
    else
        return "";

}

QString tGamepad::on_button_B(bool pressed)
{

    if (pressed == true)
    return "cw 50";
    else
        return "";
}

QString tGamepad::on_button_X(bool pressed)
{
    if (pressed != false)
    return "ccw 50";
    else
        return "";

}

QString tGamepad::on_button_R1(bool pressed)
{

    if (pressed == true)
    return "takeoff";
    else
        return "";
}

QString tGamepad::on_button_L1(bool pressed)
{
    if (pressed != false)
    return "land";
    else
        return "";

}



