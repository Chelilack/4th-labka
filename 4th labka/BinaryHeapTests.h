#pragma once
#include "BinaryHeap.h"
#include <cassert>
class BinaryHeapTests
{
private:
	void Test_BinaryHeap();
	void Test_Add();
	void Test_Delete();
	void Test_GetSubTree();
	void Test_Extract();
public:
	void Test();
};
void BinaryHeapTests :: Test_BinaryHeap()
{
	int* itemsArray = new int[10]{ 0,2,6,5,7,1,9,3,8,4 };
	BinaryHeap<int>* example = new BinaryHeap<int>(itemsArray, 10);
	int* result = new int[10]{ 9,8,6,5,7,1,0,3,2,4};
	for (int i = 0; i < example->GetLength(); i++) 
	{
		assert(example->Get(i) == result[i]);
	}
}
void BinaryHeapTests::Test_Add() 
{
	int* itemsArray = new int[9]{ 0,2,6,5,1,9,3,8,4 };
	BinaryHeap<int>* example = new BinaryHeap<int>(itemsArray, 9);
	example->Add(7);
	int* result = new int[10]{ 9,8,7,5,6,0,3,2,4,1 };
	for (int i = 0; i < example->GetLength(); i++)
	{
		assert(example->Get(i) == result[i]);
	}
}
void BinaryHeapTests::Test_Delete() 
{
	int* itemsArray = new int[10]{ 0,2,6,5,7,1,9,3,8,4 };
	BinaryHeap<int>* example = new BinaryHeap<int>(itemsArray, 10);
	example->Delete(7);
	int* result = new int[10]{ 9,8,6,5,4,1,0,3,2};
	for (int i = 0; i < example->GetLength(); i++)
	{
		assert(example->Get(i) == result[i]);
	}
}
void BinaryHeapTests::Test_GetSubTree() 
{
	int* itemsArray = new int[10]{ 0,2,6,5,7,1,9,3,8,4 };
	BinaryHeap<int>* example = new BinaryHeap<int>(itemsArray, 10);
	BinaryHeap<int>* SubTree = example->GetSubTree(5);
	int* result = new int[3]{5,3,2};
	for (int i = 0; i < SubTree->GetLength(); i++)
	{
		assert(SubTree->Get(i) == result[i]);
	}
}
void BinaryHeapTests::Test_Extract()
{
	int* itemsArray = new int[10]{ 0,2,6,5,7,1,9,3,8,4 };
	BinaryHeap<int>* example = new BinaryHeap<int>(itemsArray, 10);
	example->Extract();
	int* result = new int[10]{ 8,7,6,5,4,1,0,3,2 };
	for (int i = 0; i < example->GetLength(); i++)
	{
		assert(example->Get(i) == result[i]);
	}
}
void BinaryHeapTests::Test()
{
	Test_BinaryHeap();
	Test_Add();
	Test_Delete();
	Test_GetSubTree();
	cout << "BinaryHeap work->correctly!" << endl;
}
