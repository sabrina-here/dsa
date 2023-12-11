#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
vector<pair<int,int>> graph[N];
const int INF = 1e9+10;
vector<int> dist(N,INF);
bool vis[N];

void dijkstra(int source){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,source});
    dist[source]=0;
    //vis[source] = true;
    while(!pq.empty()){
        pair<int,int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        int parentCost = parent.first;
        if(vis[parentNode]) continue;
        vis[parentNode]= true;
        for(auto pii:graph[parentNode]){
            int childNode = pii.first;
            int childCost = pii.second;
            if(dist[childNode]> childCost+parentCost){
                dist[childNode] = childCost+parentCost;
                pq.push({childCost+parentCost, childNode});
            }
        }
    }
}

int main()
{
    // Write your code here
    int n,e; cin>>n>>e;
    for(int i=0; i<e; i++){
        int u,v,w; cin>>u>>v>>w;
        graph[u].push_back({v,w});
        //graph[v].push_back({u,w});
    }
    int s; cin>>s;
    dijkstra(s);
    // for(int i = 1;i <= n;i++){
    //     cout << dist[i] << endl;
    // }
    int q; cin>>q;
    while(q--){
        int ds,dw; cin>>ds>>dw;
        //cout<<"distance "<<ds<<" "<<dist[ds]<<endl;
        if(dw >= dist[ds]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    

    return 0;
}
