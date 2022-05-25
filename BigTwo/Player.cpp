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
    
    for(int i=0;i<numberOfCards;i++){
    	double n=0;
        double textNumber=0;
        int dou=1;
        for(int k=0;k<cardByCin[i].size();k++){
            if(isCorrect==false){
                cout<<"Please recin"<<endl;
                break;
            }
        	string aa=cardByCin[i];
            if(k==0){
                if(aa[0]=='s' or aa[0]=='S'){
    		    	n=0.4;
    			}
    			if(aa[0]=='h' or aa[0]=='H'){
	    		    n=0.3;
    			}
 	  			if(aa[0]=='d' or aa[0]=='D'){
	        		n=0.1;
	    		}
	    		if(aa[0]=='c' or aa[0]=='C'){
	        		n=0.2;
    			}
    			if(aa[0]!='c' and aa[0]!='C' and aa[0]!='d' and aa[0]!='D' and aa[0]!='h' and aa[0]!='H' and aa[0]!='s' and aa[0]!='S'){
    			    isCorrect=false;
    			    cout<<"Error"<<endl;
    			}
            }
            else{
            	textNumber=(textNumber*dou)+(int(aa[k])-48);
				dou*=10;
			}
		if(n==0.4 or n==0.3 or n==0.2 or n==0.1){
		    if(textNumber>0 and textNumber<=13){
		        card[i]=textNumber+n;
		    }
		    else{
		        isCorrect=false;
		    }
		}
		else{
		    isCorrect=false;
		}
        }
    }
    if(isCorrect==true){
        Game().setField(card[0],card[1],card[2],card[3],card[4]);
    }
    else{
        Player().playerOutCard();
    }
}
