/*
Cows on a Leash
===============

Farmer John has forced indignity onto the N (1 <= N <= 32,000) cows:
he has purchased a number of leashes and has leashed the cows to
stakes (conveniently located at integer locations) next to a long,
linear fence that is no longer than 5,300,000 meters and runs
east-west. Every single cow is straining her leash as much as she
can to the east (though never beyond the end of the fence).

Happily, the cows have acquired an ally: FJ's wife thinks that
leashes are barbaric and has come to the fence with her dull butcher
knife. She can perform only a few cuts with it and wants to do the
best job she can. She can locate herself halfway between two integer
points along the fence and cut all the leashes that cross in front
of her at that place.

Given the length of each leash and the location of its stake in the
ground, what is the minimal number of cuts she must perform to free
the cows?

PROBLEM NAME: leash

INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: Each line contains two space-separated positive
        integers that describe a leash. The first is the location of
        the leash's stake; the second is the length of the leash.

SAMPLE INPUT:

7
2 4
4 7
3 3
5 3
9 4
1 5
7 3

INPUT DETAILS:

Here is a simple graphical representation of the locations of the leashes:

                  1 1 1 1
1 2 3 4 5 6 7 8 9 0 1 2 3
-------------------------
. 111111111 . . . . . . .
. . . 222222222222222 . .
. . 3333333 . . . . . . .
. . . . 4444444 . . . . .
. . . . . . . . 555555555
66666666666 . . . . . . .
. . . . . . 7777777 . . .

OUTPUT FORMAT:

* Line 1: A single integer that is the minimum number of cuts so that
        each leash is cut at least once.

SAMPLE OUTPUT:

2

OUTPUT DETAILS:

Cutting at 5.5 cuts leashes 1, 2, 3, 4, and 6. A second cut at 9.5 cuts
leashes 5 and 7. Other locations are surely possible, but no single cut can
penetrate leashes 5 and 6, so at least two cuts are necessary.
*/

#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    cin >> N;
    vector<pair<int, int>> events;
    // <time,id>
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        events.push_back(make_pair(a, i));
        events.push_back(make_pair(a + b, i));
    }
    sort(events.begin(), events.end());
    set<int> current;
    int ans = 0;
    for (auto &e : events) {
        auto point = current.find(e.second);
        if (point != current.end()) {
            // exists
            current.erase(point);
        } else {
            current.emplace(e.second);
        }
        ans = max(ans, (int)current.size());
    }
    cout << ans << endl;
    return 0;
}