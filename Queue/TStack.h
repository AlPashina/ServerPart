#pragma once
#include <locale>

template <class T>
class TStack
{
protected:
	T* mass;
	size_t size = 10;
	size_t num = 0; //кол-во элементов
	int top_ind = -1;

	virtual int GetNextInd(int ind) { return ++ind; }
public:
	TStack(size_t _size = 10){
		size = _size;
		mass = new T[size];
		num = 0;
	}
	~TStack() {
		delete[] mass;
	}
	bool IsEmpty() {
		return num == 0;
	}
	bool IsFull() {
		return num == size;
	}
	void push(const T& elem)
	{
		if (IsFull()) {
			throw std::runtime_error("Stack is full");
		}
		else {
			top_ind = GetNextInd(top_ind);
			mass[top_ind] = elem;
			num++;
		}
	}
	virtual T pop()	{
		if (IsEmpty()) {
			throw std::runtime_error("Stack is empty");
		}
		else {
			num--;
			return mass[top_ind--];
		}
	}
};