#include "Deck.h"



Deck::Deck()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			
	
		}
	}
}

Deck::~Deck()
{
	Node *temp;
	for (int i = 0; i<length; i++)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

void Deck::insertCard(Card card)
{
	Node *temp = head;



}