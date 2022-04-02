#ifndef GAME_H
#define GAME_H

class Game
{
private:
    double repository[52];
    void setRpt();
    double cardsOnField[5];
public:
    Game();
    double getRpt(int);
    void setCardsOnField();
};

#endif
