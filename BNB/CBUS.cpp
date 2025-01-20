#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> d;
vector<bool> visited;
vector<int> route;
int load=0, c_min=INT_MAX;
int n, max_cap;
int f=0, f_optimal=INT_MAX; //f is for tracking current  value, f* is the value of optimal solution 

bool check (int i){
    if (visited[i] == true) return false;
    if (i<=n){
        if (load+1> max_cap) return false; 
    }
    if (i>n){
        if (visited[i-n] == false) return false;
    }

    return true;
}

void CBUS(int k){
    for (int i=1; i<=2*n; i++){
        if (check(i)){
            visited[i] = true;
            route[k] = i;
            f += d[route[k-1]][route[k]];

            if (i<= n) load++;
            else load --;

            if (k==2*n) {
                if (f + d[route[2*n]][0] < f_optimal) f_optimal= f + d[route[2*n]][0];
            }
            else if (f+c_min*(2*n-k+1) < f_optimal) CBUS(k+1);

            visited[i] = false;
            f -= d[route[k-1]][route[k]];
            if (i<= n) load--;
            else load++;
        }
    } 
}

int main (){
    cin >> n >> max_cap;
    d.resize(2*n+1, vector<int> (2*n+1, 0));
    visited.resize (2*n+1, false);
    route.resize(2*n+1, 0);

    for (int i=0; i<=2*n; i++){
        for (int j=0; j<=2*n; j++){
            cin >> d[i][j];
            if (d[i][j] < c_min && i != j) c_min = d[i][j];
        }
    }

    CBUS(1);

    cout << f_optimal;

    return 0;
}
