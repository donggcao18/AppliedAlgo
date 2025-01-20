#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int Num[MAXN], Low[MAXN];
bool visited[MAXN];
bool isArticulation[MAXN];
int timer, articulationPoints, bridges;

void dfs(int u, int parent) {
    visited[u] = true;
    Num[u] = Low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (v == parent) continue; // Skip the edge back to parent

        if (visited[v]) {
            // Update Low[u] for a back edge
            Low[u] = min(Low[u], Num[v]);
        } else {
            // Visit the child node
            dfs(v, u);
            children++;

            // Update Low[u] based on child's Low[v]
            Low[u] = min(Low[u], Low[v]);

            // Check if u is an articulation point
            if (parent != -1 && Low[v] >= Num[u]) {
                isArticulation[u] = true;
            }

            // Check if edge (u, v) is a bridge
            if (Low[v] > Num[u]) {
                bridges++;
            }
        }
    }

    // Special case for root
    if (parent == -1 && children > 1) {
        isArticulation[u] = true;
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // Read the graph
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        adj[X].push_back(Y);
        adj[Y].push_back(X);
    }

    // Initialize variables
    timer = 0;
    articulationPoints = 0;
    bridges = 0;
    fill(visited, visited + N + 1, false);
    fill(isArticulation, isArticulation + N + 1, false);

    // Run DFS
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i, -1);
        }
    }

    // Count articulation points
    for (int i = 1; i <= N; i++) {
        if (isArticulation[i]) articulationPoints++;
    }

    // Output results
    cout << articulationPoints << " " << bridges << endl;

    return 0;
}
 