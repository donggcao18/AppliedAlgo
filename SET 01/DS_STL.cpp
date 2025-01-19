#include <bits/stdc++.h>
using namespace std;

void stackDemo() {
    cout << "Stack Demo:" << endl;
    stack<int> s;
    s.push(10); // Push elements onto the stack
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl; // Access the top element
    s.pop(); // Remove the top element
    cout << "Top element after pop: " << s.top() << endl;
    cout << "Size of stack: " << s.size() << endl;
    cout << endl;
}

void queueDemo() {
    cout << "Queue Demo:" << endl;
    queue<int> q;
    q.push(10); // Enqueue elements
    q.push(20);
    q.push(30);
    cout << "Front element: " << q.front() << endl; // Access the front element
    cout << "Back element: " << q.back() << endl;  // Access the back element
    q.pop(); // Dequeue element
    cout << "Front element after pop: " << q.front() << endl;
    cout << "Size of queue: " << q.size() << endl;
    cout << endl;
}

void dequeDemo() {
    cout << "Deque Demo:" << endl;
    deque<int> dq;
    dq.push_back(10); // Add to the back
    dq.push_front(20); // Add to the front
    dq.push_back(30);
    cout << "Front element: " << dq.front() << endl;
    cout << "Back element: " << dq.back() << endl;
    dq.pop_front(); // Remove from the front
    dq.pop_back();  // Remove from the back
    cout << "Front element after pops: " << dq.front() << endl;
    cout << "Size of deque: " << dq.size() << endl;
    cout << endl;
}

void vectorDemo() {
    cout << "Vector Demo:" << endl;
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6); // Add element to the end
    cout << "Vector elements: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    v.pop_back(); // Remove the last element
    cout << "After pop_back: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Size of vector: " << v.size() << endl;
    cout << endl;
}

void setDemo() {
    cout << "Set Demo:" << endl;
    set<int> s;
    s.insert(10); // Insert elements
    s.insert(20);
    s.insert(10); // Duplicate elements are ignored
    cout << "Set elements: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
    s.erase(10); // Remove element
    cout << "After erase: ";
    for (int x : s) {
        cout << x << " ";
    }
    cout << endl;
    cout << "Size of set: " << s.size() << endl;
    cout << endl;
}

void mapDemo() {
    cout << "Map Demo:" << endl;
    map<string, int> m;
    m["Alice"] = 10; // Insert key-value pairs
    m["Bob"] = 20;
    m["Charlie"] = 30;
    cout << "Map elements:" << endl;
    for (auto &p : m) {
        cout << p.first << ": " << p.second << endl;
    }
    m.erase("Alice"); // Remove a key
    cout << "After erase:" << endl;
    for (auto &p : m) {
        cout << p.first << ": " << p.second << endl;
    }
    cout << "Size of map: " << m.size() << endl;
    cout << endl;
}

void pairDemo() {
    cout << "Pair Demo:" << endl;
    pair<int, string> p = {1, "Alice"};
    cout << "Pair: (" << p.first << ", " << p.second << ")" << endl;
    p = make_pair(2, "Bob");
    cout << "Updated Pair: (" << p.first << ", " << p.second << ")" << endl;
    cout << endl;
}

int main() {
    stackDemo();
    queueDemo();
    dequeDemo();
    vectorDemo();
    setDemo();
    mapDemo();
    pairDemo();
    return 0;
}
