// DSA Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<sstream>
#include <algorithm>

#include "Trie.h"
#include <fstream>
using namespace std;

//options
void options();
void menu();
void preloadTRIEDictionary();
void spellCheckAWord();
void spellcheckAFile();
void addNewWordToStructure();
void addToDictionary();
void DisplayPrefix();
void advanced();
string deletionError(int length, string word);
string insertionError(int index, string text);

//variables
int option;
string filetoload;
string fileName;

//data structures

Trie trie;

int main()
{

		preloadTRIEDictionary();
		options();
	


	
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
	cout << "\n";
	cout << "1. Spell check a word" << endl;
	cout << "2. Spell check all the words in a file" << endl;
	cout << "3. Add a new word to the current running structure " << endl;
	cout << "4. Save the txt file with word(s)" << endl;
	cout << "5. Display all words in the file that start with certain letter(s)" << endl;
	cout << "6. Advanced section; check for a deletion or an insertion error on a word!" << endl;
	cout << "7. Exit" << endl;
}



//Load dictionary for trie
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


//option 2
void spellcheckAFile()
{
	// ask for file name, getline for each word then search inside trie. If word does not exist then cout word all in the for loop
	string Opt2FileToLoad;

	cout << "Please enter a file to check its contents: ";
	cin >> Opt2FileToLoad;

	ifstream LoadFile2(Opt2FileToLoad);
	string x;

	cout << "Below are the words that are wrong in the file \n";
	while (LoadFile2>>x)
	{
		if (trie.search(x) == false)
		{
			cout << x << endl;
		
		}
	}
	LoadFile2.close();
}



//option 3
void addNewWordToStructure()
{
	string word;
	string input;
	cout << "please input in a word to add the the trie structure: ";
	cin >> word;
	trie.insert(word);
	cout << "your word has been added to the structure....thats all.";
	cout << "want to search it? <Y/N> :";
	cin >> input;

	if (input == "Y")
	{
		if (trie.search(word) != false)
		{
			cout << "Yea your word does exist in the Trie...\n."<<endl;
		}

	}
}


//option 4
void addToDictionary()
{
	
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
	}
}


//option 5
void DisplayPrefix()
{
	string key = "abcdefghijklmnopqrstuvwxyz";
	string input;
	cout << "\n Please enter the first few letter(s) for the words you want to search for: ";
	cin >> input;
	if (trie.search(input) != false)
	{
		cout << input;
	}

	for (int i = 0; i < key.size(); i++)
	{
		string appendment = input + key[i];
		if (trie.search(appendment) != false)
		{
			cout << appendment << endl;
		}
	}
}


//option 6 console
void advanced()
{
	string word;
	int errortype;
	int length;
	cout << "There are 2 types of errors this program can search for\n";
	cout << "1: deletion error where one error is removed from the word you type in \n";
	cout << "2: Insertion error where there is an extra letter in the word you type in \n";

	cout << "Please enter the error type you want to check <1:2>: ";
	cin >> errortype;

	cout << "Please enter the word which you want to check for errors: ";
	cin >> word;

	cout << "Please key in 0 : ";
	cin >> length;


	if (errortype == 1)
	{
		
		if (trie.search(word) == true)
		{
			cout << "Word already exists \n";
		}
		else
		{
			deletionError(length, word);
		}
			
	}


	else if (errortype == 2)
	{
		if (trie.search(word) == true)
		{
			cout << "Word already exists \n";
		}
		else
		{
			insertionError(length, word);
		}
	
	}


}



//thing about this method is for the recursion to work, you have to key in 0 as a parameter.
string deletionError(int length, string word)
{

	
	string key = "abcdefghijklmnopqrstuvwxyz";
	if (length == word.size())
	{
		//if word is same length then its not a deletion error anymore.
		cout << "sorry the word does not exist \n";	
		return word;
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

				cout << "did you mean: " + temp << endl;
				return temp;
				
			}
		}
		return deletionError(length + 1, word);
	}
}




//thing about this method is for the recursion to work, you have to key in 0 as a parameter.
string insertionError(int index, string text)
{
	string a = "";
	if (index == text.size())
	{
		//after checking every combination and searching in the trie is still false 
		cout << "the word does not exist";
		return "false";
	}
		

	else {
		for (int i = 0; i < text.size(); i++) {

			//adds all letters
			if (i != index)
				a += text[i];
		}

		//if word exists in trie
		if (trie.search(a) != false)
		{
			cout << "did you mean: " + a << endl;
			return a;
		}
		else
			return insertionError(index + 1,text);
	}
}




