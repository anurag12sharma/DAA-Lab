#include <iostream>
#include <queue>

using namespace std;

// Function to calculate the minimum computation cost to merge files
int mergeFiles(int n, int arr[]) {
    // Create a min-heap priority queue to store the file sizes
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert the file sizes into the priority queue
    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    int totalCost = 0;

    // Merge the files until only one file remains
    while (pq.size() > 1) {
        // Extract the two smallest files from the priority queue
        int file1 = pq.top();
        pq.pop();
        int file2 = pq.top();
        pq.pop();

        // Compute the cost of merging the two files
        int cost = file1 + file2;

        // Add the cost to the total cost
        totalCost += cost;

        // Insert the merged file size back into the priority queue
        pq.push(cost);
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    int arr[n];
    cout << "Enter the sizes of the files: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minCost = mergeFiles(n, arr);

    cout << "Minimum computation cost to merge all files: " << minCost << endl;

    return 0;
}
