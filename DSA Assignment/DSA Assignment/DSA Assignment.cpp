// DSA Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.



/*
Daniel Dharshan Ravindran, S10181158D
Ho Gi Kei, S10179388K
*/

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


// Display Menu //
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



// Load dictionary for Trie //
// allows for user to choose which file they would like to load into the Trie Tree
void preloadTRIEDictionary()
{
	//Display to ask user to input file name to load into Trie Tree
	cout << "Please enter a file to preload into TRIE:";
	//Store input into filetoload
	cin >> filetoload;

	//Read the file
	ifstream LoadFile(filetoload);
	//File does not exist
	if (LoadFile.fail())
	{
		//error message to tell user that the file cannot be located
		cout << "The file can't be located. :(" << endl;
		//Run the function preloadTRIEDictionary()
		preloadTRIEDictionary();
	}

	//File exist
	else
	{
		//Declaring datatype of variable word
		string word;
		//While loop to get word from each line in the file
		while (getline(LoadFile, word)) {
			//insert the word into the Trie Tree
			trie.insert(word);
			//cout << "inserting " << word << endl;
		}
		//Close the file
		LoadFile.close();
		//Message to tell 
		cout << "Done inserting \n" << endl;

		//Trie Tree is empty
		if (trie.isEmpty())
		{
			//Error message to tell user that file is empty
			cout << "The file is empty. Try again" << endl;
			//Run the function preloadTRIEDictionary
			preloadTRIEDictionary();
		}
	}
}



// Option 1 //
// 1. Ask for user to input a word they would like to check the spelling of
// 2. Store user input
// 3. Search the word in the Trie Tree
// 4. Display whether the word has been found or not
void spellCheckAWord()
{
	bool check = true;
	//cout << "\ndictionary.txt \t RandomWords100.txt \t RandomWords1000.txt \t RandomWords3000plus.txt" << endl;
	
	//Ask user for word input for spell check
	cout << "\nPlease enter a word that you would like to check: ";
	//Declaring datatype of variable checkWord
	string checkWord;
	//Storing user input into variable
	cin >>checkWord;
	//checkWord has been successfully found in Trie Tree
	if (check == (trie.search(checkWord)))
	{
		//Message to tell users that the word exist in the Trie Tree
		cout << "The Word Exists! :) \n" << endl;
	 }
	//checkWord cannot be found in Trie Tree
	else {
		//Error message to tell user that the word does not exist in the Trie Tree
		cout << "The Word Does Not Exist :(" << endl;
	}
}


// Option 2 //
// 1. Ask user to input name of file they wish to have a spell check on
// 2. Store user input
// 3. Open and Read the file
// 4. Check the words in the file
// 5. Display the words that are wrong in the file
void spellcheckAFile()
{
	// ask for file name, getline for each word then search inside trie. If word does not exist then cout word all in the for loop
	
	//Declaring datatype of variable
	string Opt2FileToLoad;

	//Ask user to enter file name to spell check the words in the fil
	cout << "Please enter a file to check its contents: ";
	cin >> Opt2FileToLoad;

	ifstream LoadFile2(Opt2FileToLoad);
	string x;

	cout << "Below are the words that are wrong in the file: \n";
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
	cout << "Please enter a word to add to the trie structure: ";
	cin >> word;
	trie.insert(word);
	cout << "The word has been added to the structure.... that's all.";
	cout << "Want to search it? <Y/N> :";
	cin >> input;

	if (input == "Y" || input == "y")
	{
		if (trie.search(word) != false)
		{
			cout << "Yea your word does exist in the Trie... :)\n."<<endl;
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

	if (input == "Y" || input == "y")
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


/*
this method is a interface to load the various advanced errors we implemented
It shows the user what errors we can check for 
it then asks the user to select the type of error they want to check for
*/
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



/*
deletionError(int length, string word) method
it is a recursive method that returns the length incremented and an edited version of the word to check again.
at first length passed in is 0
for example if compter is passed in. We know that U is missing. 
So with length passed in as 0 
the method will insert every letter at length plus 1 in the key and search the variations in the trie. 
so to start, 
acompter will be searched, then
bcompter 
ccompter until every letter has been inserted in that position and checked in the trie. 
If there is no existing word amongst those variations, then the length will be incremented 
the method will then move to the second position and search as such 
caompter
cbompter
ccompter
This cycle will repeat until the length is 6 and when u is placed inbetween p and t to give computer 
that word is checked in the trie and if the search != false, that word is printed out. 
*/
//thing about this method is for the recursion to work, you have to key in 0 as a parameter.
string deletionError(int length, string word)
{

	
	string key = "abcdefghijklmnopqrstuvwxyz";
	if (length == word.size())
	{
		//if word is same length then its not a deletion error  and in fact the word doesnt exist 
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





/*
insertionError(int index, string text) method

It is a recursive function that returns the index incremented and the edited version of the text.
the same logic for the deletion error method can be applied here
the method checks every possible version of the word when passing in every single alphabet at different 


*/
//thing about this method is for the recursion to work, you have to key in 0 as a parameter.
string insertionError(int index, string text)
{
	string a = "";
	//if youve reached the end and there are still no possible combinations then the word to check is gibberish
	if (index == text.size())
	{
		//after checking every combination and searching in the trie is still false 
		cout << "the word does not exist";
		return "false";
	}
		

	else {
		for (int i = 0; i < text.size(); i++) 
		{

			//add all letters
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




