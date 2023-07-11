#include <bits/stdc++.h>
using namespace std;

class myStack{
    public:
        vector<int> v;
        void push(int value){
            v.push_back(value);
        }
        int top(){
            return v.back();
        }
        void pop(){
            v.pop_back();
        }
        int size(){
            return v.size();
        }
        bool empty(){
            return v.empty();
        }

};

int main(){

    return 0;
}