/*
Lake Counting
=============

Due to recent rains, water has pooled in various places in Farmer
John's field, which is represented by a rectangle of N x M (1 <= N
<= 100; 1 <= M <= 100) squares. Each square contains either water
('W') or dry land ('.'). Farmer John would like to figure out how
many ponds have formed in his field.  A pond is a connected set of
squares with water in them, where a square is considered adjacent
to all eight of its neighbors.

Given a diagram of Farmer John's field, determine how many ponds he has.

PROBLEM NAME: lkcount

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: M characters per line representing one row of Farmer
        John's field.  Each character is either 'W' or '.'.  The
        characters do not have spaces between them.

SAMPLE INPUT:

10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.

OUTPUT FORMAT:

* Line 1: The number of ponds in Farmer John's field.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

There are three ponds: one in the upper left, one in the lower left,
and one along the right side.
*/

#include <bits/stdc++.h>
using namespace std;
int N, M;

vector<vector<bool>> grid;
vector<vector<bool>> visited;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

void floodFill(int x, int y) {
    if (x == N || x == -1 || y == M || y == -1) {
        return;
    }
    if (visited[x][y]) {
        return;
    }
    visited[x][y] = true;
    if (!grid[x][y]) {
        return;
    }
    for (int i = 0; i < 8; i++) {
        floodFill(x + dx[i], y + dy[i]);
    }
}

int main() {
    cin >> N >> M;
    grid = vector<vector<bool>>(N, vector<bool>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < M; j++) {
            grid[i][j] = (a[j] == 'W');
        }
    }
    /*
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    */
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j]) {
                ans++;
                floodFill(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}