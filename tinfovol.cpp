#include "tinfovol.h"

using namespace std;

tInfoVol::tInfoVol()
{

}

void tInfoVol::extractAndPrintData(QString data) {
    QStringList fields = data.split(";");
    foreach (QString field, fields) {
        QStringList subFields = field.split(":");
        if (subFields[0] == "vgx") {
            vgx = subFields[1].toInt();
        } else if (subFields[0] == "vgy") {
            vgy = subFields[1].toInt();
        } else if (subFields[0] == "vgz") {
            vgz = subFields[1].toInt();
        } else if (subFields[0] == "h") {
            h = subFields[1].toInt();
        } else if (subFields[0] == "bat") {
            bat = subFields[1].toInt();
        } else if (subFields[0] == "tof") {
            tof = subFields[1].toInt();
        } else if (subFields[0] == "time") {
            time = subFields[1].toInt();
        } else if (subFields[0] == "baro") {
            baro = subFields[1].toFloat();
        }
    }

    qDebug() << "Speed: (" << vgx << ", " << vgy << ", " << vgz << ")";
    qDebug() << "Altitude: " << h << "cm";
    qDebug() << "Battery Capacity: " << bat << "%";
    qDebug() << "Flight Time: " << time << "s";
    qDebug() << Qt::endl;
}

int tInfoVol::RecevoirTrame()
{
    // Configurer l'adresse IP et le port sur lesquels le serveur doit écouter
    QHostAddress address("0.0.0.0");
    udpSocket.bind(address, port);

    // Attendre indéfiniment les données entrantes
    while (true) {
        // Vérifier si des données sont disponibles pour la lecture
        if (udpSocket.hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(udpSocket.pendingDatagramSize());

            QHostAddress senderAddress;
            quint16 senderPort;

            // Lire les données entrantes et obtenir l'adresse IP et le port de l'expéditeur
            udpSocket.readDatagram(datagram.data(), datagram.size(),
                                   &senderAddress, &senderPort);

            // Afficher les données reçues
             //qDebug() << datagram << Qt::endl;


            //appel de la fonction extractAndPrintData avec en paramètre la trame
            QString data = QString(datagram);
            extractAndPrintData(data);
        }
    }
    return 0;
}
