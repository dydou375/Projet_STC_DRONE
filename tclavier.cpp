#include "tclavier.h"

tClavier::tClavier()
{
    qDebug() << "test_clavier";
}

// Methode pour la gestion de touche, plus l'envoi de la commande adéquate
QString tClavier::gererTouche(QKeyEvent *ev)
{

    qDebug() << ev->key();
    if (ev->key() == Qt::Key_1)           //https://doc.qt.io/qt-6/qt.html#Key-enum
        return "cw 40";

    else if (ev->key()  == Qt::Key_3)
        return "ccw 40";

    else if (ev->key()  == Qt::Key_5)
        return "up 50";

    else if (ev->key()  == Qt::Key_2)
        return "down 40";

    else if (ev->key()  == Qt::Key_Z)
        return "forward 50";

    else if (ev->key()  == Qt::Key_S)
        return "back 50";

    else if (ev->key()  == Qt::Key_Q)
        return "left 50";

    else if (ev->key()  == Qt::Key_D)
        return " right 50";

    else if (ev->key()  == Qt::Key_M)
        return "emergency";

    else if (ev->key()  == Qt::Key_T)
        return "takeoff";
    else if (ev->key()  == Qt::Key_L)
        return "lantd";

    else

        return "";
}




