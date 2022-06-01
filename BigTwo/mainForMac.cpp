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
    // play.getComputer1().setComputerArr(1.1, 0);
    // play.getComputer1().setComputerArr(3.1, 1);
    // play.getComputer1().setComputerArr(3.2, 2);
    // play.getComputer1().setComputerArr(3.3, 3);
    // play.getComputer1().setComputerArr(3.4, 4);
    // play.getComputer1().setComputerArr(4.1, 5);
    // play.getComputer1().setComputerArr(4.2, 6);
    // play.getComputer1().setComputerArr(5.1, 7);
    // play.getComputer1().setComputerArr(5.2, 8);
    // play.getComputer1().setComputerArr(6.1, 9);
    // play.getComputer1().setComputerArr(6.2, 10);
    // play.getComputer1().setComputerArr(7.1, 11);
    // play.getComputer1().setComputerArr(8.1, 12);

    // play.getComputer2().setComputerArr(1.1, 0);
    // play.getComputer2().setComputerArr(3.1, 1);
    // play.getComputer2().setComputerArr(3.2, 2);
    // play.getComputer2().setComputerArr(3.3, 3);
    // play.getComputer2().setComputerArr(3.4, 4);
    // play.getComputer2().setComputerArr(4.1, 5);
    // play.getComputer2().setComputerArr(4.2, 6);
    // play.getComputer2().setComputerArr(5.1, 7);
    // play.getComputer2().setComputerArr(5.2, 8);
    // play.getComputer2().setComputerArr(6.1, 9);
    // play.getComputer2().setComputerArr(6.2, 10);
    // play.getComputer2().setComputerArr(7.1, 11);
    // play.getComputer2().setComputerArr(8.1, 12);

    // play.getComputer3().setComputerArr(1.1, 0);
    // play.getComputer3().setComputerArr(3.1, 1);
    // play.getComputer3().setComputerArr(3.2, 2);
    // play.getComputer3().setComputerArr(3.3, 3);
    // play.getComputer3().setComputerArr(3.4, 4);
    // play.getComputer3().setComputerArr(4.1, 5);
    // play.getComputer3().setComputerArr(4.2, 6);
    // play.getComputer3().setComputerArr(5.1, 7);
    // play.getComputer3().setComputerArr(5.2, 8);
    // play.getComputer3().setComputerArr(6.1, 9);
    // play.getComputer3().setComputerArr(6.2, 10);
    // play.getComputer3().setComputerArr(7.1, 11);
    // play.getComputer3().setComputerArr(8.1, 12);

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
