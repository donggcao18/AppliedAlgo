#include<bits/stdc++.h>
using namespace std;
vector<int> value;
vector<int> weight;
vector<vector<int>> dp;
int w, n;

void input (){
    cin >> n >> w;
    value.resize(n+1, 0);
    weight.resize(n+1, 0);
    dp.resize(n+1, vector<int>(w+1, -1));
    
    for(int i=1; i<=n; i++) cin >> value[i];
    for(int i=1; i<=n; i++) cin >> weight[i];
}

void knapsack(){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if (i==0 || j==0) dp[i][j] = 0;
            else if (weight[i] <= j){
                dp[i][j] = max(value[i] + dp[i-1][j-weight[i]], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
}
int main(){
    input();
    knapsack();
    cout << dp[n][w];
    return 0;
}