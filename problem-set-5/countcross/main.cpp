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
int N, K, R;

struct Pixel {
    vector<pair<int, int>> blocked;
    bool cow;
    bool visited;
};

vector<vector<Pixel>> grid;

bool isBlocked(vector<pair<int, int>> arr, int r, int c) {
    for (auto &p : arr) {
        if (p.first == r && p.second == c) {
            return true;
        }
    }
    return false;
}

void floodFill(int r, int c, int &cowCount) {
    queue<pair<int, int>> todo;
    todo.emplace(r, c);
    int dx[] = {0, 0, -1, 1};
    int dy[] = {-1, 1, 0, 0};
    grid[r][c].visited = true;
    while (todo.size() > 0) {
        pair<int, int> top = todo.front();
        todo.pop();
        if (grid[top.first][top.second].cow) {
            cowCount++;
        }
        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + top.first;
            int ny = dy[i] + top.second;
            if (nx >= 0 && ny >= 0 && nx < N && ny < N &&
                !grid[nx][ny].visited &&
                !isBlocked(grid[top.first][top.second].blocked, nx, ny)) {
                todo.push(make_pair(nx, ny));
                grid[nx][ny].visited = true;
            }
        }
    }
}

int main() {
    cin >> N >> K >> R;
    grid = vector<vector<Pixel>>(N, vector<Pixel>(N));
    for (int i = 0; i < R; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        pair<int, int> p1 = {a, b};
        pair<int, int> p2 = {c, d};
        grid[a][b].blocked.push_back(p2);
        grid[c][d].blocked.push_back(p1);
    }
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        grid[a][b].cow = true;
    }
    vector<int> cowCounts;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (!grid[r][c].visited) {
                int cowCount = 0;
                floodFill(r, c, cowCount);
                if (cowCount > 0) {
                    cowCounts.push_back(cowCount);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < cowCounts.size(); i++) {
        ans += cowCounts[i] * (K - cowCounts[i]);
    }
    cout << ans / 2 << endl;
    return 0;
}