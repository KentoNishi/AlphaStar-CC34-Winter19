// Test case path: [C:\Users\kento\OneDrive\Files\Documents\GitHub\JOI-Solutions\2019-2020\training\2019-yo\2019-yo-data\2019-yo-t4]
// https://atcoder.jp/contests/joi2019yo/tasks/joi2019_yo_d

#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    cin >> N;
    vector<int> heights = vector<int>(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    vector<bool> isSea = vector<bool>(N + 2);
    isSea[0] = isSea[N + 1] = true;
    for (int i = 0; i < N; i++) {
        isSea[i + 1] = heights[i] == 0;
    }
    int islandCount = 0;
    for (int i = 1; i <= N; i++) {
        if (isSea[i - 1] && !isSea[i]) {
            islandCount++;
        }
    }
    vector<pair<int, int>> surfaces;
    // <height,id>
    for (int i = 0; i < N; i++) {
        if (heights[i] > 0) {
            surfaces.push_back(make_pair(heights[i], i + 1));
        }
    }
    sort(surfaces.begin(), surfaces.end());
    int ans = islandCount;
    for (int i = 0; i < surfaces.size(); i++) {
        int index = surfaces[i].second;
        isSea[index] = true;
        if (isSea[index - 1] && isSea[index + 1]) {
            islandCount--;
        }
        if (!isSea[index - 1] && !isSea[index + 1]) {
            islandCount++;
        }
        if (i == surfaces.size() - 1 || surfaces[i + 1].first != surfaces[i].first) {
            ans = max(islandCount, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
