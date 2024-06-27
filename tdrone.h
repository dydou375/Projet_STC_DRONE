#ifndef TDRONE_H
#define TDRONE_H

#include "tMonClientUDP.h"
#include "tclavier.h"
#include "tgamepad.h"
#include <QObject>
#include <QMessageBox>


class tDrone : public QObject
{

    Q_OBJECT
public:
    tDrone();
    ~tDrone();
    tMonClientUDP* monClient;
    tClavier* clavier;
    tGamepad* gamepad;

    bool connecter();
    int deconnecter();

    int atterir();
    int decoller();
    int Envoyer(QString cmd);




public slots:
    void reception(QString message);


private:

    QString adIPTello;
    int numPort;

    QString msgrecu;
    int Verification_retour_drone();
};

#endif // TDRONE_H
