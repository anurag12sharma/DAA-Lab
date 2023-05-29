#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
};

// Function to calculate the maximum value using Greedy Fractional Knapsack algorithm
double fractionalKnapsack(int knapsackCapacity, vector<Item>& items) {
    // Calculate the value-to-weight ratio for each item
    for (Item& item : items) {
        item.value = item.value / (double)item.weight;
    }

    // Sort the items in descending order of their value-to-weight ratio
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.value > b.value;
    });

    double totalValue = 0.0;
    int currentWeight = 0;

    // Fill the knapsack with items in a greedy manner
    for (const Item& item : items) {
        if (currentWeight + item.weight <= knapsackCapacity) {
            totalValue += item.value * item.weight;
            currentWeight += item.weight;
        } else {
            int remainingCapacity = knapsackCapacity - currentWeight;
            totalValue += item.value * remainingCapacity;
            break;
        }
    }

    return totalValue;
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    vector<Item> items(numItems);
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < numItems; i++) {
        cin >> items[i].weight;
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < numItems; i++) {
        cin >> items[i].value;
    }

    int knapsackCapacity;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> knapsackCapacity;

    double maxValue = fractionalKnapsack(knapsackCapacity, items);

    cout << "Maximum value that can be achieved: " << maxValue << "\n";

    cout << "List of selected items and their fraction amounts:\n";
    for (const Item& item : items) {
        double fraction = (double)item.weight / knapsackCapacity;
        cout << "Item with weight " << item.weight << " and value " << item.value << ": " << fraction << "\n";
    }

    return 0;
}
