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

    // test
    play.getComputer1().setComputerArr(1.1, 0);
    play.getComputer1().setComputerArr(3.1, 1);
    play.getComputer1().setComputerArr(4.2, 2);
    play.getComputer1().setComputerArr(5.3, 3);
    play.getComputer1().setComputerArr(6.4, 4);
    play.getComputer1().setComputerArr(4.1, 5);
    play.getComputer1().setComputerArr(4.2, 6);
    play.getComputer1().setComputerArr(5.1, 7);
    play.getComputer1().setComputerArr(5.2, 8);
    play.getComputer1().setComputerArr(6.1, 9);
    play.getComputer1().setComputerArr(6.2, 10);
    play.getComputer1().setComputerArr(7.1, 11);
    play.getComputer1().setComputerArr(8.1, 12);

    play.getComputer2().setComputerArr(0, 0);
    play.getComputer2().setComputerArr(0, 1);
    play.getComputer2().setComputerArr(0, 2);
    play.getComputer2().setComputerArr(0, 3);
    play.getComputer2().setComputerArr(0, 4);
    play.getComputer2().setComputerArr(0, 5);
    play.getComputer2().setComputerArr(0, 6);
    play.getComputer2().setComputerArr(0, 7);
    play.getComputer2().setComputerArr(0, 8);
    play.getComputer2().setComputerArr(0, 9);
    play.getComputer2().setComputerArr(0, 10);
    play.getComputer2().setComputerArr(1.1, 11);
    play.getComputer2().setComputerArr(2.1, 12);

    play.getComputer3().setComputerArr(0, 0);
    play.getComputer3().setComputerArr(0, 1);
    play.getComputer3().setComputerArr(0, 2);
    play.getComputer3().setComputerArr(0, 3);
    play.getComputer3().setComputerArr(0, 4);
    play.getComputer3().setComputerArr(0, 5);
    play.getComputer3().setComputerArr(0, 6);
    play.getComputer3().setComputerArr(0, 7);
    play.getComputer3().setComputerArr(0, 8);
    play.getComputer3().setComputerArr(0, 9);
    play.getComputer3().setComputerArr(0, 10);
    play.getComputer3().setComputerArr(1.1, 11);
    play.getComputer3().setComputerArr(2.1, 12);

    // test
    play.getComputer1().print();
    play.getComputer2().print();
    play.getComputer3().print();
    play.getPlayer().printPlayer_arr();

    play.outCardSequence();

    // Print().printTable();

    // test
    play.getComputer1().print();
    play.getComputer2().print();
    play.getComputer3().print();
    play.getPlayer().printPlayer_arr();

    return 0;
}
