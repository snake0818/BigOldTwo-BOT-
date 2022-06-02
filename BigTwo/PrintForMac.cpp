#include <iostream>
using namespace std;

#include "PrintForMac.h"

Print::Print() {}

void Print::welcome()
{
    cout << "\e[31m歡迎來到 \e[0m\e[32m1 個孤獨的人也能玩的 4 人大老二\e[0m" << endl;
}

void Print::rule()
{
    cout << "(按 Enter 顯示規則說明)" << endl;
    cin.get();
    clear();

    cout << "\e[32m規則：\e[0m\n\n"
         << "\e[33m本遊戲採取的是一次一場 ， 一場12局的方式進行\e[0m\n\n"
         << "\e[35m牌的大小比較(優先)：\e[0m 3 < 4 < 5 < ... < "
         << "10 < J(11) < Q(12) < K(13) < A(1) < 2\n"
         << endl
         << "\t    \e[35m(次要)：\e[0m方塊(Diamond) < 梅花(Club) < "
         << "紅心(Heart) < 黑桃(Spade)\n"
         << endl;
    cout << "\t    \e[31m注意！！！ 方塊(Diamond) 才是最小的花色喔！！！\e[0m\n";
    cout << endl;

    cout << "(按 Enter 顯示可出牌型)" << endl;
    cin.get();
    clear();

    cout << "\e[31m注意！！！ 牌不是想出就出，必須比要上一個人出的牌還要大才能出牌喔！\e[0m\n\n";
    cout << "\e[32m牌型：\e[0m\n\n"
         << "\e[35m單張(Single)  :\e[0m \e[0m總之就是出一張牌（先比數字大小再比花色）\n"
         << "\e[35m一對(Pairs)   :\e[0m 出兩張同數字的牌，遇見相同數字時比其中最大的花色大小\n"
         << "\e[35m三條(Triples) :\e[0m 出三張同數字的牌\n\n"

         << "\e[35m順子(Straight) :\e[0m 任五張有順序的牌，牌面最大為A2345、次之為23456、最小為34567，遇見相同數字時比其中最大的花色大小\n"
         << "\e[35m順子可壓的牌型 :\e[0m 順子、同花、葫蘆、四條、同花順\n\n"
         << "\e[35m同花 (Flush)  :\e[0m 相同花色的五張牌，由最大的的點數作為牌面大小\n"
         << "\e[35m同花可壓的牌型 :\e[0m 同花、葫蘆、四條、同花順\n\n"
         << "\e[35m葫蘆 Full house (gourd、Fullen):\e[0m 三張同點數的牌和兩張同點數的牌，並由三張牌的點數作為牌面大小\n"
         << "\e[35m葫蘆可壓的牌型 :\e[0m 葫蘆、四條、同花順\n\n"
         << "\e[35m四條(鐵支) Four-of-a-kind + One card (tiki):\e[0m 四張同點數的牌和任一單張，並由四張牌的點數作為牌面大小\n"
         << "\e[35m四條可壓的牌型 :\e[0m 四條、同花順\n\n"
         << "\e[35m同花順 Straight flush :\e[0m 任五張有順序的牌，且五張牌皆為相同花色，先比較牌面大小，再比較花色\n"
         << "\e[35m同花順可壓的牌型 :\e[0m 同花順\n";
    cout << endl;

    cout << "(按 Enter 顯示結算方式)" << endl;
    cin.get();
    clear();

    cout << "\e[32m結算方式 : \e[0m\n\n";
    cout << "若有人已結束手牌，該局就結束並計算每位玩家的手牌剩餘數，計算其失分。\n\n"
         << "\e[32m失分方式 :\e[0m\n\n"
         << "若手牌殘餘八張以上(含八張)失分為兩倍\n\n"
         << "十張以上(含十張)失分為三倍\n\n"
         << "當手牌殘餘十三張，失分為四倍\n\n"
         << "另外，若殘餘手牌中每含有一張2，失分皆會倍增，請小心！！！\n\n\n";

    cout << "\e[07;33m規則已清楚解釋完畢，現在開始進行我們的大老二遊戲吧！！！\e[0m\n\n";
    // 未完待續
}

void Print::printHandCard(Table& t)
{
    cout << "\e[32m您目前的手牌有 : \e[0m";
    t.getPlayer().printPlayer_arr();
}

void Print::fieldCard()
{
    cout << "\e[32m場上的牌有 : \e[0m";
}

void Print::shuffleCard()
{
    cout << "(按 Enter 開始洗牌)" << endl;
    cin.get();
    clear();

    cout << "\e[31m咻～咻～咻～  唰～唰～唰～\e[0m\n\n";
    cout << "\e[32m咻～咻～咻～  唰～唰～唰～\e[0m\n\n";
    cout << "\e[33m咻～咻～咻～  唰～唰～唰～\e[0m\n\n";
}

void Print::printSequence(int sequence)
{
    cout << "本遊戲出牌的順序採取逆時鐘進行\n";
    if(sequence == 1)
    {
        cout << "本輪你的出牌順序（如下）\n\n"
             << "[[[[ \e[31m電腦(1)\e[0m --> \e[31m電腦(2)\e[0m --> "
             << "\e[31m電腦(3)\e[0m --> \e[33m玩家(you)\e[0m ]]]]\n";
    }
    else if(sequence == 2)
    {
        cout << "本輪你的出牌順序（如下）\n\n"
             << "[[[[ \e[31m電腦(2)\e[0m --> \e[31m電腦(3)\e[0m --> "
             << "\e[33m玩家(you)\e[0m --> \e[31m電腦(1)\e[0m ]]]]\n";
    }
    else if(sequence == 3)
    {
        cout << "本輪你的出牌順序（如下）\n\n"
             << "[[[[ \e[31m電腦(3)\e[0m --> \e[33m玩家(you)\e[0m --> "
             << "\e[31m電腦(1)\e[0m --> \e[31m電腦(2)\e[0m ]]]]\n";
    }
    else if(sequence == 4)
    {
        cout << "本輪你的出牌順序（如下）\n\n"
             << "[[[[ \e[33m玩家(you)\e[0m --> \e[31m電腦(1)\e[0m --> "
             << "\e[31m電腦(2)\e[0m --> \e[31m電腦(3)\e[0m ]]]]\n";
    }
    else
    {
        throw runtime_error("sequence error.");
    }

    cout << "(按 Enter 繼續)" << endl;
    cin.get();
    system("clear");
}

void Print::clear()
{
    system("clear");
}

void Print::OutCard(Table& t)
{
    cout << "\e[31m輪到你出牌囉！！！\e[0m\n";
    cout << "(按 Enter 繼續)" << endl;
    cin.get();
    system("clear");

    printHandCard(t);
    cout << endl;
}

void Print::printTable()
{
    printShape();
    cout << endl;

    double *table = Game().getCardsOnField();
    if(table[0] == 0)
    {
        cout << "\e[07;33m場上目前沒有牌喔！等你開秀！！！\e[0m" << endl;
    }
    else
    {
        for(int i = 0; i < 5; i++)
        {
            if(table[i] == 0)
            {
                break;
            }
            cout << table[i] << "\t";
        }
        cout << endl;
    }

    cout << endl;
    printShape();
}

void Print::printShape()
{
    cout << "++";
    for(int i = 0; i < 76; i++)
    {
        cout << "=";
    }
    cout << "++" << endl;
}