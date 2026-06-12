#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int,
    vector<int>,
    greater<int>> q; // min heap

    q.push(10);
    q.push(20);
    q.push(5);
    q.push(15);
    q.push(25);
    cout<<q.top()<<endl; 
    q.pop();
    cout<<q.top()<<endl;
    cout<<q.size()<<endl;
    while(!q.empty()){
        cout<<q.top()<<" "<<endl;
        q.pop();
    }

    return 0;
}