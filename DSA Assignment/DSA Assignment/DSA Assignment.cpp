// DSA Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<sstream>
#include <algorithm>
#include "AVL.h"
#include <fstream>
//testing
using namespace std;

void menu();
void spellCheck();
void options();
void preloadDictionary();

int option;
string fileName;
AVL avl;

int main()
{
	preloadDictionary();
	options();
}





void options()
{
	bool constant= true;
	int opt;
	while (constant) {
		menu();
		cin >> opt;
		if (opt == 1)
		{
			
		}
		else if (opt == 2)
		{
			
		}
		else if (opt == 3)
		{
			
		}
		else if (opt == 4)
		{
		
		}
		else if (opt == 5)
		{
			
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
	cout << "2. Spell check a file" << endl;
	cout << "3. Add a new word to the dictionary " << endl;
	cout << "4. Save the dictionary" << endl;
	cout << "5. Display all words in the dictionary that starts with certain letter(s)" << endl;
	cout << "Exit" << endl;
}

// option 1 //
void spellCheck()
{
	cout << "\ndictionary.txt \t RandomWords100.txt \t RandomWords1000.txt \t RandomWords3000plus.txt" << endl;
	cout << "\nPease choose a file to check its spelling " << endl;
	cin >> fileName;
	//loadDictionary(fileName);
	//cout << "Your file has been loaded!" << endl;

}

//Load dictionary
void preloadDictionary()
{
	string filetoload;

	cout << "Please enter a file to preload:";
	cin >> filetoload;

	ifstream LoadFile(filetoload);
	if (LoadFile.fail())
	{
		cout << "The file cant be located." << endl;
		preloadDictionary();
	}

	else
	{
		string word;
		while (getline(LoadFile, word)) {
			avl.insert(word);
			cout << "inserting" << endl;
		}
		LoadFile.close();
		cout << "closing the file" << endl;

		if (avl.isEmpty())
		{
			cout << "The file is empty. Try again" << endl;
			preloadDictionary();
		}
	}
}