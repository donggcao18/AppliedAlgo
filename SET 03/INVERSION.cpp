#include <bits/stdc++.h>
/*Given a sequence of integers a 1 , a 2 , ..., a n . A pair (i, j) is call an inversion if i < j and a i > a j . 
Compute the number Q of inversions 
Input Line 1: contains a positive integer n (1 <= n <= 10 6 ) 
Line 2: contains a 1 , a 2 , ..., a n (0 <= a i <= 10 6 ) 
Output Write the value Q modulo 10 9 +7*/
using namespace std;
int n;
int a[100000];
int countt=0;

void input (){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
}

int merge(int l, int m, int r){

    
}
int inversion(int l, int r){
    if (l >= r) return 0;
    int m = (l+r) / 2;
    inversion(l, m);
    inversion(m+1, r);
    countt += check_var (l, m, r);
    return countt;
    
}
int main (){
    input();
    cout << inversion(0,n);
    return 0;
}