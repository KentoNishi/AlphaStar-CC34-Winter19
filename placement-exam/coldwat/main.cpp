#include <bits/stdc++.h>
using namespace std;

int N, C;

struct Point {
    int b1 = -1;
    int b2 = -1;
    int distance;
};

vector<Point> points;

int main() {
    cin >> N >> C;
    points = vector<Point>(N);
    for (int i = 0; i < C; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        c--;
        points[a].b1 = b;
        points[a].b2 = c;
    }
    queue<pair<int, int>> locs;
    // id, distance
    locs.emplace(make_pair(0, 1));
    while (locs.size() > 0) {
        pair<int, int> top = locs.front();
        int id = top.first;
        points[id].distance = top.second;
        locs.pop();
        if (points[id].b1 >= 0) {
            locs.push(make_pair(points[id].b1, top.second + 1));
        }
        if (points[id].b2 >= 0) {
            locs.push(make_pair(points[id].b2, top.second + 1));
        }
    }
    for (int i = 0; i < N; i++) {
        cout << points[i].distance << endl;
    }
    return 0;
}