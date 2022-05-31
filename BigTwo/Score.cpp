#include "Score.h"

int Score::score[4]={0,0,0,0};
Score::Score(){
    
}
void Score::setScore(int player,int computer_1,int computer_2,int computer_3){
    score[0]+=player;
    score[1]+=computer_1;
    score[2]+=computer_2;
    score[3]+=computer_3;
}
int Score::getScore(int side){
    return score[side];
}
int Score::roundScore(double cards[]){
    int remain=0;
    int numberTwo=0;
    for(int i=0;i<13;i++)
    {
        if(cards[i]>0)
        {
            remain++;
            if(int(cards[i])==2)
            {
                numberTwo++;
            }
        }
    }
    if(remain==13)
    {
        remain*=4;
        for(int i=0;i<numberTwo;i++)
        {
            remain*=2;
        }
    }
    else if(remain>=8 and remain<10)
    {
        remain*=2;
        for(int i=0;i<numberTwo;i++)
        {
            remain*=2;
        }
    }
    else if(remain>=10 and remain<13){
        remain*=3;
        for(int i=0;i<numberTwo;i++){
            remain*=2;
        }
    }
    return remain;
}

void Score::setScore_2(int side,int score_out){
    score[side]=score_out;
}
void Score::setScore_3(double player[],double computer_1[],double computer_2[],double computer_3[]){
    setScore(roundScore(player),roundScore(computer_1),roundScore(computer_2),roundScore(computer_3));
}
int Score::getScore(string side){
    int scoreSide=0;
    if(side=="computer_1"){
        scoreSide=1;
    }
    if(side=="computer_2"){
        scoreSide=2;
    }
    if(side=="computer_3"){
        scoreSide=3;
    }
    return score[scoreSide];
}
