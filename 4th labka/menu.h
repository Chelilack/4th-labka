#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "ArraySequenceTests.h"
#include "DynamicArrayTests.h"
#include "LinkedListTests.h"
#include "LinkedListSequenceTests.h"
#include "ComplexNumber.h"
#include "Student.h"
#include "Teacher.h"
#include "Errors.h"
#include "Input.h"
#include "functions.h"
#include "BinaryHeap.h"
#include "BinaryHeapTests.h"
#include "BinaryTreeTests.h"
#include "BinaryTree.h"

using namespace std;
void menu()
{
	BinaryTree<int>* binaryTreeInt = 0;
	BinaryTree<float>* binaryTreeFloat = 0;
	BinaryTree<char*>* binaryTreeCharPtr = 0;
	BinaryTree<ComplexNumber>* binaryTreeComplexNumber=0;
	BinaryTree<Student>* binaryTreeStudent=0;
	BinaryTree<Teacher>* binaryTreeTeacher=0;
	int page = -1;
	auto menuExistQueue = [&]()
	{
		if (binaryTreeCharPtr==0 && binaryTreeComplexNumber==0 && binaryTreeFloat==0 && binaryTreeInt==0 && binaryTreeStudent==0 && binaryTreeTeacher==0) 
		{
			cout << "all BinaryTree empty!" << endl; 
			system("pause");
			page = -1;
			menu();
		}
		int j = 0;
		int i=1;
		int choice;
		int* data = new int[6];
		cout <<                                             "------------------------------" << endl;
		if (binaryTreeInt != 0)           { cout <<'|'<< i << ". binaryTree<int>          |"<< endl;i++;data[j++]=1; }
		if (binaryTreeFloat != 0)         { cout <<'|'<< i << ". binaryTree<float>        |"<< endl;i++;data[j++]=2; }
		if (binaryTreeCharPtr != 0)       { cout <<'|'<< i << ". binaryTree<char*>        |"<< endl;i++;data[j++]=3; }
		if (binaryTreeComplexNumber != 0) { cout <<'|'<< i << ". binaryTree<ComplexNumber>|"<< endl;i++;data[j++]=4; }
		if (binaryTreeStudent != 0)       { cout <<'|'<< i << ". binaryTree<Student>      |"<< endl;i++;data[j++]=5; }
		if (binaryTreeTeacher != 0)       { cout <<'|'<< i << ". binaryTree<Teacher>      |"<< endl;i++;data[j++]=6; }
		cout <<                                             "------------------------------" << endl;
		cin >> choice;
		return (int)data[choice-1];
	};
	
	while (page != 0)
	{
		system("cls");
		if (page == -1)
		{
			cout << "-------------------------------" << endl;
			cout << "|1.Create BinaryTree          |" << endl;
			cout << "|2.Do smth with BinaryTree    |" << endl;
			cout << "|3.Run Tests                  |" << endl;
			cout << "|4.Run Tests with N elements  |" << endl;
			cout << "|0.Exit                       |" << endl;
			cout << "-------------------------------" << endl;
			cin >> page;
			while (page != 1 && page != 2 && page != 3 && page!=0 && page != 4)
			{
				cout << "try again!" << endl;
				cin >> page;
			}
		}
		else if (page == 1)
		{
			system("cls");
			cout << "----------------------" << endl;
			cout << "|1. Integers         |" << endl;
			cout << "|2. Floats           |" << endl;
			cout << "|3. Complex numbers  |" << endl;
			cout << "|4. Strings          |" << endl;
			cout << "|5. Students         |" << endl;
			cout << "|6. Teachers         |" << endl;
			cout << "|0. Exit             |" << endl;
			cout << "----------------------" << endl;
			int miniPage;
			int decision;
			cin >> miniPage;
			while (miniPage != 1 && miniPage != 2 && miniPage != 3 && miniPage != 4 && miniPage != 5 && miniPage != 6 && miniPage != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage;
			}
			if (miniPage == 1) 
			{
				binaryTreeInt=InputIntArray();
			}
			else if (miniPage == 2)
			{
				binaryTreeFloat=InputFloatArray();
			}
			else if (miniPage == 3) 
			{
				binaryTreeComplexNumber=InputComplexNumberArray();
			}
			else if (miniPage == 4) 
			{
				binaryTreeCharPtr=InputCharPtrArray();
			}
			else if (miniPage == 5)
			{
				binaryTreeStudent=InputStudentArray();
			}
			else if (miniPage == 6) 
			{
				binaryTreeTeacher = InputTeacherArray();
			}
			cout << endl;
			system("pause");
			page = -1;
		}
		else if (page == 2)
		{
			cout <<"----------------------" << endl;
			cout<< "|1. Add              |" << endl;
			cout<< "|2. Remove           |" << endl;
			cout<< "|3. Search           |" << endl;
			cout<< "|4. Round            |" << endl;
			cout<< "|5. Get substree     |" << endl;
			cout<< "|6. Concatenate      |" << endl;
			cout<< "|0. Quit             |" << endl;
			cout <<"----------------------" << endl;
			int miniPage2;
			cin >> miniPage2;
			while (miniPage2 != 1 && miniPage2 != 2 && miniPage2 != 3 && miniPage2 != 4 && miniPage2 != 5 && miniPage2 != 6 && miniPage2 != 7 && miniPage2 != 0)
			{
				cout << "try again!" << endl;
				cin >> miniPage2;
			}
			if (miniPage2 == 1) 
			{

				int choice = menuExistQueue();
				if (choice == 1) 
				{ 
					int intPass; 
					cout << "Enter int:" << endl;
					cin >> intPass; 
					binaryTreeInt->Add(intPass); 
				}
				else if (choice == 2)
				{
					float floatPass;
					cout << "Enter float:" << endl;
					cin >> floatPass;
					binaryTreeFloat->Add(floatPass);
				}
				else if (choice == 3)
				{
					char* charPtrPass = new char[64];
					cout << "Enter char*:" << endl;
					cin >> charPtrPass;
					binaryTreeCharPtr->Add(charPtrPass);
				}
				else if (choice == 4)
				{
					ComplexNumber complexNumberPass;
					cout << "Enter Complex Number:" << endl;
					complexNumberPass.Input();
					binaryTreeComplexNumber->Add(complexNumberPass);
				}
				else if (choice == 5)
				{
					Student studentPass;
					cout << "Enter Student:" << endl;
					studentPass.Input();
					binaryTreeStudent->Add(studentPass);
				}
				else if (choice == 6)
				{
					Teacher teacherPass;
					cout << "Enter Teacher" << endl;
					teacherPass.Input();
					binaryTreeTeacher->Add(teacherPass);
				}

			}
			else if (miniPage2 == 2) 
			{
				int choice = menuExistQueue();
				if (choice == 1)
				{
					int intPass;
					cout << "Enter int:" << endl;
					cin >> intPass;
					binaryTreeInt->Remove(intPass);
				}
				else if (choice == 2)
				{
					float floatPass;
					cout << "Enter float:" << endl;
					cin >> floatPass;
					binaryTreeFloat->Remove(floatPass);
				}
				else if (choice == 3)
				{
					char* charPtrPass = new char[64];
					cout << "Enter char*:" << endl;
					cin >> charPtrPass;
					binaryTreeCharPtr->Remove(charPtrPass);
				}
				else if (choice == 4)
				{
					ComplexNumber complexNumberPass;
					cout << "Enter Complex Number:" << endl;
					complexNumberPass.Input();
					binaryTreeComplexNumber->Remove(complexNumberPass);
				}
				else if (choice == 5)
				{
					Student studentPass;
					cout << "Enter Student:" << endl;
					studentPass.Input();
					binaryTreeStudent->Remove(studentPass);
				}
				else if (choice == 6)
				{
					Teacher teacherPass;
					cout << "Enter Teacher" << endl;
					teacherPass.Input();
					binaryTreeTeacher->Remove(teacherPass);
				}
			}
			else if (miniPage2 == 3)
			{
				int choice = menuExistQueue();
				if (choice == 1)
				{
					int intPass;
					cout << "Enter int:" << endl;
					cin >> intPass;
					cout << "Result->" << binaryTreeInt->SearchNode(intPass) << endl;
				}
				else if (choice == 2)
				{
					float floatPass;
					cout << "Enter float:" << endl;
					cin >> floatPass;
					cout << "Result->" << binaryTreeFloat->SearchNode(floatPass) << endl;
				}
				else if (choice == 3)
				{
					char* charPtrPass = new char[64];
					cout << "Enter char*:" << endl;
					cin >> charPtrPass;
					cout << "Result->" << binaryTreeCharPtr->SearchNode(charPtrPass) << endl;;
				}
				else if (choice == 4)
				{
					ComplexNumber complexNumberPass;
					cout << "Enter Complex Number:" << endl;
					complexNumberPass.Input();
					cout << "Result->" << binaryTreeComplexNumber->SearchNode(complexNumberPass)<<endl;
				}
				else if (choice == 5)
				{
					Student studentPass;
					cout << "Enter Student:" << endl;
					studentPass.Input();
					cout << "Result->" << binaryTreeStudent->SearchNode(studentPass)<<endl;
				}
				else if (choice == 6)
				{
					Teacher teacherPass;
					cout << "Enter Teacher" << endl;
					teacherPass.Input();
					cout << "Result->" << binaryTreeTeacher->SearchNode(teacherPass)<<endl;
				}
			}
			else if (miniPage2 == 4) 
			{
				int choice=menuExistQueue();
				const char** roundTrips = new const char* [6]{ "NLR","NRL","LRN","LNR","RLN","RNL" };
				cout<<"1.NLR\n2.NRL\n3.LRN\n4.LNR\n5.RLN\n6.RNL"<< endl;
				int pass;
				cin >> pass;
				while (pass != 1 && pass != 2 && pass != 3 && pass != 4 && pass != 5 && pass != 6) 
				{
					cout << "try again" << endl;
					cin >> pass;
				}
				const char* choiceRound = roundTrips[pass - 1];

				if (choice == 1) 
				{
					cout << binaryTreeInt->Round(choiceRound) << endl;
					
				}
				if (choice == 2)
				{
					cout << binaryTreeFloat->Round(choiceRound) << endl;
				}
				if (choice == 3)
				{
					cout << binaryTreeCharPtr->Round(choiceRound) << endl;
				}
				if (choice == 4)
				{
					cout << binaryTreeComplexNumber->Round(choiceRound) << endl;
				}
				if (choice == 5)
				{
					cout << binaryTreeStudent->Round(choiceRound) << endl;
				}
				if (choice == 6)
				{
					cout << binaryTreeTeacher->Round(choiceRound) << endl;

				}
			}
			else if (miniPage2 == 5)
			{
				int choice = menuExistQueue();
				if (choice == 1) 
				{ 
					int intPass; 
					cout << "Enter int:" << endl;
					cin >> intPass; 
					BinaryTree<int>* IntSubTree =binaryTreeInt->GetSubTree(intPass); 
					cout<<IntSubTree->Round("LNR")<<endl;
				}
				else if (choice == 2)
				{
					float floatPass;
					cout << "Enter float:" << endl;
					cin >> floatPass;
					BinaryTree<float>* FloatSubTree = binaryTreeFloat->GetSubTree(floatPass);
					cout << FloatSubTree->Round("LNR") << endl;
				}
				else if (choice == 3)
				{
					char* charPtrPass = new char[64];
					cout << "Enter char*:" << endl;
					cin >> charPtrPass;
					BinaryTree<char*>* CharPtrSubTree = binaryTreeCharPtr->GetSubTree(charPtrPass);
					cout << CharPtrSubTree->Round("LNR") << endl;
				}
				else if (choice == 4)
				{
					ComplexNumber complexNumberPass;
					cout << "Enter Complex Number:" << endl;
					complexNumberPass.Input();
					BinaryTree<ComplexNumber>* ComplexNumberSubTree = binaryTreeComplexNumber->GetSubTree(complexNumberPass);
					cout << ComplexNumberSubTree->Round("LNR") << endl;
				}
				else if (choice == 5)
				{
					Student studentPass;
					cout << "Enter Student:" << endl;
					studentPass.Input();
					BinaryTree<Student>* StudentSubTree = binaryTreeStudent->GetSubTree(studentPass);
					//cout << StudentSubTree->Round("LNR") << endl;
				}
				else if (choice == 6)
				{
					Teacher teacherPass;
					cout << "Enter Teacher" << endl;
					teacherPass.Input();
					BinaryTree<Teacher>* TeacherSubTree = binaryTreeTeacher->GetSubTree(teacherPass);
					//cout << TeacherSubTree->Round("LNR") << endl;
				}
			}
			else if (miniPage2 == 6)
			{
				int choice = menuExistQueue();
				if (choice == 1)
				{
					BinaryTree<int>* binaryTreeInt1 = InputIntArray();
					binaryTreeInt->Concat(binaryTreeInt1);
				}
				else if (choice == 2)
				{
					BinaryTree<float>* binaryTreeFloat1 = InputFloatArray();
					binaryTreeFloat->Concat(binaryTreeFloat1);
				}
				else if (choice == 3)
				{
					BinaryTree<char*>* binaryTreeCharPtr1 = InputCharPtrArray();
					binaryTreeCharPtr->Concat(binaryTreeCharPtr1);
				}
				else if (choice == 4)
				{
					BinaryTree<ComplexNumber>* binaryTreeComplexNumber1 = InputComplexNumberArray();
					binaryTreeComplexNumber->Concat(binaryTreeComplexNumber1);
				}
				else if (choice == 5)
				{
					BinaryTree<Student>* binaryTreeStudent1 = InputStudentArray();
					binaryTreeStudent->Concat(binaryTreeStudent1);
				}
				else if (choice == 6)
				{
					BinaryTree<Teacher>* binaryTreeTeacher1 = InputTeacherArray();
					binaryTreeTeacher->Concat(binaryTreeTeacher1);
				}
			}
			cout << endl;
			system("pause");

			page = -1;
		}
		
		else if (page == 3)
		{
			LinkedListTests* testList = new LinkedListTests();
			DynamicArrayTests* testArray = new DynamicArrayTests();
			LinkedListSequenceTests* testListSequence = new LinkedListSequenceTests();
			ArraySequenceTests* testArraySequence = new ArraySequenceTests();
			//queuePriorityTests* testQueuePriority = new queuePriorityTests();
			//testQueuePriority->Test();
			BinaryHeapTests* binaryTest = new BinaryHeapTests();
			BinaryTreeTests* binaryTreeTest = new BinaryTreeTests();
			binaryTreeTest->Test();
			std::this_thread::sleep_for(400ms);
			binaryTest->Test();
			std::this_thread::sleep_for(400ms);
			testArray->Test();
			std::this_thread::sleep_for(400ms);
			testList->Test();
			std::this_thread::sleep_for(400ms);
			testListSequence->Test();
			std::this_thread::sleep_for(400ms);
			testArraySequence->Test();
			std::this_thread::sleep_for(400ms);
			cout << "4th Laba work correctly\n";
			system("pause");
			page = -1;
		}
		else if (page == 4) 
		{
			BinaryTree<int>* example = new BinaryTree<int>();
			int len;
			cout << "Choose:" << endl;
			cout << "1.15000" << endl;
			cout << "2.10000000" << endl;
			int choice;
			cin >> choice;
			while (choice!= 1 && choice != 2 )
			{
				cout << "try again!" << endl;
				cin >> choice;
			}
			if (choice == 1) 
			{
				len = 15000;
			}
			else 
			{
				len = 10000000;
			}
			clock_t t1 = clock();
			for (int i = 0; i < len; i++) 
			{
				example->Add(rand());
			}
			clock_t t2 = clock();
			cout << difftime(t2, t1) / CLOCKS_PER_SEC << "->Time to Fill " << len << "elements"<<endl;

			t1 = clock();
			example->SearchNode(rand());
			t2 = clock();
			cout <<difftime(t2, t1) / CLOCKS_PER_SEC << "->Time to Search rendom element " <<endl;

			t1 = clock();
			example->Round("LNR");
			t2 = clock();
			cout << difftime(t2, t1) / CLOCKS_PER_SEC << "->Time to Round(LNR)" << endl;
			system("pause");
			page = -1;
		}

	}
}