/*
Securing the Barn
=================

Farmer John has installed a new security system on the barn and now
must issue a valid password to the cows in the herd. A valid password
consists of L (3 <= L <= 15) different lower-case characters (from the
traditional latin character set 'a'...'z'), has at least one vowel
('a', 'e', 'i', 'o', or 'u'), at least two consonants (non-vowels),
and has characters that appear in alphabetical order (i.e., 'abc'
is valid; 'bac' is not).

Given a desired length L along with C lower-case characters, write a
program to print all the valid passwords of length L that can be formed
from those letters. The passwords must be printed in alphabetical order,
one per line.

PROBLEM NAME: passwd

INPUT FORMAT:

* Line 1: Two space-separated integers, L and C

* Line 2: C space-separated lower-case characters that are the set of
        characters from which to build the passwords

SAMPLE INPUT:

4 6
a t c i s w

INPUT DETAILS:

Passwords of length 4 chosen from the given six characters

OUTPUT FORMAT:

* Lines 1..?: Each output line contains a word of length L characters
        (and no spaces). The output lines must appear in alphabetical
        order.

SAMPLE OUTPUT:

acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
*/

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<char> vowels;
vector<char> consonants;
vector<string> all;

void recursiveSolve(string str, int currentVowel, int currentConsonant, int vowelsUsed, int consonantsUsed) {
    if (str.size() == N) {
        if (consonantsUsed >= 2 && vowelsUsed >= 1) {
            // cout << str << endl;
            all.push_back(str);
        }
        return;
    }
    for (int i = currentVowel; i < vowels.size(); i++) {
        if (str.size() != 0 && vowels[i] < str[str.size() - 1]) {
            continue;
        }
        recursiveSolve(str + vowels[i], i + 1, currentConsonant, vowelsUsed + 1, consonantsUsed);
    }
    for (int i = currentConsonant; i < consonants.size(); i++) {
        if (str.size() != 0 && consonants[i] < str[str.size() - 1]) {
            continue;
        }
        recursiveSolve(str + consonants[i], currentVowel, i + 1, vowelsUsed, consonantsUsed + 1);
    }
    return;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        char a;
        cin >> a;
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
            vowels.push_back(a);
        } else {
            consonants.push_back(a);
        }
    }
    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());
    recursiveSolve("", 0, 0, 0, 0);
    sort(all.begin(), all.end());
    for (auto &p : all) {
        cout << p << endl;
    }
    return 0;
}