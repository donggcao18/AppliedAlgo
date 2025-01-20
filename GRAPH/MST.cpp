#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int findSet(int v, vector<int>& parent) {
    if (v == parent[v]) return v;
    return parent[v] = findSet(parent[v], parent); // Path compression
}

void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findSet(a, parent);
    b = findSet(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; i++) parent[i] = i;

    int mstWeight = 0;
    for (Edge e : edges) {
        if (findSet(e.u, parent) != findSet(e.v, parent)) {
            mstWeight += e.w;
            unionSets(e.u, e.v, parent, rank);
            cout << "Edge: " << e.u << " - " << e.v << " Weight: " << e.w << "\n";
        }
    }

    cout << "MST Weight: " << mstWeight << "\n";
}
