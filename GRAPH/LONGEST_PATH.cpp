#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN]; 
bool visited[MAXN];
int maxDistance = 0; 
int farthestNode = 0; 

void dfs(int u, int distance) {
    visited[u] = true;


    if (distance > maxDistance) {
        maxDistance = distance;
        farthestNode = u;
    }

    for (auto edge : adj[u]) {
        int v = edge.first;
        int weight = edge.second;
        if (!visited[v]) {
            dfs(v, distance + weight);
        }
    }
}

int main() {
    int N;
    cin >> N;

    // Read the tree edges
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    memset(visited, false, sizeof(visited));
    maxDistance = 0;
    dfs(1, 0); 

    memset(visited, false, sizeof(visited));
    maxDistance = 0;
    dfs(farthestNode, 0); 

    cout << maxDistance << endl;

    return 0;
}
