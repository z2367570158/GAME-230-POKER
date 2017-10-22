#include "Linklist.h"

Linklist* createLinklist()
{
	Linklist* list = new Linklist;
	list->head = nullptr;
	list->length = 0;

	return list;
}



void addFirst(Linklist* list, Card card)
{
	Node* node = new Node;
	node->card = card;
	node->next = list->head;
	list->head = node;
	list->length++;
}

void printList(Linklist* list)
{
	Node* node = list->head;
	while (node->next != nullptr)
	{
		cout << getCardInfo(node->card) << ", ";
		node = node->next;
	}
	cout << getCardInfo(node->card) << endl;
}

string getCardInfo(Card card)
{
	string info = "";
	stringstream ss;
	switch (card.value)
	{
	case 11:
		info += "Jack";
		break;
	case 12:
		info =+ "Queen";
		break;
	case 13:
		info += "King";
		break;
	case 1:
		info += "Ace";
		break;
	case 10:
		info += "10";
		break;
	default:
		ss << card.value;
		info += ss.str();
		break;
	}

	info += " of ";

	switch (card.suit)
	{
	case 0:
		info += "Hearts";
		break;
	case 1:
		info += "Spades";
		break;
	case 2:
		info += "Diamonds";
		break;
	case 3:
		info += "Clubs";
		break;
	}

	if (card.selected)
	{
		info += "(kept)";
	}

	return info;
}


Card getItem(Linklist* list, int index)
{
	Node* node = list->head;
	while (index > 0)
	{
		node = node->next;
		index--;
	}

	return node->card;
}


void removeItem(Linklist* list, int index)
{
	if (list->head == nullptr)
	{
		cout << "Linklist is empty" << endl;
	}
	else if (index == 0)
	{
		Node* temp = list->head;
		list->head = list->head->next;
		list->length--;
		delete temp;
	}
	else
	{
		Node* temp = list->head;
		while (index > 1)
		{
			temp = temp->next;
			index--;
		}
		Node* node = temp->next;
		temp->next = temp->next->next;
		list->length--;

		delete node;
	}


}

void deleteLinklist(Linklist* list)
{
	Node* node = list->head;
	while (node != nullptr)
	{
		Node* temp = node;
		node = node->next;
		delete temp;
	}
	delete list;
}

int findCard(Linklist* list,Card card)
{
	Node* node = list->head;
	int index = 0;
	while (node != nullptr)
	{
		if(card.value == node->card.value&& card.suit == node->card.suit)
		{
			return index;
		}
		node = node->next;
		index++;
	}
	return -1;
}