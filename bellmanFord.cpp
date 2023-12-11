#include<bits/stdc++.h>
using namespace std;

class Edge{

    public:
        int a,b,w;
        Edge(int x, int y, int z){
            a=x;
            b=y;
            w = z;
        }
};

int main(){

    int n,e; cin >> n >> e;
    vector<Edge> v;
    long long dis[n+1];

    while(e--){
        int a,b; 
        long long w;
        cin >> a >> b >> w;
        v.push_back(Edge(a,b,w));
    }
    for(int i=1; i<=n; i++){
        dis[i] = LONG_LONG_MAX;
    }
    int s; cin >> s;
    dis[s] = 0;

    for(int i=1; i<=n-1; i++){
        for(Edge ed:v){
        int a = ed.a;
        int b = ed.b;
        long long w = ed.w;
        if(dis[a]+w<dis[b] && dis[a] != LONG_LONG_MAX){
            dis[b] = dis[a] + w;
        }
    }
    }
    bool flag = false;

    for(Edge ed:v){
        int a = ed.a;
        int b = ed.b;
        int w = ed.w;
        if(dis[a]+w<dis[b] && dis[a] != LONG_LONG_MAX){
            flag = true;
            break;
        }
    }

    int q; 
    cin >> q;

    if(flag) cout << "Negative Cycle Detected" <<endl;
    else{
        while(q--){
            int d; 
            cin >> d;
            if(dis[d] == LONG_LONG_MAX){
                cout << "Not Possible" << endl;
            }
            else{
                cout << dis[d] << endl;
            }
        }
    }

    return 0;
}