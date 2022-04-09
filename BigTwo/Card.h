#ifndef CARD_H
#define CARD_H
#include <iostream>
#include "Check.h"
using namespace std;

class Card
{
private:
    int number;
    int flower;
    double single_arr[1];
    double pairs_arr[2];
    double triples_arr[3];
    double straight_arr[5];
    double flush_arr[5];
    double fullHouse_arr[5];
    double tiki_arr[5];
    double straightFlush_arr[5];
    Check check;

public:
    void setNumber(double);
    void setFlower(double);
    void setSingle(double);
    void setPairs(double, double);
    void setTriples(double, double, double);
    void setStraight(double, double, double, double, double);
    void setFlush(double, double, double, double, double);
    void setFullHouse(double, double, double, double, double);
    void setTiki(double, double, double, double, double);
    void setStraightFlush(double, double, double, double, double);
    int getNumber() const;
    int getFlower() const;
    double *getSingle() const;
    double *getPairs() const;
    double *getTriples() const;
    double *getStraight() const;
    double *getFlush() const;
    double *getFullHouse() const;
    double *getTiki() const;
    double *getStraightFlush() const;

    // Test
    void print() const;
};

#endif
