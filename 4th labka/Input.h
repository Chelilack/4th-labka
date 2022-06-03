#pragma once
#include "ComplexNumber.h"
#include "Student.h"
#include "Teacher.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "Stack.h"
#include"BinaryTree.h"
auto InputIntArray = [&]() {
	int typeInput;
	int* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new int[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			cin >> items[i];
		}
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	else if (typeInput == 2)
	{
		int min, max;
		cout << "Enter min:" << endl;
		cin >> min;
		cout << "Enter max:" << endl;
		cin >> max;
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			items[i] = rand() % (max - min) + min;
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	 return new BinaryTree<int>(new Stack<int>(items, count));
};
auto InputFloatArray = [&]()
{
	int typeInput;
	float* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new float[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			cin >> items[i];
		}
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	else if (typeInput == 2)
	{
		float min, max;
		cout << "Enter min:" << endl;
		cin >> min;
		cout << "Enter max:" << endl;
		cin >> max;
		cout << '[';
		for (int i = 0; i < count; i++)
		{
			items[i] = ((float)rand() / (float)RAND_MAX) * (max - min) + min;
			cout << ' ' << items[i];
		}
		cout << " ]";
	}
	return new BinaryTree<float>(new Stack<float>(items, count));
};
auto InputComplexNumberArray = [&]() {
	int typeInput;
	ComplexNumber* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new ComplexNumber[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			items[i].Input();
		}
		for (int i = 0; i < count; i++)
		{
			cout << items[i];
		}
	}
	else if (typeInput == 2)
	{
		float minReal, maxReal, minIm, maxIm;
		cout << "min Real:" << endl;
		cin >> minReal;
		cout << "max Real:" << endl;
		cin >> maxReal;
		cout << "min Imaginary:" << endl;
		cin >> minIm;
		cout << "max Imaginary:" << endl;
		cin >> maxIm;
		for (int i = 0; i < count; i++)
		{
			items[i].RandomInput(minReal, maxReal, minIm, maxIm);
			cout << items[i];
		}
	}
	return new BinaryTree<ComplexNumber>(new Stack<ComplexNumber>(items, count));
};
auto InputCharPtrArray = [&]() {
	int typeInput;
	char** items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new char* [count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			char* str = new char[64];
			cin >> str;
			items[i] = str;
		}

		for (int i = 0; i < count; i++)
		{
			cout << ' ' << items[i];
		}

	}
	else if (typeInput == 2)
	{
		ifstream WordFile;
		int strNow;
		int strNumber;

		for (int i = 0; i < count; i++)
		{
			strNow = 0;
			char* str = new char[64];
			WordFile.open("D:/опера/из гитхаба/name-generator-master/name-generator-master/resources/american/1-1000.txt");
			strNumber = rand() % 1000 + 1;
			while (strNow != strNumber)
			{
				WordFile.getline(str, 64, '\n');
				strNow++;
			}
			WordFile.close();
			items[i] = str;
			cout << ' ' << items[i];
		}

	}
	return new BinaryTree<char*>(new Stack<char*>(items, count));
};
auto InputStudentArray = [&]() {
	int typeInput;
	Student* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new Student[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			items[i].Input();
		}
		for (int i = 0; i < count; i++)
		{
			cout << items[i];
		}
	}
	else if (typeInput == 2)
	{

		for (int i = 0; i < count; i++)
		{
			items[i].RandomInput();
			cout << items[i];
			cout << "---------------" << endl;
		}
	}
	return new BinaryTree<Student>(new Stack<Student>(items, count));
};
auto InputTeacherArray = [&]() {
	int typeInput;
	Teacher* items;
	int count;
	system("cls");
	cout << "---------------" << endl;
	cout << "|1.Input      |" << endl;
	cout << "|2.RandomInput|" << endl;
	cout << "---------------" << endl;
	cin >> typeInput;
	cout << "Enter count:" << endl;
	cin >> count;

	items = new Teacher[count];
	while (typeInput != 1 && typeInput != 2)
	{
		cout << "try again!" << endl;
		cin >> typeInput;
	}
	if (typeInput == 1)
	{
		for (int i = 0; i < count; i++)
		{
			cout << "data[" << i << "]=" << endl;
			items[i].Input();
		}
		for (int i = 0; i < count; i++)
		{
			cout << items[i];
		}
	}
	else if (typeInput == 2)
	{

		for (int i = 0; i < count; i++)
		{
			items[i].RandomInput();
			cout << items[i];
			cout << "---------------" << endl;
		}
	}
	return new BinaryTree<Teacher>(new Stack<Teacher>(items, count));
};