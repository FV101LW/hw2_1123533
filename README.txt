# hw2_1123533
Homework 2 of Data Structures.

Question 1: Binary Tree - Find the Diameter of a Binary Tree
Write a program to calculate the diameter of a binary tree. The diameter of a binary tree is the length of the longest path between any two nodes in the tree. The path may or may not pass through the root.

Question 2: Heap Sort - Build a Priority Queue for Tasks
Write a program to manage a task priority queue using a max heap. Each task has a name and a priority level. Your program should allow:
1.	Add a Task: Add a task with a given priority.
2.	Get the Highest Priority Task: Remove and return the task with the highest priority.
3.	Display the Remaining Tasks: Print the remaining tasks in descending order of priority.

Input used:
ADD Task1 8
ADD Task2 5
ADD Task3 4
GET
ADD Task4 9
ADD Task5 25
ADD Task6 88
GET

Output:
Task1
Task6
Remaining Tasks: [('Task5', 25), ('Task4', 9), ('Task2', 5), ('Task3', 4)]


Question 3: Merge K Sorted Arrays Using Min Priority Queue
You are given K sorted arrays of integers. Write a Python program to merge these arrays into a single sorted array using a Min Priority Queue.
Your program should:
1.	Insert the first element of each array into a Min Priority Queue along with the array index and element index.
2.	Extract the smallest element from the queue, add it to the result array, and insert the next element from the same array into the queue.
3.	Continue this process until all elements from all arrays are merged.

Input used:
4
1 5 9
2 6
3 7 10
4 8

Output:
Merged Array: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

Question 4: Schedule Tasks with Deadlines Using Max Priority Queue
You are given N tasks, each with a profit and a deadline. Write a Python program to schedule the tasks such that the maximum profit is achieved, using a Max Priority Queue.
Each task must be completed within its deadline (1-based index), and only one task can be scheduled at a time.

Input Format
1.	An integer N, the number of tasks.
2.	N lines containing two integers each: profit and deadline of a task.
Output Format
1.	The maximum profit that can be achieved.
2.	The list of scheduled tasks in the order they are executed.

Input used:
5
88 1
25 2
45 1
32 2
22 1

Output:
Maximum Profit: 120
Scheduled Tasks: [88, 32]


Github Link:
https://github.com/FV101LW/hw2_1123533.git
