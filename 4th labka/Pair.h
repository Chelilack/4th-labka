#pragma once
template <class T>
class Pair
{
private:
    T item;
    bool status;

public:
    Pair(T item, bool status) : item(item) , status(status){}
    Pair(const Pair<T>& another)
    {
        this->item = another.GetItem();
        this->status = another.GetStatus();
    }
    Pair() {}

public:
    T GetItem() const { return this->item; }
    bool GetStatus() const { return this->status; }
    bool operator == (const Pair<T> another)
    {
        return this->item == another.GetItem() && this->status == another.GetStatus();
    }
};
