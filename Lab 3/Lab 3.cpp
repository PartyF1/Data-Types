/*
    Дано мн-во строк сет от стринг. Удалить из множества элементы строки, которые являются полиндромами. 
*/
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>
using namespace std;

void deletePolys(set<string>& a) {
    auto element = a.begin();
    while (element != a.end()) {
        auto start = next((*element).begin(), 0);
        auto end = prev((*element).end(), 1);
        bool isPoly = true;
        int count = 0;
        while (count != (*element).size() / 2) {
            if (*start != *end) {
                isPoly = false;
                break;
            }
            start++;
            end--;
            count++;
        }
        if (isPoly) {
            element = a.erase(element);
        }
        else {
            element++;
        }
    }

    /*for (auto element : a) {
        auto start = next(element.begin(), 0);
        auto end = prev(element.end(),1);
        bool isPoly = true;
        int count = 0;
        while (count != element.size()/2) {
            if (*start != *end) {
                isPoly = false;
                break;
            }
            start++;
            end--;
            count++;
        }
        if (isPoly) {
            element = a.erase(element);
        }
    }*/
}

int main()
{
    setlocale(LC_ALL, "Russian");
    set<string> a;
    a.insert("bidadadad");
    a.insert("123454321");
    a.insert("niggerundayo");
    a.insert("Fight With ME!");
    a.insert("Hey you,uoy yeH");
    a.insert("234565432");
    a.insert("FFFFFF*******CCKKKK");

    cout << "После введения: " << endl << endl;
    for (auto element : a) {
        cout << element << endl;
    }
    cout << endl << "После удаление полиндромов: " << endl << endl;
    deletePolys(a);
    for (auto element : a) {
        cout << element << endl;
    }

}
