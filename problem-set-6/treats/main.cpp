/*
Cow Treats
==========

The cows celebrated another banner month for record milk production
and thus have each earned a special treat. They completely fill a
W x H rectangle formation (1 <= W <= 25; 1 <= H <= 25) awaiting
their treat.

Each cow has a unique figure of merit F_rc (1 <= F_rc <= 1,000,000)
which denotes her overall milk production performance. Farmer John
thinks it is only fair to prioritize the treats handed out, rewarding
the highest producing cows first. He plans to traverse the rectangular
formation one row at a time, starting at the beginning of row 1 and
giving out all row 1's treats before he starts on row 2 using the
same method.

He has asked the cows to reorganize themselves so that the cows
with better production are rewarded first. The cows, though, are
not so very good at organization. They can either swap a pair of
rows or swap a pair of columns of their formation. FJ has asked
them to do the best they can by moving the best cow to the upper
left corner (row 1, column 1), the next best cow to row 1, column
2 (if possible), and so on. Of course, the cows can not fully sort
themselves, but they can do their best by following this heuristic:

    * determine the order of FJ's treat awards:
            1    2   3  ...
            W+1 W+2 W+3 ...

    * find the highest rated cow; swap rows and columns until she
      is at row 1, column 1; never move her again

    * Then execute this rule until as many cows are placed as possible:

	Find the next highest rated cow. Swap rows and columns
	(without moving any higher-rated cow) to move her to the
	best possible spot that is still available (e.g., row 1,
	column 2 if it's available of row 2, column 1 if no slots
	can be achieved in row 1.

By way of example, consider this set of 3 x 4 cows:

         5  7  4  1
         9 99  2  6
         8  3 10 11

The cow with 99 is clearly the highest-rated and belows in the upper
left corner. Swap rows 1 and 2 then swap columns 1 and 2 (or do it
the other way around -- the answer is the same):

         99  9  2  6
          7  5  4  1
          3  8 10 11

The cow with 11 should be rewarded as soon as possible after the
highest-rated cow. She is current in slot (3,4), the last slot to
be rewarded. At this point, it's too late to swap her into the first
row or even the first column. Thus, she needs to move to (2,2) by
swapping columns 2 and 4 then swapping rows 2 and 3:

       Swap cols 2 and 4     Swap rows 2 and 3
         99   6  2  9          99   6  2  9
          7   1  4  5    ->     3  11 10  8
          3  11 10  8           7   1  4  5

The cow with 10 is rewarded directly after the cow with 11.  The
cow 9 is already rewarded. The cow with 8 is awarded just after the
cow with 10. The cow with 7 is rewarded directly after the cow with
8.  The cow with 6 is already rewarded. The cow with 5 would best
move to row 3, column 2 but the rows 1 and 2 are frozen as are all
the columns.  Thus, cows 1, 4, and 5 do not move, and the second
diagram above is the "best the cows can do".

Implement this algorithm for other rectangular arrays of cows.

PROBLEM NAME: treats

INPUT FORMAT:

* Line 1: Two space-separated integers: W and H

* Lines 2..H+1: Line i+1 contains W space-separated integers F_ic,
        where c ranges from 1 to W.

SAMPLE INPUT:

4 3
5 7 4 1
9 99 2 6
8 3 10 11

OUTPUT FORMAT:

* Lines 1..H: Line i contains W space-separated integers representing
        the i-th row of cows in the cows' final formation.

SAMPLE OUTPUT:

99 6 2 9
3 11 10 8
7 1 4 5
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> grid;

int W, H;

void printGrid() {
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            cout << grid[r][c] << " ";
        }
        cout << endl;
    }
}

void swapRows(int r1, int r2) {
    swap(grid[r1], grid[r2]);
}

void swapCols(int c1, int c2) {
    for (int i = 0; i < H; i++) {
        swap(grid[i][c1], grid[i][c2]);
    }
}

int main() {
    cin >> W >> H;
    grid = vector<vector<int>>(H, vector<int>(W));
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            cin >> grid[x][y];
        }
    }
    int lockedR = 0;
    int lockedC = 0;
    while (lockedR < H || lockedC < W) {
        pair<int, int> largest = {-1, -1};
        for (int x = 0; x < H; x++) {
            for (int y = 0; y < W; y++) {
                if (x < lockedR && y < lockedC) {
                    continue;
                }
                if ((largest.first == -1 && largest.second == -1) || grid[x][y] > grid[largest.first][largest.second]) {
                    largest = {x, y};
                }
            }
        }
        //cout << largest.first << "," << largest.second << endl;
        if (largest.first >= lockedR && largest.second >= lockedC) {
            swapRows(largest.first, lockedR);
            swapCols(largest.second, lockedC);
            lockedR++;
            lockedC++;
        } else if (largest.first >= lockedR) {
            swapRows(largest.first, lockedR);
            lockedR++;
        } else if (largest.second >= lockedC) {
            swapCols(largest.second, lockedC);
            lockedC++;
        }
        // break;
    }
    printGrid();
    return 0;
}