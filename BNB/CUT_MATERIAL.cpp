#include <bits/stdc++.h>
using namespace std;

int H, W, n;
vector<pair<int, int>> pieces;

bool canCut(int h, int w, vector<pair<int, int>>& remainingPieces) {
    if (remainingPieces.empty()) return true; 

    for (int i = 0; i < remainingPieces.size(); i++) {
        int hi = remainingPieces[i].first;
        int wi = remainingPieces[i].second;

        if ((hi <= h && wi <= w) || (hi <= w && wi <= h)) {
            vector<pair<int, int>> nextPieces = remainingPieces;
            nextPieces.erase(nextPieces.begin() + i);

            if (canCut(h - hi, w, nextPieces) || canCut(h, w - wi, nextPieces)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> H >> W;
    cin >> n;
    pieces.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> pieces[i].first >> pieces[i].second;
    }
    int totalArea = 0;
    for (const auto& piece : pieces) {
        totalArea += piece.first * piece.second;
    }

    if (totalArea > H * W) {
        cout << 0;
        return 0;
    }

    if (canCut(H, W, pieces)) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}
