#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int leader[N];
int parentSize[N];
int cnt = 0;

void dsu_set(int n){
    for( int i=0; i<=n; i++){
        leader[i] = -1;
        parentSize[i] = 1;
    }
}

int dsu_find(int a){
    while(leader[a] != -1){
        a = leader[a];
    }
    return a;
}

void dsu_union(int a, int b){
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(leaderA != leaderB){
        if(parentSize[leaderA] >= parentSize[leaderB]){
            leader[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else{
            leader[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
    else cnt++;
}

int main(){
    int n,e; cin>>n>>e;
    dsu_set(n);
    while(e--){
        int a,b;
        cin>>a>>b;
        dsu_union(a,b);
    }
    cout<<cnt<<endl;

    return 0;
}