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