#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            j++;
        }
    }
    
    while (i < a.size()) {
        c.push_back(a[i]);
        i++;
    }
    
    while (j < b.size()) {
        c.push_back(b[j]);
        j++;
    }
    
    return c;
}

vector<int> mergeSort(vector<int> a) {
    if (a.size() == 1) {
        return a;
    }
    
    int mid = a.size() / 2;
    
    vector<int> arrayOne(a.begin(), a.begin() + mid);  // First half
    vector<int> arrayTwo(a.begin() + mid, a.end());    // Second half
    
    arrayOne = mergeSort(arrayOne);
    arrayTwo = mergeSort(arrayTwo);
    
    return merge(arrayOne, arrayTwo);
}

int main() {
    vector<int> forSorting = {};

    for (int i = 0; i < 9; i++) {
        int randomNum = rand() % 100;
        forSorting.push_back(randomNum);
    }

    cout << "Integers to Sort: " << endl;
    for (int num : forSorting) {
        cout << num << ", ";
    }

    vector<int> sorted = mergeSort(forSorting);

    
    cout << endl << "Sorted Array: " << endl;
    for (int num : sorted) {
        cout << num << ", ";
    }

    return 0;
}