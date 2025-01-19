#include<bits/stdc++.h>
using namespace std;
int n, sum;
vector<int> a;
vector<vector<int>> dp;

void input(){
    cin >> n >> sum;
    a.resize(n, 0);
    dp.resize(n, vector<int>(sum+1, -1));
    for(int i=0; i<n; i++) cin >> a[i];
}

int subset(int index, int re){
    if (index < 0 || re < 0) return 0;
    if (dp[index][re] != -1) return dp[index][re];
    
    if (re == 0) return 1;
    
    int include = subset(index-1, re-a[index]);
    int exclude = subset(index-1, re);
    
    return dp[index][re] = include + exclude;
}
int main(){
    input();
    cout << subset(n-1, sum);
    return 0;
}