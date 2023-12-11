#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
vector<int> adj[N];
bool visited[N] = {false};

int dfs(int s){
   visited[s] = true;
    int count = 1;
    for(int v:adj[s]){
        if(visited[v]) continue;
        count += dfs(v);
    }
    return count;
}

int main()
{
    // Write your code here
    vector<int> result;
    int n,ed; cin>>n>>ed;
    for(int i=0; i<ed; i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0; i<N; i++){
        if(visited[i]) continue;
        if(adj[i].size()==0) continue;
        result.push_back(dfs(i));
    }
    sort(result.begin(),result.end());
    
    for(int v:result){
        cout<<v<<" ";
    }

    return 0;
}
