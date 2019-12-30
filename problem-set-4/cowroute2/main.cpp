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
    int startingCity, endingCity, N;
    cin >> startingCity >> endingCity >> N;
    int cities[505];
    int MtoB[10001];
    int AtoM[10001];
    int ans = 10000000;
    int numCities = -1;
    for (int i = 0; i < 10001; i++) {
        AtoM[i] = 10000000;
        MtoB[i] = 10000000;
    }
    AtoM[startingCity] = 0;
    MtoB[endingCity] = 0;
    for (int i = 0; i < N; i++) {
        int cost, num;
        cin >> cost >> num;
        int Aindex = 10000000;
        int Bindex = -1;
        for (int k = 0; k < num; k++) {
            cin >> cities[k];
            numCities = max(cities[k], numCities);
            if (cities[k] == startingCity) {
                Aindex = k;
            }
            if (cities[k] == endingCity) {
                Bindex = k;
            }
        }
        for (int k = Aindex + 1; k < num; k++) {
            AtoM[cities[k]] = min(AtoM[cities[k]], cost);
        }
        for (int k = Bindex - 1; k >= 0; k--) {
            MtoB[cities[k]] = min(MtoB[cities[k]], cost);
        }
    }
    for (int i = 0; i < numCities + 1; i++) {
        //cout << i << ": " << AtoM[i] << "," << MtoB[i] << endl;
        ans = min(AtoM[i] + MtoB[i], ans);
    }
    if (ans == 10000000) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
    return 0;
}