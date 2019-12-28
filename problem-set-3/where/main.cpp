/*
Where's Bessie?
===============

Always known for being quite tech-savy, Farmer John is testing out 
his new automated drone-mounted cow locator camera, which supposedly 
can take a picture of his field and automatically figure out the 
location of cows. Unfortunately, the camera does not include a very 
good algorithm for finding cows, so FJ needs your help developing a 
better one.

The overhead image of his farm taken by the camera is described by an 
N x N grid of characters, each in the range A...Z, representing one 
of 26 possible colors. Farmer John figures the best way to define a 
potential cow location (PCL) is as follows: A PCL is a rectangular 
sub-grid (possibly the entire image) with sides parallel to the image 
sides, not contained within any other PCL (so no smaller subset of a 
PCL is also a PCL). Furthermore, a PCL must satisfy the following 
property: focusing on just the contents of the rectangle and ignoring 
the rest of the image, exactly two colors must be present, one forming 
a contiguous region and one forming two or more contiguous regions.

For example, a rectangle with contents

AAAAA
ABABA
AAABB

would constitute a PCL, since the A's form a single contiguous region 
and the B's form more than one contiguous region. The interpretation 
is a cow of color A with spots of color B.

A region is "contiguous" if you can traverse the entire region by 
moving repeatedly from one cell in the region to another cell in the 
region taking steps up, down, left, or right.

Given the image returned by FJ's camera, please count the number of 
PCLs.

PROBLEM NAME: where

INPUT FORMAT:

The first line of input contains N, the size of the grid (1 <= N <= 20). 
The next N lines describe the image, each consisting of N characters.

OUTPUT FORMAT:

Print a count of the number of PCLs in the image.

SAMPLE INPUT:

4
ABBC
BBBC
AABB
ABBC

SAMPLE OUTPUT:

2

In this example, the two PCLs are the rectangles with contents

ABB
BBB
AAB
ABB

and

BC
BC
BB
BC
*/

#include <bits/stdc++.h>
using namespace std;

struct Pixel {
    char value;
    bool visited = false;
};

int N;
vector<vector<Pixel>> grid;
struct PCL {
    int x1, y1, x2, y2;
};
vector<PCL> pcls;

void visit(int x, int y, int x1, int y1, int x2, int y2, char value) {
    if (x < x1 || y < y1 || x > x2 || y > y2) {
        return;
    }
    if (grid[x][y].visited) {
        return;
    }
    if (grid[x][y].value != value) {
        return;
    }
    grid[x][y].visited = true;
    visit(x + 1, y, x1, y1, x2, y2, value);
    visit(x - 1, y, x1, y1, x2, y2, value);
    visit(x, y + 1, x1, y1, x2, y2, value);
    visit(x, y - 1, x1, y1, x2, y2, value);
}

bool isPCL(int x1, int y1, int x2, int y2) {
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            grid[x][y].visited = false;
        }
    }
    map<int, int> colors;
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            if (!grid[x][y].visited) {
                colors[grid[x][y].value]++;
                visit(x, y, x1, y1, x2, y2, grid[x][y].value);
            }
        }
    }
    if (colors.size() == 2) {
        auto c = colors.begin();
        int color1Count = c->second;
        c++;
        int color2Count = c->second;
        if (color2Count < color1Count) {
            swap(color1Count, color2Count);
        }
        if (color1Count == 1 && color2Count > 1) {
            return true;
        }
    }
    return false;
}

int biggestPCL(int index) {
    for (int i = 0; i < pcls.size(); i++) {
        if (i != index) {
            if (pcls[index].x1 >= pcls[i].x1 &&
                pcls[index].y1 >= pcls[i].y1 &&
                pcls[index].x2 <= pcls[i].x2 &&
                pcls[index].y2 <= pcls[i].y2) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> N;
    grid = vector<vector<Pixel>>(N, vector<Pixel>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            grid[i][j].value = s[j];
        }
    }
    for (int x1 = 0; x1 < N; x1++) {
        for (int y1 = 0; y1 < N; y1++) {
            for (int x2 = N - 1; x2 >= 0; x2--) {
                for (int y2 = N - 1; y2 >= 0; y2--) {
                    if (isPCL(x1, y1, x2, y2)) {
                        PCL pcl = {x1, y1, x2, y2};
                        pcls.push_back(pcl);
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < pcls.size(); i++) {
        if (biggestPCL(i)) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}