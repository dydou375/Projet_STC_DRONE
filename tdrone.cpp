#include "tdrone.h"

tDrone::tDrone() //constructer initialisant monClient, et les infor générales de la connexion
{

        qDebug() << "njt";
    monClient = new tMonClientUDP();

    bool Debug = true;

    connect(monClient,SIGNAL(on_reception_datagram(QString)),this,SLOT(a_AfficherDuDrone(QString)));
    numPort = 8889;

    if (!Debug)
        adIPTello = "127.0.0.1";
    else
        adIPTello = "192.168.10.1";



}

tDrone::~tDrone()
{
    delete monClient;
    delete clavier;
    delete gamepad;
}


bool tDrone::connecter() //methode connecter
{
    if (!monClient->getEstConnecte()) //verification déjà connecter ?
    {
        if(monClient->Connecter(adIPTello,numPort) == 1)
        {
            if(monClient->Envoyer("command", adIPTello, numPort) == true)
            {
                return true;
            }
        }

        else
        {
            monClient->Deconnecter();
            return false;
        }
    }
    return 0;
}

int tDrone::deconnecter()
{
    if(monClient->getEstConnecte() == true)
    monClient->Deconnecter();
    else
        return 0;

}

void tDrone::reception(QString message)
{
    msgrecu = message;
}



int tDrone::Envoyer(QString cmd)
{
    monClient->Envoyer(cmd, adIPTello, numPort);
    return Verification_retour_drone();
}

int tDrone::decoller()
{
    monClient->Envoyer("takeoff", adIPTello, numPort);
    return Verification_retour_drone();


}

int tDrone::atterir()
{
    monClient->Envoyer("land", adIPTello, numPort);
    return Verification_retour_drone();
}


int tDrone::Verification_retour_drone()
{
    if(msgrecu == "ok")
        return 0 ;
    else
        return 1;
}
