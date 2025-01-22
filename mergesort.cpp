#include <iostream>
#include <vector>
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
    vector<int> forSorting = {8,4,2,1,5,0,9,7,3,6};
    
    vector<int> sorted = mergeSort(forSorting);
    
    cout << "sorted Array: ";
    for (int num : sorted) {
        cout << num << " ";
    }

    return 0;
}








