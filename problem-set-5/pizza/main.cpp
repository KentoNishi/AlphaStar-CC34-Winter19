/*
Cow Pizza
=========

Oh how the cows love their pizza! Even though they are picky, they
do love variety, too. They order from the local pizza parlor that
features T (1 <= T <= 20) different toppings in addition to a
complete set of soft drinks and healthy salads.

The toppings are conveniently numbered 1..T so the cows can order
by number. Your job is to calculate how many possible pizzas can
be created given that some cows will not tolerate various combinations
of toppings (e.g., some cows simply will not eat Anchovies or the
combination of Mushrooms and Asparagus).
 
Given a set of N (1 <= N <= 52) constraints, figure out how many
pizzas can be made using all possible combinations of the ingredients
(which, of course, includes no ingredients at all). Each constraint is
a set of numbers of size 1..T that lists the ingredients that disqualify
a pizza from being considered.
 
A constraint like "5 3" means that no pizza can contain ingredient    
#5 and also ingredient #3. This means a pizza with ingredients 3,
5, and 6 will not be counted as acceptable.

PROBLEM NAME: pizza

INPUT FORMAT:

* Line 1: Two space-separated integers: T and N

* Lines 2..N+1: Each line describes a constraint using space-separated
        integers. The first integer is the number of ingredients in
        the constraint, Z (1 <= Z <= T). The subsequent Z integers
        (which are unique) list the ingredient(s) whose combination
        disqualifies a pizza from consideration for the cows.

SAMPLE INPUT:

6 5
1 1
2 4 2
3 3 2 6
1 5
3 3 4 6

INPUT DETAILS:

Six ingredients numbered 1..6. Five constraints: No pizza can contain
ingredient 1, no pizza can contain ingredients numbered 2 and 4, etc.

OUTPUT FORMAT:

* Line 1: A single integer that is the total number of pizzas that can
        be created using the number of ingredients and constraints.

SAMPLE OUTPUT:

10

OUTPUT DETAILS:

This includes pizzas with: no ingredients; ingr 2; ingr's 2 & 3;
ingr's 2 & 6; ingr 3; ingr's 3 & 4; ingr's 3 & 6; ingr 4; ingr's 4
& 6; and ingr 6.
*/

#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
    cin >> T >> N;
    int constraints[N];
    for (int i = 0; i < N; i++) {
        constraints[i] = 0;
        int n;
        cin >> n;
        for (int k = 0; k < n; k++) {
            int a;
            cin >> a;
            a--;
            constraints[i] = constraints[i] | (1 << a);
        }
    }
    int ans = pow(2, T);
    for (int i = 0; i < pow(2, T); i++) {
        for (int &k : constraints) {
            if ((i & k) == k) {
                ans--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}