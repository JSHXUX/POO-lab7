#pragma once
#include <iostream>
using namespace std;
template <typename T>
bool compare(T x, T y)
{
	if (x >= y) return true;
	else return false;
}
template <typename T>
bool equal(T x, T y)
{
	if (x == y + 1) return true;
	else return false;
}
template <typename T>
class Vector
{
	private:
		T* list;
		int count;
		int size;
	public:
		Vector() : list(nullptr), count(0), size(0) {};
		~Vector() 
		{
			delete[] this->list;
			this->count = 0;
			this->size = 0;
		}
		void push(T x)
		{
			if (this->count == 0)
			{
				this->list = new T[8];
				this->list[this->count++] = x;
				this->size = 8;
			}
			else
			{
				if (this->count >= this->size)
				{
					this->size *= 2;
					T* aux = new T[this->size];
					for (int i = 0; i < this->count; i++)
						aux[i] = this->list[i];
					delete[] this->list;
					this->list = aux;
				}
				this->list[this->count++] = x;
			}
		}
		T pop()
		{
			return this->list[this->count - 1];
		}
		void remove(int index)
		{
			for (int i = index; i < this->count - 1; i++)
				this->list[i] = this->list[i + 1];
			this->count--;
			if (this->count <= this->size / 2)
			{
				T* aux = new T[this->size / 2];
				for (int i = 0; i < this->count; i++)
					aux[i] = this->list[i];
				delete[] this->list;
				this->list = aux;
				this->size /= 2;
			}
		}
		void insert(int index, T x)
		{
			this->push(x);
			for (int i = this->count - 1; i > index; i--)
				this->list[i] = this->list[i - 1];
			this->list[index] = x;
		}
		bool operator < (const T& x)
		{
			if (this < x) return true;
			else return false;
		}
		void sort(bool(*compare)(T,T) = nullptr)
		{
			if (compare != nullptr)
			{
				for (int i = 0; i < this->count - 1; i++)
					for (int j = i + 1; j < this->count; j++)
						if (compare(this->list[i], this->list[j]))
						{
							T aux = this->list[i];
							this->list[i] = this->list[j];
							this->list[j] = aux;
						}
			}
			else
			{
				for (int i = 0; i < this->count - 1; i++)
					for (int j = i + 1; j < this->count; j++)
						if (this->list[i] < this->list[j])
						{
							T aux = this->list[i];
							this->list[i] = this->list[j];
							this->list[j] = aux;
						}
			}
		}
		void print()
		{
			for (int i = 0; i < this->count; i++)
				cout << this->list[i] << ' ';
			printf("%c", '\n');
		}
		const T& get(int index)
		{
			return this->list[index];
		}
		void set(int index, T x)
		{
			if (index < this->count)
				this->list[index] = x;
		}
		int counter()
		{
			return this->count;
		}
		bool operator == (const T& x)
		{
			if (this == x) return true;
			else return false;
		}
		int firstIndexOf(T x, bool(*equal)(T, T) = nullptr)
		{
			if (equal != nullptr)
			{
				for (int i = 0; i < this->count; i++)
					if (equal(this->list[i], x))
						return i;
			}
			else
			{
				for (int i = 0; i < this->count; i++)
					if (this->list[i]==x)
						return i;
			}
		}
};