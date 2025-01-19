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

int knapsack(int index, int capacity){
    if (dp[index][capacity] != -1) return dp[index][capacity];
    if (index < 1) return 0;
    if (weight[index] > capacity) return dp[index-1][capacity] = knapsack(index-1, capacity);
    return dp[index][capacity] = max(value[index] + knapsack(index-1, capacity-weight[index]),
                                        knapsack(index-1, capacity));
}
int main(){
    input();
    int a = knapsack(n, w);
    cout << a;
    return 0;
}