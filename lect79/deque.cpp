#include<iostream>
#include<deque>

using namespace std;

int main(){
    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30); // 10 20 30

    dq.push_front(5); // 5 10 20 30
    dq.pop_back();    // 5 10 20
    cout<<dq.front()<< " "<< dq.back() << endl;

    return 0;
}

