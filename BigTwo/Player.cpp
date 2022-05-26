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

double* Player::getPlayer_arr()
{
	return player_arr;
}
void Player::playerOutCard(){
    isCorrect=true;
    string playerOutCard;
    getline(cin,playerOutCard);
    stringstream word(playerOutCard);

    string cardByCin[5];
    double card[5]={0,0,0,0,0};
    
    int numberOfCards=0;
    while(!word.eof()){
    	word>>cardByCin[numberOfCards];
        numberOfCards++;
    }
    isCorrect=true;
    for(int i=0;i<numberOfCards;i++){
        if(cardByCin[0]=="pass" or cardByCin[0]=="Pass"){
            break;
        }
        string textWord=cardByCin[i];
        double douNumber=0;
        double intNumber=0;
        isCorrect=false;
        for(int k=0;k<cardByCin[i].size();k++){
            if(k==0){
                if(textWord[0]=='c' or textWord[0]=='C'){
                    douNumber=0.1;
                    isCorrect=true;
                }
                if(textWord[0]=='d' or textWord[0]=='D'){
                    douNumber=0.2;
                    isCorrect=true;
                }
                if(textWord[0]=='h' or textWord[0]=='H'){
                    douNumber=0.3;
                    isCorrect=true;
                }
                if(textWord[0]=='s' or textWord[0]=='S'){
                    douNumber=0.4;
                    isCorrect=true;
                }
            }
            else{
                int text=int(textWord[k])-48;
                intNumber=intNumber*10+text;
            }
        }
        if(isCorrect==false){
            cout<<"Please recin"<<endl;
            break;
        }
        Game().setField_2(intNumber+douNumber,i);
    }
    if(cardByCin[0]=="pass" or cardByCin[0]=="Pass"){
        cout<<"Pass"<<endl;
    }
    if(isCorrect==false){
        Player().playerOutCard();
    }
}
