#include <bits/stdc++.h>

using namespace std;

void printRev(stack<char> st){
    if(st.empty()) return;
    char c = st.top();
    st.pop();
    printRev(st);
    cout<<c;
}

int main()
{
    int q; cin>>q;
    while(q--){
        int n; cin>>n;
        stack<char> st;
        while(n--){
            char c; cin>>c;
            if(st.empty()) st.push(c);
            else if(st.top()==c) {
                while(!st.empty() && st.top()==c){
                    st.pop();
                }
                
            }
            else if((st.top()=='R' && c=='B') || (st.top()=='B' && c=='R')) {
                st.pop();
                if(!st.empty() && st.top()=='P') st.pop();
                else st.push('P');
            }
            else if((st.top()=='R' && c=='G') || (st.top()=='G' && c=='R')) {
                st.pop();
                if(!st.empty() && st.top()=='Y') st.pop();
                else st.push('Y');

            }
            else if((st.top()=='B' && c=='G') || (st.top()=='G' && c=='B')) {
                st.pop();
                if(!st.empty() && st.top()=='C') st.pop();
                else st.push('C');
            }
            else st.push(c);
        }
        if(st.empty()) cout<<endl;
        else{
            printRev(st);
            cout<<endl;
        }
        
    }

    return 0;
}
