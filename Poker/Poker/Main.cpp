#include "Linklist.h"

Linklist* deck;
bool again = true;
bool win = false;
bool endgame = false;
int currentMoney;
Card inHand[5];

void initiate();
Card getRandomCard();
void printHand();
void printOptions();
bool invalidChoice(string choice);
void markInHand(string choice);
void getNewHand();
void checkHand();



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF |
		_CRTDBG_LEAK_CHECK_DF);

	srand((unsigned)time(NULL));
	currentMoney = 10;

	cout << "Hi, welcom to Video Poker!" << endl;
	cout << "Your current money is $" << currentMoney <<"."<< endl;
	initiate();


	while (currentMoney > 0&&!endgame)
	{
		currentMoney--;
		cout << "You pay a $1 and now have $" << currentMoney << "." << endl;

		for (int i = 0; i < 5; i++)
		{
			inHand[i] = getRandomCard();
		}

		while (!win)
		{
			
			printHand();

			cout << "The deck contains " << deck->length << " cards." << endl;

			printOptions();

			while (true)
			{
				cout << "YOUR CHOICE: ";
				string choice = "";
				cin >> choice;

				cout << endl;

				if (choice == "deck")
				{
					printList(deck);
				}
				else if (choice == "none")
				{

				}
				else if (choice == "all")
				{

				}
				else if (choice == "exit")
				{
					endgame = true;
					break;
				}
				else if (choice == "swap")
				{
					cout << "Enter the letter in your hand: ";
					char letter;
					cin >> letter;
					if (cin.good())
					{
						cin.clear();
						cin.ignore(1000, '\n');
						int value, suit;
						cout << "Enter the value you want: ";
						cin >> value;
						if (cin.good())
						{
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Enter the suit you want: ";
							cin >> suit;
							if (cin.good())
							{
								cin.clear();
								cin.ignore(1000, '\n');

							}
						}
					}
				}
				else
				{
					if (!invalidChoice(choice))
					{
						markInHand(choice);
						break;
					}
				}
			}

			if (endgame)
				break;


			getNewHand();

			checkHand();
		}
	}

	if(currentMoney <= 0)
		cout << "You are out of money, get out of my casino!!!" << endl;
	system("pause");
	deleteLinklist(deck);
}

void initiate()
{
	deck = createLinklist();

	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			Card card = {j,i};
			addFirst(deck, card);
		}
	}

}


Card getRandomCard()
{
	
	int index;
	if (deck->length == 1)
	{
		index = 0;
		Card card = getItem(deck, index);
		removeItem(deck, index);
		delete(deck);
		initiate();
		cout << "new deck" << endl;
		return card;
	}
	else
	{
		index = rand() % (deck->length - 1);
		Card card = getItem(deck, index);
		removeItem(deck, index);

		return card;
	}
	//cout << getCardInfo(getItem(deck, index)) << endl;
}

void printHand()
{
	cout << "\n"<<"You hand contains:" << endl;
	char option[5] = { 'A','B', 'C', 'D', 'E' };
	for (int i = 0; i < 5; i++)
	{
		cout << option[i] << ": " << getCardInfo(inHand[i]) << endl;
	}
	cout << endl;
}

void printOptions()
{
	cout << "\nOPTIONS..." << endl;
	cout << "- Type the letters for the cards you wish to keep. (i.e., \"acd\")"<< endl;
	cout << "- Type \"deck\" to view the cards remaining in the deck." << endl;
	cout << "- Type \"none\" to discard all cards in your hand." << endl;
	cout << "- Type \"all\" to keep all cards in your hand." << endl;
	cout << "- Type \"exit\" to exit the game." << endl;
	cout << "- Type \"swap\" to CHEAT and swap a card in your hand with one in the deck." << endl;
	cout << endl;
}


bool invalidChoice(string choice)
{
	if (choice.empty())
	{
		cout << "no input" << endl;
		return true;
	}
	else if (choice.length() > 5)
	{
		cout << "input more than 5 letters" << endl;
		return true;

	}
	else
	{
		for (int i = 0; i < choice.length(); i++)
		{
			if ((choice.c_str()[i] < 'a'|| choice.c_str()[i] > 'e')&&(choice.c_str()[i]<'A'||choice.c_str()[i]>'E'))
			{
				cout << "input include invalid letter(s)"<<endl;
				return true;
			}
		}

		return false;
	}
}

void markInHand(string choice)
{
	for (int i = 0; i < choice.length(); i++)
	{
		if (choice.c_str()[i] == 'a' || choice.c_str()[i] == 'A')
		{
			inHand[0].selected = true;
		}
		else if (choice.c_str()[i] == 'b' || choice.c_str()[i] == 'B')
		{
			inHand[1].selected = true;
		}
		else if (choice.c_str()[i] == 'c' || choice.c_str()[i] == 'C')
		{
			inHand[2].selected = true;
		}
		else if (choice.c_str()[i] == 'd' || choice.c_str()[i] == 'D')
		{
			inHand[3].selected = true;
		}
		else if (choice.c_str()[i] == 'e' || choice.c_str()[i] == 'E')
		{
			inHand[4].selected = true;
		}
	}
}

void getNewHand()
{

	Card temp[5];
	int selectedNum = 0;
	for (int i = 0; i < 5; i++)
	{
		if (inHand[i].selected)
		{
			temp[selectedNum] = inHand[i];
			selectedNum++;
		}
	}

	for (int i = selectedNum; i < 5; i++)
	{
		temp[i] = getRandomCard();
	}

	for (int i = 0; i < 5; i++)
	{
		inHand[i] = temp[i];
	}

}


void checkHand()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (inHand[i].value > inHand[j].value)
			{
				Card temp = inHand[i];
				inHand[i] = inHand[j];
				inHand[j] = temp;
			}
		}
	}

	//printHand();
	
	
	int rank = 0;

	//jacks or better


}