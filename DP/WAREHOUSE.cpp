#include <bits/stdc++.h>
using namespace std;

int n, d, counter;
vector<int> a, t;
vector<vector<int>> dp;

void input() {
    cin >> n >> counter >> d;
    a.resize(n);
    t.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> t[i];

    dp.resize(n, vector<int>(counter + 1, -1));
}

int dfs(int index, int counter) {
    if (counter < t[index]) return 0; 
    if (index == 0) return (counter >= t[0]) ? a[0] : 0; // Base case for station 0
    if (dp[index][counter] != -1) return dp[index][counter];

    int res = INT_MIN;
    for (int i = 1; i <= d && index - i >= 0; i++) {
        if (counter - t[index] >= 0) {
            res = max(res, dfs(index - i, counter - t[index]));
        }
    }

    dp[index][counter] = (res == INT_MIN) ? res : res + a[index]; 
    return dp[index][counter];
}

int main() {
    input();
    int res = INT_MIN;
    
    for (int i = 1; i < n; i++) { 
        res = max(res, dfs(i, counter));
    }
    

    cout << (res == INT_MIN ? -1 : res) << endl; // Handle no valid path
    return 0;
}
