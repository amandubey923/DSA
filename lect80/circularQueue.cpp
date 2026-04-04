#include<iostream>
using namespace std;

class CircularQueue{
    int* arr ;
    int currSize, cap ;
    int f , r;

    public:
    CircularQueue(int size){
        cap = size;
        arr = new int[cap];
        currSize = 0;
        f = 0;
        r = -1;
    }
    void push(int data){
        if(currSize == cap){
            cout<<"Queue is full"<<endl;
            return;
        }
        r = (r + 1) % cap;
        arr[r] = data;
        currSize++;
    }
    void pop(){
        if(currSize == 0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f = (f + 1) % cap;
        currSize--;
    }
    int front(){
        if(currSize == 0){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[f];
    }
    bool empty(){
        return currSize == 0;
    }

};

int main(){
    CircularQueue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout << "Front element: " << q.front() << endl;

    q.pop();
    cout << "Front element after pop: " << q.front() << endl;

    if(q.empty()){
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;

}