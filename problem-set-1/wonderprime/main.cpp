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