#include <iostream>
#include <queue>

using namespace std;

class RunningMedian {
private:


    priority_queue<int> maxHeap;

    priority_queue<int, vector<int>, greater<int>> minHeap;

public:

    void insert(int num) {

        // If maxHeap is empty or num belongs
        // to the smaller half
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        // Balance the heaps

        if (maxHeap.size() > minHeap.size() + 1) {

            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if (minHeap.size() > maxHeap.size() + 1) {

            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    float getMedian() {

        // No numbers
        if (maxHeap.empty() && minHeap.empty()) {
            return 0;
        }

        // Same number of elements
        if (maxHeap.size() == minHeap.size()) {

            return (maxHeap.top() + minHeap.top()) / 2.0f;
        }

        // maxHeap has one extra
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // minHeap has one extra
        return minHeap.top();
    }
};

int main() {

    RunningMedian median;

    median.insert(5);
    cout << median.getMedian() << endl;

    median.insert(2);
    cout << median.getMedian() << endl;

    median.insert(10);
    cout << median.getMedian() << endl;

    median.insert(4);
    cout << median.getMedian() << endl;

    return 0;
}