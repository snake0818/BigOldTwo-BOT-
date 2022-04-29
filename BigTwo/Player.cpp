#include "Player.h"

void Player::setArr(double Num, int index)
{
	PlayerArr[index] = Num;
}

bool Player::find(double num)
{
	for (int i = 0; i < 13; i++) {
		if (PlayerArr[i] == num) return true;
	}
	return false;
}

int Player::getNumOfCards() const
{
	int count = 0;
	for (int i = 0; i < 13; i++) {
		if (PlayerArr[i] != 0) count++;
	}
	return count;
}

void Player::arrange()
{
	const int size = 13;

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (PlayerArr[j] > PlayerArr[i])
			{
				double temp = PlayerArr[j];
				PlayerArr[j] = PlayerArr[i];
				PlayerArr[i] = temp;
			}
		}
	}
}

double Player::getCard(int index) const
{
	return PlayerArr[index];
}

void Player::print()
{
	for (int i = 0; i < 13; i++) {
		cout << setw(6) << PlayerArr[i];
	}
	cout << endl;
}
