#ifndef PMAC_H
#define PMAC_H

class Print
{
public:
    void welcome();
    void rule();
    void printHandCard();
    void fieldCard();
    void shuffleCard();
    void printSequence(int);

private:
    void clear();
};

#endif