#include "Table.h"
#include "Tool.h"

int Table::count = 1;

Player Table::getPlayer() const
{
    return player;
}

Computer Table::getComputer1() const
{
    return computer1;
}

Computer Table::getComputer2() const
{
    return computer2;
}

Computer Table::getComputer3() const
{
    return computer3;
}

void Table::start()
{
    double *list = new double[52];
    list = Game().shuffleCards();

    for (int i = 0; i < 52; i += 4) 
    {
        player.setPlayerArr(list[i], i / 4);
        computer1.setComputerArr(list[i + 1], i / 4);
        computer2.setComputerArr(list[i + 2], i / 4);
        computer3.setComputerArr(list[i + 3], i / 4);
    }

    Tool().arrange(player.getPlayer_arr(), 13);
    Tool().arrange(computer1.getComputer_arr(), 13);
    Tool().arrange(computer2.getComputer_arr(), 13);
    Tool().arrange(computer3.getComputer_arr(), 13);

    delete [] list;
}

int Table::whoFirst()
{
    const double firstNum = 3.1;
    if (player.isInPlayer_arr(firstNum))
    {
        count = 4;
    }
    if (computer1.isInComputer_arr(firstNum))
    {
        count = 1;
    }
    if (computer2.isInComputer_arr(firstNum))
    {
        count = 2;
    }
    if (computer3.isInComputer_arr(firstNum))
    {
        count = 3;
    }
    return count;
}

bool Table::end()
{
    if (player.getHandCardsSize() == 0 || computer1.getHandCardsSize() == 0 || computer2.getHandCardsSize() == 0 || computer3.getHandCardsSize() == 0)
        return true;
    return false;
}
void Table::playerOutCard(){
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
        Table().playerOutCard();
    }
}
