#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "ttt.h"
#include "TicTacToe.h"
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(NULL));

    TicTacToe* ttt = new TicTacToe();

    auto switchLabel = [this, ttt] ()
    {
        if (ttt->getSpieler() == TTT::SPIELER_1)
        {
            ui->label_spieler1->setStyleSheet("font-weight: bold; color: red");
            ui->label_spieler2->setStyleSheet("font-weight: normal; color: black");
        }
        else if (ttt->getSpieler() == TTT::SPIELER_2)
        {
            ui->label_spieler2->setStyleSheet("font-weight: bold; color: red");
            ui->label_spieler1->setStyleSheet("font-weight: normal; color: black");
        }
    };
    auto neuesSpiel = [this, ttt, switchLabel] ()
    {
        ttt->initSpielfeld();
        ui->pushButton_00->setText(TTT::SYMBOL_LEER);
        ui->pushButton_01->setText(TTT::SYMBOL_LEER);
        ui->pushButton_02->setText(TTT::SYMBOL_LEER);
        ui->pushButton_10->setText(TTT::SYMBOL_LEER);
        ui->pushButton_11->setText(TTT::SYMBOL_LEER);
        ui->pushButton_12->setText(TTT::SYMBOL_LEER);
        ui->pushButton_20->setText(TTT::SYMBOL_LEER);
        ui->pushButton_21->setText(TTT::SYMBOL_LEER);
        ui->pushButton_22->setText(TTT::SYMBOL_LEER);

        switchLabel();
    };
    auto reset = [this, ttt, neuesSpiel] () //modified capture
    {
        ttt->reset();
        neuesSpiel();
        ui->label_spieler1_gowonnen->setNum(ttt->spieler1_gewonnen);
        ui->label_spieler2_gowonnen->setNum(ttt->spieler2_gewonnen);
    };


    auto zugLambda = [switchLabel, this, ttt, neuesSpiel] (QPushButton* button, int x, int y) //modified capture
    {
        if (ttt->istVoll()) //new game if all boxes are filled
        {
            neuesSpiel();
        }
        if (ttt->setFeld(x, y, ttt->getSpieler())) //if insertion is sucessful
        {
           QString temp = ttt->getSpieler() == TTT::SPIELER_1 ? TTT::SYMBOL_SPIELER_1 : TTT::SYMBOL_SPIELER_2;
           button->setText(temp);
        }
        if (ttt->getSieger() == TTT::LEER) //no winner
        {
            ttt->spielerWechsel();
            switchLabel();
        }
        else if (ttt->getSieger() == TTT::SPIELER_1)
        {
            ttt->spieler1_gewonnen++;
            ui->label_spieler1_gowonnen->setNum(ttt->spieler1_gewonnen);
            neuesSpiel();
        }
        else if (ttt->getSieger() == TTT::SPIELER_2)
        {
            ttt->spieler2_gewonnen++;
            ui->label_spieler2_gowonnen->setNum(ttt->spieler2_gewonnen);
            neuesSpiel();
        }

    };



    connect(ui->pushButton_neuesSpiel, &QPushButton::clicked, neuesSpiel);
    connect(ui->pushButton_reset, &QPushButton::clicked, reset);

    connect(ui->pushButton_00, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_00, 0, 0);
    });
    connect(ui->pushButton_01, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_01, 0, 1);
    });
    connect(ui->pushButton_02, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_02, 0, 2);
    });
    connect(ui->pushButton_10, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_10, 1, 0);
    });
    connect(ui->pushButton_11, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_11, 1, 1);
    });
    connect(ui->pushButton_12, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_12, 1, 2);
    });
    connect(ui->pushButton_20, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_20, 2, 0);
    });
    connect(ui->pushButton_21, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_21, 2, 1);
    });

    connect(ui->pushButton_22, &QPushButton::clicked, [=] ()
    {
        zugLambda(ui->pushButton_22, 2, 2);
    });

    neuesSpiel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

