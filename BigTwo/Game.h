#include <string>
using namespace std;

#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    void setField(double, int);
    void setField(double, double, double, double, double);
    void setField(double*);
    void gameStart(); // 目前沒有功能
    double get1RptCard(int);
    double get1CardOnField(int) const;
    double *getCardsOnField() const;
    double *shuffleCards();
    bool compare(double*, string) const;
    int getNumOfCardsOnField() const;

    // void distributeCards();
private:
    double repository[52];
    double *pRepository;
    void setRpt();
    static double cardsOnField[5];
};

#endif
