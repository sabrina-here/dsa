#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1005;
int graph[N][N];
bool vis[N][N];
int dis[N][N];
vector<pair<int, int>> path = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};

bool isValid(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m) return true;
    return false;
}

void bfs(int ki, int kj){
    queue<pair<int,int>> q;
    q.push({ki,kj});
    vis[ki][kj] = true;
    dis[ki][kj] = 0;
    while(!q.empty()){
        pair<int,int> parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;
        for(auto child:path){
            int ci = pi + child.first;
            int cj = pj + child.second;
            if(isValid(ci,cj) && !vis[ci][cj]){
                q.push({ci,cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[pi][pj] + 1;
            }
        }
    }
}

int main(){

    int t; cin>>t;
    int qi,qj,ki,kj;
    while(t--){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                vis[i][j] = false;
                dis[i][j] = -1;
            }
        }
        cin>>ki>>kj;
        cin>>qi>>qj;
        bfs(ki,kj);
        cout<<dis[qi][qj]<<endl;
        
    }

    return 0;
}