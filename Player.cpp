#include "Player.h"

void Player::print()
{
	for (int i = 0; i < 13; i++) {
		cout << setw(6) << PlayerArr[i];
	}
	cout << endl;
}
