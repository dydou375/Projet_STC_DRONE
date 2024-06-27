// Octobre 2019

#include "tMonClientUDP.h"


// ************************************************************************************************
tMonClientUDP :: tMonClientUDP(QObject *parent) : QObject(parent)
{
    pMaSocket = new QUdpSocket(this) ;
    //pMaSocket->setProxy(QNetworkProxy::NoProxy) ;

    connect(pMaSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(TraiterErreur(QAbstractSocket::SocketError))) ;
    connect(pMaSocket, SIGNAL(connected()), this, SLOT(ConnexionOK())) ;
    connect(pMaSocket, SIGNAL(readyRead()), this, SLOT(ReceptionUDP())) ;
    connect(pMaSocket, SIGNAL(disconnected()), this, SLOT(OnDeconnexion()));

    EstConnecte=false ;
}

//-------------------------------------------------------------------
void tMonClientUDP::ConnexionOK()
{
    // selon ses besoins ...
    QMessageBox::information(0,"Mon Client", "Bingo !!");
}

//---------------------------------------------------------------------
void tMonClientUDP::TraiterErreur(QAbstractSocket::SocketError error)
{
   switch(error) // On affiche un message différent selon l'erreur qu'on nous indique
   {
    case QAbstractSocket::HostNotFoundError:
      QMessageBox::critical(0, "SocketError", "<b>The host address was not found.<b>");
      break;
    case QAbstractSocket::ConnectionRefusedError:
      QMessageBox::critical(0, "SocketError", "<b>The connection was refused by the peer (or timed out).<b>");
      break;
    case QAbstractSocket::RemoteHostClosedError:
      QMessageBox::critical(0, "SocketError", "<b>The remote host closed the connection. Note that the client socket (i.e., this socket) will be closed after the remote close notification has been sent.<b>");
      break;
    case QAbstractSocket::NetworkError :
      QMessageBox::critical(0,"SocketError", "An error occurred with the network (e.g., the network cable was accidentally plugged out).");
      break;
    case QAbstractSocket::ProxyAuthenticationRequiredError:
      QMessageBox::critical(0,"SocketError","The socket is using a proxy, and the proxy requires authentication");
      break;
    //default:
      //QMessageBox::critical((QString), "SocketError", pMaSocket->errorString());
   }

}

// ************************************************************************************************
tMonClientUDP :: ~tMonClientUDP()
{
    if (EstConnecte)
        //pMaSocket->disconnectFromHost() ;
        pMaSocket->close();

    delete pMaSocket ;
}

// ************************************************************************************************
bool tMonClientUDP :: Connecter(QString AdresseServeur, int PortServeur)
{
    if (!EstConnecte )
    {
        if (AdresseServeur!="" && PortServeur>0)
        {
            //EstConnecte = pMaSocket->bind(QHostAddress(AdresseServeur),PortServeur) ;
            EstConnecte = 1;
        }
    }
    return EstConnecte ;
}

// ************************************************************************************************
void tMonClientUDP :: Deconnecter()
{
    if (EstConnecte )
    {
        //pMaSocket->disconnectFromHost() ;
        pMaSocket->close();
        EstConnecte=false;
    }
}

// ************************************************************************************************
void tMonClientUDP :: ReceptionUDP()
{
  QNetworkDatagram Datagram;
  while (pMaSocket->hasPendingDatagrams())
        Datagram = pMaSocket->receiveDatagram();

  emit on_reception_datagram((QString)Datagram.data());
}

// ************************************************************************************************
bool tMonClientUDP :: Envoyer (QString TexteAEnvoyer, QString adIP, int numPort)
{
    QByteArray Data;
    Data.append(TexteAEnvoyer);
    bool Retour = false ;
    if (EstConnecte)
    {
        if (TexteAEnvoyer!="")
        {
            pMaSocket->writeDatagram(Data, QHostAddress(adIP), (qint16)numPort);
            Retour = true;
        }
    }
    return Retour ;
}

// ************************************************************************************************
bool tMonClientUDP :: getEstConnecte()
{
    return EstConnecte ;
}

// ************************************************************************************************
void tMonClientUDP::OnDeconnexion()
{
    //qDebug() << "Deconnexion établie";
    EstConnecte = false;
    QMessageBox::critical(0,"INFORMATION","Deconnexion réseau !");
}
