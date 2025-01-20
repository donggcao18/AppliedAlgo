#include <bits/stdc++.h>
using namespace std;

#define MAX 100
int n, M;
int coeff[MAX];
int t[MAX];
int f = 0;
int countt = 0;

void solution (){
    if (f == M) countt++;
}

void try_func(int index){
    if (M-f-(t[n]-t[index]) < 0) return; 
    for (int i = 1; i <= (M-f-(t[n]-t[index])) / coeff[index]; i++) { 
        f += i * coeff[index];
        if (index==n){
            solution();
        }
        else try_func(index + 1);

        f -= i * coeff[index]; // Backtrack
    }
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) {
        cin >> coeff[i];
        if (i == 1) {
            t[1] = coeff[1];
        }
        else {
            t[i] = coeff[i] + t[i - 1];
        }
    }

    try_func(1); 
    cout << countt; 
    return 0;
}