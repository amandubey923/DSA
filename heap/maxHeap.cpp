#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MaxHeap{
    int * arr;
    int size; // total size of the heap
    int total_size; // total size of the array
public:
    MaxHeap(int n){
        arr = new int[total_size];
        size = 0;
        total_size = n;
       
    }
    // insert an element in the heap
    void insert(int value){
        // check if the heap is full
        if(size == total_size){
            cout<<"Heap is full"<<endl;
            return;
        }
        // insert the element at the end of the heap
        arr[size] = value;
        int index = size;
        size++;
        // heapify the heap
        while(index > 0 && arr[(index-1)/2] < arr[index]){
            swap(arr[(index-1)/2], arr[index]);
            index = (index-1)/2;
        };
        cout <<arr[index] <<" inserted"<<endl;
    }
    void print (){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MaxHeap H1(6);
    H1.insert(10);
    H1.insert(20);
    H1.insert(5);
    H1.insert(15);
    H1.insert(30);
    H1.insert(25);
    H1.insert(35); // Heap is full
    H1.print();

    return 0;
}