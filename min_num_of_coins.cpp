#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;
    
    while(t--){
        int n, sum; cin>>n>>sum;
        sum = 1000-sum;
        int w[n+1];
        for(int i=0; i<n; i++) cin>>w[i];
        
        int dp[n+1][sum+1];

        for(int i=1; i<=sum; i++){ 
            dp[0][i] = INT_MAX-1;
        }
        dp[0][0]=0;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++) {
                if(w[i-1] <= j){
                    int op1 = 1 + dp[i][j- w[i-1]];
                    int op2 = dp[i-1][j];
                    dp[i][j] = min(op1, op2);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        if(dp[n][sum]<1000) cout<<dp[n][sum]<<endl;
        else cout<<-1<<endl;
    }


    return 0;
}