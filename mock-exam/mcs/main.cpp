/*
Magic Cow Shoes
===============

One day while grazing in particularly deep hay, Betsy discovered 
four magic cow shoes! She donned them and found that they enabled 
her to jump around the pasture which, of course, is subdivided into 
a convenient grid with R rows (1 <= R <= 50) and C columns 
(1 <= C <= 50).

The shoes enabled her to jump two different ways: both like a chess 
game knight and in another pattern she'd never seen before. She 
noticed that she jumped like a knight on her first, third, fifth, 
and odd-numbered moves while she jumped in the new way on the second, 
fourth, sixth, and even-numbered moves. Here is a map of the possible 
move patterns she discovered:

Knight (Odd moves)     Other (Even moves)
   . . K . K . .         . . . O . . .
   . K . . . K .         . . . . . . .
   . . . B . . .         . O . B . O .
   . K . . . K .         . . . . . . .
   . . K . K . .         . . . O . . .

When Betsy starts at the 'B', depending on whether her next move is 
an odd or even one, she can jump to any one of the 'K's or 'O's.
Realizing she can now move about the pasture much more quickly, Betsy 
wonders how long it will take her to jump using the magic shoes all 
the way over to the Milky Way candy bar Farmer John accidentally 
dropped on his recent visit to the cows.

Given the size of the field along with the locations of Betsy and the 
candy bar, determine the minimum number of magic shoe jumps required 
for Betsy to land on the square with the candy bar. She is not allowed 
to jump outside the pasture but is sure that it is always possible to 
get to the candy bar.

PROBLEM NAME: mcs

INPUT FORMAT:

* Line 1: Two space-separated integers: respectively R and C.

* Line 2: Two space-separated integers: respectively the row and column 
          of Betsy's starting location.

* Line 3: Two space-separated integers: respectively the row and column 
          of the candy bar.

SAMPLE INPUT:

4 5
4 1
4 3

INPUT DETAILS:

. . . . .
. . . . . 
. . . . . 
B . C . . 

OUTPUT FORMAT:

* Line 1: A single integer that is the minimum number of jumps using 
          the magic shoes until Betsy lands on the candy bar.

SAMPLE OUTPUT:

3

OUTPUT DETAILS:

Here is one way she can do it:

. . . . .
. 1 . 2 .
. . . . .
B . 3 . .
*/

#include <bits/stdc++.h>
using namespace std;

int R, C;

int oddDC[] = {2, 1, -1, -2, -2, -1, 1, 2};
int oddDR[] = {1, 2, 2, 1, -1, -2, -2, -1};
int evenDC[] = {2, 0, -2, 0};
int evenDR[] = {0, 2, 0, -2};

int main() {
    cin >> R >> C;
    pair<int, int> start;
    cin >> start.first >> start.second;
    pair<int, int> end;
    cin >> end.first >> end.second;
    start.first--;
    start.second--;
    end.first--;
    end.second--;
    queue<pair<pair<int, int>, int>> toVisit;
    toVisit.emplace(pair<pair<int, int>, int>(start, 0));
    while (toVisit.size() > 0) {
        pair<pair<int, int>, int> top = toVisit.front();
        toVisit.pop();
        if (top.first.first >= R || top.first.second >= C || top.first.first < 0 || top.first.second < 0) {
            continue;
        }
        if (top.first.first == end.first && top.first.second == end.second) {
            cout << top.second << endl;
            break;
        }
        if (top.second % 2 == 0) {
            for (int i = 0; i < 8; i++) {
                pair<int, int> p = make_pair(top.first.first + oddDR[i], top.first.second + oddDC[i]);
                if (p.first >= R || p.second >= C || p.first < 0 || p.second < 0) {
                    continue;
                }
                toVisit.emplace(make_pair(p, top.second + 1));
            }
        } else {
            for (int i = 0; i < 4; i++) {
                pair<int, int> p = make_pair(top.first.first + evenDR[i], top.first.second + evenDC[i]);
                if (p.first >= R || p.second >= C || p.first < 0 || p.second < 0) {
                    continue;
                }
                toVisit.emplace(make_pair(p, top.second + 1));
            }
        }
    }
    return 0;
}