#include "pch.h"
#include "AVL.h"


AVL::AVL()
{
	root = NULL;
}


AVL::~AVL()
{
}


// Height //
int AVL::height(Node *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height(temp->left);
		int r_height = height(temp->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

// Height Difference //
int AVL::difference(Node *temp)
{
	int difference;
	int l_height = height(temp->left);
	int r_height = height(temp->right);
	difference = l_height - r_height;
	return difference;
}

// Right Rotation //
AVL::Node *AVL::rightRotation(Node *parent)
{
	Node *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

// Left Rotation //
AVL::Node *AVL::leftRotation(Node *parent)
{
	Node *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

//Left-Right Rotation //
AVL::Node *AVL::leftRightRotation(Node *parent)
{
	Node *temp;
	temp = parent->left;
	parent->left = rightRotation(temp);
	return leftRotation(parent);
}

//Right-Left Rotation //
AVL::Node *AVL::rightLeftRotation(Node *parent)
{
	Node *temp;
	temp = parent->right;
	parent->right = leftRotation(temp);
	return rightRotation(parent);
}

// Balancing AVL Tree //
AVL::Node *AVL::balance(Node *temp)
{
	int balanceFactor = difference(temp);
	//check if there is a height difference of more than 1
	if (balanceFactor > 1)
	{
		if (difference(temp->left) > 0)
			temp = leftRotation(temp);
		else
			temp = leftRightRotation(temp);
	}
	//
	else if (balanceFactor < -1)
	{
		if (difference(temp->right) > 0)
			temp = rightLeftRotation(temp);
		else
			temp = rightRotation(temp);
	}
	return temp;
}

// Insert Element into Tree //
AVL::Node* AVL::insert(Node * root, ItemType data)
{
	//if there is no elements in the avl tree
	if (root == NULL)
	{
		root = new Node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}

	//if data is less that the data in the root
	else if (data < root->data)
	{
		root->left = insert(root->left, data);
		root = balance(root);
	}

	//if data is greater than equal to the data in the root
	else if (data >= root->data)
	{
		root->right = insert(root->right, data);
		root = balance(root);
	}
	return root;
}

// Display AVL Tree //
void AVL::display(Node *ptr, int level)
{
	int i;
	if (ptr != NULL)
	{
		display(ptr->right, level + 1);
		printf("\n");
		if (ptr == root)
			cout << "Root -> ";
		for (i = 0; i < level && ptr != root; i++)
			cout << "          ";
		cout << ptr->data;
		display(ptr->left, level + 1);
	}
}

// Inorder Traversal of AVL Tree //
void AVL::inOrder(Node *tree)
{
	if (tree == NULL)
		return;
	inOrder(tree->left);
	cout << tree->data << "   ";
	inOrder(tree->right);
}

//Preorder Traversal of AVL Tree //
void AVL::preOrder(Node *tree)
{
	if (tree == NULL)
		return;
	cout << tree->data << "   ";
	preOrder(tree->left);
	preOrder(tree->right);
}

// Postorder Traversal of AVL Tree //
void AVL::postOrder(Node *tree)
{
	if (tree == NULL)
		return;
	postOrder(tree->left);
	postOrder(tree->right);
	cout << tree->data << "   ";
}

// Check if Node is empty //
bool AVL::isEmpty()
{
	return root == NULL;
}