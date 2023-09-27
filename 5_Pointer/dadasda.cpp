#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void print(vector<int> v, string s);
void selection_sort(vector<int> v);
void selection_sort_reverse(vector<int> v);

int main2() {
    vector<int> v = { 1, 7, 4, 3, 2, 9, 4 };
    selection_sort(v);
    selection_sort_reverse(v);

    return 0;
}


void print(vector<int> v, string s) {
    cout << s << " : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void selection_sort(vector<int> v) {
    int size = v.size();
    for (int i = 0; i < size - 1; i++) {
        int index = i;
        for (int j = i + 1; j < size; j++) {
            if (v[j] < v[index]) {
                index = j;
            }
        }
        int temp = v[i];
        v[i] = v[index];
        v[index] = temp;
    }
    print(v, "Selection Sort");
}

void selection_sort_reverse(vector<int> v) {
    int size = v.size();
    for (int i = 0; i < size - 1; i++) {
        int index = i;
        for (int j = i + 1; j < size; j++) {
            if (v[j] > v[index]) {
                index = j;
            }
        }
        int temp = v[i];
        v[i] = v[index];
        v[index] = temp;
    }
    print(v, "Selection Sort Reverse");
}