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

#include<iostream>
#include <string>
#include <sstream>

using namespace std;

//H5 s13 c9 d12

int main()
{

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

    cout << "\033[33m電腦的牌 ！！！\033[0m" << endl << endl;

    play.getComputer1().print();
    play.getComputer2().print();
    play.getComputer3().print();

    cout << endl << endl;

    cout << "\033[32m現在是第\033[0m\033[31m" << sequence << "\033[0m\033[32m位出牌\033[0m" << endl << endl;

    cout << "S :4是黑桃" << " " << "H :3是紅心" << " " << "C :2是梅花" << " " << "D :1是方塊" << endl << endl;
    cout << "請輸入小數點的方式出牌，Ex:方塊3 = 3.1" << endl << endl;

    Player p;
    OutOfCard out;
    Game game;
    Computer c1;

    double ca[5] = { 0,0,0,0,0 };

    int caSize = 0;

    if (sequence == 1) {
        print.printHandCard();
        cout << endl << endl;

        play.getPlayer().playerOutCard();
        cout << endl;
    }
    else if(sequence == 2) {
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

    for (int i = 0;i < caSize;i++) {
        cout << ca[i] << " ";
    }

    cout << endl << endl;

    double TableCa[5] = { 0,0,0,0,0 };

    for (int i = 0;i < 5;i++) {
        TableCa[i] = ca[i];
    }

    cout << "\033[33m 電腦的牌 ！！！\033[0m" << endl << endl;

    play.getComputer1().print();
    play.getComputer2().print();
    play.getComputer3().print();
    cout << endl;

    if (sequence != 4) {
        sequence++;
    }
    else {
        sequence = sequence / 4;
    }
    cout << endl;

    cout << "\033[32m現在是第\033[0m\033[31m" << sequence << "\033[0m\033[32m位出牌\033[0m" << endl << endl;

    caSize = 0;









    while (play.end() == false) {
    
        caSize = 0;
        cout << "S :4是黑桃" << " " << "H :3是紅心" << " " << "C :2是梅花" << " " << "D :1是方塊" << endl << endl;
        cout << "請輸入小數點的方式出牌，Ex:方塊3 = 3.1" << endl << endl;

        print.fieldCard();
        cout << endl << endl << "  ";
        for (int i = 0;i < 5;i++) {
            if (TableCa[i] != 0) {
                cout << TableCa[i] << " ";
            }
        }

        cout << endl << endl;

        if (sequence == 1) {
            print.printHandCard();
            cout << endl << endl;

            play.getPlayer().playerOutCard();
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

        for (int i = 0;i < caSize;i++) {
                cout << ca[i] << " ";
        }

        cout << endl << endl;
        
        /*
        Compare compare;

        if (caSize == 1) {
            cout << compare.singleCompare(ca[0]);
            cout << endl;
            cout << "GGWP" << endl;
        }

        cout << endl << endl;
        */

        for (int i = 0;i < 5;i++) {
            TableCa[i] = ca[i];
        }
        
        Tool tool;
        
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
        
        tool.arrange( play.getPlayer().getPlayer_arr(), 13);
        
        cout << "\033[33m 電腦的牌 ！！！\033[0m" << endl << endl;

        play.getComputer1().print();
        play.getComputer2().print();
        play.getComputer3().print();
        cout << endl;

        if (sequence != 4) {
            sequence++;
        }
        else {
            sequence = sequence / 4;
        }
        cout << endl;

        cout << "\033[32m現在是第\033[0m\033[31m" << sequence << "\033[0m\033[32m位出牌\033[0m" << endl << endl;
        
    }
    
    return 0;
}
