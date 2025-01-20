#include<bits/stdc++.h>
using namespace std;
string s1, s2;
vector<vector<int>> dp;
int n1, n2;

void input(){
    cin >> s1 >> s2;
    n1 = s1.size();
    n2 = s2.size();
    dp.resize(n1, vector<int>(n2, -1));
}

int lcs(int l1, int l2){
    if (l1 < 0 || l2 < 0) return 0;
    if(dp[l1][l2] != -1) return dp[l1][l2];
    
    if (s1[l1] == s2[l2]) return dp[l1][l2] = 1+lcs(l1-1, l2-1);
    
    return dp[l1][l2] = max(lcs(l1-1, l2), lcs(l1, l2-1));
}
int main(){
    input();
    cout << lcs(n1-1, n2-1);
    
    return 0;
}