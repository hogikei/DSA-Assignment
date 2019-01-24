#pragma once
#include <iostream>

// define character size
#define CHAR_SIZE 128

// A Class representing a Trie node
class Trie
{

public:

	bool isLeaf;

	Trie* character[CHAR_SIZE];
	int size;

	// Constructor

	Trie()
	{
		this->isLeaf = false;


		for (int i = 0; i < CHAR_SIZE; i++)
			this->character[i] = nullptr;

	}



	void insert(std::string);
	bool isEmpty();
	bool search(std::string);
	bool end(Trie const*);
	
};