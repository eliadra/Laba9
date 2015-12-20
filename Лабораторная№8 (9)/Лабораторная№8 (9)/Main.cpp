#include "Array.h"
#include "Person.h"
#include <iostream>
#include <time.h>
using namespace std;

template <class T>
void sort(Array<T> & arr) {
	Array<T>temp(arr.getSize());
	for (int i = 0; i < arr.getSize(); i++) {
		int c = 0;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				c++;
			}
		}
		for (int j = i + 1; j < arr.getSize(); j++) {
			if (arr[j] < arr[i]) {
				c++;
			}
		}
		temp.setData(c, arr[i]);
	}
	arr = temp;
}

void main() {
	setlocale(LC_ALL, "rus");
	cout << "\n������ ������ �������������� �������:\n";
	cout << "Array <int> arr(-5);\n";
	Array <int> arr(-5);

	system("pause");
	cout << "\n���������� ����� � ������ ��� ������������� ��������\n";
	cout << "arr.setData(-6, 7);\n";
	arr.setData(-6, 7);

	system("pause");
	cout << "\n���������� ����� � ������ ��������, �������, ��� ������ �������\n";
	cout << "arr.setData(6, 13);\n";
	arr.setData(6, 13);

	system("pause");
	cout << "\n���������� �������� �� ������� �������\n";
	cout << "arr.getData(6);\n";
	arr.getData(6);

	system("pause");
	cout << "\n������ ��������, �� �� ��������� ��� �����\n";
	cout << "Person UnN(" << '"' << '"' << ");\n";
	Person UnN("");
	cout << "������� ��� ��������\n";
	cout << "UnN.print();\n";
	UnN.print();
}