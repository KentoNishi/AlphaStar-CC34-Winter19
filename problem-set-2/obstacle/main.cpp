/*
Obstacle Course
===============

Consider an N x N (1 <= N <= 100) square field composed of 1
by 1 tiles. Some of these tiles are impassible by cows and are
marked with an 'x' in this 5 by 5 field that is challenging to
navigate:

. . B x .
. x x A .
. . . x .
. x . . .
. . x . .

Bessie finds herself in one such field at location A and wants to
move to location B in order to lick the salt block there. Slow,
lumbering creatures like cows do not like to turn and, of course,
may only move parallel to the edges of the square field. For
a given field, determine the minimum number of ninety degree turns
in any path from A to B. The path may begin and end with Bessie
facing in any direction. Bessie knows she can get to the salt lick.

PROBLEM NAME: obstacle

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N + 1: Line i+1 represents row i of the field with N
characters as above (i.e., '.', 'x', 'A', and 'B'); no spaces
are present on a line

SAMPLE INPUT:

3
.xA
...
Bx.

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

The cow must make at least 2 turns: For example, the cow may start
by facing south, move south, turn to face west, move west, move
west, then turn to face south, and finally move south into the B
square.
*/

#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<bool>> grid;

struct State {
    int x;
    int y;
    int dir;
    int dist;
};

int dy[] = {0, 1, 0, -1};
int dx[] = {-1, 0, 1, 0};

int main() {
    cin >> N;
    int startX;
    int startY;
    int endX;
    int endY;
    grid = vector<vector<bool>>(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j] == 'x';
            if (s[j] == 'A') {
                startX = i;
                startY = j;
            }
            if (s[j] == 'B') {
                endX = i;
                endY = j;
            }
        }
    }
    deque<State> locations;
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(4, -1)));
    for (int i = 0; i < 4; i++) {
        locations.push_back({startX, startY, i, 0});
    }
    while (locations.size() > 0) {
        auto top = locations.front();
        locations.pop_front();
        if (top.x == -1 || top.x == N || top.y == -1 || top.y == N) {
            continue;
        }
        if (dp[top.x][top.y][top.dir]>=0 && top.dist>dp[top.x][top.y][top.dir]) {
            continue;
        };
        if (grid[top.x][top.y]) {
            continue;
        }
        cout << "Currently at " << top.x << "," << top.y << " with distance " << top.dist << " facing direction " << top.dir << endl;
        if(dp[top.x][top.y][top.dir]==-1){
            dp[top.x][top.y][top.dir]=top.dist;
        }
        dp[top.x][top.y][top.dir] = min(top.dist,dp[top.x][top.y][top.dir]);
        if (top.x == endX && top.y == endY) {
            cout << top.dist << endl;
            break;
            //return 0;
        }
        for (int i = 0; i < 4; i++) {
            if (i == top.dir) {
                locations.push_front({top.x + dx[i], top.y + dy[i], i, top.dist});
            } else {
                int timeToTurn=(top.dir-i)==1?1:abs(top.dir-i);
                locations.push_back({top.x, top.y, i, top.dist+timeToTurn});
            }
        }
    }
    for(int i=0;i<N;i++){
        cout << "|||";
        for(int j=0;j<N;j++){
            for(int k=0;k<4;k++){
                cout << dp[i][j][k] << ":";
            }
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}