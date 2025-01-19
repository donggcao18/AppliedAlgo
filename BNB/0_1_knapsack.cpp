#include <bits/stdc++.h>
using namespace std;

// Structure for items
struct Item {
    int weight, value;
    double valuePerWeight; // Used for sorting
};

// Structure for a node in the Branch and Bound tree
struct Node {
    int level;      // Index of the item
    int value;      // Total value of items in the knapsack
    int weight;     // Total weight of items in the knapsack
    double bound;   // Upper bound of the total value
};

// Comparator for sorting items by value/weight ratio
bool compare(Item a, Item b) {
    return a.valuePerWeight > b.valuePerWeight;
}

// Function to calculate the upper bound for a node
double calculateBound(Node u, int n, int W, vector<Item>& items) {
    if (u.weight >= W) return 0; // If weight exceeds capacity, bound is 0

    double bound = u.value;
    int totalWeight = u.weight;
    int i = u.level + 1;

    // Add items fractionally to the bound
    while (i < n && totalWeight + items[i].weight <= W) {
        totalWeight += items[i].weight;
        bound += items[i].value;
        i++;
    }

    // Add a fraction of the next item if capacity allows
    if (i < n) {
        bound += (W - totalWeight) * items[i].valuePerWeight;
    }

    return bound;
}

// Branch and Bound Knapsack function
int knapsack(int W, vector<Item>& items, int n) {
    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    // Priority queue for Best-First Search
    priority_queue<Node> pq;

    // Lambda function for custom comparator in priority queue
    auto cmp = [](Node a, Node b) { return a.bound < b.bound; };
    priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

    // Start with the root node
    Node u, v;
    u.level = -1;
    u.value = u.weight = 0;
    u.bound = calculateBound(u, n, W, items);
    pq.push(u);

    int maxValue = 0;

    // Process nodes in the priority queue
    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        // If this node cannot improve the solution, skip it
        if (u.bound <= maxValue) continue;
        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].weight;
        v.value = u.value + items[v.level].value;

        if (v.weight <= W && v.value > maxValue) {
            maxValue = v.value;
        }

        // Calculate bound for this node
        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxValue) {
            pq.push(v);
        }

        v.weight = u.weight;
        v.value = u.value;
        v.bound = calculateBound(v, n, W, items);
        if (v.bound > maxValue) {
            pq.push(v);
        }
    }

    return maxValue;
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) cin >> items[i].value;
    for (int i = 0; i < n; i++) cin >> items[i].weight;

    // Calculate value per weight for each item
    for (int i = 0; i < n; i++) {
        items[i].valuePerWeight = (double)items[i].value / items[i].weight;
    }

    cout << knapsack(W, items, n) << endl;
    return 0;
}