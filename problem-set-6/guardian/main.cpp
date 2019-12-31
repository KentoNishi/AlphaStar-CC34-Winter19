/*
Guarding the Farm
=================

The farm has many hills upon which Farmer John would like to place
guards to ensure the safety of his valuable milk-cows.

He wonders how many guards he will need if he wishes to put one on
top of each hill. He has a map supplied as a matrix of integers;
the matrix has N (1 < N <= 700) rows and M (1 < M <= 700) columns.
Each member of the matrix is an altitude H_ij (0 <= H_ij <= 10,000).
Help him determine the number of hilltops on the map.

A hilltop is one or more adjacent matrix elements of the same value
surrounded exclusively by either the edge of the map or elements
with a lower (smaller) altitude. Two different elements are adjacent
if the magnitude of difference in their X coordinates is no greater
than 1 and the magnitude of differences in their Y coordinates is
also no greater than 1.

PROBLEM NAME: guardian

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 describes row i of the matrix with M
        space-separated integers: H_ij

SAMPLE INPUT:

8 7
4 3 2 2 1 0 1
3 3 3 2 1 0 1
2 2 2 2 1 0 0
2 1 1 1 1 0 0
1 1 0 0 0 1 0
0 0 0 1 1 1 0
0 1 2 2 1 1 0
0 1 1 1 2 1 0

OUTPUT FORMAT:

* Line 1: A single integer that specifies the number of hilltops

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

There are three peaks: The one with height 4 on the left top, one of
the points with height 2 at the bottom part, and one of the points with
height 1 on the right top corner.
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;

struct Pixel {
    int height;
    bool visited;
};

vector<vector<Pixel>> grid;

struct State {
    int x;
    int y;
    int h;
    State(int px, int py, int ph) {
        x = px;
        y = py;
        h = ph;
    }
};

int main() {
    cin >> N >> M;
    grid = vector<vector<Pixel>>(N, vector<Pixel>(M));
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            cin >> grid[x][y].height;
        }
    }
    int dx[] = {0, 0, 1, -1, 1, -1, -1, 1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
    int ans = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {
            if (!grid[x][y].visited) {
                bool hilltop = true;
                queue<State> todo;
                todo.emplace(x, y, grid[x][y].height);
                while (todo.size() > 0) {
                    State top = todo.front();
                    todo.pop();
                    // cout << top.x << "," << top.y << endl;
                    for (int i = 0; i < 8; i++) {
                        int nx = top.x + dx[i];
                        int ny = top.y + dy[i];
                        if (nx >= N || nx < 0 || ny >= M || ny < 0) {
                            continue;
                        }
                        if (grid[nx][ny].height != top.h) {
                            if (grid[nx][ny].height > top.h) {
                                // cout << "+++ " << nx << "," << ny << " is " << grid[nx][ny].height << ", which is taller than " << top.x << "," << top.y << " which is " << top.h << endl;
                                hilltop = false;
                            }
                            continue;
                        }
                        if (!grid[nx][ny].visited) {
                            todo.emplace(nx, ny, top.h);
                            grid[nx][ny].visited = true;
                        }
                    }
                }
                if (hilltop) {
                    // cout << "Region from " << x << "," << y << " is a hilltop" << endl;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}