#ifndef TINFOVOL_H
#define TINFOVOL_H
#include <QUdpSocket>
#include <QDebug>
#include <QString>
#include <iostream>
#include <sstream>
#include <string>

class tInfoVol
{
public:
    tInfoVol();
    void extractAndPrintData(QString data);
    int RecevoirTrame();

private:
    int vgx =0, vgy=0, vgz=0, h=0, bat=0, tof=0, time=0;
    float baro=0;
    // Créer une instance de QUdpSocket
    QUdpSocket udpSocket;
    //QHostAddress address("0.0.0.0");
    quint16 port = 8890;

};

#endif // TINFOVOL_H
