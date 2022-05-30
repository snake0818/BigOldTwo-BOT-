#include "Card.h"
#include "Check.h"
#include "Computer.h"
#include "Game.h"
#include "Player.h"
#include "Table.h"
#include "Tool.h"
#include"Print.h"

#include<iostream>
#include <string>
#include <sstream>

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

    cout << "現在是第" << sequence << "位出牌" << endl;
    cout << endl;

    //以下部分都通過測試
    print.printHandCard();
    cout << endl << endl <<"   ";
    play.getPlayer().print();

    //電腦測試
    play.getComputer1().print();
    play.getComputer2().print();
    play.getComputer3().print();

    cout << endl;

    while (play.end() == false) {
    
        cout << "S :4是黑桃" << " " << "H :3是紅心" << " " << "C :2是梅花" << " " << "D :1是方塊" << endl << endl;
        cout << "請輸入英文+數字方式出牌，Ex:方塊3 = D3 or d3" << endl << endl;

        Computer c1;
        Game g;
        Card card1;

        Player p;
        p.playerOutCard();

        double ca[5] = {0,0,0,0,0};

        int caSize = 0;
        /**/
        for (int i = 0;i < 5;i++) {
            if (g.get1CardOnField(i) != 0) {
                ca[i] = 0;
                ca[i] = g.get1CardOnField(i);
                caSize++;
            }
        }

        int t = 0;

        switch (sequence) {
        case 1:
            for (int i = 0;i < 13;i++) {
                for (int j = 0;j < 5;j++) {
                    if (ca[j] != play.getPlayer().getIndexOfCard(i)) {
                        t++;
                    }
                }
            }
            if ((t + caSize) % 13 != 0) {
                cout << "please recin";
            }
            else {
                for (int i = 0;i < caSize;i++) {
                    cout << ca[i] << " ";
                }
            }
            t = 0;
            break;
        case 2:
            for (int i = 0;i < 13;i++) {
                for (int j = 0;j < 5;j++) {
                    if (ca[j] != play.getComputer1().getIndexOfCard(i)) {
                        t++;
                    }
                }
            }
            if ((t + caSize) % 13 != 0) {
                cout << "please recin";
            }
            else {
                for (int i = 0;i < caSize;i++) {
                    cout << ca[i] << " ";
                }
            }
            t = 0;
            break;
        case 3:
            for (int i = 0;i < 13;i++) {
                for (int j = 0;j < 5;j++) {
                    if (ca[j] != play.getComputer2().getIndexOfCard(i)) {
                        t++;
                    }
                }
            }
            if ((t + caSize) % 13 != 0) {
                cout << "please recin";
            }
            else {
                for (int i = 0;i < caSize;i++) {
                    cout << ca[i] << " ";
                }
            }
            t = 0;
            break;
        case 4:
            for (int i = 0;i < 13;i++) {
                for (int j = 0;j < 5;j++) {
                    if (ca[j] != play.getComputer3().getIndexOfCard(i)) {
                        t++;
                    }
                }
            }
            if ( (t + caSize) % 13 != 0) {
                cout << "please recin";
            }
            else {
                for (int i = 0;i < caSize;i++) {
                    cout << ca[i] << " ";
                }
            }
            t = 0;
            break;
        }

        cout << endl << endl;

        /*
        Check ch;
        cout << ch.checkCardsType(ca,Casize)<<endl;
        */
        
        if (sequence != 4) {
            sequence++;
        }
        else {
            sequence = sequence / 4;
        }
        
        cout << endl;

        print.printHandCard();
        cout << endl << endl << "   ";
        play.getPlayer().print();
        play.getComputer1().print();
        play.getComputer2().print();
        play.getComputer3().print();
        cout << endl;

        cout << "現在是第" << sequence << "位出牌" << endl;
        cout << endl;
        }
    return 0;
}
