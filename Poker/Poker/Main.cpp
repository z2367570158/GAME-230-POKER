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
bool invalidChoice(string choice, int index);
void markInHand(string choice);
void getNewHand();
void checkHand();
void swapCard();

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

		win = false;

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
					markInHand("");
					break;

				}
				else if (choice == "all")
				{
					markInHand("abcde");
					break;

				}
				else if (choice == "exit")
				{
					endgame = true;
					break;
				}
				else if (choice == "swap")
				{
					swapCard();
				}
				else
				{
					if (!invalidChoice(choice, choice.length()))
					{
						markInHand(choice);
						break;
					}
				}
			}

			if (endgame)
				break;


			getNewHand();
			printHand();
			checkHand();


			cout << "Press Enter to Continue"; 
			char temp = 'x';
			cin.clear();
			cin.ignore(1000, '\n');
			while (temp != '\n')
			{
				cin.get(temp);
			}
			system("cls");
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


bool invalidChoice(string choice, int index)
{
	if (choice.empty())
	{
		cout << "no input" << endl;
		return true;
	}
	else if (choice.length() > index)
	{
		cout << "input more than "<<index<<" letters" << endl;
		return true;

	}
	else
	{
		for (int i = 0; i < index; i++)
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

	cout << "you kept " << selectedNum << " and drew " << 5 - selectedNum << " cards" << endl;

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
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (inHand[i].value == inHand[i + 1].value)
			count++;
	}
	
	int rank = 0;

	bool temp = false;
	switch (count)
	{
	case 0:
		if (inHand[4].value - inHand[0].value == 4 && inHand[4].value - inHand[1].value == 3 && inHand[4].value - inHand[2].value == 2 && inHand[4].value - inHand[3].value == 1
			|| inHand[0].value == 1 && inHand[1].value == 10 && inHand[2].value == 11 && inHand[3].value == 12 && inHand[4].value == 13)
		{
			rank = 4;//straight
		}
		else
			rank = 0;//high card
		break;
	case 1:
		for (int i = 0; i < 4; i++)
		{
			if (inHand[i].value == 11 && inHand[i + 1].value == 11)
				rank = 1;//jacks or better
			else
				rank = 0;//high card
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++)
		{
			if (inHand[i].value == inHand[i + 2].value)
			{
				rank = 3;//three of a kind
				temp = true;
				break;
			}
		}
		if (!temp)
		{
			rank = 2;//two pairs
		}
		break;
	case 3:
		if (inHand[1].value == inHand[3].value)
			rank = 7;//four of a kind
		else
			rank = 6;//full house
		break;
	}

	
	if (inHand[0].suit == inHand[1].suit || inHand[1].suit == inHand[2].suit || inHand[2].suit == inHand[3].suit || inHand[3].suit == inHand[4].suit)
	{
		if (rank < 4)
			rank = 5;
		else if (rank == 4)
		{
			if (inHand[0].value==1&& inHand[1].value == 10 && inHand[2].value == 11 && inHand[3].value == 12 && inHand[4].value == 13)
			{
				rank = 9;
			}
			else
			{
				rank = 8;
			}
		}
	}
		



	if (rank ==0)
	{
		cout << "sorry, no poker hand score " << currentMoney << endl;
	}
	else if (rank == 1)
	{
		currentMoney += 1;
		cout << "Jacks or better! you get $1, now you have " <<currentMoney << endl;
	}
	else if (rank == 2)
	{
		currentMoney += 2;
		cout << "two pairs! you get $2, now you have " << currentMoney << endl;
	}
	else if (rank == 3)
	{
		currentMoney += 3;
		cout << "three of a kind! you get $3, now you have $" << currentMoney << endl;
	}
	else if (rank == 4)
	{
		currentMoney += 4;
		cout << "straight! you get $4, now you have $" << currentMoney << endl;
	}
	else if (rank == 5)
	{
		currentMoney += 6;
		cout << "flush! you get $6, now you have $" << currentMoney << endl;
	}
	else if (rank == 6)
	{
		currentMoney += 9;
		cout << "full house! you get $9, now you have $" << currentMoney << endl;
	}
	else if (rank == 7)
	{
		currentMoney += 25;
		cout << "four of a kind! you get $25, now you have $" << currentMoney << endl;
	}
	else if (rank == 8)
	{
		currentMoney += 50;
		cout << "straight flush! you get $50, now you have $" << currentMoney << endl;
	}
	else if (rank == 9)
	{
		currentMoney += 800;
		cout << "royal flush! you get $800, now you have $" << currentMoney << endl;
	}

	win = true;
}

void swapCard()
{
	cout << "Enter the letter in your hand: ";
	bool lettervalid = false;;
	char letter;
	cin >> letter;
	while(!lettervalid)
	{
		while (!cin.good())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "invalid value, reinpur: ";
			cin >> letter;
		}
		cin.ignore(1000, '\n');

		if (letter == 'a' || letter == 'b' || letter == 'c' || letter == 'd' || letter == 'e' || letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'E')
		{
			lettervalid = true;
		}
	}

	bool valuevalid = false;
	int value;
	cout << "Enter the value you want: ";
	cin >> value;
	while (!valuevalid)
	{
		while (!cin.good())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "invalid value, reinpur: ";
			cin >> value;
		}
		cin.ignore(1000, '\n');

		if (value <= 13 && value >= 1)
		{
			valuevalid = true;
		}
	}

	bool suitvalid = false;
	char suit;
	cout << "Enter the suit you want (c,h,d,s): ";
	cin >> suit;
	while (!suitvalid)
	{
		while (!cin.good())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "invalid suit, reinpur: ";
			cin >> suit;
		}
		cin.ignore(1000, '\n');


		if (suit != 'c' || suit != 'd' || suit != 'h' || suit != 's' || suit != 'C' || suit != 'D' || suit != 'H' || suit != 'S')
		{
			suitvalid = true;
		}
	}
	int intsuit;
	if (suit == 'c' || suit == 'C')
		intsuit = 3;
	else if(suit == 'd'|| suit =='D')
		intsuit = 2;
	else if (suit == 's' || suit == 'S')
		intsuit = 1;
	else if (suit == 'h' || suit == 'H')
		intsuit = 0;

	Card target = { value, intsuit, false };
	int targetIndex = findCard(deck, target);
	if (targetIndex==-1)
	{
		cout << "card is not in deck" << endl;
	}
	else
	{
		Node* node = deck->head;
		while (targetIndex > 0)
		{
			node = node->next;
			targetIndex--;
		}
		if (letter == 'a' || letter == 'A')
		{
			node->card = inHand[0];
			inHand[0] = target;
		}
		else if (letter == 'b' || letter == 'B')
		{

			node->card = inHand[1];
			inHand[1] = target;
		}
		else if (letter == 'c' || letter == 'C')
		{

			node->card = inHand[2];
			inHand[2] = target;
		}
		else if (letter == 'd' || letter == 'D')
		{

			node->card = inHand[3];
			inHand[3] = target;
		}
		else if (letter == 'e' || letter == 'E')
		{
			node->card = inHand[4];
			inHand[4] = target;
		}
		cout << "swap done" << endl;
	}

}