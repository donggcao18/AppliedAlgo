#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> mapping(1000, vector<int>(1000, 0));
vector<vector<long long>> dp(1000, vector<long long>(1000, -1));
int x_max=INT_MIN, y_max=INT_MIN;
int n;

void input(){
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n;
    int x, y, gold;
    
    for (int i=0; i<n; i++){
        cin >> x >> y >> gold;
        mapping[x][y] = gold;
        x_max = max(x_max, x);
        y_max = max(y_max, y);
    }
    
}
long long dfs(int x, int y){
   if (x < 0 || y < 0) return 0;
   if (dp[x][y] != -1) return dp[x][y];
   dp[x][y] = max(max(dfs(x-1, y-1), dfs(x-1, y)), dfs(x, y-1)) + mapping[x][y];
   return dp[x][y];
}

int main(){
    input();
    long long res = dfs(x_max, y_max);
    cout << res;
    
    return 0;
}
