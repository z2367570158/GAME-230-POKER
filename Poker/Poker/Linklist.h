#pragma once
#define _CRTDBG_MAP_ALLOC
#define _CRTDBG_MAP_ALLOC_NEW
#include <cstdlib>
#include <crtdbg.h>
#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif

#ifndef LINKLIST_H
#define LINKLIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> 
#include <time.h>  

using namespace std;

struct Card
{
	int value;
	int suit;
	bool selected = false;
};

struct Node
{
	Card card;
	Node* next;
};

struct Linklist
{
	Node* head;
	int length;
};

Linklist* createLinklist();
void addFirst(Linklist* list, Card card);
void printList(Linklist* list);
string getCardInfo(Card card);
Card getItem(Linklist* list, int index);
void removeItem(Linklist* list, int index);
void deleteLinklist(Linklist* list);
int findCard(Linklist* list, Card card);

#endif 


