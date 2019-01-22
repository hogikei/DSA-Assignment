// DSA Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<sstream>
#include <algorithm>
#include "AVL.h"
#include <fstream>

using namespace std;

void menu();
void spellCheck();
void loadDictionary(string);

int option;
string fileName;

int main()
{
	while (true)
	{
		menu();
		cin >> option;

		if (option == 1)
		{
			spellCheck();
		}
	}

	system("PAUSE");
	return 0;
}

// display menu //
void menu()
{
	cout << "1. Spell check a word" << endl;
	cout << "2. Spell check a file" << endl;
	cout << "3. Add a new word to the dictionary " << endl;
	cout << "4. Save the dictionary" << endl;
	cout << "5. Display all words in the dictionary that starts with certain letter(s)" << endl;
}

// option 1 //
void spellCheck()
{
	cout << "\ndictionary.txt \t RandomWords100.txt \t RandomWords1000.txt \t RandomWords3000plus.txt" << endl;
	cout << "\nPease choose a file to check spelling with: " << endl;
	cin >> fileName;
	loadDictionary(fileName);

}

//Load dictionary
void loadDictionary(string fN)
{
	ifstream file(fN);

	if (file.fail())
	{
		cout << "File not found\n" << endl;
	}
	else
	{
		cout << "loading";
	}
}