#include <iostream>
#include <vector>       // for array vectors
#include <cstdlib>
#include <ctime>        // for timing aka clocks

using namespace std;

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c;
    size_t i = 0, j = 0;

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
    if (a.size() <= 1) {
        return a;
    }
    
    size_t mid = a.size() / 2;
    
    vector<int> arrayOne(a.begin(), a.begin() + mid);  // First half
    vector<int> arrayTwo(a.begin() + mid, a.end());    // Second half
    
    arrayOne = mergeSort(arrayOne);
    arrayTwo = mergeSort(arrayTwo);
    
    return merge(arrayOne, arrayTwo);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {    // Error if user have more than 1 argument.
        cerr << "Usage: " << argv[0] << "<array_size>" << endl;
        return 1;
    }

    size_t n = atoi(argv[1]);  // convert input into size_t
    if (n <= 0) {
        cerr << "Error: Array size must be positive" << endl;
        return 1;
    }

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    vector<int> forSorting(n);

    for (size_t i = 0; i < n; i++) {
        forSorting[i] = rand() % 1000;  // Random Number from 0 - 999
    }

    if (n <= 20) {
        cout << "Integers to Sort: " << endl;
        for (size_t i = 0; i < n; i++) {
            cout << forSorting[i] << " ";
        }
        cout << endl;
    }

    clock_t start = clock();    // Starts timing.

    vector<int> sorted = mergeSort(forSorting);

    clock_t end = clock();      // Stop timing.
    double duration = double(end - start) / CLOCKS_PER_SEC * 1e3;   // Convert to milliseconds.

    cerr << "Time taken by merge sort: " << duration << " milliseconds." << endl;

    if (n <= 20) {
        cout << endl << "Sorted Array: " << endl;
        for (size_t i = 0; i < n; i++) {
            cout << sorted[i] << " ";
        }
        cout << endl;
    }

    return 0;
}