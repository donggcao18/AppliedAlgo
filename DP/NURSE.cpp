#include <bits/stdc++.h>
using namespace std;
int count = 0 ;
vector<vector<int>> F;
int k1, k2; // bound  for the working period
int N; // working consecuutive day

void input (){
    cin >> N;
    cin >> k1 >> k2;
    F.resize (N, vector<int> (N, 0));
    for (int i=0; i< N; i++){
        for (int j=0; j<N; j++){
            F[i][j] = 0;
        }
    }

}

int checking_consecutive_day(){
    for (int i =0; i<k1; i++){
        for (int j=0; j< k2; j++){
            F[j][0] += F[i-j][0];
        }
            F[i][1] += F[i-1][1];
    }
}
int main (){
    input();
    checking_consecutive_day ();

    return 0;
}