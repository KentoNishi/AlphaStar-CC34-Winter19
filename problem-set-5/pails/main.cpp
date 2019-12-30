/*
Milk Pails
==========

Farmer John has received an order for exactly M units of milk (1 <= M 
<= 200) that he needs to fill right away. Unfortunately, his fancy 
milking machine has just become broken, and all he has are two milk 
pails of integer sizes X and Y (1 <= X,Y <= 100) with which he can 
measure milk. Both pails are initially empty. Using these two pails, 
he can perform up to K of the following types of operations (1 <= K 
<= 100):

- He can fill either pail completely to the top.

- He can empty either pail.

- He can pour the contents of one pail into the other, stopping when 
the former becomes empty or the latter becomes full (whichever of 
these happens first).

Although FJ realizes he may not be able to end up with exactly M 
total units of milk in the two pails, please help him compute the 
minimum amount of error between M and the total amount of milk in the 
two pails. That is, please compute the minimum value of |M-M'| such 
that FJ can construct M' units of milk collectively between the two 
pails.

PROBLEM NAME: pails

INPUT FORMAT:

The first, and only line of input, contains X, Y, K, and M.

OUTPUT FORMAT:

Output the smallest distance from M to an amount of milk FJ can 
produce.

SAMPLE INPUT:

14 50 2 32

SAMPLE OUTPUT:

18

In two steps FJ can be left with the following quanities in his pails

(0, 0) = 0 units
(14, 0) = 14 units
(0, 50) = 50 units
(0, 14) = 14 units
(14, 36) = 50 units
(14, 50) = 64 units

The closest we can come to 32 units is 14 for a difference of 18. 
Note that it would require an extra step to pour out the first pail 
to end up with (0, 36). 
*/

#include <bits/stdc++.h>
using namespace std;

struct State {
    int bucket1;
    int bucket2;
    int moves;
    State(int b1, int b2, int m) {
        bucket1 = b1;
        bucket2 = b2;
        moves = m;
    }
};

bool operator<(State a, State b) {
    return make_tuple(a.bucket1, a.bucket2, a.moves) < make_tuple(b.bucket1, b.bucket2, b.moves);
}

int main() {
    int capacity1, capacity2, maxMoves, target;
    cin >> capacity1 >> capacity2 >> maxMoves >> target;
    map<State, bool> visited;
    queue<State> todo;
    todo.emplace(State(0, 0, 0));
    int ans = INT_MAX;
    while (todo.size() > 0) {
        State top = todo.front();
        todo.pop();
        ans = min(ans, abs(target - (top.bucket1 + top.bucket2)));
        if (top.moves + 1 > maxMoves) {
            continue;
        }
        int bucket2to1 = min(top.bucket1 + top.bucket2, capacity1) - top.bucket1;
        int bucket1to2 = min(top.bucket1 + top.bucket2, capacity2) - top.bucket2;
        State nextStates[] = {
            State(capacity1, top.bucket2, top.moves + 1),
            State(top.bucket1, capacity2, top.moves + 1),
            State(top.bucket1, 0, top.moves + 1),
            State(0, top.bucket2, top.moves + 1),
            State(top.bucket1 + bucket2to1, top.bucket2 - bucket2to1, top.moves + 1),
            State(top.bucket1 - bucket1to2, top.bucket2 + bucket1to2, top.moves + 1),
        };
        for (int k = 0; k < 6; k++) {
            if (!visited[nextStates[k]]) {
                visited[nextStates[k]] = true;
                todo.emplace(nextStates[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}