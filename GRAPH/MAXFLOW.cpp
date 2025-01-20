#include <bits/stdc++.h>
using namespace std;

bool bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = s;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < rGraph.size(); v++) {
            if (rGraph[u][v] > 0 && parent[v] == -1) {
                parent[v] = u;
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int u, v, maxFlow = 0;
    vector<vector<int>> rGraph = graph;
    vector<int> parent(graph.size());

    while (bfs(rGraph, s, t, parent)) {
        int pathFlow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= pathFlow;
            rGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}
