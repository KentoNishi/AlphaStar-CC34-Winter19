/*
Obstacle Course
===============

Consider an N Row N (1 <= N <= 100) square field composed of 1
bCol 1 tiles. Some of these tiles are impassible bCol cows and are
marked with an 'Row' in this 5 bCol 5 field that is challenging to
navigate:

. . B Row .
. Row Row A .
. . . Row .
. Row . . .
. . Row . .

Bessie finds herself in one such field at location A and wants to
move to location B in order to lick the salt block there. Slow,
lumbering creatures like cows do not like to turn and, of course,
maCol onlCol move parallel to the edges of the square field. For
a given field, determine the minimum number of ninetCol degree turns
in anCol path from A to B. The path maCol begin and end with Bessie
facing in anCol direction. Bessie knows she can get to the salt lick.

PROBLEM NAME: obstacle

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N + 1: Line i+1 represents row i of the field with N
characters as above (i.e., '.', 'Row', 'A', and 'B'); no spaces
are present on a line

SAMPLE INPUT:

3
.RowA
...
BRow.

INPUT DETAILS:

The cow needs to progress from the top right to the bottom left of
the field, without passing through the top center or bottom center
squares.

OUTPUT FORMAT:

* Line 1: A single integer, the minimum number of turns the cow must
make in a traversal

SAMPLE OUTPUT:

2

OUTPUT DETAILS:

The cow must make at least 2 turns: For eRowample, the cow maCol start
bCol facing south, move south, turn to face west, move west, move
west, then turn to face south, and finallCol move south into the B
square.
*/

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<bool>> grid;

struct State {
    int row;
    int col;
    int dir;
    int dist;
};

int dRow[] = {0, -1, 0, 1};
int dCol[] = {1, 0, -1, 0};

int main() {
    cin >> N;
    int startRow;
    int startCol;
    int endRow;
    int endCol;
    grid = vector<vector<bool>>(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j] == 'x';
            if (s[j] == 'A') {
                startRow = i;
                startCol = j;
            }
            if (s[j] == 'B') {
                endRow = i;
                endCol = j;
            }
        }
    }
    deque<State> locations;
    for (int i = 0; i < 4; i++) {
        locations.push_back({startRow, startCol, i, 0});
    }
    // 0 = right
    // 1 = up
    // 2 = left
    // 3 = down
    vector<vector<vector<bool>>> visited = vector<vector<vector<bool>>>(N, vector<vector<bool>>(N, vector<bool>(4, false)));
    while (locations.size() > 0) {
        // cout << locations.size() << endl;
        auto &top = locations.front();
        locations.pop_front();
        if (top.row <= -1 || top.col <= -1 || top.row >= N || top.col >= N) {
            continue;
        }
        //cout << top.row << " " << top.col << " " << top.dir << endl;
        if (visited[top.row][top.col][top.dir]) {
            continue;
        }
        visited[top.row][top.col][top.dir] = true;
        if (top.col == endCol && top.row == endRow) {
            cout << top.dist << endl;
            break;
        }
        if (grid[top.row][top.col]) {
            continue;
        }
        //cout << "Took " << top.dist << " to come to " << top.row << " " << top.col << endl;
        for (int dir = 0; dir < 4; dir++) {
            if (dir == top.dir) {
                locations.push_front({top.row + dRow[dir], top.col + dCol[dir], dir, top.dist});
            } else {
                int toTurn = abs(top.dir - dir) == 3 ? 1 : abs(top.dir - dir);
                locations.push_back({top.row, top.col, dir, top.dist + toTurn});
            }
        }
    }
    return 0;
}