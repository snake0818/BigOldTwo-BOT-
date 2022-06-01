#include "Card.h"
#include "Check.h"
#include "Computer.h"
#include "Game.h"
#include "Player.h"
#include "Table.h"
#include "Tool.h"
#include "PrintForMac.h"
#include "OutOfCard.h"

int main()
{
    Print().welcome();
    Print().rule();
    Print().shuffleCard();

    Table play;
    play.start();
    int sequence = play.whoFirst();

    Print().printSequence(sequence);

    // play.getComputer1().print();
    // play.getComputer2().print();
    // play.getComputer3().print();
    
    // test
    // play.getPlayer().printPlayer_arr();
    // OutOfCard().computerFirstOutHand(play.getComputer1());
    // OutOfCard().computerFirstOutHand(play.getComputer2());
    // OutOfCard().computerFirstOutHand(play.getComputer3());

    play.outCardSequence();

    Print().printTable();

    // while(sequence != 4) // while for test
    // {
    //     cout << "Computer time." << endl;
    //     sequence++;
    // }

    // if(sequence == 4)
    // {
    //     print.OutCard(play);
    //     sequence++;
    // }

    return 0;
}
