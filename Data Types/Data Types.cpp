/*
Дан целочисленный двусвязный список, тип лист от инт. Найти максимальный из его локальных минимумов. (Элемент, который меньше
своих соседей).
*/


#include <iostream>
#include <list>
#include <random>
#include <algorithm>
#include <iterator>
using namespace std;

int min2(int a, int b) {
	return a > b ? b : a;
}

int min3(int a, int b, int c) {
	return min2(a, min2(b, c));
}

int getMin(list<int> a) {
	int temp = 0;
	int local;
	for (auto it = a.begin(); it != a.end(); it++) {
		auto itP = it == a.begin() ? it : prev(it, 1);
		auto itN = next(it, 1) == a.end() ? it : next(it, 1);
		local = min3(*itP, *it, *itN);
		if (temp < local) {
			temp = local;
		}
	}
	return temp;
}



int main()
{
	list<int> a;
	
	for (int i = 0; i < 10; i++) {
		a.push_back(rand() % 100);
		cout << a.back() << " ";
	}
	cout << endl;

	cout << getMin(a) << endl;
}
