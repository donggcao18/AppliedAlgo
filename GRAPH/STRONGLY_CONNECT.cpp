#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN], revAdj[MAXN];
bool visited[MAXN];
stack<int> nodeStack;

void dfs1(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    nodeStack.push(u);
}

void dfs2(int u) {
    visited[u] = true;
    for (int v : revAdj[u]) {
        if (!visited[v]) {
            dfs2(v);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);         // Original graph
        revAdj[v].push_back(u);      // Reversed graph
    }

    fill(visited, visited + N + 1, false);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    fill(visited, visited + N + 1, false);
    int sccCount = 0;

    while (!nodeStack.empty()) {
        int u = nodeStack.top();
        nodeStack.pop();
        if (!visited[u]) {
            dfs2(u);
            sccCount++; 
        }
    }

    // Output the number of SCCs
    cout << sccCount << endl;

    return 0;
}
