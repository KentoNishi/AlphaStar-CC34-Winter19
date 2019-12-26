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