/*
Knights of Ni
=============

Bessie is in Camelot and has encountered a sticky situation: she
needs to pass through the forest that is guarded by the Knights of
Ni. In order to pass through safely, the Knights have demanded that
she bring them a single shrubbery. Time is of the essence, and
Bessie must find and bring them a shrubbery as quickly as possible.

Bessie has a map of of the forest, which is partitioned into a
square grid arrayed in the usual manner, with axes parallel to the
X and Y axes. The map is W x H units in size (1 <= W <= 1000; 1 <=
H <= 1000).

The map shows where Bessie starts her quest, the single square where
the Knights of Ni are, and the locations of all the shrubberies of
the land. It also shows which areas of the map can be traverse (some
grid blocks are impassable because of swamps, cliffs, and killer
rabbits). Bessie can not pass through the Knights of Ni square
without a shrubbery.

In order to make sure that she follows the map correctly, Bessie
can only move in four directions: North, East, South, or West (i.e.,
NOT diagonally). She requires one day to complete a traversal from
one grid block to a neighboring grid block.

It is guaranteed that Bessie will be able to obtain a shrubbery and then
deliver it to the Knights of Ni. Determine the quickest way for her to do so.

PROBLEM NAME: ni

INPUT FORMAT:

* Line 1: Two space-separated integers: W and H.

* Lines 2..?: These lines describe the map, row by row. The first line
        describes the most northwest part of the map; the last line
        describes the most southeast part of the map. Successive
        integers in the input describe columns of the map from west to
        east. Each new row of a map's description starts on a new
        input line, and each input line contains no more than 40
        space-separated integers. If W <= 40, then each input line
        describes a complete row of the map. If W > 40, then more than
        one line is used to describe a single row, 40 integers on each
        line except potentially the last one. No input line ever
        describes elements of more than one row.

The integers that describe the map come from this set:
0: Square through which Bessie can travel
1: Impassable square that Bessie cannot traverse
2: Bessie's starting location
3: Location of the Knights of Ni
4: Location of a shrubbery

SAMPLE INPUT:

8 4
4 1 0 0 0 0 1 0
0 0 0 1 0 1 0 0
0 2 1 1 3 0 4 0
0 0 0 4 1 1 1 0

INPUT DETAILS:

Width=8, height=4. Bessie starts on the third row, only a few squares away
from the Knights.

OUTPUT FORMAT:

* Line 1: D, the minimum number of days it will take Bessie to reach a
        shrubbery and bring it to the Knights of Ni.

SAMPLE OUTPUT:

11

OUTPUT DETAILS:

Bessie can move in this pattern to get a shrubbery for the Knights:
N, W, N, S, E, E, N, E, E, S, S. She gets the shrubbery in the northwest
corner and then makes her away around the barriers to the east and then
south to the Knights.
*/

#include <bits/stdc++.h>
using namespace std;

int W, H;

struct Pixel {
    bool clear;
    bool shrub;
    bool knight;
    bool visited[2];
};

vector<vector<Pixel>> grid;

struct State {
    int x;
    int y;
    bool hasShrub;
    int steps;
    State(int ax, int ay, bool hs, int st) {
        x = ax;
        y = ay;
        hasShrub = hs;
        steps = st;
    }
};

int main() {
    cin >> W >> H;
    int startX;
    int startY;
    grid = vector<vector<Pixel>>(H, vector<Pixel>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a;
            cin >> a;
            grid[i][j].clear = (a != 1 && a != 3);
            grid[i][j].shrub = (a == 4);
            grid[i][j].knight = (a == 3);
            if (a == 2) {
                startX = i;
                startY = j;
            }
        }
    }
    queue<State> todo;
    todo.emplace(startX, startY, false, 0);
    grid[startX][startY].visited[0] = true;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (todo.size() > 0) {
        State top = todo.front();
        todo.pop();
        if (!top.hasShrub) {
            top.hasShrub = grid[top.x][top.y].shrub;
        }
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + top.x;
            int ny = dy[i] + top.y;
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
                continue;
            }
            if (grid[nx][ny].visited[top.hasShrub ? 1 : 0]) {
                continue;
            }
            if (grid[nx][ny].knight && top.hasShrub) {
                cout << top.steps + 1 << endl;
                return 0;
            }
            if (!grid[nx][ny].clear) {
                continue;
            }
            grid[nx][ny].visited[top.hasShrub ? 1 : 0] = true;
            todo.emplace(nx, ny, top.hasShrub, top.steps + 1);
        }
    }
    return 0;
}