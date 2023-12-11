#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    int nums[n];
    for(int i=0; i<n; i++){
        cin>> nums[i];
    }
    int k; cin>>k;
    int l =0, r = n-1;
    int mid , flag = 0;
    while(l<r){
         mid = (l+r)/2;
        if(nums[mid]==k){
            if(mid-1>=0 && nums[mid-1]==k){
                flag=1;
                break;
            }
            else if(mid+1<n && nums[mid+1]==k){
                flag=1;
                break;
            }
            else break;
        }
        else if(mid<k){
            l=mid +1;
        }
        else r = mid;
    }
    if(flag==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}