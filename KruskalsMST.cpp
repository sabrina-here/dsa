#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int leader[N];
int parentSize[N];

class Edge{

    public:
        int a,b,w;
        Edge(int x, int y, int z){
            a=x;
            b=y;
            w = z;
        }
};

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
}


bool cmp(Edge a, Edge b){
    return a.w  < b.w;
}

int main(){

    int n,e; cin>>n>>e;
    vector<Edge> v;
    vector<Edge> ans;
    dsu_set(n);
    while(e--){
        int a,b,w; cin>>a>>b>>w;
        v.push_back(Edge(a,b,w));
    }
    sort(v.begin(),v.end(),cmp);

    for(Edge val:v){
        int a = val.a;
        int b = val.b;
        int w = val.w;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA == leaderB) continue;
        dsu_union(a,b);
        ans.push_back(val);
    }

    int total =0;
    for(Edge cost:ans){
        total += cost.w;
    }
    
    if(ans.size()==n-1) cout<<total<<endl;
    else cout<<-1<<endl;


    return 0;
}