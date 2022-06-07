#include "Card.h"
#include "Check.h"
#include "Computer.h"
#include "Game.h"
#include "Player.h"
#include "Table.h"
#include "Tool.h"
#include"Print.h"
#include"OutOfCard.h"
#include"Compare.h"
#include"Score.h"

#include<iostream>
#include <string>
#include <sstream>

using namespace std;

//H5 s13 c9 d12

int main()
{
    for (int i = 0;i < 12;i++) {
        Print print;

        print.welcome();
        cout << endl;
        print.rule();

        Table play;

        play.start();
        cout << endl;

        print.shuffleCard();

        int sequence = play.whoFirst();

        print.printSequence(sequence);

        if (sequence != 4) {
            sequence++;
        }
        else {
            sequence = sequence / 4;
        }
        cout << endl;

        cout << "\033[32m現在是第\033[0m\033[31m" << sequence << "\033[0m\033[32m位出牌\033[0m" << endl << endl;

        if (sequence == 1) {
            cout << " 4 是黑桃" << " " << " 3 是紅心" << " " << " 2 是梅花" << " " << " 1 是方塊" << endl << endl;
            cout << "請輸入小數點的方式出牌，Ex:方塊3 = 3.1" << endl << endl;
        }


        Player p;
        OutOfCard out;
        Game game;
        Computer c1;

        double ca[5] = { 0,0,0,0,0 };
        double TableCa[5] = { 0,0,0,0,0 };

        int caSize = 0;

        if (sequence == 1) {
            print.printTable();
            cout << endl;
            print.printHandCard();
            cout << endl << endl;

            cout << "    ";
            play.getPlayer().printPlayer_arr();
            cout << endl << endl;

            p.FirstPlayerOutCard(play.getPlayer());
            cout << endl;
        }
        else if (sequence == 2) {
            out.computerFirstOutHand(play.getComputer1());
        }
        else if (sequence == 3) {
            out.computerFirstOutHand(play.getComputer2());
        }
        else {
            out.computerFirstOutHand(play.getComputer3());
        }

        /**/
        for (int i = 0;i < 5;i++) {
            ca[i] = 0;
            if (game.get1CardOnField(i) != 0) {
                ca[i] = game.get1CardOnField(i);
                caSize++;
            }
        }

        if (sequence != 1) {
            cout << "Computer 出牌 : ";
        }

        for (int i = 0;i < caSize;i++) {
            cout << ca[i] << " ";
        }

        cout << endl << endl;

        for (int i = 0;i < 5;i++) {
            TableCa[i] = ca[i];
        }

        Tool tool;

        /**/
        if (sequence == 1) {
            for (int i = 0;i < 13;i++) {
                for (int j = 0;j < caSize;j++) {
                    if (TableCa[j] == play.getPlayer().getIndexOfCard(i)) {
                        cout << i << endl;
                        play.getPlayer().setPlayerArr(0, i);
                    }
                }
            }
        }

        tool.arrange(play.getPlayer().getPlayer_arr(), 13);








        while (play.end() == false) {

            if (sequence != 4) {
                sequence++;
            }
            else {
                sequence = sequence / 4;
            }
            cout << endl;

            cout << "\033[32m現在是第\033[0m\033[31m" << sequence << "\033[0m\033[32m位出牌\033[0m" << endl << endl;

            caSize = 0;

            if (sequence == 1) {
                cout << " 4 是黑桃" << " " << " 3 是紅心" << " " << " 2 是梅花" << " " << " 1 是方塊" << endl << endl;
                cout << "請輸入小數點的方式出牌，Ex:方塊3 = 3.1" << endl << endl;
            }

            cout << "Pass Count : " << play.getPassNumber();
            cout << endl << endl;

            if (play.getPassNumber() == 3) {
                if (sequence == 1) {
                    print.printHandCard();
                    cout << endl << endl;

                    cout << "    ";
                    play.getPlayer().printPlayer_arr();
                    cout << endl << endl;

                    p.nLimitPlayerOutCard(play.getPlayer());
                }

                else if (sequence == 2) {
                    out.nLimitComputerOutHand(play.getComputer1());
                }

                else if (sequence == 3) {
                    out.nLimitComputerOutHand(play.getComputer2());
                }

                else {
                    out.nLimitComputerOutHand(play.getComputer3());
                }
            }

            else {
                print.fieldCard();
                cout << endl << endl << "  ";
                for (int i = 0;i < 5;i++) {
                    if (TableCa[i] != 0) {
                        cout << TableCa[i] << " ";
                    }
                }
            }

            cout << endl << endl;

            if (sequence == 1) {
                print.printHandCard();
                cout << endl << endl;

                cout << "    ";
                play.getPlayer().printPlayer_arr();
                cout << endl << endl;

                p.playerOutCard(play.getPlayer());
                cout << endl;

            }
            else if (sequence == 2) {
                out.computerOutHand(play.getComputer1());
            }
            else if (sequence == 3) {
                out.computerOutHand(play.getComputer2());
            }
            else {
                out.computerOutHand(play.getComputer3());
            }

            /**/
            for (int i = 0;i < 5;i++) {
                ca[i] = 0;
                if (game.get1CardOnField(i) != 0) {
                    ca[i] = game.get1CardOnField(i);
                    caSize++;
                }
            }

            if (sequence != 1) {
                cout << "Computer 出牌 : ";
            }

            for (int i = 0;i < caSize;i++) {
                cout << ca[i] << " ";
            }
            cout << endl << endl;

            double test[5] = { 0 };

            for (int i = 0;i < 5;i++) {
                test[i] = TableCa[i];
            }

            for (int i = 0;i < 5;i++) {
                TableCa[i] = ca[i];

            }

            /**/
            for (int i = 0;i < caSize;i++) {
                if (test[i] != ca[i]) {
                    play.resetPassNumber();
                }
            }


            /**/
            if (sequence == 1) {
                for (int i = 0;i < 13;i++) {
                    for (int j = 0;j < caSize;j++) {
                        if (TableCa[j] == play.getPlayer().getIndexOfCard(i)) {
                            cout << i << endl;
                            play.getPlayer().setPlayerArr(0, i);
                        }
                    }
                }
            }

            tool.arrange(play.getPlayer().getPlayer_arr(), 13);

        }
        Score score;
        score.setScore( score.roundScore(play.getPlayer().getPlayer_arr() ) , score.roundScore(play.getComputer1().getComputer_arr()),
            score.roundScore(play.getComputer1().getComputer_arr()) , score.roundScore(play.getComputer1().getComputer_arr()) );

        for (int i = 0;i < 4;i++) {
            cout << "第" << i << "位成績為 : " << score.getScore(i) << endl;
        }

        cout << "Game Over" << endl;
    }

    return 0;
}
