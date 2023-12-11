#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;

int main(){

    int t; cin>>t;
    while(t--){
        int n, sum; cin>>n>>sum;
        sum = 1000-sum;
        int w[n+1];
        for(int i=0; i<n; i++) cin>>w[i];
        
        int dp[n+1][sum+1];

        for(int i=1; i<=sum; i++){ 
            dp[0][i] = 0;
        }
        dp[0][0]=1;

        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++) {
                if(w[i-1] <= j){
                    int op1 = dp[i][j- w[i-1]];
                    int op2 = dp[i-1][j];
                    dp[i][j] = (op1 + op2) % inf; 
                }
                else{
                    dp[i][j] = dp[i-1][j] % inf;
                }
            }
        }
        cout << dp[n][sum] << endl;
    }

    return 0;
}