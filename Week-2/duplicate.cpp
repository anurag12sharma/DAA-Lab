#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int countOccurrences(int arr[], int n, int key) {
    int idx = binarySearch(arr, 0, n - 1, key);
    if (idx == -1)
        return 0;
    int count = 1;
    int left = binarySearch(arr, 0, idx - 1, key);
    while (left != -1) {
        count++;
        left = binarySearch(arr, 0, left - 1, key);
    }
    int right = binarySearch(arr, idx + 1, n - 1, key);
    while (right != -1) {
        count++;
        right = binarySearch(arr, right + 1, n - 1, key);
    }
    return count;
}

int main() {
    int n, key;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the key element to search: ";
    cin >> key;
    int count = countOccurrences(arr, n, key);
    if (count == 0)
        cout <<key<< " not found" << endl;
    else
        cout <<key<< " found " << count << " times" << endl;
    return 0;
}
