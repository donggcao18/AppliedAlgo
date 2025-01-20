#include <bits/stdc++.h>
using namespace std;


int maxHistogramArea(const vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int areaWithTop;

    int i = 0;
    while (i < heights.size()) {
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        } else {
            int top = s.top();
            s.pop();
            areaWithTop = heights[top] * (s.empty() ? i : i - s.top() - 1);
            maxArea = max(maxArea, areaWithTop);
        }
    }

    while (!s.empty()) {
        int top = s.top();
        s.pop();
        areaWithTop = heights[top] * (s.empty() ? i : i - s.top() - 1);
        maxArea = max(maxArea, areaWithTop);
    }

    return maxArea;
}


int maxRectangleArea(const vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    int maxArea = 0;
    vector<int> heights(matrix[0].size(), 0);

    for (const auto& row : matrix) {
        for (int j = 0; j < row.size(); ++j) {
            heights[j] = (row[j] == 1) ? heights[j] + 1 : 0;
        }
        maxArea = max(maxArea, maxHistogramArea(heights));
    }

    return maxArea;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    
    // Read the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Calculate and print the area of the largest rectangle
    cout << maxRectangleArea(matrix) << endl;

    return 0;
}
