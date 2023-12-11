#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
vector<int> graph[N];
bool vis[N];

void dfs(int source){
    vis[source] = true;
    for(int child:graph[source]){
        if(!vis[child]) dfs(child);
    }
}

int main(){

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int count = 0;
    vector<int> ans;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            count++;
            ans.push_back(i);
            dfs(i);
        }
    }
    cout<<count-1<<endl;
    for(int i=0; i<ans.size()-1; i++){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }

    return 0;
}