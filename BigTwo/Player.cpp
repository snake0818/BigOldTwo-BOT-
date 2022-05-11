#include "Player.h"

Player::Player()
{
	for (int i = 0; i < 13; i++)
	{
		player_arr[i] = 0;
	}
}

void Player::setPlayerArr(double num, int index)
{
	player_arr[index] = num;
}

bool Player::isInPlayer_arr(double num)
{
	for (int i = 0; i < 13; i++)
	{
		if (player_arr[i] == num)
		{
			return true;
		}
	}
	return false;
}

int Player::getHandCardsSize() const
{
	int count = 0;
	for (int i = 0; i < 13; i++)
	{
		if (player_arr[i] != 0)
			count++;
	}
	return count;
}

double Player::getIndexOfCard(int index) const
{
	return player_arr[index];
}

void Player::print()
{
	for (int i = 0; i < 13; i++)
	{
		cout << setw(6) << player_arr[i];
	}
	cout << endl;
}