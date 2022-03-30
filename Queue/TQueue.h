#pragma once
#include "TStack.h"

template <class T>
class TQueue : public TStack<T>
{
protected:
	size_t low_ind = 0;
	virtual int GetNextIndex(int ind)const
	{
		return ++ind % this->size;
	}
public:
	TQueue() { }
	TQueue(size_t _size):TStack<T>(_size){}
	virtual T pop()override
	{
		if (this->IsEmpty())
		{
			throw std::runtime_error("Queue is empty");
		}
		T& tmp = this->mass[low_ind];
		this->num--;
		low_ind = GetNextIndex(low_ind);
		return tmp;
	}

	TQueue(const TQueue<T>& q) {
		this->size = q.size;
		this->num = q.num;
		this->top_ind = q.top_ind;
		this->low_ind = q.low_ind;
		this->mass = new T[this->size];
		for (size_t i = 0; i < this->size; i++) {
			this->mass[i] = q.mass[i];
		}
	}

	TQueue<T>& operator=(const TQueue<T>& q) {
		if (&q == this) {
			return *this;
		}
		this->size = q.size;
		this->num = q.num;
		this->top_ind = q.top_ind;
		this->low_ind = q.low_ind;
		this->mass = new T[this->size];
		for (size_t i = 0; i < this->size; i++) {
			this->mass[i] = q.mass[i];
		}

		return *this;
	}



};