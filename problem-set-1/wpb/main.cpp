/*
Wonderprime Brands
==================

The cows are forever competing to see who has the best brand. The
latest rage is brands that are 'Wonderprimes'. You probably already
know that a brand consists of a sequence of digits that does not
begin with 0; brands actually look a lot like positive integers.

A wonderprime is a number that can be partitioned into two prime
numbers, each of which has at least D digits and, of course, doesn't
start with 0. When D=2, the number 11329 is a wonderprime (since it
connects 113 and 29, both of which are prime).

Only a few of the cows have wonderprime brands, but they all want
one. Your job is to find the first wonderprime greater than or equal
to a supplied integer N (1 <= N <= 2,000,000,000). No integer greater
than 2,000,000,000 will be required.

PROBLEM NAME: wpb

INPUT FORMAT:

* Line 1: Two space-separated integers: D and N

SAMPLE INPUT:

2 11328


OUTPUT FORMAT:

* Line 1: A line that contains the first wonderprime no smaller than
        N.

SAMPLE OUTPUT:

11329
*/

#include <bits/stdc++.h>
using namespace std;

int D, N;
int getSubInt(int n, int j, int k) {
    int num = 0;
    int digits = to_string(n).size();
    for (int i = 0; i < digits - k; i++) {
        n /= 10;
    }
    for (int i = 0; i < k - j; i++) {
        num += (n % 10) * pow(10, i);
        n /= 10;
    }
    return num;
}

bool isPrime(int number) {
    if (number < 2)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;
    for (int i = 3; (i * i) <= number; i += 2) {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main() {
    cin >> D >> N;
    if(N<pow(10,D-1)){
        N=pow(10,D*2-1);
    }
    // cout << "Starting at " << N << endl;
    while (true) {
        int digits = to_string(N).size();
        for (int i = D; i <= digits - D; i++) {
            int num1 = getSubInt(N, 0, i);
            int num2 = getSubInt(N, i, digits);
            if (num1<pow(10,i-1) || num2 < pow(10,digits-i-1)) {
                continue;
            }
            if (isPrime(num1) && isPrime(num2)) {
                cout << N << endl;
                return 0;
            }
        }
        N++;
    }
    return 0;
}