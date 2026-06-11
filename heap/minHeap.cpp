#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MinHeap{
    int * arr;
    int size; // total size of the heap
    int total_size; // total size of the array
public:
    MinHeap(int n){
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
        void Heapify(int index){
            int smallest = index;
            int left = 2*index+1;
            int right = 2*index+2;
    
            // smallest will store the index of the element 
            //which is smallest among the root, left and right child
            if(left < size && arr[left] < arr[smallest]){
                smallest = left;
            }
            if(right < size && arr[right] < arr[smallest]){
                smallest = right;
            }
    
            if(smallest != index){
                swap(arr[index], arr[smallest]);
                Heapify(smallest);
            }
        }
};
int main(){
    MinHeap H1(6);
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