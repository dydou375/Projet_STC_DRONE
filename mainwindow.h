#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGamepad/QGamepad>
#include <QGamepad>
#include "tMonClientUDP.h"
#include <QDebug>
#include <QKeyEvent>
#include <QTimer>
#include "unistd.h"

#include "tdrone.h"
#include "tgamepad.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QGamepad;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonQuitter_clicked();

    void on_pushButtonSeConnecter_clicked();

    bool on_pushButtonClavier_clicked();

    bool on_pushButtonManette_clicked();

    void on_pushButtonRetourModePilotage_clicked();

    void on_pushButtonRetourConnexion_clicked();

private:
    Ui::MainWindow *ui;



    tDrone* drone;
    int numPort;
    QString adIPTello;

    QGamepad* m_gamepad;

    tClavier* tclavier = nullptr;
    tGamepad* tgamepad;

protected:

    //CONTROLE DU DRONE

    // Methode du clavier
    void keyPressEvent(QKeyEvent *event);


    // Methodes de la mannette
    void on_gamePadAxis_action_LeftX(double value);
    void on_gamePadAxis_action_LeftY(double value);
    void on_gamepadButton_action_ButtonA(bool pressed);
    void on_gamepadButton_action_ButtonB(bool pressed);
    void on_gamepadButton_action_ButtonX(bool pressed);
    void on_gamepadButton_action_ButtonY(bool pressed);
    void on_gamepadButton_action_ButtonR1(bool pressed);
    void on_gamepadButton_action_ButtonL1(bool pressed);
};
#endif // MAINWINDOW_H
