#pragma once
#include"Stack.h"
#include"Binaryheap.h"
#include "queuePriority.h"
#include <cassert>
class BinaryTreeTests
{
private:
	void Test_Search();
    void Test_Remove();
    void Test_Concat();
    void Test_GetSubTree();
    void Test_Round();
public:
    void Test();
};
void BinaryTreeTests::Test_Round() 
{
    int* itemsArray = new int[10]{ 0,2,6,5,7,1,9,3,8,4 };
    Stack<int>* stack = new Stack<int>(itemsArray, 10);
    BinaryTree<int>* example = new BinaryTree<int>(stack);
    assert(example->Round("NLR") == "4,3,1,0,2,8,7,5,6,9"); 
    assert(example->Round("NRL") == "4,8,9,7,5,6,3,1,2,0");
    assert(example->Round("LRN") == "0,2,1,3,6,5,7,9,8,4");
    assert(example->Round("LNR") == "0,1,2,3,4,5,6,7,8,9");
    assert(example->Round("RLN") == "9,6,5,7,8,2,0,1,3,4");
    assert(example->Round("RNL") == "9,8,7,6,5,4,3,2,1,0");
}
void BinaryTreeTests::Test_Search() 
{
    int* itemsArray = new int[10]{ 0,2,6,5,7,1,9,3,8,4 };
    Stack<int>* stack = new Stack<int>(itemsArray, 10);
    BinaryTree<int>* example = new BinaryTree<int>(stack);
    assert(example->SearchNode(5)==true);
    assert(example->SearchNode(51)==false);
}
void BinaryTreeTests::Test_Remove() 
{
    int* itemsArray = new int[10]{ 0,2,6,5,7,1,9,3,8,4 };
    Stack<int>* stack = new Stack<int>(itemsArray, 10);
    BinaryTree<int>* example = new BinaryTree<int>(stack);
    example->Remove(3);
    assert(example->Round("LNR") == "0,1,2,4,5,6,7,8,9");
    example->Remove(0);
    assert(example->Round("LNR") == "1,2,4,5,6,7,8,9");
    
}
void BinaryTreeTests::Test_Concat()
{
    int* itemsArray = new int[5]{ 1,9,3,8,4 };
    Stack<int>* stack = new Stack<int>(itemsArray, 5);
    BinaryTree<int>* example = new BinaryTree<int>(stack);
    int* itemsArray1 = new int[5]{ 0,2,6,5,7 };
    Stack<int>* stack1 = new Stack<int>(itemsArray1, 5);
    BinaryTree<int>* example1 = new BinaryTree<int>(stack1);
    example->Concat(example1);
    assert( example->Round("LNR") == "0,1,2,3,4,5,6,7,8,9");
}
void BinaryTreeTests::Test_GetSubTree() 
{
    int* itemsArray = new int[10]{ 0,2,6,5,7,1,9,3,8,4 };
    Stack<int>* stack = new Stack<int>(itemsArray, 10);
    BinaryTree<int>* example = new BinaryTree<int>(stack);
    BinaryTree<int>* SubTree = example->GetSubTree(3);
    assert(SubTree->Round("LNR") == "0,1,2,3");
}


void BinaryTreeTests::Test()
{
    Test_Search();
    Test_Concat();
    Test_Remove();
    Test_GetSubTree();
    Test_Round();
    cout << "BinaryTree work->correctly" << endl;
}
