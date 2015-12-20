#pragma once
#include <iostream>
#include "Errors.h"
using namespace std;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

template <class T>
class Array {
	T*data = new T[0];
	int size = 0;
public:
	Array(int size) {
		try {
			if (size < 0) {
				throw NegativeSize();
			}
		}
		catch (NegativeSize a) {
			a.printError();
			size = 0;
			cout << "Создано с размером " << size << endl;
		}
		delete[]data;
		data = new T[size];
		this->size = size;
	}
	Array(Array & arr) {
		delete[]data;
		size = arr.getSize();
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = arr.data[i];
		}
	}
	~Array() {
		delete[] data;
	}
	void setData(int index, T data) {
		try {
			if (index < 0) {
				throw NegativeIndex();
			}
			else if (index >= size) {
				throw UndefinedIndex();
			}
		}
		catch (NegativeIndex a) {
			a.printError();
			return;
		}
		catch (UndefinedIndex a) {
			a.printError();
			return;
		}
		this->data[index] = data;
	}
	T getData(int index) {
		try {
			if (size == 0) {
				throw ZeroArray();
			}
			else if (index < 0) {
				throw NegativeIndex();
			}
			else if (index >= size) {
				throw UndefinedIndex();
			}
		}
		catch (ZeroArray a) {
			a.printError();
			return 0;
		}
		catch (NegativeIndex a) {
			a.printError();
			return 0;
		}
		catch (UndefinedIndex a) {
			a.printError();
			return 0;
		}
		return data[index];
	}
	int getSize() {
		return size;
	}
	void print() {
		cout << "Array: (";
		for (int i = 0; i < size; i++) {
			if (i > 0) {
				cout << ", ";
			}
			else {
				cout << " ";
			}
			cout << data[i];
		}
		cout << " )\n";
	}
	friend Array<T> operator * (const Array<T>&array1, const Array<T>&array2) {
		Array<T>temp(min(array1.size, array2.size));
		for (int i = 0; i < temp.getSize(); i++) {
			temp.setData(i, array1.data[i] * array2.data[i]);
		}
		return temp;
	}
	T operator [](int index) {
		return getData(index);
	}
	Array<T> & operator = (Array<T> & arr) {
		delete[]data;
		size = arr.getSize();
		data = new T[size];
		for (int i = 0; i < size; i++) {
			data[i] = arr.data[i];
		}
		return *this;
	}
};