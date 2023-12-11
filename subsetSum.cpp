#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int sum = 1000-m;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        bool dp[n+1][sum+1];
        for(int i=0; i<=sum; i++) dp[0][i] = false;
        dp[0][0] = true;

        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(a[i-1]<= j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j - a[i-1]];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        

        if(dp[n][sum]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}