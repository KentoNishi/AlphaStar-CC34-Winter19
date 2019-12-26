/*
Evening Stroll
==============

As we all know, cows love novelty. So many times we are called upon to 
help them avoid duplication of effort or scenery. Another important 
question has appeared.

Betsy is happily grazing in a field of R (1 <= R <= 20) rows by C (1 <= 
C <= 30) columns of both grass plots (denoted by '.') and rocky plots 
(denoted by 'R'). Plot (1,1) is in the upper left corner of this grid. 
The sun is going down, so it's time to head back to the barn, which is 
south and east of Betsy.

Betsy wants to take a new route to the barn every night. She can't walk 
on the rocky plots at all and will only travel south (larger row) and 
east (larger column) toward the barn, never north or west. Please 
calculate how many evenings she can amble to the barn on a new route 
before she has to repeat a route taken earlier.

As an example, consider this layout of Betsy's pasture:

           B . . .       B = Betsy    . = plot for walking
           R . . .       R = Rocks
           . . . B       B = Barn

Here are the six ways she can walk to the barn:

B## . .    B## . .    B#### .    B## . .   B######   B#### .
R # . .    R ### .    R . # .    R #####   R . . #   R . ###
. ####B    . . ##B    . . ##B    . . . B   . . . B   . . . B

PROBLEM NAME: stroll

INPUT FORMAT:

* Line 1: Two space-separated integers, respectively: R and C

* Lines 2..R+1: Line i+1 represents row i and contains C 
        space-separated elements that represent plots in the field. 
        The first element is the element in column 1 of row i. Each 
        element is a 'B', 'R', or '.' as above. The 'B's are unambiguous.

SAMPLE INPUT:

3 4
B . . .
R . . .
. . . B

OUTPUT FORMAT:

* Line 1: A single integer that is the number of unique paths from
        Betsy to the barn. The answer will not exceed 2,000,000,000.

SAMPLE OUTPUT:

6
*/

#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<char>> grid;
vector<vector<int>> visited;

int floodFrom(int row, int col) {
    if (row >= R || col >= C) {
        return 0;
    }
    if (grid[row][col] == 'B') {
        return 1;
    }
    if (grid[row][col] == 'R') {
        return 0;
    }
    if (visited[row][col] > 0) {
        return visited[row][col];
    }
    //cout << "Visiting " << row << "," << col << endl;
    int sum = floodFrom(row + 1, col) + floodFrom(row, col + 1);
    visited[row][col] = sum;
    return sum;
}

int main() {
    cin >> R >> C;
    grid = vector<vector<char>>(R, vector<char>(C));
    visited = vector<vector<int>>(R, vector<int>(C, 0));
    int cowR = -1;
    int cowC = -1;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> grid[r][c];
            if (cowR == -1 && grid[r][c] == 'B') {
                cowR = r;
                cowC = c;
                grid[r][c] = '.';
            }
        }
    }
    floodFrom(cowR, cowC);
    /*
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            cout << visited[r][c] << " ";
        }
        cout << endl;
    }
    */
    cout << visited[cowR][cowC] << endl;
    return 0;
}