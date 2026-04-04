#include<iostream>
#include<vector>

using namespace std ;

class Node{
    public:
    int data;
    Node*next;

    Node(int val){
        data= val;
        next= NULL;
    }

};

class Queue{
    Node* head;
    Node* tail;

    public:
    Queue(){
        head = tail = NULL;
    }
    void push(int data){// insert dAta at tail
        Node* newNode = new Node(data);
        if(empty()){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return;
        }else{
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int front(){
        if(empty()){
            cout << "Queue is empty" << endl;
            return -1;  // Meaningful value indicating empty queue
        }
        return head->data;
    }

    bool empty(){
        return head == NULL;
    }

};

int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }

    cout<<endl;

    return 0;
}