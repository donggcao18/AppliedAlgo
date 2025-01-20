#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
using namespace std;

const int MAXN = 100005;
const long long INF = 1e18;

vector<pair<int, int>> adj[MAXN];
long long dist[MAXN]; 

void dijkstra(int s, int n) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    fill(dist, dist + n + 1, INF);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        // Relaxation step
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int s, t;
    cin >> s >> t;

    dijkstra(s, n);

    if (dist[t] == INF)
        cout << -1 << endl; // No path found
    else
        cout << dist[t] << endl; // Shortest path distance

    return 0;
}
