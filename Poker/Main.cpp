#include "Config.h"
#include "Deck.h"

int startMoney;
int currentMoney;


bool again;

void initiate();


int main()
{
	initiate();

	cout<<"Welcom to Video Poker!!!"<<endl;
	cout << "Your current money is $"<<currentMoney << endl;
	Deck deck = Deck();
	while (again&&currentMoney>0)
	{
		if (deck.head->next == NULL)
		{
			cout <<"NO"<< endl;
		}










	}
	system("PAUSE");

}

void initiate()
{
	again = true;
	startMoney = 10;
	currentMoney = startMoney;


}

bool checkCommand(string input)
{
	if (input == commandDeck)
	{


	}
	else if (input == commandAll)
	{

	}
	else if (input == commandExit)
	{

	}
	else if (input == commandNone)
	{

	}

	return false;
}

