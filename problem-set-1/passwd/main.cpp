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