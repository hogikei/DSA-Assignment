#pragma once
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

typedef string ItemType;

class AVL
{
private:
	//Create Node properties
	struct Node
	{
		ItemType data; //data item
		Node *left; //pointer pointing to the left of item
		Node *right; //pointer pointing to the right of item
	};
	Node *root;

public:
	int height(Node *);
	int difference(Node *);
	Node *rightRotation(Node *);
	Node *leftRotation(Node *);
	Node *leftRightRotation(Node *);
	Node *rightLeftRotation(Node *);
	Node* balance(Node *);
	Node* insert(Node *, ItemType);
	void display(Node *, int);
	void inOrder(Node *);
	void preOrder(Node *);
	void postOrder(Node *);
	bool isEmpty();
	AVL();
	~AVL();
};

