// DSA Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<sstream>
#include <algorithm>
#include "AVL.h"
#include "Trie.h"
#include <fstream>
//testing
using namespace std;

void options();
void menu();
void preloadAVLDictionary();
void preloadTRIEDictionary();
void spellCheckAWord();
void spellcheckAFile();
void addNewWordToStructure();
void addToDictionary();
void DisplayPrefix();

int option;
string filetoload;
string fileName;
AVL avl;
Trie trie;

int main()
{
	int input;
	cout << "Would you like to load into a AVL or Trie structure" << endl;
	cout << "1: AVL"<<endl;
	cout << "2: Trie" << endl;
	cout << "Key in your structure: ";
	cin >> input;
	if (input == 1)
	{
		preloadAVLDictionary();
		options();
	}

	else
	{
		preloadTRIEDictionary();
		options();
	}


	
}





void options()
{
	bool constant= true;
	int opt;
	while (constant) {
		menu();
		cout << "Please enter an option: ";
		cin >> opt;
		if (opt == 1)
		{
			spellCheckAWord();
		}
		else if (opt == 2)
		{
			spellcheckAFile();
		}
		else if (opt == 3)
		{
			addNewWordToStructure();
		}
		else if (opt == 4)
		{
			addToDictionary();
		}
		else if (opt == 5)
		{
			DisplayPrefix();
		}
		else if (opt == 6)
		{
			constant = false;
			cout << "byebye" << endl;
			system("PAUSE");
		}
		else
		{
			cout << "Enter 1 - 6" << endl;
		}
	}
	cout << "\n";
}

// display menu //
void menu()
{
	cout << "1. Spell check a word" << endl;
	cout << "2. Spell check all the words in a file" << endl;
	cout << "3. Add a new word to the current running structure " << endl;
	cout << "4. Save the txt file with a word" << endl;
	cout << "5. Display all words in the file that start with certain letter(s)" << endl;
	cout << "6. Exit" << endl;
}


//Load dictionary
void preloadAVLDictionary()
{
	

	cout << "Please enter a file to preload into AVL:";
	cin >> filetoload;

	ifstream LoadFile(filetoload);
	if (LoadFile.fail())
	{
		cout << "The file cant be located." << endl;
		preloadAVLDictionary();
	}

	else
	{
		string word;
		while (getline(LoadFile, word)) {
			avl.insert(word);
			cout << "inserting "<<word << endl;
		}
		LoadFile.close();
		cout << "closing the file" << endl;

		if (avl.isEmpty())
		{
			cout << "The file is empty. Try again" << endl;
			preloadAVLDictionary();
		}
	}
}



//Load dictionary
void preloadTRIEDictionary()
{
	string filetoload;

	cout << "Please enter a file to preload into TRIE:";
	cin >> filetoload;

	ifstream LoadFile(filetoload);
	if (LoadFile.fail())
	{
		cout << "The file cant be located." << endl;
		preloadTRIEDictionary();
	}

	else
	{
		string word;
		while (getline(LoadFile, word)) {
			trie.insert(word);
			//cout << "inserting " << word << endl;
		}
		LoadFile.close();
		cout << "Done inserting" << endl;

		if (trie.isEmpty())
		{
			cout << "The file is empty. Try again" << endl;
			preloadTRIEDictionary();
		}
	}
}



// option 1 
void spellCheckAWord()
{
	bool check = true;
	//cout << "\ndictionary.txt \t RandomWords100.txt \t RandomWords1000.txt \t RandomWords3000plus.txt" << endl;
	cout << "\nWhat word would you like to check ? ";
	string Checkword;
	cin >>Checkword;
	if (check == (trie.search(Checkword)))
	{
		cout << "the word exists!" << endl;
	 }
	else {
		cout << "the word does not exist" << endl;
	}
	

}


//option 2
void spellcheckAFile()
{
	// ask for file name, getline for each word then search inside trie. If word does not exist then cout word all in the for loop
	string Opt2FileToLoad;

	cout << "Please enter a file check its contents: ";
	cin >> Opt2FileToLoad;

	ifstream LoadFile(Opt2FileToLoad);
	string x;
	while (LoadFile >> x)
	{
		if (!trie.search(x))
		{
			cout << x << endl;
			cout << "searching";
		}
		LoadFile.close();
	}

}



//option 3
void addNewWordToStructure()
{

}


//option 4
void addToDictionary()
{


}


//option 5
void DisplayPrefix()
{

}
