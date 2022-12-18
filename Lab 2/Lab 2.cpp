/*
    Дана целочисленная матрица векторов, найти кол-во, строк, все элементы которых различны.
*/
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>
#include <unordered_set>
using namespace std;

int countOfStrings(vector<vector<int>> a) {
    int count = 0;
    for (auto it = a.begin(); it != a.end(); it++) {
        unordered_set<int> uniqSet((*it).begin(), (*it).end());
        bool isUniq = uniqSet.size() == (*it).size() ? true : false;
        if (isUniq) {
            count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> a;

    for (int i = 0; i < 5; i++) {
        vector<int> b;
        for (int j = 0; j < 5; j++) {
            b.push_back(rand() % 10);
        }
        a.push_back(b);
    }

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << countOfStrings(a) << endl;
}

