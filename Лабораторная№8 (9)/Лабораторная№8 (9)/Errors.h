#pragma once
#include <iostream>

using namespace std;

class Error {
	char * name = new char[0];
	int name_length = 0;
public:
	Error() {}
	Error(Error & copy) {
		delete[] name;
		name_length = copy.name_length;
		name = new char[name_length];
		for (int i = 0; i < name_length; i++) {
			name[i] = copy.name[i];
		}
	}
	void setName(const char * name) {
		delete[] this->name;
		name_length = strlen(name);
		this->name = new char[name_length];
		for (int i = 0; i < name_length; i++) {
			this->name[i] = name[i];
		}
	}
	virtual void printError() {
		for (int i = 0; i < name_length; i++) {
			cout << name[i];
		}
		cout << endl;
	}
	virtual~Error() {
		delete[] name;
	}
};

class NegativeSize : public Error {
public:
	NegativeSize() {
		setName("Исключение: отрицательный размер!");
	}
};

class NegativeIndex : public Error {
public:
	NegativeIndex() {
		setName("Исключение: отрицательный индекс!");
	}
};

class UndefinedIndex : public Error {
public:
	UndefinedIndex() {
		setName("Исключение: индекс больше размера массива!");
	}
};

class ZeroArray : public Error {
public:
	ZeroArray() {
		setName("Исключение: нулевой массив!");
	}
};

class UnnamedPeople : public Error {
public:
	UnnamedPeople() {
		setName("Исключение: человек без имени!");
	}
};