/*
Meeting Time
============

Bessie and her sister Elsie want to travel from the barn to their
favorite field, such that they leave at exactly the same time from the
barn, and also arrive at exactly the same time at their favorite
field.

The farm is a collection of N fields (1 <= N <= 16) numbered 1..N,
where field 1 contains the barn and field N is the favorite field.
The farm is built on the side of a hill, with field X being higher in
elevation than field Y if X < Y.  An assortment of M paths connect
pairs of fields.  However, since each path is rather steep, it can
only be followed in a downhill direction. For example, a path
connecting field 5 with field 8 could be followed in the 5 -> 8
direction but not the other way, since this would be uphill.  Each
pair of fields is connected by at most one path, so M <= N(N-1)/2.

It might take Bessie and Elsie different amounts of time to follow a
path; for example, Bessie might take 10 units of time, and Elsie 20.
Moreover, Bessie and Elsie only consume time when traveling on paths
between fields -- since they are in a hurry, they always travel
through a field in essentially zero time, never waiting around
anywhere.

Please help determine the shortest amount of time Bessie and Elsie
must take in order to reach their favorite field at exactly the same
moment.

PROBLEM NAME: meeting

INPUT:

The first input line contains N and M, separated by a space.

Each of the following M lines describes a path using four integers A B
C D, where A and B (with A < B) are the fields connected by the path,
C is the time required for Bessie to follow the path, and D is the
time required for Elsie to follow the path.  Both C and D are in the
range 1..1000.

SAMPLE INPUT:

3 3
1 3 1 2
1 2 1 2
2 3 1 2

OUTPUT:

A single integer, giving the minimum time required for Bessie and
Elsie to travel to their favorite field and arrive at the same moment.
If this is impossible, or if there is no way for Bessie or Elsie to reach
the favorite field at all, output the word IMPOSSIBLE on a single line.

SAMPLE OUTPUT:

2

SOLUTION NOTES:

Bessie is twice as fast as Elsie on each path, but if Bessie takes the
path 1->2->3 and Elsie takes the path 1->3 they will arrive at the
same time.
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;

struct Edge {
    int bessie;
    int elsie;
    int to;
};

struct Node {
    int height;
    vector<Edge> edges;
};

vector<Node> graph;

struct State {
    int node;
    int time;
    State(int n, int t) {
        node = n;
        time = t;
    }
};

int ans = INT_MAX;

void findPaths(set<int> &times, bool bessie) {
    queue<State> todo;
    todo.emplace(0, 0);
    while (todo.size() > 0) {
        State top = todo.front();
        todo.pop();
        // cout << (bessie?"bessie":"elsie") << " is at " << top.node << " at time " << top.time << endl;
        for (auto &edge : graph[top.node].edges) {
            if (bessie) {
                int totalTime = top.time + edge.bessie;
                if (edge.to == N - 1) {
                    times.insert(totalTime);
                } else {
                    todo.emplace(edge.to, totalTime);
                }
            } else {
                int totalTime = top.time + edge.elsie;
                if (edge.to == N - 1) {
                    if (times.find(totalTime) != times.end()) {
                        ans = min(ans, totalTime);
                    }
                } else {
                    todo.emplace(edge.to, totalTime);
                }
            }
        }
    }
}

int main() {
    cin >> N >> M;
    graph = vector<Node>(N);
    for (int i = 0; i < M; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        int from = a;
        int to = b;
        Edge edge = {c, d, to};
        graph[from].edges.push_back(edge);
    }
    set<int> times;
    findPaths(times, true);
    findPaths(times, false);
    if (ans == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}