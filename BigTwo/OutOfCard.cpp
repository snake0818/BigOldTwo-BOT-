#include "OutOfCard.h"
#include "Card.h"
#include "Tool.h"

OutOfCard::OutOfCard() {}

void OutOfCard::FirstOutHand(Player player)
{
    Tool().copyDouble_arr(player.getPlayer_arr(), handCard, 13);
    // 已經測試過複製無誤
}

void OutOfCard::FirstOutHand(Computer computer)
{
    
}