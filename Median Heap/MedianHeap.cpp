#include <iostream>
#include <queue>


int main()
{
    using std::cout;
    using std::endl;
    int x = 0;
    std::vector<float> nums = { 2, 6, 4, 5, 4, 0, 6, 7, 7, 7, 6, 9, 3, 0, 4 };
    std::priority_queue<float, std::vector<float>, std::greater<float>> minheap;
    std::priority_queue<float> maxheap;

    for (auto itr = nums.begin(); itr != nums.end(); itr++) {
        if (itr == nums.begin()) {
            maxheap.push(*itr);
        }
        else {
            if (maxheap.size() > minheap.size() + 1) {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            if (minheap.size() > maxheap.size() + 1) {
                maxheap.push(minheap.top());
                minheap.pop();
            }
            if (*itr <= maxheap.top()) {
                maxheap.push(*itr);
            }
            else {
                minheap.push(*itr);
            }
        }
        cout << "INT: " << *itr << endl;
    }

    if (maxheap.size() > minheap.size() + 1) {
        minheap.push(maxheap.top());
        maxheap.pop();
    }
    if (minheap.size() > maxheap.size() + 1) {
        maxheap.push(minheap.top());
        minheap.pop();
    }

    cout << "\nMedian: ";
    if (maxheap.size() == minheap.size()) {
        cout << (double)((maxheap.top() + minheap.top()) / 2);
    }
    else if (maxheap.size() > minheap.size()) {
        cout << maxheap.top();
    }
    else {
        cout << minheap.top();
    }
    cout << "\nMax Heap: \n";

    while (!maxheap.empty()) {
        cout << maxheap.top() << " ";
        maxheap.pop();
    }

    cout << "\nMin Heap: \n";

    while (!minheap.empty()) {
        cout << minheap.top() << " ";
        minheap.pop();
    }

    return 0;
}
