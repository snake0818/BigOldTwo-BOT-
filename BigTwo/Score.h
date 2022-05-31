#ifndef S_H
#define S_H
#include <iostream>
#include <string>
using namespace std;
class Score{
    public:
    Score();
    void setScore(int,int,int,int);
    void setScore_2(int,int);
    void setScore_3(double[],double[],double[],double[]);
    
    int getScore(int);
    int getScore(string);
    
    int roundScore(double[]);
    private:
    static int score[4];
};
#endif
