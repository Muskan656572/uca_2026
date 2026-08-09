#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class HeapSort {
private:

    void heapify(vector<int>& arr, int n, int i) {

        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {

            swap(arr[i], arr[largest]);

            heapify(arr, n, largest);
        }
    }

public:

    void sort(vector<int>& arr) {

        int n = arr.size();

        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Remove maximum repeatedly
        for (int i = n - 1; i > 0; i--) {

            swap(arr[0], arr[i]);

            heapify(arr, i, 0);
        }
    }
};


// Create random array
vector<int> randomArray(int n) {

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    return arr;
}


// Create ascending array
vector<int> ascendingArray(int n) {

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = i;
    }

    return arr;
}


// Create descending array
vector<int> descendingArray(int n) {

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }

    return arr;
}


// Measure Heap Sort time
double measureTime(vector<int> arr) {

    HeapSort sorter;

    clock_t start = clock();

    sorter.sort(arr);

    clock_t end = clock();

    double timeTaken =
        double(end - start) / CLOCKS_PER_SEC;

    return timeTaken;
}


int main() {

    srand(time(0));

    // Different input sizes
    vector<int> sizes = {
        1000,
        5000,
        10000,
        50000,
        100000
    };

    cout << "Size,Random,Ascending,Descending" << endl;

    for (int n : sizes) {

        vector<int> random =
            randomArray(n);

        vector<int> ascending =
            ascendingArray(n);

        vector<int> descending =
            descendingArray(n);

        double randomTime =
            measureTime(random);

        double ascendingTime =
            measureTime(ascending);

        double descendingTime =
            measureTime(descending);

        cout << n << ","
             << randomTime << ","
             << ascendingTime << ","
             << descendingTime << endl;
    }

    return 0;
}