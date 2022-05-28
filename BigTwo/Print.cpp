#include <iostream>
using namespace std;

#include "Print.h"

void Print::welcome()
{
    cout << "歡迎來到 \"1 個孤獨的人也能玩的 4 人大老二\"" << endl;
}

void Print::rule()
{
    cout << "(按 Enter 顯示規則說明)" << endl;
    cin.get();

    cout << "規則：\n"
        << "牌的大小比較(優先)： 3 < 4 < 5 < ... < "
        << "10 < J(11) < Q(12) < K(13) < A(1) < 2\n" 
        << "\t    （次要)：方塊(diamond) < 梅花(club) < "
        << "紅心(heart) < 黑桃(spade)\n" << endl;
    cout << "\t     注意！！！ 方塊(diamond) 才是最小的花色喔！！！\n";
    cout << endl;

    cout << "(按 Enter 顯示可出牌型)" << endl;
    cin.get();

    cout << "牌不是想出就出，必須比上一個人出的還要大才能出牌喔！\n\n"
        << "單張(Single) : 總之就是出一張牌（先比數字大小在比花色）\n"
        << "一對(Pairs)  : 出兩張同數字的牌，遇見相同數字時比其中最大的花色大小\n";
    // 未完待續
}