#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int arr1[n+1];
    for(int i=0; i<n; i++) cin>>arr1[i];
    arr1[n] = INT_MIN;
    int m; cin>>m;
    int arr2[m+1];
    for(int j=0; j<m; j++) cin>>arr2[j];
    arr2[m] = INT_MIN;
    int result[m+n];
    int r = m+n, lp=0, rp=0;
    for(int i=0; i<r; i++){
        if(arr1[lp]>arr2[rp]){
            result[i] = arr1[lp];
            lp++;
        }
        else{
            result[i] = arr2[rp];
            rp++;
        }
    }
    for(int i:result) cout<<i<<" ";
}