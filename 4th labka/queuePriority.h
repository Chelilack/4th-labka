#pragma once
#include "BinaryHeap.h"
template<typename T >
class queuePriority
{
private:
	BinaryHeap<T>* binHeap;
public:
	queuePriority(T* items, int count);
	queuePriority();
public:
	int GetLength();
	void Add(T item);
	T Extract();
	T Get(int i);
	T GetFirst();
	T GetLast();
};
template<typename T>
queuePriority<T>::queuePriority(T* items, int count)
{
	this->binHeap = new BinaryHeap<T>(items,count);
}
template<typename T>
queuePriority<T>::queuePriority() 
{
	this->binHeap = new BinaryHeap<T>();
}
template<typename T>
int queuePriority<T>::GetLength() 
{
	return this->binHeap->GetLength();
}
template<typename T>
void queuePriority<T> ::Add(T item) 
{
	return this->binHeap->Add(item);
}
template<typename T>
T queuePriority<T> ::Extract()
{
	return this->binHeap->Extract();
}
template<typename T>
T queuePriority<T> ::Get(int i) 
{
	this->binHeap->Get(i);
}
template<typename T>
T queuePriority<T> ::GetFirst() 
{
	this->binHeap->Get(0);
}
template<typename T>
T queuePriority<T> ::GetLast() 
{
	this->binHeap->Get(this->binHeap->GetLength());
}