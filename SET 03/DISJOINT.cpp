#include <bits/stdc++.h>
using namespace std;

#define MAX 100000
int n;
pair<int, int>disjoint_set[MAX];

bool cmp(pair<int, int>a, pair<int, int>b){
    if (a.second < b.second) return true;
    return false;
}

void input (){
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> disjoint_set[i].first >> disjoint_set[i].second;
    }
}

int check (){
    sort (disjoint_set, disjoint_set+n, cmp);
    int count=0;
    int last = -1;
    for (int i=0; i<n; i++){
        if (disjoint_set[i].first > last){
            count++;
            last = disjoint_set[i].second;
        }
    }

    return count;
}

int main (){
    input ();
    cout << check();

    return 0;
}
