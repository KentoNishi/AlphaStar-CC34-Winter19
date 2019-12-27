/*
Going to the Movies
===================

Farmer John is taking some of his cows to the movies! While his 
truck has a limited capacity of C (100 <= C <= 5000) kilograms, he   
wants to take the cows that, in aggregate, weigh as much as possible
without exceeding the limit C.

Given N (1 <= N <= 16) cows and their respective weights W_i, determine   
the weight of the heaviest group of cows that FJ can take to the 
movies.

PROBLEM NAME: cowflix

INPUT FORMAT:

* Line 1: Two space-separated integers: C and N

* Lines 2..N+1: Line i+1 contains a single integer: W_i

SAMPLE INPUT:

259 5
81
58
42
33
61

OUTPUT FORMAT:

* Line 1: A single integer that is the weight of the heaviest group of
        cows that can go to the movies

SAMPLE OUTPUT:

242

OUTPUT DETAILS:

81+58+42+61 = 242; this is the best possible sum
*/

#include <bits/stdc++.h>
using namespace std;

int W, N;
vector<int> weights;
int ans = 0;

void tryAll(vector<bool> used, int total) {
    if (total > W) {
        return;
    }
    ans = max(ans, total);
    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            vector<bool> localUsed = used;
            localUsed[i] = true;
            tryAll(localUsed, total + weights[i]);
        }
    }
}

int main() {
    cin >> W >> N;
    weights = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }
    vector<bool> used = vector<bool>(N);
    tryAll(used, 0);
    cout << ans << endl;
    return 0;
}