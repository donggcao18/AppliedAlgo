// 0 1 0 0 0
// 1 1 1 0 0
// 1 1 1 1 1
// 1 1 1 0 1
// 1 1 1 1 1
#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<int>> matrix;
vector<int> h;

int compute (vector<int>& histo){
    stack <int> flag;
    flag.push (histo[0]);
    int max_area= 0;
    int area = 0;
    int i = 1;

    while (i < histo.size()){
        if (flag.empty()|| histo[flag.top()] <= histo[i]){
            flag.push(i);
            i++;
        }
        else{
            int height = histo[flag.top()];
            flag.pop();
            int width = flag.empty() ? i : i-flag.top()-1;
            max_area = max(height*width, max_area);       
        }
    }
    while (!flag.empty()){
        int height = histo[flag.top()];
        flag.pop();
        int width = flag.empty() ? i: i-flag.top()-1;
        max_area = max(max_area, height*width);
    }

    return max_area;


}
int main (){
    int max_area = 0;
    cin >> r >> c;
    matrix.resize(r, vector<int> (c, 0));
    h.resize(r, 0);
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cin >> matrix[i][j];
        }
    }

    for ( int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (i==0){
                if (matrix[i][j] == 0) h[j] = 0;
                else h[j] = 1;  
            }
            else{
                if (matrix[i][j] == 0) h[j] = 0;
                else {
                    h[j] = h[j] + 1;
                }
            }
        }
        int temp = compute(h);
        max_area = max(max_area, temp);
    }

    cout << max_area << endl;
    return 0;
}
