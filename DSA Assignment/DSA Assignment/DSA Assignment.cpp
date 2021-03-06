// DSA Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.



/*
Daniel Dharshan Ravindran, S10181158D
Ho Gi Kei, S10179388K
*/

#include "pch.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Trie.h"
#include <fstream>
#include <string>

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
		//Declaring variable datatype
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
	//Declaring variable datatype
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
	
	//Declaring variable datatype
	string Opt2FileToLoad;

	//Ask user to enter file name to spell check the words in the file
	cout << "Please enter a file name to check its contents: ";
	//Store file name into variable
	cin >> Opt2FileToLoad;

	//Open and Read the file
	ifstream LoadFile2(Opt2FileToLoad);
	//Declarint variable datatype
	string x;

	//Diaplay words that are wrong in the file
	cout << "Below are the words that are wrong in the file:\n";
	//While there are words in the file
	while (LoadFile2>>x)
	{
		//The word cannot be found in the dictionary
		if (trie.search(x) == false)
		{
			//Print the wrong word
			cout << x << endl;
		}
	}
	//Close the file
	LoadFile2.close();
}



// Option 3 //
// 1. Ask user to input word they would want to add to Trie Tree
// 2. Store user input
// 3. Check if the word is already in the Trie Tree
// 4a. If the word is not in the Trie Tree: Insert word into the Trie Tree
// 5a. Ask the user if they want to search the word in the Trie Tree
// 6a. If user chooses yes: Search the word in the Trie Tree
//							Tell user whether the word exist in the Trie Tree

// 4b. The word already exist in the Trie : Ask user if they would want to add another word into the Trie
// 5b. If user chooses yes: Ask user for word input

void addNewWordToStructure()
{
	//Declaring variable datatype
	string word;
	string cont;

	//Ask user to input word they would like to enter into Trie Tree
	cout << "Please enter a word to add to the Trie structure: ";
	//Store word into variable
	cin >> word;
	//Word does not already exist in Trie Tree
	if (trie.search(word) != false)
	{
		//Insert word into Trie
		trie.insert(word);
		//Display success message
		cout << "The word has been added to the structure... that's all.";
		//Ask user if they would like to earch it up
		cout << "Want to search it? <Y/N> :";
		//Store user input
		cin >> cont;

		//User choose yes
		if (cont == "Y" || cont == "y")
		{
			//Word exist in the Trie Tree
			if (trie.search(word) != false)
			{
				//Display success message
				cout << "Yea your word does exist in the Trie... :)\n." << endl;
			}
			//Word does not exist in the Trie Tree
			else
			{
				//Display error message
				cout << "Oops... the word does not exist in the Trie... :(" << endl;
				//Run addNewwordToStructure() again
				addNewWordToStructure();
			}
		}
	}
	// Word already exist in the Trie Tree
	else
	{
		//Display message to tell user that word already exist in Trie
		cout << "The word already exist in the Trie :)\n";
		//Ask user if they would like to enter another word
		cout << "Would you like to enter another word? <Y/N>:" << endl;
		//Store user input into variable
		cin >> cont;
		//User choose yes
		if (cont == "Y" || cont == "y")
		{
			//Run addNewWordToStructure() again
			addNewWordToStructure();
		}
	}
}


// Option 4 //
// 1. Ask user is they would like to add the word into the current file loaded into the Trie Tree
// 2a. If user choose yes
// 3a. Open the file to Write in the file
// 
void addToDictionary()
{
	//Declaring variable datatype
	string input;
	ofstream writeFile1;
	ofstream writeFile2;
	string cont;
	Trie trie2;

	//Ask user if they want to add the word into the file that had been previously added into Trie Tree
	cout << "Do you want to add to " + filetoload + "? <Y/N:>" << endl;
	//Store input into variable
	cin >> input;

	//User choose yes
	if (input == "Y" || input == "y")
	{
		//Open and Write in file
		writeFile1.open(filetoload, ios::in | ios::app);
			do
			{
				//Declaring variable datatype
				bool check = true;
				string addWord;

				//Ask user to input word they would like to add into the file
				cout << "Please enter a word to add to  " + filetoload + " :\n";
				//Store user input into variable
				cin >> addWord;

				//Word can be found in the file
				if (check == (trie.search(addWord)))
				{
					//Display message of success
					cout << "The word already exists! :)\n" << endl;
					//Ask user if they still want to add word into the dictionary
					cout << "Would you still like to add another word into the dictionary? <Y/N>:";
					//Store user input into variable
					cin >> cont;
					//User choose yes
					if (cont == "Y" || cont == "y")
					{
						//Run addToDictionary() again
						addToDictionary();
					}
				}
				//Word cannot be found in the file
				else 
				{
					//Add word into the file
					writeFile1 << "\n"  + addWord;
					//Display success message
					cout << "Inserted!\n";
					//Ask user if they would like to add another word into the dictionary
					cout << "Want to add another word? <Y/N> " << endl;
					//Store user input into variable
					cin >> cont;
				}
			} 
			while (cont=="Y" || cont == "y");
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



// Option 5 //
// 1. Ask user to input the first few letter(s) they want to find
// 2. Store user input into variable
// 3. Pass the user input into trie.Prefix(input, input.length()
void DisplayPrefix()
{
	//Declaring variable datatype
	string input;
	//Ask users for input
	cout << "\nPlease enter the first few letter(s) for the words you want to search for: ";
	//Store user input into variable
	cin >> input;
	//Pass user input into trie.Prefix(input, input.length)
	trie.Prefix(input, input.length());
}


// Option 6 console //
/*
This method is a interface to load the various advanced error checks we implemented
It shows the user what errors we can check for it then asks the user to select the 
type of error they want to check for
*/
// 1. Ask the user which type of error check they wish to run
// 2. Store user input
// 3. Check if the word exist in the dictionary already
// 4a. The word already exist in the dictionary
// 5a. Ask user if they want to check another word
// 6a. If yes: Run advanced again

// 4b. The word does not exist in the dictionary
// 5b. Run the error check on the word

void advanced()
{
	//Declaring of variable datatype
	string word;
	int errortype;
	int length;
	string cont;

	//Display options for advanced error check
	cout << "\n\nThere are 2 types of errors this program can search for\n";
	cout << "1: Deletion error: Where one letter is removed from the word you type in \n";
	cout << "2: Insertion error: Where there is an extra letter in the word you type in \n";

	//Ask user to input what kind of error check they would like to use
	cout << "Please enter the error type you want to check <1/2>: ";
	//Store user input into variable
	cin >> errortype;

	//Ask user to enter a word they wish to check
	cout << "Please enter the word which you want to check for errors:";
	//Store user input into variable
	cin >> word;

	//Ask user to input 0 for recursive to work
	cout << "Please key in 0:";
	//Store user input into variable
	cin >> length;

	//User choose errortype 1; deletionError
	if (errortype == 1)
	{
		//The word exist in the dictionary
		if (trie.search(word) == true)
		{
			//Display success message
			cout << "There is no error with the word :)\n";
			//Ask user if they would like to check another word for advanced error checking
			cout << "Would you like to check another word? <Y/N>";
			//Store user input into variable
			cin >> cont;
			//User choose yes
			if (cont == "Y" || cont == "y")
			{
				//Run advanced()
				advanced();
			}
		}
		//The word does not exist in the dictionary
		else
		{
			//Run deletionError(length, word) function
			deletionError(length, word);
		}	
	}

	//User choose errortype 2; insertionError
	else if (errortype == 2)
	{
		//The word exist in the dictionary
		if (trie.search(word) == true)
		{
			//Display success message
			cout << "There is no error with the word :)\n";
			cout << "Would you like to check another word? <Y/N>";
			//Store user input into variable
			cin >> cont;
			//User choose yes
			if (cont == "Y" || cont == "y")
			{
				//Run advanced()
				advanced();
			}
		}
		//The word does not exist in the dictionary
		else
		{
			//Run insertionError(length, word) function
			insertionError(length, word);
		}
	}
}


// Advance 1: deletionError //
//deletionError(int length, string word)
/*
It is a recursive method that returns the length incremented and an edited version of the word to check again.
At first the length passed in is 0:
Example:
"compter" is passed in, we know that 'U' is missing. 
So with length passed in as 0, the method will insert every letter at length plus 1 in the key and search the 
different variations in the trie. 

So to start,
acompter will be searched, 
then bcompter 
then ccompter 
until every letter has been inserted in that position and checked in the trie. 

If there is no existing word amongst those variations, then the length will be incremented.
The method will then move to the second position and search as such:
caompter
cbompter
ccompter

This cycle will repeat until the length is 6 and when 'u' is placed inbetween 'p' and 't' to give the word "computer",
that word is checked in the trie and if the search != false, that word is printed out. 
*/
//This method makes use of recursion. Users would need to key in 0 as a parameter for this method to work
string deletionError(int length, string word)
{
	//Declaring variable datatype
	string key = "abcdefghijklmnopqrstuvwxyz";
	//Check whether the word is the same length as the length users have input
	if (length == word.size())
	{
		//if word is same length then its not a deletion error  and in fact the word doesnt exist 
		cout << "Sorry the word does not exist :(\n";	
		return word;
	}
	//The word is not the same lenth as the length users have input
	else 
	{
		//for loop
		//index range from 0 to 25, index increase by 1
		for (int i = 0; i < key.size(); i++)
		{
			//create temp and store the value of word into temp
			string temp = word;
			//create appendment
			string appendment = "";
			appendment = appendment + key[i];
			//Insert appendment word to temp word
			temp.insert(length + 1, appendment);

			//Check if temp word exist in the dictionary
			if (trie.search(temp) != false)
			{
				//The word exist, telling the user what the word is suppose to be
				cout << "Did you mean: " + temp << endl;
				//Print the temp word
				return temp;
			}
		}
		return deletionError(length + 1, word);
	}
}


// insertionError //
// insertionError(int index, string text) 
/*
- Index stands for character position

insertionError is a recursive function that returns the index incremented and the edited version of the text.
The essential functionality of the method takes place in the for loop and onwards.
Other than the character with the same index, the for loop takes out all the characters from the user input 
and puts it in the new string.

The new string is then checked in the trie to see if exists. 
If it does not exist then the index is incremented.


Example: 
The user types in "computxer" and then "0".
The loop takes out all the characters from the word and places them in a new string, EXCEPT for the indexed char.
The first check would be omputxer to see if it exists in the trie. 
If it does not, then index is incremented and cmputxer is checked in the trie.
The process repeats, until computer is checked in the trie. 
*/
//This method makes use of recursion. Users would need to key in 0 as a parameter for this method to work
string insertionError(int index, string text)
{
	//Create temp string
	string temp = "";
	//if youve reached the end and there are still no possible combinations then the word to check is gibberish
	if (index == text.size())
	{
		//after checking every combination and searching in the trie is still false 
		cout << "The word does not exist :(";
		return "False";
	}
	else {
		for (int i = 0; i < text.size(); i++) 
		{
			if (i != index)
				temp += text[i];
		}

		//if word exists in trie
		if (trie.search(temp) != false)
		{
			cout << "Did you mean:" + temp << endl;
			return temp;
		}
		else
			return insertionError(index + 1,text);
	}
}




