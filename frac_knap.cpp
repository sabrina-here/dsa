#include<bits/stdc++.h>
using namespace std;

int main(){

    int t; cin>>t;
    while(t--){
        int n, sum; cin>>n>>sum;
        sum = 1000-sum;
        int w[n+1];
        int v[n+1];
        for(int i=0; i<n; i++) cin>>w[i];
        int dp[n+1][sum+1];

        for(int i=0; i<=n; i++){
            for(int j=0; j<=sum; j++) {
                if(i==0 || j==0) dp[i][j]=0;
            }
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++) {
                if(w[i-1] <= j){
                    int op1 = v[i-1] + dp[i][j- w[i-1]];
                    int op2 = dp[i-1][j];
                    dp[i][j] = max(op1, op2);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        cout<<dp[n][sum]<<endl;
    }


    return 0;
}