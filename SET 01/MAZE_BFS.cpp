#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<vector<int>> matrix;
vector<vector<int>> d;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

typedef pair<int, int> p;
queue<p> qu;

bool check(int n, int m) {
    if (n < 0 || m < 0 || n >= r || m >= c) return false;
    return true;
}

int shortest_path(int n, int m) {
    
    qu.push(p(n, m));
    d[n][m] = 1;  

    while (!qu.empty()) {
        p temp = qu.front();
        qu.pop();
        int x = temp.first;
        int y = temp.second;

        for (int i = 0; i < 4; i++) {
            int curx = x + dx[i];
            int cury = y + dy[i];
            if (!check(curx, cury)) continue;

            if (matrix[curx][cury] != 1 && d[curx][cury] == -1) {
                qu.push(p(curx, cury));
                d[curx][cury] = d[x][y] + 1;  
                if (curx == 0 || curx == r - 1 || cury == 0 || cury == c - 1) {
                    return d[curx][cury];  
                }
            }
        }
    }

    return -1;  // No valid path found
}


int main() {
    int n, m;
    cin >> r >> c >> n >> m;

    matrix.resize(r, vector<int>(c, 0)); 
    d.resize(r, vector<int>(c, -1));     

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> matrix[i][j];
        }
    }
    n--;
    m--;

    cout << shortest_path(n, m) << endl;

    return 0;
}
