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

    // test
    play.getComputer1().print();
    play.getComputer2().print();
    play.getComputer3().print();
    play.getPlayer().printPlayer_arr();

    play.outCardSequence();

    Print().printTable();

    // test
    play.getComputer1().print();
    play.getComputer2().print();
    play.getComputer3().print();
    play.getPlayer().printPlayer_arr();

    return 0;
}
