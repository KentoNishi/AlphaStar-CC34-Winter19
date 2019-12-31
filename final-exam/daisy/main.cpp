/*
Daisy Chains in the Field
=========================

Farmer John let his N (1 <= N <= 250) cows conveniently numbered
1..N play in the field. The cows decided to connect with each other
using cow-ropes, creating M (1 <= M <= N*(N-1)/2) pairwise connections.
Of course, no two cows had more than one rope directly connecting
them. The input shows pairs of cows c1 and c2 that are connected
(1 <= c1 <= N; 1 <= c2 <= N; c1 != c2).

FJ instructed the cows to be part of a chain which contained cow
#1. Help FJ find any misbehaving cows by determining, in ascending
order, the numbers of the cows not connected by one or more ropes
to cow 1 (cow 1 is always connected to herself, of course). If there
are no misbehaving cows, output 0.

To show how this works, consider six cows with four connections:

    1---2  4---5
     \  |
      \ |      6
       \|
        3

Visually, we can see that cows 4, 5, and 6 are not connected to cow 1.

PROBLEM NAME: daisy

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..M+1: Line i+1 shows two cows connected by rope i with two
        space-separated integers: c1 and c2

SAMPLE INPUT:

6 4
1 3
2 3
1 2
4 5

OUTPUT FORMAT:

* Lines 1..???: Each line contains a single integer

SAMPLE OUTPUT:

4
5
6
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;

struct Node {
    vector<int> edges;
    bool visited;
};

vector<Node> graph;

int main() {
    cin >> N >> M;
    graph.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].edges.push_back(b);
        graph[b].edges.push_back(a);
    }
    queue<int> todo;
    todo.emplace(0);
    graph[0].visited = true;
    while (todo.size() > 0) {
        int top = todo.front();
        todo.pop();
        for (auto &edge : graph[top].edges) {
            if (!graph[edge].visited) {
                graph[edge].visited = true;
                todo.emplace(edge);
            }
        }
    }
    bool isAns = false;
    for (int i = 0; i < N; i++) {
        if (!graph[i].visited) {
            cout << i + 1 << endl;
            isAns = true;
        }
    }
    if (!isAns) {
        cout << 0 << endl;
    }
    return 0;
}