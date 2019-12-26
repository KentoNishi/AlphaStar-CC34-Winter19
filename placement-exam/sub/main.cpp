/*
Longest Contiguous Subsequence
==============================
Bessie's friend Jessie wanted to enter a programming contest. "What
are the tasks like?" she asked. 

Bessie, known to be knowledgeable about so many things, said "Here
is a typical problem that folks solve early in their competitive
career. See if you can solve it."

Perhaps you can solve it, too.

You are given two sequences of integers, S1 and S2. S1 has length
L1 (1 <= L1 <= 180) and S2 has length L2 (1 <= L2 <= 180). Your job
is to print out the length of the longest contiguous subsequence
of numbers common to both L1 and L2. Ordered sequence S1 has elements
S1_1, S1_2, ..., S1_L1 (-100 <= S1_i <= 100); S2 has elements S2_i
(-100 <= S2_i <= 100).

A contiguous subsequence is a consecutive run of numbers in that
sequence. The subsequences of 1 2 3 1 are: the empty sequence, "1",
"1 2", "1 2 3", "1 2 3 1", "2", "2 3", "2 3 1", "3", "3 1", and a
repeat occurrence of "1".

PROBLEM NAME: sub

INPUT FORMAT:

* Line 1: Two space-separated integers: L1 and L2

* Lines 2..L1+1: Line i+1 contains a single integer: S1_i

* Lines L1+2..L1+L2+1: Line L1+i+1 A single integer: S2_i

SAMPLE INPUT:

10 12
1
1
1
3
2
3
3
3
4
5
1
1
1
1
3
2
3
3
4
4
5
-8

INPUT DETAILS:

Two sequences:
1,1,1,3,2,3,3,3,4,5
1,1,1,1,3,2,3,3,4,4,5,-8

OUTPUT FORMAT:

* Line 1: A single integer, the length of the longest contiguous
        subsequence of L1 and L2

SAMPLE OUTPUT:

7

OUTPUT DETAILS:

Corresponds to the contiguous subsequence 1,1,1,3,2,3,3.
*/

#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> list1;
vector<int> list2;

bool inList2(int i,int k){
    for(int j=0;j<M;j++){
        bool found=true;
        for(int p=0;p<(k-i);p++){
            if(list2[j+p]!=list1[i+p]){
                found=false;
                break;
            }
        }
        if(found){
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    list1=vector<int>(N);
    list2=vector<int>(M);
    for(int i=0;i<N;i++){
        cin >> list1[i];
    }
    for(int i=0;i<M;i++){
        cin >> list2[i];
    }
    if(M<N){
        swap(list1,list2);
        swap(M,N);
    }
    // N is always less than M
    int ans=0;
    for(int i=0;i<N;i++){
        for(int k=N-1;k>i;k--){
            if(inList2(i,k)){
                ans=max(k-i,ans);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}