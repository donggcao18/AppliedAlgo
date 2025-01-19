#include <bits/stdc++.h>
using namespace std;

void sortDemo() {
    cout << "Sort Demo:" << endl;
    vector<int> arr = {5, 2, 8, 1, 3};
    sort(arr.begin(), arr.end()); // Sort in ascending order
    cout << "Ascending order: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    sort(arr.begin(), arr.end(), greater<int>()); // Sort in descending order
    cout << "Descending order: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    cout << endl;
}

void maxMinDemo() {
    cout << "Max/Min Element Demo:" << endl;
    vector<int> arr = {10, 20, 15, 5, 30};
    int maxElem = *max_element(arr.begin(), arr.end());
    int minElem = *min_element(arr.begin(), arr.end());
    cout << "Max element: " << maxElem << endl;
    cout << "Min element: " << minElem << endl;
    cout << endl;
}

void accumulateDemo() {
    cout << "Accumulate Demo:" << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    int sum = accumulate(arr.begin(), arr.end(), 0); // Sum of elements
    cout << "Sum of elements: " << sum << endl;
    cout << endl;
}

void binarySearchDemo() {
    cout << "Binary Search Demo:" << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    sort(arr.begin(), arr.end()); // Ensure the array is sorted
    int target = 3;
    bool found = binary_search(arr.begin(), arr.end(), target);
    cout << "Is " << target << " found? " << (found ? "Yes" : "No") << endl;
    cout << endl;
}

void lowerUpperBoundDemo() {
    cout << "Lower and Upper Bound Demo:" << endl;
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    auto lower = lower_bound(arr.begin(), arr.end(), target);
    auto upper = upper_bound(arr.begin(), arr.end(), target);

    cout << "Lower bound of " << target << ": Index " << (lower - arr.begin()) << endl;
    cout << "Upper bound of " << target << ": Index " << (upper - arr.begin()) << endl;
    cout << endl;
}

void uniqueDemo() {
    cout << "Unique Demo:" << endl;
    vector<int> arr = {1, 2, 2, 3, 3, 3, 4, 5};
    sort(arr.begin(), arr.end()); // Sort first
    auto it = unique(arr.begin(), arr.end()); // Remove duplicates
    arr.erase(it, arr.end()); // Resize the array
    cout << "Array after unique: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    cout << endl;
}

void reverseDemo() {
    cout << "Reverse Demo:" << endl;
    vector<int> arr = {1, 2, 3, 4, 5};
    reverse(arr.begin(), arr.end());
    cout << "Reversed array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    cout << endl;
}

void permutationDemo() {
    cout << "Next/Previous Permutation Demo:" << endl;
    vector<int> arr = {1, 2, 3};
    cout << "Next permutations:" << endl;
    do {
        for (int x : arr) cout << x << " ";
        cout << endl;
    } while (next_permutation(arr.begin(), arr.end()));

    cout << "Previous permutations:" << endl;
    do {
        for (int x : arr) cout << x << " ";
        cout << endl;
    } while (prev_permutation(arr.begin(), arr.end()));

    cout << endl;
}

int main() {
    sortDemo();
    maxMinDemo();
    accumulateDemo();
    binarySearchDemo();
    lowerUpperBoundDemo();
    uniqueDemo();
    reverseDemo();
    permutationDemo();
    return 0;
}
