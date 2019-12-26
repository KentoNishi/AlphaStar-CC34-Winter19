#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> grid;

void recursiveFill(int x, int y, int dx, int dy, int c) {
    grid[x][y] = c++;
    if (c == N * N + 1) {
        return;
    }
    if (dy == 0 && (x + dx == N || x + dx == -1 || grid[x + dx][y] > 0)) {
        if (dx == 1) {
            dy = 1;
        } else {
            dy = -1;
        }
        dx = 0;
    }
    if (dx == 0 && (y + dy == N || y + dy == -1 || grid[x][y + dy] > 0)) {
        if (dy == 1) {
            dx = -1;
        } else {
            dx = 1;
        }
        dy = 0;
    }
    recursiveFill(x + dx, y + dy, dx, dy, c);
}

int main() {
    cin >> N;
    grid = vector<vector<int>>(N, vector<int>(N));
    recursiveFill(0, 0, 1, 0, 1);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << grid[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}