/*
Why Did the Cow Cross the Road III
==================================

Why did the cow cross the road? Well, one reason is that Farmer 
John's farm simply has a lot of roads, making it impossible for his 
cows to travel around without crossing many of them.

FJ's farm is arranged as an N x N square grid of fields (2 <= N <= 
100), Certain pairs of adjacent fields (e.g., north-south or 
east-west) are separated by roads, and a tall fence runs around the 
external perimeter of the entire grid, preventing cows from leaving 
the farm. Cows can move freely from any field to any other adjacent 
field (north, east, south, or west), although they prefer not to 
cross roads unless absolutely necessary.

There are K cows (1 <= K <= 100, K <= N^2) on FJ's farm, each located 
in a different field. A pair of cows is said to be "distant" if, in 
order for one cow to visit the other, it is necessary to cross at 
least one road. Please help FJ count the number of distant pairs of 
cows.

PROBLEM NAME: countcross

INPUT FORMAT:

The first line of input contains N, K, and R. The next R lines 
describe R roads that exist between pairs of adjacent fields. Each 
line is of the form r c r' c' (integers in the range 1..N), 
indicating a road between the field in (row r, column c) and the 
adjacent field in (row r', column c'). The final K lines indicate the 
locations of the K cows, each specified in terms of a row and column.

OUTPUT FORMAT:

Print the number of pairs of cows that are distant.

SAMPLE INPUT:

3 3 3
2 2 2 3
3 3 3 2
3 3 2 3
3 3
2 2
2 3

SAMPLE OUTPUT:

2
*/

#include <bits/stdc++.h>
using namespace std;

int dirToIndex(int dr, int dc) {
    if (dr == 1) {
        return 3;
    }
    if (dr == -1) {
        return 1;
    }
    if (dc == 1) {
        return 0;
    }
    return 2;
}

int N, K, R;

int main() {
    cin >> N >> K >> R;
    bool cow[N][N];
    bool visited[N][N];
    bool blocked[N][N][4];
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            visited[i][k] = false;
            cow[i][k] = false;
            for (int j = 0; j < 4; j++) {
                blocked[i][k][j]=false;
            }
        }
    }
    for (int i = 0; i < K; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;
        if (c1-c2 == 1) {
            blocked[r1][c1][0] = true;
            blocked[r2][c2][3] = true;
        } else if (c2-c1 == 1) {
            blocked[r1][c1][3] = true;
            blocked[r2][c2][0] = true;
        }
        if (r1-r2 == 1) {
            blocked[r1][c1][1] = true;
            blocked[r2][c2][2] = true;
        } else if (r2-r1 == 1) {
            blocked[r1][c1][2] = true;
            blocked[r2][c2][1] = true;
        }
    }
    for (int i = 0; i < R; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        cow[r][c] = true;
    }
    int dr[] = {0, -1, 0, 1};
    int dc[] = {1, 0, -1, 0};
    vector<int> regions;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (!visited[r][c]) {
                int cowsInRegion = 0;
                queue<pair<int, int>> todo;
                todo.emplace(r, c);
                while (todo.size() > 0) {
                    int row, col;
                    tie(row, col) = todo.front();
                    todo.pop();
                    visited[row][col] = true;
                    if (cow[row][col]) {
                        cowsInRegion++;
                    }
                    for (int k = 0; k < 4; k++) {
                        if (row + dr[k] >= N || row + dr[k] < 0 || col + dc[k] >= N || col + dc[k] < 0) {
                            continue;
                        }
                        cout << blocked[row][col][k] << endl;
                        if (blocked[row][col][k]) {
                            continue;
                        }
                        if (visited[row + dr[k]][col + dc[k]]) {
                            continue;
                        }
                        todo.emplace(row + dr[k], col + dc[k]);
                        visited[row + dr[k]][col + dc[k]] = true;
                    }
                }
                for (int a = 0; a < N; a++) {
                    for (int b = 0; b < N; b++) {
                        cout << visited[a][b] << " ";
                    }
                    cout << endl;
                }
                cout << "==========" << endl;
                cout << cowsInRegion << endl;
                regions.push_back(cowsInRegion);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < regions.size(); i++) {
        for (int k = i + 1; k < regions.size(); k++) {
            ans += regions[i] * regions[k];
        }
    }
    cout << ans << endl;
    return 0;
}