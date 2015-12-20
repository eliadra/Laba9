#pragma once
#include <iostream>
using namespace std;

class Person {
	char * name = new char[0];
	int name_length = 0;
public:
	Person() {}
	Person(const char * name) {
		setName(name);
	}
	Person(Person & copy) {
		name_length = copy.name_length;
		delete[]name;
		name = new char[name_length];
		for (int i = 0; i < name_length; i++) {
			name[i] = copy.name[i];
		}
	}
	~Person() {
		delete[] name;
	}
	void setName(const char * name) {
		delete[] this->name;
		name_length = strlen(name);
		this->name = new char[name_length];
		for (int i = 0; i < name_length; i++) {
			this->name[i] = name[i];
		}
	}
	char * getName() {
		return name;
	}
	void print() {
		try {
			if (name_length == 0) {
				throw UnnamedPeople();
			}
		}
		catch (UnnamedPeople a) {
			a.printError();
			return;
		}
		for (int i = 0; i < name_length; i++) {
			cout << name[i];
		}
	}
	friend ostream & operator << (ostream & output, const Person & pers) {
		for (int i = 0; i < pers.name_length; i++) {
			output << pers.name[i];
		}
		return output;
	}
	Person & operator = (Person & pers) {
		name_length = pers.name_length;
		delete[]name;
		name = new char[name_length];
		for (int i = 0; i < name_length; i++) {
			name[i] = pers.name[i];
		}
		return *this;
	}
	friend bool operator < (Person & left, Person & right) {
		if (strcmp(left.name, right.name) == -1) {
			return true;
		}
		else {
			return false;
		}
	}
};