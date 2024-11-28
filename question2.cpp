// Wei-li Lin
// 1123533
// 11-28-2024
// Homework 2 - Question 2
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Task structure to hold task name and priority
struct Task {
    string name;
    int priority;

    // Constructor to initialize a Task
    Task(string n, int p) : name(n), priority(p) {}

    // To create a max heap based on priority
    bool operator<(const Task& other) const {
        return priority < other.priority;  // Reverse comparison to ensure max-heap behavior
    }
};

int main() {
    int N;
    cin >> N;  // Number of operations


    priority_queue<Task> taskQueue;  // Max-heap priority queue to manage tasks

    // The operations
    for (int i = 0; i < N; i++) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            string task_name;
            int priority;
            cin >> task_name >> priority;

            // Add task to the priority queue
            taskQueue.push(Task(task_name, priority));
        }
        else if (operation == "GET") {
            if (!taskQueue.empty()) {
                // Fetch n' remove the task with the highest priority
                Task highestPriority = taskQueue.top();
                cout << highestPriority.name << endl; //NOTE: For some reason, it keeps displaying the Task first whenever GET is inputted, rather than altogether after finishing the input.
                taskQueue.pop();  // Remove the task after it's fetched
            }
        }
    }

    // Print remaining tasks in descending order of priority
    vector<Task> remainings;

    // Extract remaining tasks from the priority queue into the vector
    while (!taskQueue.empty()) {
        remainings.push_back(taskQueue.top());
        taskQueue.pop();
    }

    // Print remaining tasks
    cout << "Remaining Tasks: [";
    for (int i = 0; i < remainings.size(); i++) {
        cout << "('" << remainings[i].name << "'" << ", " << remainings[i].priority << ")";
        if (i < remainings.size() - 1) {
            cout << ", ";  // Print a comma for all but the last task
        }
    }
    cout << "]" << endl;

    return 0;
}
