/*
Cow Art
=======

A little known fact about cows is the fact that they are red-green
colorblind, meaning that red and green look identical to them.  This makes
it especially difficult to design artwork that is appealing to cows as well
as humans.

Consider a square painting that is described by an N x N grid of characters
(1 <= N <= 100), each one either R (red), G (green), or B (blue).  A
painting is interesting if it has many colored "regions" that can
be distinguished from each-other.  Two characters belong to the same
region if they are directly adjacent (east, west, north, or south), and
if they are indistinguishable in color.  For example, the painting

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

has 4 regions (2 red, 1 blue, and 1 green) if viewed by a human, but only 3
regions (2 red-green, 1 blue) if viewed by a cow.  

Given a painting as input, please help compute the number of regions in the
painting when viewed by a human and by a cow.

PROBLEM NAME: cowart

INPUT FORMAT:

* Line 1: The integer N.

* Lines 2..1+N: Each line contains a string with N characters,
        describing one row of a painting.

SAMPLE INPUT:

5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

OUTPUT FORMAT:

* Line 1: Two space-separated integers, telling the number of regions
        in the painting when viewed by a human and by a cow.

SAMPLE OUTPUT:

4 3
*/

#include <bits/stdc++.h>
using namespace std;
int N;

vector<vector<char>> grid;
vector<vector<bool>> visited;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void floodFill(int x, int y, char c) {
    if (x >= N || x == -1 || y >= N || y == -1) {
        return;
    }
    //cout << x << "," << y << endl;
    if (visited[x][y]) {
        return;
    }
    if (grid[x][y] != c) {
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        floodFill(x + dx[i], y + dy[i], c);
    }
}

int main() {
    cin >> N;
    grid = vector<vector<char>>(N, vector<char>(N));
    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    for (int i = 0; i < N; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < N; j++) {
            grid[i][j] = a[j];
        }
    }
    int human = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                human++;
                floodFill(i, j, grid[i][j]);
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            if (grid[i][j] == 'R') {
                grid[i][j] = 'G';
            }
        }
    }
    int cow = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                cow++;
                floodFill(i, j, grid[i][j]);
            }
        }
    }
    cout << human << " " << cow << endl;
    return 0;
}