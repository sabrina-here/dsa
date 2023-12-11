#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m;
const int N = 1005;
char a[N][N];
bool vis[N][N];
vector<pii> path ={{0,1},{0,-1},{1,0},{-1,0}}; 

bool isValid(int ci, int cj){
    if(ci>=0 && ci<n && cj>=0 && cj<m && a[ci][cj] != '#') return true;
    return false;
}

void bfs(int si, int sj){

    queue<pii> q;
    q.push({si,sj});
    vis[si][sj] = true;
    while(!q.empty()){
        pii parent = q.front();
        q.pop();
        int pi = parent.first;
        int pj = parent.second;
        for(int i=0; i<4; i++){
            pii childIndex = path[i];
            int ci = pi + childIndex.first;
            int cj = pj + childIndex.second;
            if(isValid(ci,cj) && !vis[ci][cj]){
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
        }
    }
}

int main(){

    cin>>n>>m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == '.' && !vis[i][j]){
                bfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;

    return 0;
}