// Octobre 2019
#ifndef TMONCLIENTUDP_H
#define TMONCLIENTUDP_H

#include <QObject>
//#include <QTcpSocket>
#include <QUdpSocket>
#include <QNetworkDatagram>
//#include <QNetworkProxy>
#include <QMessageBox>

class tMonClientUDP : public QObject
{
    Q_OBJECT
public:
    explicit tMonClientUDP(QObject *parent = 0);
    ~tMonClientUDP();
    bool Connecter(QString AdresseServeur, int PortServeur) ;
    void Deconnecter() ;
    bool Envoyer (QString TexteAEnvoyer,  QString adIP, int numPort) ;
    bool getEstConnecte() ;

signals:
    void on_reception_datagram(QString) ;

public slots:
    void ReceptionUDP();
    void ConnexionOK();
    void TraiterErreur(QAbstractSocket::SocketError err);
    void OnDeconnexion();


private:
    QUdpSocket* pMaSocket ;

    bool EstConnecte ;


};

#endif // TMONCLIENTUDP_H
