#include <iostream>
using namespace std;

#include "PrintForMac.h"

void Print::welcome()
{
    cout << "歡迎來到 \"1 個孤獨的人也能玩的 4 人大老二\"" << endl;
}

void Print::rule()
{
    cout << "(按 Enter 顯示規則說明)" << endl;
    cin.get();
    clear();

    cout << "規則：\n\n"
         << "本遊戲採取的是一次一場 ， 一場12局的方式進行\n\n"
         << "牌的大小比較(優先)： 3 < 4 < 5 < ... < "
         << "10 < J(11) < Q(12) < K(13) < A(1) < 2\n"
         << endl
         << "\t    (次要)：方塊(Diamond) < 梅花(Club) < "
         << "紅心(Heart) < 黑桃(Spade)\n"
         << endl;
    cout << "\t    注意！！！ 方塊(Diamond) 才是最小的花色喔！！！\n";
    cout << endl;

    cout << "(按 Enter 顯示可出牌型)" << endl;
    cin.get();
    clear();

    cout << "注意！！！ 牌不是想出就出，必須比要上一個人出的牌還要大才能出牌喔！\n\n";
    cout << "牌型：\n\n"
         << "單張(Single)  : 總之就是出一張牌（先比數字大小再比花色）\n"
         << "一對(Pairs)   : 出兩張同數字的牌，遇見相同數字時比其中最大的花色大小\n"
         << "三條(Triples) : 出三張同數字的牌\n\n"

         << "順子(Straight) : 任五張有順序的牌，牌面最大為A2345、次之為23456、最小為34567，遇見相同數字時比其中最大的花色大小\n"
         << "順子可壓的牌型 : 順子、同花、葫蘆、四條、同花順\n\n"
         << "同花 (Flush) : 相同花色的五張牌，由最大的的點數作為牌面大小\n"
         << "同花可壓的牌型 : 同花、葫蘆、四條、同花順\n\n"
         << "葫蘆 Full house (gourd、Fullen): 三張同點數的牌和兩張同點數的牌，並由三張牌的點數作為牌面大小\n"
         << "葫蘆可壓的牌型 : 葫蘆、四條、同花順\n\n"
         << "四條(鐵支) Four-of-a-kind + One card (tiki): 四張同點數的牌和任一單張，並由四張牌的點數作為牌面大小\n"
         << "四條可壓的牌型 : 四條、同花順\n\n"
         << "同花順 Straight flush: 任五張有順序的牌，且五張牌皆為相同花色，先比較牌面大小，再比較花色\n"
         << "同花順可壓的牌型 : 同花順\n";
    cout << endl;

    cout << "(按 Enter 顯示結算方式)" << endl;
    cin.get();
    clear();

    cout << "結算方式:\n\n";
    cout << "若有人已結束手牌，該局就結束並計算每位玩家的手牌剩餘數，計算其失分。\n\n"
         << "失分方式:\n\n"
         << "若手牌殘餘八張以上(含八張)失分為兩倍\n\n"
         << "十張以上(含十張)失分為三倍\n\n"
         << "當手牌殘餘十三張，失分為四倍\n\n"
         << "另外，若殘餘手牌中每含有一張2，失分皆會倍增，請小心！！！\n\n\n";

    cout << "規則已清楚解釋完畢，現在開始進行我們的大老二遊戲吧！！！\n\n";
    // 未完待續
}

void Print::printHandCard()
{
    cout << "您的手牌目前有 : ";
}

void Print::fieldCard()
{
    cout << "場上的牌有 : ";
}

void Print::shuffleCard()
{
    cout << "(按 Enter 開始洗牌)" << endl;
    cin.get();
    clear();

    cout << "咻～咻～咻～  唰～唰～唰～\n\n";
}

void Print::printSequence(int sequence)
{
    cout << "本遊戲出牌的順序採取逆時鐘進行\n";
    if(sequence == 1)
    {
        cout << "本輪你的出牌順序（如下）\n\n"
             << "[[[[ 電腦(1) --> 電腦(2) -->"
             << "電腦(3) --> 玩家(you) ]]]]\n";
    }
    else if(sequence == 2)
    {
        cout << "本輪你的出牌順序（如下）\n\n"
             << "[[[[ 電腦(2) --> 電腦(3) -->"
             << "玩家(you) --> 電腦(1) ]]]]\n";
    }
    else if(sequence == 3)
    {
        cout << "本輪你的出牌順序（如下）\n\n"
             << "[[[[ 電腦(3) --> 玩家(you) -->"
             << "電腦(1) --> 電腦(2) ]]]]\n";
    }
    else if(sequence == 4)
    {
        cout << "本輪你的出牌順序（如下）\n\n"
             << "[[[[ 玩家(you) --> 電腦(1) -->"
             << "電腦(2) --> 電腦(3) ]]]]\n";
    }
    else
    {
        throw runtime_error("sequence error.");
    }
}

void Print::clear()
{
    system("clear");
}