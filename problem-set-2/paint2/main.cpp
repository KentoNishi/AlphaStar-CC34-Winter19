/*
Super Paintball
===============

The cows have purchased a Super Paintball Deluxe game set from
Tycow, the cow-toy manufacturer. Bessie, knowing you can help, has
partitioned the pasture into a set of N x N unit squares (1 <= N
<= 100) and compiled a list of the K (1 <= K <= 100,000) locations
(1 <= R_i <= N; 1 <= C_i <= N) of every one of her opponents in the
Paintball game.

This paintball game features a paintball gun that can shoot paintballs
in any of eight directions: north, south, east, west, and the
diagonals that split those directions exactly (northeast, southeast,
northwest, southwest).

Bessie wants you to tell her the total number of squares she can
occupy and still be able to shoot all of her opponents (she can
even shoot them if she shares the same square as they occupy!).

PROBLEM NAME: paint2

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..K+1: Line i+1 describes cow i's location with two
        space-separated integers: R_i and C_i

SAMPLE INPUT:

4 3
2 1
2 3
4 1

INPUT DETAILS:

The pasture has 4 rows and 4 columns. Bessie needs to shoot cows
at (2,1), (2,3), and (4,1):
           . . . .
           C . C .  
           . . . .   <---  Cow locations
           C . . .

OUTPUT FORMAT:

* Line 1: A single integer that tells how many different locations
        Bessie may occupy if she is to be able to shoot any cow
        according to the shooting rules.

SAMPLE OUTPUT:

5

OUTPUT DETAILS:

Bessie can occupy any of these cells: (2,1), (2,3), (3,2), (4,1),
and (4,3). The diagram below notates possibly shared spaces by '*':
        . . . .           . . . .
        B . B .   ---\    * . * .
        . B . .   ---/    . B . .
        B . B .           * . B .
   Potential Bessie     Bessie & Cows
     Locations
*/

#include <bits/stdc++.h>
using namespace std;

int N, C;
vector<vector<int>> grid;

int main() {
    cin >> N >> C;
    grid = vector<vector<int>>(N, vector<int>(N));
    for (int i = 0; i < C; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        grid[a][b] = 1;
    }
    int ans = 0;
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            int hits = 0;
            for (int i = 0; i < N; i++) {
                hits += grid[i][y];
                hits += grid[x][i];
            }
            hits -= grid[x][y];
            for (int i = 1; x + i < N && y + i < N; i++) {
                hits += grid[x + i][y + i];
            }
            for (int i = 1; x + i < N && y - i >= 0; i++) {
                hits += grid[x + i][y - i];
            }
            for (int i = 1; y + i < N && x - i >= 0; i++) {
                hits += grid[x - i][y + i];
            }
            for (int i = 1; x - i >= 0 && y - i >= 0; i++) {
                hits += grid[x - i][y - i];
            }
            // cout << hits << " ";
            if (hits == C) {
                ans++;
            }
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}