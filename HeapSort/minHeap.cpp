#include<iostream>
using namespace std;

void Heapify(int arr[], int index, int n ){
    int smallest = index;
    int left = 2*index+1;
    int right = 2*index+2;

    if(left < n && arr[left] < arr[smallest])
    smallest = left;
    if(right <n && arr[right] < arr[smallest])
    smallest = right;

    if(smallest != index){
        swap(arr[smallest] , arr[index]);
        Heapify(arr,smallest,n);
    }
}

void BuildMinHeap(int arr[],int n){
    // step down
    for(int i=n/2-1; i >= 0; i--){
        Heapify(arr,i,n);
    }
}

void printHeap(int arr[], int n){
    for(int i=0; i<n; i++)
    cout<<arr[i] << " ";
    cout<<endl;
}

int main(){
    int arr[]= {10,3,8,9,5,13,18,14,11,70};
    BuildMinHeap(arr,10);
    printHeap(arr,10);
    return 0;
}