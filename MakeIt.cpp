#include<bits/stdc++.h>
using namespace std;

unordered_map<int, bool> dp;

bool steps(int i, int n){

    if(i==n) return true;
    if(i>n) return false;

    if(dp.find(i) != dp.end()) {
        return dp[i];
    }

    bool op1 = steps(i+3, n);
    bool op2 = steps(i*2, n);

    return dp[i] = op1 || op2;
}

int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n; 
        dp.clear();

        bool result = steps(1,n);
        if(result) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}
