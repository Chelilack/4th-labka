#pragma once
#include"Stack.h"
#include"Binaryheap.h"
#include "queuePriority.h"
#include "Pair.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>
using namespace std;
template<typename T>
class Node 
{
private:
	Node<T>* left;
	Node<T>* right;
	Node<T>* parent;
	T value;
public:
	Node(T item) :left(NULL), right(NULL), parent(NULL), value(item) {};
public:
	Node<T>* GetLeft()const    {return this->left;}
	Node<T>* GetRight()const 	 {return this->right;}
	Node<T>* GetParent()const  {return this->parent;}
	T GetValue()const  { return this->value; }
	void SetLeft(Node<T>* item) { this->left = item; }
	void SetRight(Node<T>* item) { this->right = item; }
	void SetParent(Node<T>* item) { this->parent = item; }
	bool operator ==(const Node<T>* item) { return this->GetValue() == item->GetValue(); }
};
template<typename T>
class BinaryTree
{
private:
	Node<T>* root;
	int length;
public:
	BinaryTree();
	BinaryTree(Stack<T>* stack);
public:
	void Add(T item);
	void Print();
	bool SearchNode(T value);
	Node<T>* GetRoot();
	Node<T>* FindNode(T value);
	string Round(const char* order);
	void Concat(BinaryTree<T>* tree);
	BinaryTree<T>* GetSubTree(T value);
	void Remove(T value);
	
};
template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}
template<typename T>
BinaryTree<T>::BinaryTree() 
{
	this->root = NULL;
	this->length = 0;
}
template<typename T>
BinaryTree<T>::BinaryTree(Stack<T>* stack) 
{
	while (stack->GetLength() != 0) 
	{
		this->Add(stack->Extract());
	}
}
template<typename T>
Node<T>* BinaryTree<T> ::GetRoot() 
{
	return this->root;
}
template<typename T>
void BinaryTree<T>::Add(T item) 
{
	Node<T>* pastingNode = new Node<T>(item);
	Node<T>* pass = this->GetRoot();
	Node<T>* parent = NULL;
	while (pass != NULL) 
	{
		parent = pass;
		if (item < pass->GetValue()) 
		{
			pass = pass->GetLeft();
		}
		else 
		{
			pass = pass->GetRight();
		}
	}
	if (parent == NULL) 
	{
		this->root = pastingNode;
	}
	else if(pastingNode->GetValue()<parent->GetValue())
	{
		pastingNode->SetParent(parent);
		parent->SetLeft(pastingNode);
	}
	else if (pastingNode->GetValue() > parent->GetValue()) 
	{
		pastingNode->SetParent(parent);
		parent->SetRight(pastingNode);
	}
	this->length++;
}

template<typename T>
void BinaryTree<T>::Print() 
{
	queuePriority<Node<T>*>* queue = new queuePriority<Node<T>*>();
	queue->Add(this->root);

	while (queue->GetLength()!=0) 
	{
		Node<T>* node = queue->Extract();

		if (node->GetLeft()) queue->Add(node->GetLeft());
		if (node->GetRight()) queue->Add(node->GetRight()); 
		cout<<node->GetValue()<<endl;
	}
	
}
template<typename T>
Node<T>* BinaryTree<T> ::FindNode(T value)
{
	queuePriority<Node<T>*>* queue = new queuePriority<Node<T>*>();
	queue->Add(this->root);

	while (queue->GetLength() != 0)
	{
		Node<T>* node = queue->Extract();

		if (node->GetLeft()) queue->Add(node->GetLeft());
		if (node->GetRight()) queue->Add(node->GetRight());
		if (node->GetValue() == value) return node;
	}
	return NULL;
}
template<typename T>
bool BinaryTree<T>::SearchNode(T value) 
{
	return FindNode(value) != NULL;
}
template<typename T>
void BinaryTree<T> ::Remove(T item) 
{
	Node<T>* node = FindNode(item);
	Node<T>* parent = node->GetParent();
	if (node->GetRight() == NULL && node->GetLeft() == NULL) 
	{
		if (parent == NULL) { this->root = NULL; }
		else if (parent->GetLeft() == node) { parent->SetLeft(NULL); }
		else { parent->SetRight(NULL); }
	}
	else if (node->GetRight() == NULL || node->GetLeft() == NULL) 
	{
		if(node->GetRight() == NULL)
		{
			if (parent->GetLeft() == node) { parent->SetLeft(node->GetLeft()); }
			else { parent->SetRight(node->GetLeft()); }
		}
		else 
		{
			if (parent->GetLeft() == node) { parent->SetLeft(node->GetRight()); }
			else { parent->SetRight(node->GetRight()); }
		}
	}
	else 
	{
		Node<T>* newNode;
		Node<T>*node1 = node->GetRight();
		while (node1->GetLeft() != NULL) 
		{
			node1 = node1->GetLeft();
		}
		newNode = node1;
		if (node->GetRight() == newNode) 
		{
			if (parent->GetLeft() == node) { parent->SetLeft(newNode); }
			else { parent->SetRight(newNode); }
			newNode->SetLeft(node->GetLeft());
		}
		else 
		{
			newNode->GetParent()->SetLeft(newNode->GetRight());
			newNode->GetRight()->SetParent(newNode->GetParent());
			newNode->SetParent(node->GetParent());
			newNode->SetLeft(node->GetLeft());
			newNode->SetRight(node->GetRight());
			if (node == this->GetRoot()) { this->root = newNode; }
		}
		this->length--;

	}
}
template<typename T>
string  BinaryTree<T>::Round( const char* order)
{
	string result = "";
	if (!this->root) return result;
	Stack<Pair<Node<T>*>>* stack = new Stack<Pair<Node<T>*>>;
	stack->Add(Pair<Node<T>*>(this->root, false));
	while (stack->GetLength()!=0) 
	{
		Pair<Node<T>*> pair = stack->Extract();
		if (pair.GetStatus()) 
		{
			Node<T>* item = pair.GetItem();
			result += toString(item->GetValue())+',';
		}
		else
		{
			for (int i = strlen(order) - 1; i >= 0; i--) 
			{
				switch (order[i]) 
				{
				case 'N':
					stack->Add(Pair<Node<T>*>(pair.GetItem(), true));
					break;
				case 'L':
					if (pair.GetItem()->GetLeft()) { stack->Add(Pair<Node<T>*>(pair.GetItem()->GetLeft(), false)); }
					break;
				case 'R':
					if (pair.GetItem()->GetRight()) { stack->Add(Pair<Node<T>*>(pair.GetItem()->GetRight(), false)); }
					break;
				}
			}
		}
	}
	result = result.substr(0, result.size() - 1);
	return result;
}
template<typename T>
void BinaryTree<T>::Concat(BinaryTree<T>* tree) 
{
	queuePriority<Node<T>*>* queue = new queuePriority<Node<T>*>();
	queue->Add(tree->GetRoot());

	while (queue->GetLength() != 0)
	{
		Node<T>* node = queue->Extract();

		if (node->GetLeft()) queue->Add(node->GetLeft());
		if (node->GetRight()) queue->Add(node->GetRight());
		this->Add(node->GetValue());
	}
}
template<typename T>
BinaryTree<T>* BinaryTree<T>::GetSubTree(T value) 
{
	Node<T>* newRoot = FindNode(value);
	BinaryTree<T>* result = new BinaryTree<T>();
	queuePriority<Node<T>*>* queue = new queuePriority<Node<T>*>();
	queue->Add(newRoot);

	while (queue->GetLength() != 0)
	{
		Node<T>* node = queue->Extract();

		if (node->GetLeft()) queue->Add(node->GetLeft());
		if (node->GetRight()) queue->Add(node->GetRight());
		result->Add(node->GetValue());
	}
	return result;
}
