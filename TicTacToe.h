#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "ttt.h"
#include <stdlib.h>

class TicTacToe
{
private:
    int spielfeld[3][3];
    int spielerAmzug;

protected:
    int spieler1_gewonnen = 0;
    int spieler2_gewonnen = 0;

public:
    friend class MainWindow;
    void initSpielfeld()
    {
        for (auto &row : spielfeld)
        {
            for (auto &column : row)
            {
                column = TTT::LEER;
            }
        }
    }
    void reset()
    {
        initSpielfeld();
        spieler1_gewonnen = 0;
        spieler2_gewonnen = 0;
        spielerAmzug = (rand() % TTT::SPIELER_2) + TTT::SPIELER_1; //wtf

    }
    bool setFeld(int x, int y, int spieler)
    {
        if (spielfeld[x][y] != TTT::LEER)
        {
            return false;
        }
        if ((spieler == TTT::SPIELER_1 || spieler == TTT::SPIELER_2) && spielfeld[x][y] == TTT::LEER)
        {
            spielfeld[x][y] = spieler;
            return true;
        }
    }
    int getSpieler()
    {
        return spielerAmzug;
    }
    void spielerWechsel()
    {
        spielerAmzug = getSpieler() == TTT::SPIELER_1 ? TTT::SPIELER_2 : TTT::SPIELER_1;
    }
    int getFeld(int x, int y)
    {
        return spielfeld[x][y];
    }
    bool istVoll()
    {
        for (auto &row : spielfeld)
        {
            for (auto &column : row)
            {
                if (column == TTT::LEER)
                {
                    return false;
                }
            }
        }
        return true;
    }
    int getSieger()
    {

        if ((spielfeld[0][0] == TTT::SPIELER_1 && spielfeld[1][0] == TTT::SPIELER_1 && spielfeld[2][0] == TTT::SPIELER_1)
             ||(spielfeld[0][1] == TTT::SPIELER_1 && spielfeld[1][1] == TTT::SPIELER_1 && spielfeld[2][1] == TTT::SPIELER_1)
             ||(spielfeld[0][2] == TTT::SPIELER_1 && spielfeld[1][2] == TTT::SPIELER_1 && spielfeld[2][2] == TTT::SPIELER_1)
             ||(spielfeld[0][0] == TTT::SPIELER_1 && spielfeld[1][1] == TTT::SPIELER_1 && spielfeld[2][2] == TTT::SPIELER_1)
             ||(spielfeld[0][2] == TTT::SPIELER_1 && spielfeld[1][1] == TTT::SPIELER_1 && spielfeld[2][0] == TTT::SPIELER_1)
             ||(spielfeld[0][0] == TTT::SPIELER_1 && spielfeld[0][1] == TTT::SPIELER_1 && spielfeld[0][2] == TTT::SPIELER_1)
             ||(spielfeld[1][0] == TTT::SPIELER_1 && spielfeld[1][1] == TTT::SPIELER_1 && spielfeld[1][2] == TTT::SPIELER_1)
             ||(spielfeld[2][0] == TTT::SPIELER_1 && spielfeld[2][1] == TTT::SPIELER_1 && spielfeld[2][2] == TTT::SPIELER_1))
        {
            return TTT::SPIELER_1;
        }
        if ((spielfeld[0][0] == TTT::SPIELER_2 && spielfeld[1][0] == TTT::SPIELER_2 && spielfeld[2][0] == TTT::SPIELER_2)
             ||(spielfeld[0][1] == TTT::SPIELER_2 && spielfeld[1][1] == TTT::SPIELER_2 && spielfeld[2][1] == TTT::SPIELER_2)
             ||(spielfeld[0][2] == TTT::SPIELER_2 && spielfeld[1][2] == TTT::SPIELER_2 && spielfeld[2][2] == TTT::SPIELER_2)
             ||(spielfeld[0][0] == TTT::SPIELER_2 && spielfeld[1][1] == TTT::SPIELER_2 && spielfeld[2][2] == TTT::SPIELER_2)
             ||(spielfeld[0][2] == TTT::SPIELER_2 && spielfeld[1][1] == TTT::SPIELER_2 && spielfeld[2][0] == TTT::SPIELER_2)
             ||(spielfeld[0][0] == TTT::SPIELER_2 && spielfeld[0][1] == TTT::SPIELER_2 && spielfeld[0][2] == TTT::SPIELER_2)
             ||(spielfeld[1][0] == TTT::SPIELER_2 && spielfeld[1][1] == TTT::SPIELER_2 && spielfeld[1][2] == TTT::SPIELER_2)
             ||(spielfeld[2][0] == TTT::SPIELER_2 && spielfeld[2][1] == TTT::SPIELER_2 && spielfeld[2][2] == TTT::SPIELER_2))
        {
            return TTT::SPIELER_2;
        }

        return TTT::LEER;
    }
    TicTacToe()
    {
        reset();
    }

};

#endif
