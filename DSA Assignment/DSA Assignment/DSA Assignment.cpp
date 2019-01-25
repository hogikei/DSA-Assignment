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
void advanced();
string insertionError();
string deletionError();
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
			advanced();
		}
		else if (opt == 7)
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
	cout << "4. Save the txt file with word(s)" << endl;
	cout << "5. Display all words in the file that start with certain letter(s)" << endl;
	cout << "6. Advanced section; check for a deletion or an insertion error on a word!" << endl;
	cout << "7. Exit" << endl;
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
		cout << "Done inserting \n" << endl;

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
	cout << "\nWhat word would you like to check ?: ";
	string Checkword;
	cin >>Checkword;
	if (check == (trie.search(Checkword)))
	{
		cout << "the word exists! \n" << endl;
	 }
	else {
		cout << "the word does not exist" << endl;
	}
	

}


////option 2
//void spellcheckAFile()
//{
//	// ask for file name, getline for each word then search inside trie. If word does not exist then cout word all in the for loop
//	bool check = false;
//	string Opt2FileToLoad;
//
//	cout << "Please enter a file check its contents: ";
//	cin >> Opt2FileToLoad;
//
//	ifstream LoadFile(Opt2FileToLoad);
//	string x;
//	while (LoadFile >> x)
//	{
//		if (check == trie.search(x))
//		{
//			cout << x << endl;
//			cout << "searching";
//		}
//		LoadFile.close();
//	}
//
//}
//

//option 2 second way 
void spellcheckAFile()
{
	string  Opt2FileToLoad;
	cout << "Please enter a file to check its contents ";
	cin >> Opt2FileToLoad;

	
}

//option 3
void addNewWordToStructure()
{
	string word;
	cout << "please input in a word to add the the trie structure: ";
	cin >> word;
	trie.insert(word);
	cout << "your word has been added to the structure....thats all.";
}


//option 4
void addToDictionary()
{
	//bool variable to see if word the user wants to add already exists in the text file. 
	
	string input;
	ofstream writeFile1;
	ofstream writeFile2;
	string cont;
	Trie trie2;
	cout << "Do you want to add to " + filetoload + "? " << endl;
	cout << "Y/N: ";
	cin >> input;

	if (input == "Y")
	{
		writeFile1.open(filetoload, ios::in | ios::app);
			do
			{
				bool check = true;
				string addWord;

				cout << "Please enter a word to add to  " + filetoload + " :\n";
				cin >> addWord;

				if (check == (trie.search(addWord)))
				{
					cout << "the word already exists! \n" << endl;
					addToDictionary();
				}

				else {
					writeFile1 << "\n"  + addWord;
					cout << "Inserted!\n";
					cout << "Want to add another word? <Y/N> " << endl;
					cin >> cont;
				}

			
			} while (cont=="Y");
			writeFile1.close();
	}


	/*else
	{
		bool check = true;
		string secondInput;
		cout << "enter a name of a dictionary/txt file to add the words to: ";
		cin >> secondInput;
		writeFile2.open(secondInput, ios::in | ios::app);

		do
		{

			string addWord;
			cout << "Please enter a word to add to " + secondInput + " :\n";
			cin >> addWord;

			if (check == (trie.search(addWord)))
			{
				cout << "the word already exists! \n" << endl;
			}

			else {
				writeFile2 << "\n" + addWord;
				cout << "Want to add another word? <Y/N>  " << endl;
				cin >> cont;
			}
		
		} while (cont == "Y");
		writeFile2.close();
	}*/
}


//option 5
void DisplayPrefix()
{

}


void advanced()
{
	string word;
	int errortype;
	cout << "There are 2 types of errors this program can search for\n";
	cout << "1: deletion error where one error is removed from the word you type in \n";
	cout << "2: Insertion error where there is an extra letter in the word you type in \n";

	cout << "Please enter the error type you want to check: ";
	cin >> errortype;

	cout << "Please enter the word which you want to check for errors: ";
	cin >> word;


	if (errortype == 1)
	{
		//deletionError()
	}
}



string deletionError(int length, string word)
{
	string key = "abcdefghijklmnopqrstuvwxyz";
	if (length == word.size())
	{
		//word isnt found
		return "word isnt found inside the dictionary";
	}


	else 
	{
		for (int i = 0; i < key.size(); i++)
		{
			string temp = word;
			string appendment = "";
			appendment = appendment + key[i];
			temp.insert(length + 1, appendment);

			if (trie.search(temp) != false)
			{
				return temp;
			}
		}
		return deletionError(length + 1, word);
	}
}






/*string DelWord(int length, string input) {
	string a = "abcdefghijklmnopqrstuvwxyz";
	if (length == input.size()) {
		return "wrong";
	}
	else {
		for (int i = 0; i < 26; i++) {
			string word = input;
			string chars = "";
			chars += a[i];
			word.insert(length + 1, chars);
			if (bst.search(word) != NULL) {
				return word;
			}
		}
		return DelWord(length + 1, input);
	}

}

*/




string insertionError(string word, int index)
{
	string a = "";
	if (index == word.size())
	{
		return "word isnt found inside the dictionary";
	}

	else
	{
		//for (size)
	}
}




/*
string checkInsertion(string word, int index) {
	string tempWord = "";
	if (index == word.size()) // Not Found
		return "false";

	else {
		for (size_t i = 0; i < word.size(); i++) 
		{
			if (i != index) // Add all letters except 1 to tempWord
				tempWord += word[i];
		}

		if (bst.search(tempWord) != NULL) // Word Found
			return tempWord;
		else
			return checkInsertion(word, index + 1);
	}
}

*/
