/*
Cow Routing
===========

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
irrespective of the number of cities she visits along the route.

Bessie would like to find the cheapest way to travel from her farm
(in city A) to her tropical destination (city B). Since she does not
want to be confused by a complicated itinerary, she wants to use only
a single route.  Please help her decide what is the minimum cost she
must pay.

PROBLEM NAME: cowroute

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

Output the minimum cost of a single route Bessie can use to travel
from city A to city B.  If there is no such route, output -1.

SAMPLE OUTPUT:

8

SOLUTION NOTES:

Although there is a cheaper two-route solution (use route 2 to travel
from city 1 to city 3, then route 1 to travel from city 3 to city 2),
Bessie is only allowed to use a single route, so she must use route 3
at a cost of 8.
*/

#include <bits/stdc++.h>
using namespace std;

int A, B, N;

int main() {
    cin >> A >> B >> N;
    vector<int> costs = vector<int>(N);
    vector<vector<int>> routes = vector<vector<int>>(N);
    for (int i = 0; i < N; i++) {
        int cost, cities;
        cin >> cost >> cities;
        costs[i] = cost;
        for (int j = 0; j < cities; j++) {
            int city;
            cin >> city;
            routes[i].push_back(city);
        }
    }
    int ans = -1;
    for (int i = 0; i < N; i++) {
        bool Afound = false;
        for (int j = 0; j < routes[i].size(); j++) {
            if (routes[i][j] == B) {
                if (!Afound) {
                    break;
                }
                if (ans == -1) {
                    ans = costs[i];
                }
                ans = min(costs[i], ans);
            } else if (routes[i][j] == A) {
                Afound = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
}