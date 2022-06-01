#include "Computer.h"
#include "Tool.h"

Computer::Computer()
{
    for(int i = 0; i < 13; i++)
    {
        computer_arr[i] = 0;
    }
}

void Computer::setComputerArr(double num, int index)
{
    computer_arr[index] = num;
}

bool Computer::isInComputer_arr(double num)
{
    for (int i = 0; i < 13; i++)
    {
        if (computer_arr[i] == num)
        {
            return true;
        }
    }
    return false;
}

int Computer::getHandCardsSize() const
{
    int count = 0;
    for (int i = 0; i < 13; i++)
    {
        if (computer_arr[i] != 0)
        {
            count++;
        }
    }
    return count;
}

double Computer::getIndexOfCard(int index) const
{
    return computer_arr[index];
}

// test
void Computer::print()
{
    for(auto i:computer_arr)
    {
        cout << setw(6) << i;
    }
    cout << endl;
}

double* Computer::getComputer_arr()
{
	return computer_arr;
}
void Computer::computerOutCard(){
    double cardsField[5];
    double cardsByComputer[13];
    for(int i=0;i<13;i++){
        if(int(computer_arr[i])==1 or int(computer_arr[i])==2){
            cardsByComputer[i]=computer_arr[i]+13;
        }
        else{
            cardsByComputer[i]=computer_arr[i];
        }
    }
    int text=0;
    for(int i=0;i<5;i++){
        cardsField[i]=Game().get1CardOnField(i);
        if(Game().get1CardOnField(i)!=0){
            text++;
        }
    }
    if(text==1){
        double text_che=15;
        int side;
        for(int i=0;i<13;i++){
            if( (cardsByComputer[i]-Game().get1CardOnField(i))>0 and (cardsByComputer[i]-Game().get1CardOnField(i))<text_che ){
                side=i;
                cout<<"sc"<<endl;
            }
        }
        Game().setField(cardsByComputer[side],0);
    }
}
