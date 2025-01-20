#include<bits/stdc++.h>
using namespace std;
int n, Q, c=0;
vector<int> a;
int hashh[100001] = {0};

void input (){
    cin >> n >> Q;
    a.resize(n, 0);
    for (int i=0; i<n; i++) cin >> a[i];
}

void hashing(){
    for (int i=1; i<n; i++){
        if (hashh[a[i]] !=0){
                c+=hashh[a[i]];
            }
        for (int j=0; j<i; j++){
            if(Q-a[i]-a[j] >=0) hashh[Q-a[i]-a[j]]+=1;
        }
    }
}
int main(){
    input();
    sort(a.begin(), a.end());
    hashing();
    
    cout << c;
    return 0;
}