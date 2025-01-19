#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int numberTeacher=0, numberCourse=0, numberConflict=0; 
int conflict[MAX][MAX] = {0};
int load[MAX] = {0};
int schedule[MAX];
int minLoad=INT_MAX;
vector<int> T[MAX];

void input (){
    cin >> numberTeacher >> numberCourse;
    for (int i=1; i<=numberTeacher; i++){
        int eachTeacher;
        cin >> eachTeacher;
        for (int j=1; j<=eachTeacher; j++){
            int course;
            cin >> course;
            T[course].push_back(i);
        }
        }

    cin >> numberConflict;
    for (int i=1; i<=numberConflict; i++){
        int a,b;
        cin >> a >> b;
        conflict[a][b]=1;
        conflict[b][a]=1;
    }
}

void solution(){
    int maxLoad=0;
    for (int i=1; i<=numberTeacher; i++){
        maxLoad=max(maxLoad, load[i]);
    }
    minLoad=min(minLoad, maxLoad);
}

int check(int k, int t){
    for (int i=1; i<=k; i++){
        if (schedule[i]==t && conflict[i][k]==1) return 0;
    }

    return 1;
}

void BCA (int k){
    for (int t=0; t<T[k].size(); t++){
        if (check(k, T[k][t])){
            schedule[k]=T[k][t];
            load[schedule[k]]++;
            if (k==numberCourse){
                solution();
            }
            if (load[schedule[k]] < minLoad) BCA(k+1);
            load[schedule[k]]--;
            schedule[k]=0;
        }
    }
}
int main (){
    input ();
    BCA(1);
    cout << minLoad;
    return 0;
}