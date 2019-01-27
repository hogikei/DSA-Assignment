#include "pch.h"
#include "Trie.h"
#include <iostream>
#include "string"
// Converts key current character into index 
// use only 'a' through 'z' and lower case 
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 

using namespace std;

// Iterative function to insert a key in the Trie
void Trie::insert(std::string key)
{
	// start from root node
	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		// create a new node if path doesn't exists
		if (curr->character[key[i]] == nullptr)
			curr->character[key[i]] = new Trie();

		// go to next node
		curr = curr->character[key[i]];
	}

	// mark current node as leaf
	curr->isLeaf = true;
	size += 1;
}

// Iterative function to search a key in Trie. It returns true
// if the key is found in the Trie, else it returns false
bool Trie::search(std::string key)
{
	// return false if Trie is empty
	if (this == nullptr)
		return false;

	Trie* curr = this;
	for (int i = 0; i < key.length(); i++)
	{
		// go to next node
		curr = curr->character[key[i]];

		// if string is invalid (reached end of path in Trie)
		if (curr == nullptr)
			return false;
	}

	// if current node is a leaf and we have reached the
	// end of the string, return true
	return curr->isLeaf;
}

// returns true if given node has any children
bool Trie::end(Trie const* curr)
{
	for (int i = 0; i < CHAR_SIZE; i++)
		if (curr->character[i])
			return true;	// child found

	return false;
}




bool Trie::isEmpty() 
{
	return (size == 0);
}


bool Trie::DisplayPrefix(string input, int length)
{
	//search for a prefix from trie
	bool Validate = false;
	Trie* trie = new Trie;

	if (this == nullptr)
		return false;
	else
	{
		Trie* current = this;
		for (int i = 0; i < length; i++) {
			if (current->character[input[i]] == nullptr) {
				Validate = false;
				break;
			}
			else {
				current = current->character[input[i]];
				Validate = true;
			}
		}
		if (Validate)
		{
			Traversal(input, current);
		}
	}
}


void Trie::Traversal(string input, Trie* trie) {
	//online code to traverse 
	for (int i = 0; i < CHAR_SIZE; i++) {
		if (trie->character[i] != nullptr)  // if there is a value
		{
			Trie* tempTrie = trie->character[i]; //pointer points to letter
			char character = char(i);
			string tempString = input + character;
			if (!tempTrie->isLeaf) {
				Traversal(tempString, tempTrie);
			}
			else {
				cout << tempString << endl;
			}

		}
	}
}