#pragma once
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>
using namespace std;

class Card
{
public:
	string value;
	string suit;


	Card(string value, string suit);
	void show();
};


#endif
