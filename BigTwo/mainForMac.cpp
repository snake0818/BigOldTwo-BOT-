#include "Card.h"
#include "Check.h"
#include "Computer.h"
#include "Game.h"
#include "Player.h"
#include "Table.h"
#include "Tool.h"
#include "PrintForMac.h"
#include "OutOfCard.h"
#include "Compare.h"

int main()
{
    Print().welcome();
    Print().rule();
    Print().shuffleCard();

    Table play;
    play.start();
    int sequence = play.whoFirst();

    Print().printSequence(sequence);

    while(!play.end())
    {
        play.outCardSequence();
    }

    Print().printWhoWin(play);

    return 0;
}
