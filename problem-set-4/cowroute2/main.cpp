/*
Cow Routing II
==============

Tired of the cold winter weather on her farm, Bessie the cow plans to
fly to a warmer destination for vacation.  Unfortunately, she
discovers that only one airline, Air Bovinia, is willing to sell
tickets to cows, and that these tickets are somewhat complicated in
structure.

Air Bovinia owns N planes (1 <= N <= 500), each of which flies on a
specific "route" consisting of two or more cities.  For example, one
plane might fly on a route that starts at city 1, then flies to city
5, then flies to city 2, and then finally flies to city 8.  No city
appears multiple times in a route.  If Bessie chooses to utilize a
route, she can board at any city along the route and then disembark at
any city later along the route.  She does not need to board at the
first city or disembark at the last city.  Each route has a certain
cost, which Bessie must pay if she uses any part of the route,
irrespective of the number of cities she visits along the route, and
Bessie may make use of a route only once (that is, she cannot use a
route and then later use a different part of the same route).

Bessie would like to find the cheapest way to travel from her farm
(in city A) to her tropical destination (city B). Since she does not
want to be confused by a complicated itinerary, she wants to use at
most two routes.  Please help her decide what is the minimum cost she
must pay.

PROBLEM NAME: cowroute2

INPUT:

The first line of input contains A, B, and N, separated by spaces.

The next 2N lines describe the available routes, in two lines per
route. The first line contains the cost of using the route (an integer
in the range 1..1000), and the number of cities along the route (an
integer in the range 1..500).  The second line contains a list of the
cities in order along the route.  Each city is identified by an
integer in the range 1..10,000.

SAMPLE INPUT:

1 2 3
3 3
3 2 1
4 4
2 1 4 3
8 5
4 1 7 8 2

OUTPUT:

Output the minimum cost of an itinerary using at most two routes that
Bessie can use to travel from city A to city B.  If there is no such
solution, output -1.

SAMPLE OUTPUT:

7

SOLUTION NOTES:

Use route 2 to travel from city 1 to city 3, then route 1 to travel
from city 3 to city 2.
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int AtoM[10001] = {INT_MAX};
    int MtoB[10001] = {INT_MAX};
    int pointA, pointB, N;
    cin >> pointA >> pointB >> N;
    for (int i = 0; i < 10001; i++) {
        AtoM[i] = 1000;
        MtoB[i] = 1000;
    }
    AtoM[pointA] = 0;
    MtoB[pointB] = 0;
    int maxCity = 0;
    for (int i = 0; i < N; i++) {
        int cost, cityCount;
        cin >> cost >> cityCount;
        int cities[cityCount];
        int Aindex = cityCount;
        int Bindex = -1;
        for (int j = 0; j < cityCount; j++) {
            cin >> cities[j];
            maxCity = max(maxCity, cities[j]);
            if (cities[j] == pointA) {
                Aindex = j;
            }
            if (cities[j] == pointB) {
                Bindex = j;
            }
        }
        if (Aindex < Bindex) {
            AtoM[pointB] = min(AtoM[pointB], cost);
        }
        for (int j = Aindex; j < cityCount; j++) {
            AtoM[cities[j]] = min(AtoM[cities[j]], cost);
        }
        for (int j = Bindex - 1; j >= 0; j--) {
            MtoB[cities[j]] = min(MtoB[cities[j]], cost);
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < maxCity + 1; i++) {
        if (AtoM[i] != INT_MAX && MtoB[i] != INT_MAX) {
            ans = min(ans, AtoM[i] + MtoB[i]);
        }
    }
    if (ans == INT_MAX) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}