#include<bits/stdc++.h>
using namespace std;
int n, lb, ub;
vector<int> a;
vector<vector<int>> dp;

void input(){
    cin >> n >> lb >> ub;
    a.resize(n, 0);
    for(int i=0; i<n; i++) cin >> a[i];
}

int subset(int index, int sum){
    if (index < 0) return (sum>=0) ? 1: 0;
    if (sum <0) return 0;
    if (dp[index][sum] != -1) return dp[index][sum];
    
    
    return dp[index][sum] = subset(index-1, sum) +
                                subset(index-1, sum-a[index]);
}

int main(){
    input();
    dp.assign(n, vector<int>(ub+1, -1));
    int upper = subset(n-1, ub);
    
    dp.assign(n, vector<int>(lb, -1));
    int lower = subset(n-1, lb-1);
    
    cout << upper - lower;
    
    return 0;
}