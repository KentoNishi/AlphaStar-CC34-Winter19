/*
Bad Grass
=========

Bessie was munching on tender shoots of grass and, as cows do,
contemplating the state of the universe. She noticed that she only
enjoys the grass on the wide expanses of pasture whose elevation
is at the base level of the farm. Grass from elevations just 1 meter
higher is tougher and not so appetizing. The bad grass gets worse
as the elevation increases.

Continuing to chew, she realized that this unappetizing food grows
the sides of hills that form a set of 'islands' of bad grass among
the sea of tender, verdant, delicious, abundant grass.

Bessie donned her lab coat and vowed to determine just how many
islands of bad grass her pasture had. She created a map in which
she divided the pasture into R (1 < R <= 1,000) rows and C (1 < C
<= 1,000) columns of 1 meter x 1 meter squares. She measured the
elevation above the base level for each square and rounded it to a
non-negative integer. She noted hungrily that the tasty grass all
had elevation 0.

She commenced counting the islands. If two squares are neighbors
in any of the horizontal, vertical or diagonal directions then they
are considered to be part of the same island.

How many islands of bad grass did she count for each of the supplied
maps?

PROBLEM NAME: badgras

INPUT FORMAT:

* Line 1: Two space-separated integers: R and C

* Lines 2..R+1: Line i+1 describes row i of the map with C space
        separated integers

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

* Line 1: A single integer that specifies the number of islands.

SAMPLE OUTPUT:

2

OUTPUT DETAILS:

There are two islands. The big one on the left side that extends
all the way to the bottom through a diagonal and the small one on
the upper-right corner.
*/

#include <bits/stdc++.h>
using namespace std;
int N, M;

vector<vector<bool>> grid;
vector<vector<bool>> visited;
int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

queue<pair<int, int>> toProcess;

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
        toProcess.emplace(x + dx[i], y + dy[i]);
    }
}

int main() {
    cin >> N >> M;
    grid = vector<vector<bool>>(N, vector<bool>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int a;
            cin >> a;
            grid[i][j] = (a > 0);
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && grid[i][j]) {
                ans++;
                toProcess.emplace(i, j);
                while (toProcess.size() > 0) {
                    auto top = toProcess.front();
                    toProcess.pop();
                    floodFill(top.first, top.second);
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}