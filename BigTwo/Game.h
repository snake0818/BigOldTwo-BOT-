#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    void setCardsOnField(double, double, double, double, double);
    void gameStart(); // 目前沒有功能
    double get1RptCard(int);
    double get1CardOnField(int) const;
    double *getCardsOnField() const;

private:
    double repository[52];
    void setRpt();
    static double cardsOnField[5];
};

#endif
