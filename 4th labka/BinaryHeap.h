#pragma once
#include "ArraySequence.h"
template<typename T>
class BinaryHeap
{
private:
	ArraySequence<T> * buffer;
public:
	BinaryHeap(T* items, int count);
	BinaryHeap(ArraySequence<T>* items);
	BinaryHeap();
public:
	void FillArray(int index, ArraySequence<T>*);
	void Swap(int firstIndex, int secondIndex);
	void Heapify(int index);
	void Add(T item);
	void Print();
	int GetLength();
	bool Search(const T item);
	void Delete(T item);
	T Extract();
	BinaryHeap<T>* GetSubTree(T item);
	T Get(int index);
};
template<typename T>
BinaryHeap<T>::BinaryHeap(T* items, int count)
{
	this->buffer = new ArraySequence<T>(items,count);
	
	for (int i = ((this->buffer->GetLength())/2)-1; i >= 0; i--) 
	{
		Heapify(i);
	}

}
template<typename T>
BinaryHeap<T>::BinaryHeap(ArraySequence<T>* items)
{
	this->buffer = items;

	for (int i = ((this->buffer->GetLength()) / 2) - 1; i >= 0; i--)
	{
		Heapify(i);
	}

}
template<typename T>
BinaryHeap<T>::BinaryHeap() 
{
	buffer = new ArraySequence<T>();
}


template <typename T>
void BinaryHeap<T>:: Swap (int firstIndex, int secondIndex)
{
	T firstElement = this->buffer->Get(firstIndex);
	T secondElement = this->buffer->Get(secondIndex);
	this->buffer->Remove(firstIndex);
	this->buffer->InsertAt(secondElement, firstIndex);
	this->buffer->Remove(secondIndex);
	this->buffer->InsertAt(firstElement, secondIndex);
}
template<typename T>
void BinaryHeap<T>::Heapify(int index)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	int lagestIndex = index;
	if (left<this->buffer->GetLength() && this->buffer->Get(left) > this->buffer->Get(lagestIndex)) { lagestIndex = left; }
	if (right < this->buffer->GetLength() && this->buffer->Get(right) > this->buffer->Get(lagestIndex)) { lagestIndex = right; }
	if (lagestIndex != index) 
	{
		Swap(index, lagestIndex);
		Heapify(lagestIndex);
	}
}
template<typename T>
int BinaryHeap<T>::GetLength() 
{
	return this->buffer->GetLength();
}
template <typename T>
T BinaryHeap<T> :: Get(int index) 
{
	return buffer->Get(index);
}
template <typename T>
void BinaryHeap<T> ::Add(T item)
{
	this->buffer->Append(item);
	int index = (this->buffer->GetLength()-1);
	while (item > this->buffer->Get(index / 2) && index / 2 != 0)
	{
		Swap(index, index / 2);
		index = index / 2;
	}
	if (index / 2 == 0 && item > this->buffer->Get(index / 2))
	{
		Swap(index, index / 2);
	}

}
template <typename T>
void BinaryHeap<T> ::Print()
{
	for (int i = 0; i < buffer->GetLength(); i++) 
	{
		cout << buffer->Get(i) << endl; 
	}
}template <typename T>
bool BinaryHeap<T> :: Search(const T item) 
{
	for (int i = 1; i < this->buffer->GetLength(); i++)
		if (this->buffer->Get(i) == item)
			return true;

	return false;
}
template<typename T>
void BinaryHeap<T>::Delete(T item) 
{
	int leastElementIndex = this->buffer->GetLength() - 1;
	for (int i = 0; i < this->buffer->GetLength(); i++) 
	{
		if (this->Get(i) == item) 
		{
			Swap(i, leastElementIndex);
			this->buffer->Remove(leastElementIndex);
			Heapify(i);
			return;
		}
	}
}
template<typename T>
void BinaryHeap<T>::FillArray(int index,ArraySequence<T>* resultArray)
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	resultArray->Append(this->Get(index));
	if (left < this->buffer->GetLength()) { FillArray(left, resultArray); }
	if (right < this->buffer->GetLength()) { FillArray(right, resultArray); }
	return;
};
template<typename T>
BinaryHeap<T>* BinaryHeap<T>::GetSubTree(T item) 
{
	ArraySequence<T>* resultArray = new ArraySequence<T>();
	
	
	for (int i = 0; i < this->GetLength(); i++) 
	{
		if (this->Get(i) == item) 
		{
			FillArray(i,resultArray);
			return new BinaryHeap<T>(resultArray);
		}
	}
}
template<typename T>
T BinaryHeap<T>::Extract()
{
	int lastIndex = this->GetLength() - 1;
	T result = this->Get(0);
	Swap(lastIndex,0);
	this->buffer->Remove(lastIndex);
	Heapify(0);
	return result;
}
