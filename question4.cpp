// Wei-li O. Lin
// 1123533
// 11-28-2024
// Homework 2 - Question 4
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Task {
    int profit;
    int deadline;

    Task(int p, int d) : profit(p), deadline(d) {}

    // Compare to sort tasks by profit in descending order
    bool operator>(const Task& other) const {
        return profit > other.profit;
    }
};

// To find the maximum profit and schedule tasks
pair<int, vector<Task>> scheduleTasks(const vector<Task>& tasks, int maxDeadline) {
    // Sort tasks in descending order based on profit
    vector<Task> sortedTasks = tasks;
    sort(sortedTasks.begin(), sortedTasks.end(), greater<Task>());

    // To keep track of which slots are filled (We need only maxDeadline slots)
    vector<bool> slots(maxDeadline + 1, false);
    vector<Task> scheduledTasks;
    int totalProfit = 0;

    // Process each task
    for (const Task& task : sortedTasks) {
        // Try to find a free slot for this task within its deadline
        for (int i = task.deadline; i > 0; --i) {
            if (!slots[i]) {
                // Available slot found, schedule task
                slots[i] = true;
                scheduledTasks.push_back(task);
                totalProfit += task.profit;
                break;
            }
        }
    }

    return make_pair(totalProfit, scheduledTasks);
}

int main() {
    int N;  // Number of tasks
    cin >> N;

    vector<Task> tasks;
    int maxDeadline = 0;

    // Read tasks input
    for (int i = 0; i < N; ++i) {
        int profit, deadline;
        cin >> profit >> deadline;
        tasks.push_back(Task(profit, deadline));
        maxDeadline = max(maxDeadline, deadline);  // Keep track of the maximum deadline
    }

    // Get maximum profit and scheduled tasks
    pair<int, vector<Task>> result = scheduleTasks(tasks, maxDeadline);
    int maxProfit = result.first;  // Total profit
    vector<Task> scheduledTasks = result.second;  // List of scheduled tasks

    cout << "Maximum Profit: " << maxProfit << endl;

    cout << "Scheduled Tasks: [ ";
    for (const Task& task : scheduledTasks) {
        cout << task.profit << " ";
    }
    cout << "]" << endl;

    return 0;
}
