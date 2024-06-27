#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    qDebug() << "test";
    ui->setupUi(this);
    ui->tabWidget->setTabVisible(1 ,false);
    ui->tabWidget->setTabVisible(2 ,false);

    this->drone = new tDrone();
    //    this->tclavier = new tClavier();
    //    this->tgamepad = new tGamepad();


    //---------- Initinilasition de la manette et des signaux utilisé pour le controle ------
    //init Gamepad
    QLoggingCategory::setFilterRules(QStringLiteral("qt.gamepad.debug=true"));

    auto gamepads = QGamepadManager::instance()->connectedGamepads();
    if (gamepads.isEmpty()) {
        qDebug() << "Did not find any connected gamepads";
        return;
    }

    m_gamepad = new QGamepad(*gamepads.begin(), this);


    connect(m_gamepad, &QGamepad::axisLeftXChanged, this, [=](double
                                                                  value){on_gamePadAxis_action_LeftX(value);});

    connect(m_gamepad, &QGamepad::axisLeftYChanged, this, [=](double
                                                                  value){on_gamePadAxis_action_LeftY(value);});

    connect(m_gamepad, &QGamepad::buttonAChanged, this, [=](bool
                                                                pressed){on_gamepadButton_action_ButtonA(pressed);});

    connect(m_gamepad, &QGamepad::buttonBChanged, this, [=](bool
                                                                pressed){on_gamepadButton_action_ButtonB(pressed);});

    connect(m_gamepad, &QGamepad::buttonXChanged, this, [=](bool
                                                                pressed){on_gamepadButton_action_ButtonX(pressed);});

    connect(m_gamepad, &QGamepad::buttonYChanged, this, [=](bool
                                                                pressed){on_gamepadButton_action_ButtonY(pressed);});

    connect(m_gamepad, &QGamepad::buttonR1Changed, this, [=](bool
                                                                 pressed){on_gamepadButton_action_ButtonL1(pressed);});

    connect(m_gamepad, &QGamepad::buttonL1Changed, this, [=](bool
                                                                 pressed){on_gamepadButton_action_ButtonR1(pressed);});
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonQuitter_clicked()
{
    drone->deconnecter();
    close();
}

void MainWindow::on_pushButtonSeConnecter_clicked()
{
    ui->tabWidget->setTabVisible(1 ,true);
    ui->tabWidget->setTabVisible(0 ,false);


    if(drone->connecter() == false) // verification si le drone est connecter
    {
        if(drone->connecter() == false)
        {
            ui->tabWidget->setTabVisible(1 ,true);
            ui->tabWidget->setTabVisible(0 ,false);
            drone->deconnecter();
        }
        else{
            QMessageBox::critical(0, "connection error", "<b>la connexion n'est pas effective<b>");
        }
    }
    else
    {
        QMessageBox::critical(0, "connection error", "<b>la connexion n'est pas effective<b>");
    }
}

bool MainWindow::on_pushButtonClavier_clicked()
{

    if(tclavier == nullptr)
    {
        this->tclavier = new tClavier();
        ui->tabWidget->setTabVisible(1 ,false);
        ui->tabWidget->setTabVisible(2 ,true);
    }
    else
    {
        QMessageBox::critical(0, "connection error", "<b>Probleme de création pour le controle clavier<b>");
    }

}

bool MainWindow::on_pushButtonManette_clicked()
{
    if(tclavier == nullptr)
    {
        this->tgamepad = new tGamepad();
        ui->tabWidget->setTabVisible(1 ,false);
        ui->tabWidget->setTabVisible(2 ,true);
    }
    else
    {
        QMessageBox::critical(0, "connection error", "<b>Probleme de création pour le controle mannette <b>");
    }
}

void MainWindow::on_pushButtonRetourModePilotage_clicked()
{
    ui->tabWidget->setTabVisible(1 ,true);
    ui->tabWidget->setTabVisible(2 ,false);
}

void MainWindow::on_pushButtonRetourConnexion_clicked()
{
    ui->tabWidget->setTabVisible(0 ,true);
    ui->tabWidget->setTabVisible(1 ,false);
}



// COMMANDE DU DRONE

void MainWindow::keyPressEvent(QKeyEvent *event) //récupération de l'event de la methode pour envoyer les commande au drone
{

    QString Cmd;
    if ((Cmd = tclavier->gererTouche(event)) != "") //créer au préalable, la commande prend comme valeur, ce que retourne la fonctione gerer touche + verif si elle est vide
    {
        if (drone->Envoyer(Cmd) == false) // verification si la commande c'est nvoyer ou nan
        {
            QMessageBox::critical(0, "atterrisage error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
    else{
        QMessageBox::critical(0, "clavier error", "<b>probleme de reconnaissances des touche du clavier<b>");
    }


}

//commande de l'axe du joystick gauche
// une valeur est affecter au methode et permet de récuperer la valeur envoyer par les methodes de gestion est recupérer la commande en conséquence

void MainWindow::on_gamePadAxis_action_LeftX(double value)
{

    QString Cmd = tgamepad->gestion_joystick_leftX(value);

    if (Cmd != "")
    {
        qDebug() << Cmd;
        if (drone->Envoyer(Cmd) == false)
        {
            QMessageBox::critical(0, "envoie error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
}

void MainWindow::on_gamePadAxis_action_LeftY(double value)
{
    // qDebug() << value;
    QString Cmd = tgamepad->gestion_joystick_leftY(value);
    if (Cmd != "")
    {
        qDebug() << Cmd;
        if (drone->Envoyer(Cmd) == false)
        {
            QMessageBox::critical(0, "envoie error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
}

// command bouton pour le drone
// Recuperation de la valeur renvoyer par les methodes boutons et envoyé la commande retourné par cette même méthode

void MainWindow::on_gamepadButton_action_ButtonA(bool pressed)
{

    QString Cmd = tgamepad->on_button_A(pressed);
    if (Cmd != "")
    {
        if (drone->Envoyer(Cmd) == false)
        {
            QMessageBox::critical(0, "envoie error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
}

void MainWindow::on_gamepadButton_action_ButtonB(bool pressed)
{

    QString Cmd = tgamepad->on_button_B(pressed);
    if (Cmd != "")
    {
        if (drone->Envoyer(Cmd) == false)
        {
            QMessageBox::critical(0, "envoie error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
}

void MainWindow::on_gamepadButton_action_ButtonX(bool pressed)
{

    QString Cmd = tgamepad->on_button_X(pressed);
    if (Cmd != "")
    {
        if (drone->Envoyer(Cmd) == false)
        {
            QMessageBox::critical(0, "envoie error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
}

void MainWindow::on_gamepadButton_action_ButtonY(bool pressed)
{

    QString Cmd = tgamepad->on_button_Y(pressed);
    if (Cmd != "")
    {
        if (drone->Envoyer(Cmd) == false)
        {
            QMessageBox::critical(0, "envoie error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
}

void MainWindow::on_gamepadButton_action_ButtonR1(bool pressed)
{

    QString Cmd = tgamepad->on_button_R1(pressed);
    if (Cmd != "")
    {
        if (drone->Envoyer(Cmd) == false)
        {
            QMessageBox::critical(0, "envoie error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
}

void MainWindow::on_gamepadButton_action_ButtonL1(bool pressed)
{

    QString Cmd = tgamepad->on_button_L1(pressed);
    if (Cmd != "")
    {
        if (drone->Envoyer(Cmd) == false)
        {
            QMessageBox::critical(0, "envoie error", "<b>l'envoie de la commande ne s'est pas fait<b>");
        }
    }
}
