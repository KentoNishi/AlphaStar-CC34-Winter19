/*
RADAR Brands
============

Farmer John has been branding the cows with a serial number ever
since he started the farm. The new cow fad is 'RADAR' brands,
so-called because they read the same forwards and backwards (they
are palindromic). All the cows want their daughters branded in the
new RADAR style.

Each mother wants her daughter's brand to be derived from her own
non-RADAR brand by summing the mother's brand and its reverse.
Sometimes (e.g., 12 + 21 = 33) this yields a RADAR palindrome right
away. Sometimes the process must be repeated several times until
a RADAR brand emerges. Consider the brand '87' that requires four
steps to convert to a RADAR brand:

       Brand  Reverse   Sum
Step 1:   87 +    78 =  165
Step 2:  165 +   561 =  726
Step 3:  726 +   627 = 1353
Step 4: 1353 +  3531 = 4884

Given the mother's brand (a positive integer), determine the number
of steps and ultimate RADAR brand that results from applying the
procedure above. No answer will be greater than two billion.

PROBLEM NAME: radar

INPUT FORMAT:

* Line 1: A single integer, the mother's non-RADAR brand.

SAMPLE INPUT:

87

OUTPUT FORMAT:

* Line 1: Two space-separated integers, respectively: the number of
steps to find the RADAR brand and the ultimate RADAR brand.

SAMPLE OUTPUT:

4 4884
*/

#include <bits/stdc++.h>
using namespace std;

int N;

int getReverse(int n) {
    int a = 0;
    while (n > 0) {
        a *= 10;
        a += n % 10;
        n /= 10;
    }
    return a;
}

int main() {
    cin >> N;
    int ans = 1;
    int newNum = N + getReverse(N);
    while (newNum != getReverse(newNum)) {
        newNum = newNum + getReverse(newNum);
        ans++;
    }
    cout << ans << " " << newNum << endl;
    return 0;
}