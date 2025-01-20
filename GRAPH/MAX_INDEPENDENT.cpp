#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

vector<int> adj[MAXN + 1];
int weight[MAXN + 1];
long long dp[MAXN + 1][2];
bool visited[MAXN + 1];

void dfs(int u) {
    visited[u] = true;
    dp[u][1] = weight[u];

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);

            dp[u][0] += max(dp[v][0], dp[v][1]); // u not included
            dp[u][1] += dp[v][0];               // u included
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> weight[i];
    }

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);

    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}
