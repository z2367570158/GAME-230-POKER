#include "Card.h"




Card::Card(string value, string suit)
{
	Card::value = value;
	Card::suit = suit;
}

void Card::show()
{
	cout << value << " of " << suit;
}