/*
It's All About the Base
=======================

Bessie the cow has been taking computing classes at her local college
(or "cow-ledge", in her case), and she has been very excited to
recently learn about writing numbers in different bases.

Recall that a number written in base B has digit places representing
1, B, B^2, B^3, and so on from right to left.  For example, in our
familiar base 10 numbering system, we have digits representing 1's,
10's, 100's, 1000's and so on. The sequence of digits 1234,
interpreted in base 10, really means 1(1000) + 2(100) + 3(10) + 4(1).
The same sequence of digits 1234, interpreted in base 5, would mean
1(125) + 2(25) + 3(5) + 4(1), which adds up to the number 194 in base
10.  Bessie notices that if the base increases, so does the number
represented by a sequence of digits -- for example, 1234 in base 7
represents a larger number than 1234 in base 6.

When writing numbers in base B, each digit can range from 0 through
B-1, so for example in base 10 each digit is in the range 0..9, and in
base 5 each digit is in the range 0..4.  It is entirely possible to
consider bases larger than 10.  Computer scientists often use base 16
("hexadecimal"), where the letters A..F represent digits of values
10..15.  For example, BEEF in hexadecimal corresponds to 11(4096) +
14(256) + 14(16) + 15, which adds up to the number 48879 in base 10.

Bessie is intrigued by the concept of using bases much larger than 10.
She takes a number N and writes it down in two different bases X and
Y, where both X and Y are in the range 10..15,000.  Interestingly, in
both cases, she gets a sequence of 3 digits, each of which happens to
be only in the range 1..9.  Unfortunately, due to Bessie's poor
memory, she has now forgotten N, X, and Y!  Given just the two 3-digit
sequences she wrote down, please help her figure the two bases X and Y
that she used.

Note that due to the potential size of X and Y, a program that
searches exhaustively over every possible value of X and Y (nearly
15,000^2 possibilities!) will not run within the time limit, so it
would not receive full credit.

PROBLEM NAME: whatbase

INPUT:

The input file starts with an integer K, then it contains K lines each
specifying a separate test case.  Each test case consists of two
3-digit numbers.  The first is a number N written in base X, and the
second is N written in base Y (N, X, and Y are possibly different for
each test case).

SAMPLE INPUT:

1
419 792

OUTPUT:

Your output should contain K lines, one for each test case.  On each
line, output the two numbers X and Y for the relevant test case,
separated by a space.  A unique solution for each case is guaranteed
to exist.

SAMPLE OUTPUT:

47 35

SOLUTION NOTES:

The number 8892, written in base 47, is 419.  Written in base 35, it is
792.
*/

#include <bits/stdc++.h>
using namespace std;

int N;

int changeBase(int n, int b, int old) {
    //cout << n << " in base " << b << " is ";
    int num = 0;
    int i = 0;
    while (n > 0) {
        num += (n % old) * pow(b, i);
        i++;
        n /= old;
    }
    return num;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int aChanged, bChanged;
        cin >> aChanged >> bChanged;
        int baseA = 10;
        int baseB = 10;
        while (aChanged != bChanged) {
            // cout << aChanged << " " << bChanged << endl;
            // cout << "============" << endl;
            if (aChanged > bChanged) {
                baseB++;
                bChanged = changeBase(bChanged, baseB, baseB - 1);
            } else {
                baseA++;
                aChanged = changeBase(aChanged, baseA, baseA - 1);
            }
            // cout << baseA << " " << baseB << " --> " << aChanged << " " << bChanged << endl;
        }
        cout << baseA << " " << baseB << endl;
    }
    return 0;
}