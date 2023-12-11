#include<stdc++.h>
using namespace std;

const int N = 1e3+5;
vector<int> adj[N];
bool visited[N] = {false};

// ------ shortest distance from one node to another------

void shortestPathBfs(int s, int d) {
    
    if(s==d) return 0;
    queue<pair<int,int>> q;
    q.push({s,1});
    visited[s] = true;
    
    while (!q.empty()) {
       pair<int, int> p = q.front();
        q.pop();
        int node = p.first;
        int level = p.second;
        for(int v:adj[node]){
            if(visited[v])continue;
            if(v==d) return level;
            q.push({v,level+1});
            visited[v] = true;
        }
    }
    return -1;
}


void bfs(int s){
    int count =0;
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(visited[v]) continue;
            q.push(v);
            visited[v] = true;
        }
    }
}

void dfs(int s){
   visited[s] = true;
    for(int v:adj[s]){
        if(visited[v]) continue;
        dfs(v);
    }
}

int main(){

//-------------taking graph input---------------
    
    int n,ed; cin>>n>>ed;
    for(int i=0; i<ed; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int test; cin>>test;
    while(test--){
        int s,d; cin>>s>>d;
        bfs(s,d);
    }

    return 0;
}