#include "Card.h"
#include "Check.h"
#include "Computer.h"
#include "Game.h"
#include "Player.h"
#include "Table.h"
#include "Tool.h"
#include "Print.h"

int main()
{
    Print print;
    print.welcome();
    print.rule();

    Table play;
    play.start();
    int sequence = play.whoFirst();

    /*    
        以下部分都通過測試
        play.getPlayer().print();
        play.getComputer1().print();
        play.getComputer2().print();
        play.getComputer3().print();
    */

    return 0;
}