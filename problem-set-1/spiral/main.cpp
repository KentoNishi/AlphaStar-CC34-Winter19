/*
A Spiral Walk
=============

Oh how the cows love to walk in their square pasture with sides of
length N (1 <= N <= 750) and which is partitioned into N*N squares.
They enjoy the sights, the smells, and the general ambience of the
grass and trees.

Bessie has decided to take the cows on the longest possible walk
from the upper left corner to the center (or near center in the
case of an even number of sides) of the pasture, passing through
each and every square along the way after starting.

She has decided to create the obvious clockwise spiral route (example
below) for this evening's stroll. Write a program to create a map
for her that shows the order of squares she should visit.

By way of example, for pastures of size N=3 and N=4, here are the
routes Bessie should use:

      1  2  3        1  2  3  4
      8  9  4       12 13 14  5
      7  6  5       11 16 15  6
                    10  9  8  7

PROBLEM NAME: spiral

INPUT FORMAT:

* Line 1: A single integer: N

SAMPLE INPUT:

3

OUTPUT FORMAT:

* Lines 1..N: N space-separated integers

SAMPLE OUTPUT:

1 2 3
8 9 4
7 6 5
*/

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