#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<pair<int,int>> graph[N];
bool vis[N];
vector<int> dis(N, INT_MAX);

void dijkstra(int source){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
     pq.push({0,source});
     dis[source] = 0;
     vis[source] = true;
     while(!pq.empty()){
        pair<int , int> parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        int parentCost = parent.first;
        if(vis[parentNode]) continue;
        vis[parentNode] = true;
        for(pair<int,int> pii:graph[parentNode]){
            int childNode = pii.first;
            int childCost = pii.second;
            if(dis[childNode] > childCost+parentCost){
                dis[childNode] = childCost + parentCost;
                pq.push({childCost+parentCost, childNode});
            }
        }
     }   
}

int main(){

    int n, e;
    while(e--){
        int a, b, w; cin>>a>>b>>w;
        graph[a].push_back({b,w});
    }
    int q; cin>>q;
    while(q--){
        int x,y; cin>>x>>y;
        dijkstra(x);
        if(dis[y]<INT_MAX) cout<<dis[y]<<endl;
        else cout<<"-1"<<endl;
        for(int i=0; i<=n; i++){
            vis[i] = false;
            dis[i] = INT_MAX;
        }
    }

    return 0;
}