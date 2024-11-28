// Wei-li O. Lin
// 1123533
// 11-28-2024
// Homework 2 - Question 3
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>  // To handle line-based input

using namespace std;

// To store each element along with its source array index and element index
struct Element {
    int value;
    int arrayIndex;  
    int elementIndex;  

    // To create a min-heap based on the value of the elements
    bool operator>(const Element& other) const {
        return value > other.value;  // Reverse order to get min-heap behavior
    }
};

// To merge K sorted arrays using a min-heap (priority queue)
vector<int> mergeSortedArrays(const vector<vector<int>>& arrays) {
    vector<int> result;
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;

    // Insert 1st element of each array into priority queue
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push(Element{ arrays[i][0], i, 0 });
        }
    }

    // Get the minimum element, and push next element from the same array into heap
    while (!minHeap.empty()) {
        Element current = minHeap.top();
        minHeap.pop();

        result.push_back(current.value);  // Add smallest element to result array

        // If there's another element in  same array, insert it into heap
        if (current.elementIndex + 1 < arrays[current.arrayIndex].size()) {
            int nextElement = arrays[current.arrayIndex][current.elementIndex + 1];
            minHeap.push(Element{ nextElement, current.arrayIndex, current.elementIndex + 1 });
        }
    }

    return result;
}

int main() {
    int K;  // Number of sorted arrays
    cin >> K;  // Read number of arrays

    vector<vector<int>> arrays(K);

    // Read K sorted arrays
    cin.ignore();  // To ignore the newline character after reading K

    for (int i = 0; i < K; ++i) {
        string line;
        getline(cin, line);  // Read the entire line for the current array

        stringstream ss(line);
        int num;
        while (ss >> num) {
            arrays[i].push_back(num);  // Push the number to the corresponding array
        }
    }

    // Merge the arrays
    vector<int> mergedArray = mergeSortedArrays(arrays);

    // Print the merged sorted array
    cout << "Merged Array: [";
    for (int i = 0; i < mergedArray.size(); ++i) {
        cout << mergedArray[i];
        if (i < mergedArray.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
