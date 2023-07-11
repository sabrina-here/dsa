#include <bits/stdc++.h>
using namespace std;

class myQ{
    public:
        list<int> q;
        void push(int value){
            q.push_back(value);
        }
        void pop(){
            q.pop_front();
        }
        int front(){
            return q.front();
        }
        int size(){
            return q.size();
        }
        bool empty(){
            return q.empty();
        }

};

int main(){

    return 0;
}