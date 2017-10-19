#pragma once

#include "Card.h"
struct Node
{
	Card card;
	Node* next;
};



class Deck
{
public:
	Node *head;
	int length;
	Deck();
	~Deck();
	void insertCard(Card card);

};

