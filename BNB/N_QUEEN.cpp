#include<bits/stdc++.h>
using namespace std;
int n, k=0, c=0;
vector<int> a;
vector<int> row, col, diag1, diag2;

void input(){
    cin >> n;
    row.resize(n,0);
    col.resize(n,0);
    diag1.resize(2*n-1, 0);
    diag2.resize(2*n-1, 0);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int m;
            cin >> m;
            if (m==1){
                row[i] = 1;
                col[j] = 1;
                diag1[i+j] = 1;
                diag2[i-j+n] = 1;
                k+=1;
            }
        }
    }
}

void backtrack(int h){
    if (h==n){
        c+=1;
        return;
    }
    if (row[h]==1){
        backtrack(h+1);
        return;
    }
    for(int i=0; i<n; i++){
        if(col[i] == 0 && diag1[i+h] ==0 && diag2[h-i+n] ==0){
            row[h] = col[i] = diag1[i+h] = diag2[h-i+n] = 1;
            backtrack(h+1);
            row[h] = col[i] = diag1[i+h] = diag2[h-i+n] = 0;
            
        }
    }
}

int main(){
    input();
    backtrack(0);
    
    cout << c;
    return 0;
}