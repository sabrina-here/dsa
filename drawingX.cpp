#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin>> n;
    int ss=0, sb=n-2;
    if(n%2==0){
        cout<<"invalid entry"<<endl;
    }
    else{
        for(int i=0; i<n; i++){
            
            
            if(i<= floor(n/2)){
                for(int j=0; j<=ss; j++){
                cout<<" ";
            }
            if(i== floor(n/2)) {
                cout<<"X"<<endl;
                ss-=2;
                sb+=4;
            }
            else{
                cout<<"\\";
                for(int j=0; j<sb; j++){
                    cout<<" ";
                }
                cout<<"/"<<endl;
            }
                 ss+=1;
                sb-=2;
            }
            else {
                for(int j=0; j<=ss; j++){
                cout<<" ";
            }
            
            
                cout<<"/";
                for(int j=0; j<sb; j++){
                    cout<<" ";
                }
                cout<<"\\"<<endl;
            
                ss-=1;
                sb+=2;
                
            }
        }
    }
    return 0;
}